/**
 * Axway Titanium
 * Copyright (c) 2018-present by Axway Appcelerator. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

import RichEditorView
import TitaniumKit

@objc(TiEditorEditorView)
public class TiEditorEditorView : TiUIView {

  lazy var editorView: RichEditorView = {
    let editor = RichEditorView(frame: self.frame)
    editor.delegate = self
    
    let toolbar = RichEditorToolbar(frame: CGRect(x: 0, y: 0, width: self.bounds.size.width, height: 44))
    toolbar.editor = editor
    toolbar.options = [
      RichEditorDefaultOption.bold,
      RichEditorDefaultOption.underline,
      RichEditorDefaultOption.strike,
      RichEditorDefaultOption.orderedList,
      RichEditorDefaultOption.unorderedList,
      RichEditorDefaultOption.alignLeft,
      RichEditorDefaultOption.alignCenter,
      RichEditorDefaultOption.alignRight,
      RichEditorOptionItem(image: nil, title: NSLocalizedString("done", comment: "done"), action: { toolbar in
        let _ = editor.resignFirstResponder()
        editor.inputAccessoryView?.isHidden = true
      })
    ]

    editor.inputAccessoryView = toolbar
    
    self.addSubview(editor)
    
    return editor
  }()

  public override func frameSizeChanged(_ frame: CGRect, bounds: CGRect) {
    super.frameSizeChanged(frame, bounds: bounds)
    self.editorView.frame = bounds
  }
}

// MARK: RichEditorDelegate

extension TiEditorEditorView : RichEditorDelegate {
  
  public func richEditorDidLoad(_ editor: RichEditorView) {
    if let editorProxy = self.proxy as? TiEditorEditorViewProxy, let backgroundColor = editorProxy.backgroundColor {
      editorView.setEditorBackgroundColor(TiUtils.colorValue(backgroundColor)!.color)
    }
  }

  public func richEditor(_ editor: RichEditorView, contentDidChange content: String) {
    self.proxy.fireEvent("change", with: ["value": content])
  }
  
  public func richEditor(_ editor: RichEditorView, heightDidChange height: Int) {
    self.proxy.fireEvent("heightDidChange", with: ["height": height])
  }
  
  public func richEditorTookFocus(_ editor: RichEditorView) {
    self.editorView.inputAccessoryView?.isHidden = false
  }
  
  public func richEditorLostFocus(_ editor: RichEditorView) {
    self.editorView.inputAccessoryView?.isHidden = true
  }
}
