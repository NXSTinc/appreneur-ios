#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface NWebviewTracker : NSObject {
}

- (id) init;
- (id) initWithViewController:(UIViewController *)viewController;

//--
- (void) track:(id) webView;

@end
