#if 0
#elif defined(__arm64__) && __arm64__
// Generated by Apple Swift version 5.0 effective-4.1.50 (swiftlang-1001.0.69.5 clang-1001.0.46.3)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="RichEditorView",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class UIImage;
@class NSCoder;

/// RichBarButtonItem is a subclass of UIBarButtonItem that takes a callback as opposed to the target-action pattern
SWIFT_CLASS("_TtC14RichEditorView17RichBarButtonItem")
@interface RichBarButtonItem : UIBarButtonItem
@property (nonatomic, copy) void (^ _Nullable actionHandler)(void);
- (nonnull instancetype)initWithImage:(UIImage * _Nullable)image handler:(void (^ _Nullable)(void))handler;
- (nonnull instancetype)initWithTitle:(NSString * _Nonnull)title handler:(void (^ _Nullable)(void))handler;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class RichEditorView;

/// RichEditorDelegate defines callbacks for the delegate of the RichEditorView
SWIFT_PROTOCOL("_TtP14RichEditorView18RichEditorDelegate_")
@protocol RichEditorDelegate
@optional
/// Called when the inner height of the text being displayed changes
/// Can be used to update the UI
- (void)richEditor:(RichEditorView * _Nonnull)editor heightDidChange:(NSInteger)height;
/// Called whenever the content inside the view changes
- (void)richEditor:(RichEditorView * _Nonnull)editor contentDidChange:(NSString * _Nonnull)content;
/// Called when the rich editor starts editing
- (void)richEditorTookFocus:(RichEditorView * _Nonnull)editor;
/// Called when the rich editor stops editing or loses focus
- (void)richEditorLostFocus:(RichEditorView * _Nonnull)editor;
/// Called when the RichEditorView has become ready to receive input
/// More concretely, is called when the internal UIWebView loads for the first time, and contentHTML is set
- (void)richEditorDidLoad:(RichEditorView * _Nonnull)editor;
/// Called when the internal UIWebView begins loading a URL that it does not know how to respond to
/// For example, if there is an external link, and then the user taps it
- (BOOL)richEditor:(RichEditorView * _Nonnull)editor shouldInteractWith:(NSURL * _Nonnull)url SWIFT_WARN_UNUSED_RESULT;
/// Called when custom actions are called by callbacks in the JS
/// By default, this method is not used unless called by some custom JS that you add
- (void)richEditor:(RichEditorView * _Nonnull)editor handle:(NSString * _Nonnull)action;
@end

@protocol RichEditorToolbarDelegate;
@class UIColor;

/// RichEditorToolbar is UIView that contains the toolbar for actions that can be performed on a RichEditorView
SWIFT_CLASS("_TtC14RichEditorView17RichEditorToolbar")
@interface RichEditorToolbar : UIView
/// The delegate to receive events that cannot be automatically completed
@property (nonatomic, weak) id <RichEditorToolbarDelegate> _Nullable delegate;
/// A reference to the RichEditorView that it should be performing actions on
@property (nonatomic, weak) RichEditorView * _Nullable editor;
/// The tint color to apply to the toolbar background.
@property (nonatomic, strong) UIColor * _Nullable barTintColor;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


/// RichEditorToolbarDelegate is a protocol for the RichEditorToolbar.
/// Used to receive actions that need extra work to perform (eg. display some UI)
SWIFT_PROTOCOL("_TtP14RichEditorView25RichEditorToolbarDelegate_")
@protocol RichEditorToolbarDelegate
@optional
/// Called when the Text Color toolbar item is pressed.
- (void)richEditorToolbarChangeTextColor:(RichEditorToolbar * _Nonnull)toolbar;
/// Called when the Background Color toolbar item is pressed.
- (void)richEditorToolbarChangeBackgroundColor:(RichEditorToolbar * _Nonnull)toolbar;
/// Called when the Insert Image toolbar item is pressed.
- (void)richEditorToolbarInsertImage:(RichEditorToolbar * _Nonnull)toolbar;
/// Called when the Insert Link toolbar item is pressed.
- (void)richEditorToolbarInsertLink:(RichEditorToolbar * _Nonnull)toolbar;
@end

@class UIWebView;
@class UIScrollView;
@class UIGestureRecognizer;

