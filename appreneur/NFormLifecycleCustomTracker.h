#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NFormLifecycleTracker.h"

@interface NFormLifecycleCustomTracker : NFormLifecycleTracker {
}

@property (weak, atomic) id current;

//--

+ (NFormLifecycleCustomTracker *) instance;
+ (NFormLifecycleCustomTracker *) create: (BOOL) recreate;

- (void) pauseAll;

@end
