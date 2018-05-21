#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NErrorTracker : NSObject {
}

//--
+ (void) trackError: (nonnull NSString *) eventId withError: (nonnull id) error;

+ (void) trackCrash: (nonnull id) error;

@end
