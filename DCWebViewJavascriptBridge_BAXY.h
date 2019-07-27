//
//  WebViewJavascriptBridge.h
//  ExampleApp-iOS
//
//  Created by Marcus Westin on 6/14/13.
//  Copyright (c) 2013 Marcus Westin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DCWebViewJavascriptBridgeBase.h"

#if (__MAC_OS_X_VERSION_MAX_ALLOWED > __MAC_10_9 || __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_7_1)
#define DCsupportsWKWebView
#endif

#if defined DCsupportsWKWebView
#import <WebKit/WebKit.h>
#endif

#if defined __MAC_OS_X_VERSION_MAX_ALLOWED
    #define DCWVJB_PLATFORM_OSX
    #define DCWVJB_WEBVIEW_TYPE WebView
    #define DCWVJB_WEBVIEW_DELEGATE_TYPE NSObject<WebViewJavascriptBridgeBaseDelegate>
    #define DCWVJB_WEBVIEW_DELEGATE_INTERFACE NSObject<DCWebViewJavascriptBridgeBaseDelegate, WebPolicyDelegate>
#elif defined __IPHONE_OS_VERSION_MAX_ALLOWED
    #import <UIKit/UIWebView.h>
    #define WVJB_PLATFORM_IOS
    #define DCWVJB_WEBVIEW_TYPE UIWebView
    #define DCWVJB_WEBVIEW_DELEGATE_TYPE NSObject<UIWebViewDelegate>
    #define DCWVJB_WEBVIEW_DELEGATE_INTERFACE NSObject<UIWebViewDelegate, DCWebViewJavascriptBridgeBaseDelegate>
#endif

@interface DCWebViewJavascriptBridge_BAXY : DCWVJB_WEBVIEW_DELEGATE_INTERFACE


+ (instancetype)bridgeForWebView:(id)webView;
+ (instancetype)bridge:(id)webView;

+ (void)enableLogging;
+ (void)setLogMaxLength:(int)length;

- (void)registerHandler:(NSString*)handlerName handler:(DCWVJBHandler)handler;
- (void)removeHandler:(NSString*)handlerName;
- (void)callHandler:(NSString*)handlerName;
- (void)callHandler:(NSString*)handlerName data:(id)data;
- (void)callHandler:(NSString*)handlerName data:(id)data responseCallback:(DCWVJBResponseCallback)responseCallback;
- (void)setWebViewDelegate:(id)webViewDelegate;
- (void)disableJavscriptAlertBoxSafetyTimeout;

@end
