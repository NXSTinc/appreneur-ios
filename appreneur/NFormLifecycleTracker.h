#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NFormLifecycleTracker : NSObject {
}

@property (strong, atomic) id context;
@property BOOL autoTrack;

//--

- (UINavigationController *) navigationController;
- (void) viewControllerChange: (NSNotification *) notification;
- (void) onActivityCreated: (UIViewController *) view;
- (void) onActivityResumed: (UIViewController *) view;
- (void) onActivityPaused: (UIViewController *) view;
- (void) onActivityDestroyed: (UIViewController *) view;

- (void) applicationDidBecomeActive: (UIApplication *)application;
- (void) applicationDidEnterBackground: (UIApplication *)application;

@end
