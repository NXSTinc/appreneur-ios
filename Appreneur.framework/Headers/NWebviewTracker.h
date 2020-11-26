#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface NWebviewTracker : NSObject {
}

- (id) init;

//--
- (void) track:(id) webView;
- (void) track:(id) webView withViewController:(UIViewController *)viewController;

@end
