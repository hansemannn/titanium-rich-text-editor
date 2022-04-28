/**
 * Axway Titanium
 * Copyright (c) 2018-present by Axway Appcelerator. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

import Aztec
import Gridicons
import TitaniumKit

@objc(TiEditorEditorView)
public class TiEditorEditorView : TiUIView {

  fileprivate(set) lazy var editorView: Aztec.TextView = {
    let editor = Aztec.TextView(defaultFont: UIFont.systemFont(ofSize: 15.0), defaultMissingImage: Constants.defaultMissingImage)

    editor.formattingDelegate = self
    editor.delegate = self
    editor.textAttachmentDelegate = self
    editor.textContainer.lineFragmentPadding = 0

    let providers: [TextViewAttachmentImageProvider] = [
        CommentAttachmentRenderer(font: Constants.defaultContentFont),
        HTMLAttachmentRenderer(font: Constants.defaultHtmlFont),
    ]

    for provider in providers {
        editor.registerAttachmentImageProvider(provider)
    }

    self.addSubview(editor)

    return editor
  }()
  
  
  fileprivate(set) lazy var formatBar: Aztec.FormatBar = {
    let formatBar = createToolbar()
    return formatBar
  }()

  public override func frameSizeChanged(_ frame: CGRect, bounds: CGRect) {
    super.frameSizeChanged(frame, bounds: bounds)
    self.editorView.frame = bounds
  }
  
  private let formattingIdentifiersWithOptions: [FormattingIdentifier] = [.orderedlist, .unorderedlist, .p, .header1, .header2, .header3, .header4, .header5, .header6]
  
  private func formattingIdentifierHasOptions(_ formattingIdentifier: FormattingIdentifier) -> Bool {
      return formattingIdentifiersWithOptions.contains(formattingIdentifier)
  }
}

extension TiEditorEditorView {
  
  func handleAction(for barItem: FormatBarItem) {
      guard let identifier = barItem.identifier,
          let formattingIdentifier = FormattingIdentifier(rawValue: identifier) else {
              return
      }

      switch formattingIdentifier {
      case .bold:
          toggleBold()
      case .italic:
          toggleItalic()
      case .underline:
          toggleUnderline()
      case .strikethrough:
          toggleStrikethrough()
      case .blockquote:
          toggleBlockquote()
      case .unorderedlist:
        toggleUnorderedList()
      case .orderedlist:
        toggleOrderedList()
      case .link:
        toggleLink()
      case .p:
          toggleParagraph()
      case .header1:
          toggleHeadline()
      default:
          break
      }

      updateFormatBar()
  }

  func toggleBold() {
      editorView.toggleBold(range: editorView.selectedRange)
  }

  func toggleItalic() {
      editorView.toggleItalic(range: editorView.selectedRange)
  }

  func toggleUnderline() {
      editorView.toggleUnderline(range: editorView.selectedRange)
  }

  func toggleStrikethrough() {
      editorView.toggleStrikethrough(range: editorView.selectedRange)
  }

  func toggleBlockquote() {
      editorView.toggleBlockquote(range: editorView.selectedRange)
  }
  
  func toggleUnorderedList() {
    editorView.toggleUnorderedList(range: editorView.selectedRange)
  }
  
  func toggleOrderedList() {
    editorView.toggleOrderedList(range: editorView.selectedRange)
  }
  
  func toggleParagraph() {
    editorView.toggleHeader(.none, range: editorView.selectedRange)
  }
  
  func toggleHeadline() {
    editorView.toggleHeader(.h1, range: editorView.selectedRange)
  }
  
  func toggleLink() {
    var linkTitle = ""
    var linkURL: URL? = nil
    var linkRange = editorView.selectedRange
    if let expandedRange = editorView.linkFullRange(forRange: editorView.selectedRange) {
       linkRange = expandedRange
       linkURL = editorView.linkURL(forRange: expandedRange)
    }
    let target = editorView.linkTarget(forRange: editorView.selectedRange)
    linkTitle = editorView.attributedText.attributedSubstring(from: linkRange).string
    let allowTextEdit = !editorView.attributedText.containsAttachments(in: linkRange)
    
    if proxy._hasListeners("addlink") {
      proxy.fireEvent("addlink", with: [
        "url": linkURL != nil ? linkURL!.absoluteString : "",
        "range": ["location": linkRange.location, "length": linkRange.length],
        "text": linkTitle,
        "target": target ?? "",
        "allowTextEdit": allowTextEdit
      ])
    }
  }
  
  func setLink(link: String, in range: NSRange) {
    editorView.setLink(URL(string: link)!, inRange: range)
  }

  func changeRichTextInputView(to: UIView?) {
      if editorView.inputView == to {
          return
      }

      editorView.inputView = to
      editorView.reloadInputViews()
  }
  
  static var tintedMissingImage: UIImage = {
      if #available(iOS 13.0, *) {
          return Gridicon.iconOfType(.image).withTintColor(.label)
      } else {
          // Fallback on earlier versions
          return Gridicon.iconOfType(.image)
      }
  }()
  
  struct Constants {
      static let defaultContentFont   = UIFont.systemFont(ofSize: 14)
      static let defaultHtmlFont      = UIFont.systemFont(ofSize: 24)
      static let defaultMissingImage  = tintedMissingImage
      static let formatBarIconSize    = CGSize(width: 20.0, height: 20.0)
      static let headers              = [Header.HeaderType.none, .h1, .h2, .h3, .h4, .h5, .h6]
      static let lists                = [TextList.Style.unordered, .ordered]
      static let moreAttachmentText   = "more"
      static let titleInsets          = UIEdgeInsets(top: 5, left: 0, bottom: 5, right: 0)
  }

  func updateFormatBar() {
      guard let toolbar = editorView.inputAccessoryView as? Aztec.FormatBar else {
          return
      }

      let identifiers: Set<FormattingIdentifier>
      if editorView.selectedRange.length > 0 {
          identifiers = editorView.formattingIdentifiersSpanningRange(editorView.selectedRange)
      } else {
          identifiers = editorView.formattingIdentifiersForTypingAttributes()
      }

      toolbar.selectItemsMatchingIdentifiers(identifiers.map({ $0.rawValue }))
  }
  
  func createToolbar() -> Aztec.FormatBar {
      let scrollableItems = scrollableItemsForToolbar
      let overflowItems = overflowItemsForToolbar

      let toolbar = Aztec.FormatBar()

      if #available(iOS 13.0, *) {
          toolbar.backgroundColor = UIColor.systemGroupedBackground
          toolbar.tintColor = UIColor.secondaryLabel
          toolbar.highlightedTintColor = UIColor.systemBlue
          toolbar.selectedTintColor = UIColor.systemBlue
          toolbar.disabledTintColor = .systemGray4
          toolbar.dividerTintColor = UIColor.separator
      } else {
          toolbar.tintColor = .gray
          toolbar.highlightedTintColor = .blue
          toolbar.selectedTintColor = self.tintColor
          toolbar.disabledTintColor = .lightGray
          toolbar.dividerTintColor = .gray
      }

      toolbar.overflowToggleIcon = Gridicon.iconOfType(.ellipsis)
      toolbar.frame = CGRect(x: 0, y: 0, width: UIScreen.main.bounds.width, height: 44.0)
      toolbar.autoresizingMask = [ .flexibleHeight ]
      toolbar.formatter = self

      toolbar.setDefaultItems(scrollableItems, overflowItems: overflowItems)

      toolbar.barItemHandler = { [weak self] item in
          self?.handleAction(for: item)
      }

      return toolbar
  }
  
  func makeToolbarButton(identifier: FormattingIdentifier) -> FormatBarItem {
    let button = FormatBarItem(image: identifier.iconImage, identifier: identifier.rawValue)
    button.accessibilityLabel = identifier.accessibilityLabel
    button.accessibilityIdentifier = identifier.accessibilityIdentifier

    return button
  }

  var scrollableItemsForToolbar: [FormatBarItem] {
      let headerButton = makeToolbarButton(identifier: .header1)

      let listButton = makeToolbarButton(identifier: .unorderedlist)
      var listIcons = [String: UIImage]()
      for list in Constants.lists {
          listIcons[list.formattingIdentifier.rawValue] = list.iconImage
      }

      listButton.alternativeIcons = listIcons

      return [
          headerButton,
          listButton,
          makeToolbarButton(identifier: .bold),
          makeToolbarButton(identifier: .italic),
          // makeToolbarButton(identifier: .link),
          makeToolbarButton(identifier: .underline),
          makeToolbarButton(identifier: .strikethrough)
      ]
  }

  // Unused right now
  var overflowItemsForToolbar: [FormatBarItem] {
      return []
  }
}

// MARK: TextViewFormattingDelegate

extension TiEditorEditorView : TextViewFormattingDelegate {

  public func textViewCommandToggledAStyle() {
    if proxy._hasListeners("toggle") {
      proxy.fireEvent("toggle")
    }
  }
}

// MARK: TextViewAttachmentDelegate

extension TiEditorEditorView : TextViewAttachmentDelegate {

  public func textView(_ textView: TextView, attachment: NSTextAttachment, imageAt url: URL, onSuccess success: @escaping (UIImage) -> Void, onFailure failure: @escaping () -> Void) {
    
  }
  
  public func textView(_ textView: TextView, urlFor imageAttachment: ImageAttachment) -> URL? {
    return imageAttachment.url
  }
  
  public func textView(_ textView: TextView, placeholderFor attachment: NSTextAttachment) -> UIImage {
    attachment.image ?? UIImage()
  }
  
  public func textView(_ textView: TextView, deletedAttachment attachment: MediaAttachment) {
    
  }
  
  public func textView(_ textView: TextView, selected attachment: NSTextAttachment, atPosition position: CGPoint) {
    
  }
  
  public func textView(_ textView: TextView, deselected attachment: NSTextAttachment, atPosition position: CGPoint) {
    
  }
}

// MARK: FormatBarDelegate

extension TiEditorEditorView : FormatBarDelegate {
  
  public func formatBarTouchesBegan(_ formatBar: FormatBar) {
    
  }
  
  public func formatBar(_ formatBar: FormatBar, didChangeOverflowState overflowState: FormatBarOverflowState) {
    switch overflowState {
    case .hidden:
        print("Format bar collapsed")
    case .visible:
        print("Format bar expanded")
    }

  }
}

private extension Header.HeaderType {
    var formattingIdentifier: FormattingIdentifier {
        switch self {
        case .none: return FormattingIdentifier.p
        case .h1:   return FormattingIdentifier.header1
        case .h2:   return FormattingIdentifier.header2
        case .h3:   return FormattingIdentifier.header3
        case .h4:   return FormattingIdentifier.header4
        case .h5:   return FormattingIdentifier.header5
        case .h6:   return FormattingIdentifier.header6
        }
    }

    var description: String {
        switch self {
        case .none: return NSLocalizedString("Default", comment: "Description of the default paragraph formatting style in the editor.")
        case .h1: return "Heading 1"
        case .h2: return "Heading 2"
        case .h3: return "Heading 3"
        case .h4: return "Heading 4"
        case .h5: return "Heading 5"
        case .h6: return "Heading 6"
        }
    }

    var iconImage: UIImage? {
        return formattingIdentifier.iconImage
    }
}

private extension TextList.Style {
    var formattingIdentifier: FormattingIdentifier {
        switch self {
        case .ordered:   return FormattingIdentifier.orderedlist
        case .unordered: return FormattingIdentifier.unorderedlist
        }
    }

    var description: String {
        switch self {
        case .ordered: return "Ordered List"
        case .unordered: return "Unordered List"
        }
    }

    var iconImage: UIImage? {
        return formattingIdentifier.iconImage
    }
}

extension TiEditorEditorView : UITextViewDelegate {
  
  public func textViewDidChangeSelection(_ textView: UITextView) {
      updateFormatBar()
      changeRichTextInputView(to: nil)
  }

  public func textViewDidChange(_ textView: UITextView) {
      switch textView {
      case editorView:
          updateFormatBar()
      default:
          break
      }

    if proxy._hasListeners("change") {
      proxy.fireEvent("change", with: ["value": editorView.getHTML()])
    }
  }

  public func textViewShouldBeginEditing(_ textView: UITextView) -> Bool {
      switch textView {
      case editorView:
          formatBar.enabled = true
      default:
          break
      }

      editorView.inputAccessoryView = formatBar

      return true
  }
}

extension FormattingIdentifier {

    var iconImage: UIImage {

        switch(self) {
        case .media:
            return gridicon(.addOutline)
        case .p:
            return gridicon(.heading)
        case .bold:
            return gridicon(.bold)
        case .italic:
            return gridicon(.italic)
        case .underline:
            return gridicon(.underline)
        case .strikethrough:
            return gridicon(.strikethrough)
        case .blockquote:
            return gridicon(.quote)
        case .orderedlist:
            return gridicon(.listOrdered)
        case .unorderedlist:
            return gridicon(.listUnordered)
        case .link:
            return gridicon(.link)
        case .horizontalruler:
            return gridicon(.minusSmall)
        case .sourcecode:
            return gridicon(.code)
        case .more:
            return gridicon(.readMore)
        case .header1:
            return gridicon(.headingH1)
        case .header2:
            return gridicon(.headingH2)
        case .header3:
            return gridicon(.headingH3)
        case .header4:
            return gridicon(.headingH4)
        case .header5:
            return gridicon(.headingH5)
        case .header6:
            return gridicon(.headingH6)
        case .code:
            return gridicon(.posts)
        default:
            return gridicon(.help)
        }
    }

    private func gridicon(_ gridiconType: GridiconType) -> UIImage {
        let size = TiEditorEditorView.Constants.formatBarIconSize
        return Gridicon.iconOfType(gridiconType, withSize: size)
    }

    var accessibilityIdentifier: String {
        switch(self) {
        case .media:
            return "formatToolbarInsertMedia"
        case .p:
            return "formatToolbarSelectParagraphStyle"
        case .bold:
            return "formatToolbarToggleBold"
        case .italic:
            return "formatToolbarToggleItalic"
        case .underline:
            return "formatToolbarToggleUnderline"
        case .strikethrough:
            return "formatToolbarToggleStrikethrough"
        case .blockquote:
            return "formatToolbarToggleBlockquote"
        case .orderedlist:
            return "formatToolbarToggleListOrdered"
        case .unorderedlist:
            return "formatToolbarToggleListUnordered"
        case .link:
            return "formatToolbarInsertLink"
        case .horizontalruler:
            return "formatToolbarInsertHorizontalRuler"
        case .sourcecode:
            return "formatToolbarToggleHtmlView"
        case .more:
            return "formatToolbarInsertMore"
        case .header1:
            return "formatToolbarToggleH1"
        case .header2:
            return "formatToolbarToggleH2"
        case .header3:
            return "formatToolbarToggleH3"
        case .header4:
            return "formatToolbarToggleH4"
        case .header5:
            return "formatToolbarToggleH5"
        case .header6:
            return "formatToolbarToggleH6"
        case .code:
            return "formatToolbarCode"
        default:
            return ""
        }
    }

    var accessibilityLabel: String {
        switch(self) {
        case .media:
            return NSLocalizedString("Insert media", comment: "Accessibility label for insert media button on formatting toolbar.")
        case .p:
            return NSLocalizedString("Select paragraph style", comment: "Accessibility label for selecting paragraph style button on formatting toolbar.")
        case .bold:
            return NSLocalizedString("Bold", comment: "Accessibility label for bold button on formatting toolbar.")
        case .italic:
            return NSLocalizedString("Italic", comment: "Accessibility label for italic button on formatting toolbar.")
        case .underline:
            return NSLocalizedString("Underline", comment: "Accessibility label for underline button on formatting toolbar.")
        case .strikethrough:
            return NSLocalizedString("Strike Through", comment: "Accessibility label for strikethrough button on formatting toolbar.")
        case .blockquote:
            return NSLocalizedString("Block Quote", comment: "Accessibility label for block quote button on formatting toolbar.")
        case .orderedlist:
            return NSLocalizedString("Ordered List", comment: "Accessibility label for Ordered list button on formatting toolbar.")
        case .unorderedlist:
            return NSLocalizedString("Unordered List", comment: "Accessibility label for unordered list button on formatting toolbar.")
        case .link:
            return NSLocalizedString("Insert Link", comment: "Accessibility label for insert link button on formatting toolbar.")
        case .horizontalruler:
            return NSLocalizedString("Insert Horizontal Ruler", comment: "Accessibility label for insert horizontal ruler button on formatting toolbar.")
        case .sourcecode:
            return NSLocalizedString("HTML", comment:"Accessibility label for HTML button on formatting toolbar.")
        case .more:
            return NSLocalizedString("More", comment:"Accessibility label for the More button on formatting toolbar.")
        case .header1:
            return NSLocalizedString("Heading 1", comment: "Accessibility label for selecting h1 paragraph style button on the formatting toolbar.")
        case .header2:
            return NSLocalizedString("Heading 2", comment: "Accessibility label for selecting h2 paragraph style button on the formatting toolbar.")
        case .header3:
            return NSLocalizedString("Heading 3", comment: "Accessibility label for selecting h3 paragraph style button on the formatting toolbar.")
        case .header4:
            return NSLocalizedString("Heading 4", comment: "Accessibility label for selecting h4 paragraph style button on the formatting toolbar.")
        case .header5:
            return NSLocalizedString("Heading 5", comment: "Accessibility label for selecting h5 paragraph style button on the formatting toolbar.")
        case .header6:
            return NSLocalizedString("Heading 6", comment: "Accessibility label for selecting h6 paragraph style button on the formatting toolbar.")
        case .code:
            return NSLocalizedString("Code", comment: "Accessibility label for selecting code style button on the formatting toolbar.")
        default:
            return ""
        }
    }
}