/// RichEditorView is a UIView that displays richly styled text, and allows it to be edited in a WYSIWYG fashion.
SWIFT_CLASS("_TtC14RichEditorView14RichEditorView")
@interface RichEditorView : UIView <UIGestureRecognizerDelegate, UIScrollViewDelegate, UIWebViewDelegate>
/// The delegate that will receive callbacks when certain actions are completed.
@property (nonatomic, weak) id <RichEditorDelegate> _Nullable delegate;
/// Input accessory view to display over they keyboard.
/// Defaults to nil
@property (nonatomic, strong) UIView * _Nullable inputAccessoryView;
/// The internal UIWebView that is used to display the text.
@property (nonatomic, readonly, strong) UIWebView * _Nonnull webView;
/// Whether or not scroll is enabled on the view.
@property (nonatomic) BOOL isScrollEnabled;
/// Whether or not to allow user input in the view.
@property (nonatomic) BOOL isEditingEnabled;
/// The content HTML of the text being displayed.
/// Is continually updated as the text is being edited.
@property (nonatomic, readonly, copy) NSString * _Nonnull contentHTML;
/// The internal height of the text being displayed.
/// Is continually being updated as the text is edited.
@property (nonatomic, readonly) NSInteger editorHeight;
/// The line height of the editor. Defaults to 28.
@property (nonatomic, readonly) NSInteger lineHeight;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
/// The HTML that is currently loaded in the editor view, if it is loaded. If it has not been loaded yet, it is the
/// HTML that will be loaded into the editor view once it finishes initializing.
@property (nonatomic, copy) NSString * _Nonnull html;
/// Text representation of the data that has been input into the editor view, if it has been loaded.
@property (nonatomic, readonly, copy) NSString * _Nonnull text;
/// The placeholder text that should be shown when there is no user input.
@property (nonatomic, copy) NSString * _Nonnull placeholder;
/// The href of the current selection, if the current selection’s parent is an anchor tag.
/// Will be nil if there is no href, or it is an empty string.
@property (nonatomic, readonly, copy) NSString * _Nullable selectedHref;
/// Whether or not the selection has a type specifically of “Range”.
@property (nonatomic, readonly) BOOL hasRangeSelection;
/// Whether or not the selection has a type specifically of “Range” or “Caret”.
@property (nonatomic, readonly) BOOL hasRangeOrCaretSelection;
- (void)removeFormat;
- (void)setFontSize:(NSInteger)size;
- (void)setEditorBackgroundColor:(UIColor * _Nonnull)color;
- (void)undo;
- (void)redo;
- (void)bold;
- (void)italic;
- (void)subscriptText;
- (void)superscript;
- (void)strikethrough;
- (void)underline;
- (void)setTextColor:(UIColor * _Nonnull)color;
- (void)setEditorFontColor:(UIColor * _Nonnull)color;
- (void)setTextBackgroundColor:(UIColor * _Nonnull)color;
- (void)header:(NSInteger)h;
- (void)indent;
- (void)outdent;
- (void)orderedList;
- (void)unorderedList;
- (void)blockquote;
- (void)alignLeft;
- (void)alignCenter;
- (void)alignRight;
- (void)insertImage:(NSString * _Nonnull)url alt:(NSString * _Nonnull)alt;
- (void)insertLink:(NSString * _Nonnull)href title:(NSString * _Nonnull)title;
- (void)focus;
- (void)focusAt:(CGPoint)at;
- (void)blur;
/// Runs some JavaScript on the UIWebView and returns the result
/// If there is no result, returns an empty string
/// \param js The JavaScript string to be run
///
///
/// returns:
/// The result of the JavaScript that was run
- (NSString * _Nonnull)runJS:(NSString * _Nonnull)js;
- (void)scrollViewDidScroll:(UIScrollView * _Nonnull)scrollView;
- (BOOL)webView:(UIWebView * _Nonnull)webView shouldStartLoadWithRequest:(NSURLRequest * _Nonnull)request navigationType:(UIWebViewNavigationType)navigationType SWIFT_WARN_UNUSED_RESULT;
/// Delegate method for our UITapGestureDelegate.
/// Since the internal web view also has gesture recognizers, we have to make sure that we actually receive our taps.
- (BOOL)gestureRecognizer:(UIGestureRecognizer * _Nonnull)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer * _Nonnull)otherGestureRecognizer SWIFT_WARN_UNUSED_RESULT;
- (BOOL)becomeFirstResponder SWIFT_WARN_UNUSED_RESULT;
- (BOOL)resignFirstResponder SWIFT_WARN_UNUSED_RESULT;
@end





#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop

