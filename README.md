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

// Alloy: <EditorView module="ti.editor" onChange="..." onLink="..." />
const editorView = TiEditor.createEditorView({ top: 20, left: 20, right: 20 });

editorView.addEventListener('change', ({ value }) => {
  console.warn('Content changed: ', value);
});

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
