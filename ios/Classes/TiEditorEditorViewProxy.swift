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
    get { return self.editorView.editorView.html }
    set {
      _content = newValue
      if let content = _content {
        self.editorView.editorView.html = content
      }
      self.replaceValue(newValue, forKey: "content", notification: false)
    }
  }

  private var _hintText: String?
  @objc var hintText: String {
    get { return self.editorView.editorView.placeholder }
    set {
      _hintText = newValue
      if let hintText = _hintText {
        self.editorView.editorView.placeholder = hintText
      }
      self.replaceValue(newValue, forKey: "hintText", notification: false)
    }
  }
  
  private var _editable: Bool?
  @objc var editable: Bool {
    get { return self.editorView.editorView.isEditingEnabled }
    set {
      _editable = newValue
      if let editable = _editable {
        self.editorView.editorView.isEditingEnabled = editable
      }
      self.replaceValue(newValue, forKey: "editable", notification: false)
    }
  }
  
  @objc(setColor:)
  func setColor(content: String) {
    self.editorView.editorView.setTextColor(TiUtils.colorValue(content)!.color)
  }
  
  @objc(focus:)
  func focus(_ unused: Any) {
    self.editorView.editorView.inputAccessoryView?.isHidden = false
    _ = self.editorView.editorView.becomeFirstResponder()
  }
  
  @objc(blur:)
  func blur(_ unused: Any) {
    _ = self.editorView.editorView.resignFirstResponder()
    self.editorView.editorView.inputAccessoryView?.isHidden = true
  }
  
  @objc(hideToolbar:)
  func hideToolbar(_ unused: Any) {
    self.editorView.editorView.inputAccessoryView?.isHidden = false
  }

  @objc(showToolbar:)
  func showToolbar(_ unused: Any) {
    self.editorView.editorView.inputAccessoryView?.isHidden = true
  }
}
