# Titanium Rich Text Editor

Use the native `Aztec` rich text editor ([iOS](https://github.com/wordpress-mobile/AztecEditor-ios) & [Android](https://github.com/wordpress-mobile/AztecEditor-Android)) in Titanium!

## Requirements

- [x] Android: Titanium SDK 9.0.0+
- [x] iOS: Titanium SDK 9.2.0+

## Example

```js
import TiEditor from 'ti.editor';

const window = Ti.UI.createWindow({ title: 'Add blog post' });
const nav = Ti.UI.createNavigationWindow({ window });

// Alloy: <EditorView id="editorView" module="ti.editor" onChange="..." onLink="..." />
const editorView = TiEditor.createEditorView({ top: 20, left: 20, right: 20 });

// Editable
editorView.editable = true | false;

// Text Color
editorView.color = "#CCC";

// Editor ContentInsets
// iOS:
editorView.contentInset = { left: 8, right: 8, top: 10, bottom: 10 };
// Android:
editorView.padding = { left: 8, right: 8, top: 10, bottom: 10 };

// Scroll Indicator Insets
editorView.scrollIndicatorInsets = { top: 10, bottom: 10 };

// Hint Text (Android-Only):
editorView.hintText = "Enter text here...";

editorView.focus(); // Focus the Editor
editorView.blur(); // Blur the Editor

// populate content html
editorView.content = "<h1>Hello World<h1>"; 
// Get content html:
editorView.content;

// Check if content changed: Android-Only
editorView.isChanged;

// BackgroundColor: iOS-Only
editorView.editorBackgroundColor = "#CCC";

editorView.addEventListener('change', ({ value }) => {
  console.warn('Content changed: ', value);
});

// Show/Hide Editor Toolbar (Android-Only):
editorView.editorToolbarVisible = true | false;

editorView.addEventListener('link', ({ url }) => {
  Ti.Platform.openURL(url);
});

window.add(editorView);
window.addEventListener('focus', () => editorView.focus());

nav.open();
```

## Author

Hans Knöchel

## License

MIT
