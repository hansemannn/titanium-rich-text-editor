import TiEditor from 'ti.editor';

const window = Ti.UI.createWindow({ title: 'Add blog post' });
const nav = Ti.UI.createNavigationWindow({ window });

const editorView = TiEditor.createEditorView();

editorView.addEventListener('change', ({ value }) => {
	console.warn('Content changed: ', value);
});

editorView.addEventListener('link', ({ url }) => {
	Ti.Platform.openURL(url);
});

window.add(editorView);
window.addEventListener('focus', () => editorView.focus());

nav.open();