#elif defined(__ARM_ARCH_7A__) && __ARM_ARCH_7A__
// Generated by Apple Swift version 5.0 effective-4.1.50 (swiftlang-1001.0.69.5 clang-1001.0.46.3)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="RichEditorView",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class UIImage;
@class NSCoder;

/// RichBarButtonItem is a subclass of UIBarButtonItem that takes a callback as opposed to the target-action pattern
SWIFT_CLASS("_TtC14RichEditorView17RichBarButtonItem")
@interface RichBarButtonItem : UIBarButtonItem
@property (nonatomic, copy) void (^ _Nullable actionHandler)(void);
- (nonnull instancetype)initWithImage:(UIImage * _Nullable)image handler:(void (^ _Nullable)(void))handler;
- (nonnull instancetype)initWithTitle:(NSString * _Nonnull)title handler:(void (^ _Nullable)(void))handler;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class RichEditorView;

/// RichEditorDelegate defines callbacks for the delegate of the RichEditorView
SWIFT_PROTOCOL("_TtP14RichEditorView18RichEditorDelegate_")
@protocol RichEditorDelegate
@optional
/// Called when the inner height of the text being displayed changes
/// Can be used to update the UI
- (void)richEditor:(RichEditorView * _Nonnull)editor heightDidChange:(NSInteger)height;
/// Called whenever the content inside the view changes
- (void)richEditor:(RichEditorView * _Nonnull)editor contentDidChange:(NSString * _Nonnull)content;
/// Called when the rich editor starts editing
- (void)richEditorTookFocus:(RichEditorView * _Nonnull)editor;
/// Called when the rich editor stops editing or loses focus
- (void)richEditorLostFocus:(RichEditorView * _Nonnull)editor;
/// Called when the RichEditorView has become ready to receive input
/// More concretely, is called when the internal UIWebView loads for the first time, and contentHTML is set
- (void)richEditorDidLoad:(RichEditorView * _Nonnull)editor;
/// Called when the internal UIWebView begins loading a URL that it does not know how to respond to
/// For example, if there is an external link, and then the user taps it
- (BOOL)richEditor:(RichEditorView * _Nonnull)editor shouldInteractWith:(NSURL * _Nonnull)url SWIFT_WARN_UNUSED_RESULT;
/// Called when custom actions are called by callbacks in the JS
/// By default, this method is not used unless called by some custom JS that you add
- (void)richEditor:(RichEditorView * _Nonnull)editor handle:(NSString * _Nonnull)action;
@end

@protocol RichEditorToolbarDelegate;
@class UIColor;

/// RichEditorToolbar is UIView that contains the toolbar for actions that can be performed on a RichEditorView
SWIFT_CLASS("_TtC14RichEditorView17RichEditorToolbar")
@interface RichEditorToolbar : UIView
/// The delegate to receive events that cannot be automatically completed
@property (nonatomic, weak) id <RichEditorToolbarDelegate> _Nullable delegate;
/// A reference to the RichEditorView that it should be performing actions on
@property (nonatomic, weak) RichEditorView * _Nullable editor;
/// The tint color to apply to the toolbar background.
@property (nonatomic, strong) UIColor * _Nullable barTintColor;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


/// RichEditorToolbarDelegate is a protocol for the RichEditorToolbar.
/// Used to receive actions that need extra work to perform (eg. display some UI)
SWIFT_PROTOCOL("_TtP14RichEditorView25RichEditorToolbarDelegate_")
@protocol RichEditorToolbarDelegate
@optional
/// Called when the Text Color toolbar item is pressed.
- (void)richEditorToolbarChangeTextColor:(RichEditorToolbar * _Nonnull)toolbar;
/// Called when the Background Color toolbar item is pressed.
- (void)richEditorToolbarChangeBackgroundColor:(RichEditorToolbar * _Nonnull)toolbar;
/// Called when the Insert Image toolbar item is pressed.
- (void)richEditorToolbarInsertImage:(RichEditorToolbar * _Nonnull)toolbar;
/// Called when the Insert Link toolbar item is pressed.
- (void)richEditorToolbarInsertLink:(RichEditorToolbar * _Nonnull)toolbar;
@end

@class UIWebView;
@class UIScrollView;
@class UIGestureRecognizer;

