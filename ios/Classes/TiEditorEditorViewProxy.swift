/**
 * Axway Titanium
 * Copyright (c) 2018-present by Axway Appcelerator. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

import TitaniumKit

@objc(TiEditorEditorViewProxy)
public class TiEditorEditorViewProxy : TiViewProxy {

  lazy var editorView: TiEditorEditorView = {
    return self.view as! TiEditorEditorView
  }()

  private var _content: String?
  @objc var content: String {
    get { return self.editorView.editorView.getHTML() }
    set {
      _content = newValue
      if let content = _content {
        self.editorView.editorView.setHTML(content)
      }
      self.replaceValue(newValue, forKey: "content", notification: false)
    }
  }

  private var _editable: Bool?
  @objc var editable: Bool {
    get { return self.editorView.editorView.isEditable }
    set {
      _editable = newValue
      if let editable = _editable {
        self.editorView.editorView.isEditable = editable
      }
      self.replaceValue(newValue, forKey: "editable", notification: false)
    }
  }

  @objc(setColor:)
  func setColor(content: Any) {
    self.editorView.editorView.textColor = TiUtils.colorValue(content)!.color
  }
  
  @objc(setEditorBackgroundColor:)
  func setEditorBackgroundColor(backgroundColor: Any) {
    self.editorView.editorView.backgroundColor = TiUtils.colorValue(backgroundColor)?.color
  }

  @objc(setContentInset:)
  func setContentInset(contentInset: Any) {
    self.editorView.editorView.contentInset = TiUtils.contentInsets(contentInset)
  }

  @objc(setScrollIndicatorInsets:)
  func setScrollIndicatorInsets(scrollIndicatorInsets: Any) {
    self.editorView.editorView.scrollIndicatorInsets = TiUtils.contentInsets(scrollIndicatorInsets)
  }

  @objc(focus:)
  func focus(_ unused: Any) {
    _ = self.editorView.editorView.becomeFirstResponder()
  }

  @objc(blur:)
  func blur(_ unused: Any) {
    self.editorView.editorView.resignFirstResponder()
  }
  
  @objc(toggleLink:)
  func toggleLink(link: [Any]) {
    if let params = link[0] as? [String: Any], let link = params["link"] as? String, let range = params["range"] as? [String: Int] {
      self.editorView.setLink(link: link, in: NSRange(location: range["location"]!, length: range["length"]!))
    } else {
      print("[WARN] Invalid params!")
    }
  }
}