/// RichEditorView is a UIView that displays richly styled text, and allows it to be edited in a WYSIWYG fashion.
SWIFT_CLASS("_TtC14RichEditorView14RichEditorView")
@interface RichEditorView : UIView <UIGestureRecognizerDelegate, UIScrollViewDelegate, UIWebViewDelegate>
/// The delegate that will receive callbacks when certain actions are completed.
@property (nonatomic, weak) id <RichEditorDelegate> _Nullable delegate;
/// Input accessory view to display over they keyboard.
/// Defaults to nil
@property (nonatomic, strong) UIView * _Nullable inputAccessoryView;
/// The internal UIWebView that is used to display the text.
@property (nonatomic, readonly, strong) UIWebView * _Nonnull webView;
/// Whether or not scroll is enabled on the view.
@property (nonatomic) BOOL isScrollEnabled;
/// Whether or not to allow user input in the view.
@property (nonatomic) BOOL isEditingEnabled;
/// The content HTML of the text being displayed.
/// Is continually updated as the text is being edited.
@property (nonatomic, readonly, copy) NSString * _Nonnull contentHTML;
/// The internal height of the text being displayed.
/// Is continually being updated as the text is edited.
@property (nonatomic, readonly) NSInteger editorHeight;
/// The line height of the editor. Defaults to 28.
@property (nonatomic, readonly) NSInteger lineHeight;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
/// The HTML that is currently loaded in the editor view, if it is loaded. If it has not been loaded yet, it is the
/// HTML that will be loaded into the editor view once it finishes initializing.
@property (nonatomic, copy) NSString * _Nonnull html;
/// Text representation of the data that has been input into the editor view, if it has been loaded.
@property (nonatomic, readonly, copy) NSString * _Nonnull text;
/// The placeholder text that should be shown when there is no user input.
@property (nonatomic, copy) NSString * _Nonnull placeholder;
/// The href of the current selection, if the current selection’s parent is an anchor tag.
/// Will be nil if there is no href, or it is an empty string.
@property (nonatomic, readonly, copy) NSString * _Nullable selectedHref;
/// Whether or not the selection has a type specifically of “Range”.
@property (nonatomic, readonly) BOOL hasRangeSelection;
/// Whether or not the selection has a type specifically of “Range” or “Caret”.
@property (nonatomic, readonly) BOOL hasRangeOrCaretSelection;
- (void)removeFormat;
- (void)setFontSize:(NSInteger)size;
- (void)setEditorBackgroundColor:(UIColor * _Nonnull)color;
- (void)undo;
- (void)redo;
- (void)bold;
- (void)italic;
- (void)subscriptText;
- (void)superscript;
- (void)strikethrough;
- (void)underline;
- (void)setTextColor:(UIColor * _Nonnull)color;
- (void)setEditorFontColor:(UIColor * _Nonnull)color;
- (void)setTextBackgroundColor:(UIColor * _Nonnull)color;
- (void)header:(NSInteger)h;
- (void)indent;
- (void)outdent;
- (void)orderedList;
- (void)unorderedList;
- (void)blockquote;
- (void)alignLeft;
- (void)alignCenter;
- (void)alignRight;
- (void)insertImage:(NSString * _Nonnull)url alt:(NSString * _Nonnull)alt;
- (void)insertLink:(NSString * _Nonnull)href title:(NSString * _Nonnull)title;
- (void)focus;
- (void)focusAt:(CGPoint)at;
- (void)blur;
/// Runs some JavaScript on the UIWebView and returns the result
/// If there is no result, returns an empty string
/// \param js The JavaScript string to be run
///
///
/// returns:
/// The result of the JavaScript that was run
- (NSString * _Nonnull)runJS:(NSString * _Nonnull)js;
- (void)scrollViewDidScroll:(UIScrollView * _Nonnull)scrollView;
- (BOOL)webView:(UIWebView * _Nonnull)webView shouldStartLoadWithRequest:(NSURLRequest * _Nonnull)request navigationType:(UIWebViewNavigationType)navigationType SWIFT_WARN_UNUSED_RESULT;
/// Delegate method for our UITapGestureDelegate.
/// Since the internal web view also has gesture recognizers, we have to make sure that we actually receive our taps.
- (BOOL)gestureRecognizer:(UIGestureRecognizer * _Nonnull)gestureRecognizer shouldRecognizeSimultaneouslyWithGestureRecognizer:(UIGestureRecognizer * _Nonnull)otherGestureRecognizer SWIFT_WARN_UNUSED_RESULT;
- (BOOL)becomeFirstResponder SWIFT_WARN_UNUSED_RESULT;
- (BOOL)resignFirstResponder SWIFT_WARN_UNUSED_RESULT;
@end





#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop

#endif
