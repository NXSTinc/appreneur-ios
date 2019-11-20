#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NForm.h"

#define KEEPALIVE_INTERVAL 3600.0 // 1 hour (UNIT : seconds)
#define TIMER_INTERVAL 5.0


@interface NSession : NSObject {
    
}

@property (weak, atomic) id tracker;
@property (weak, atomic) id context;
@property (strong, atomic) NSString *sessionId;
@property (readonly, atomic) BOOL isStarted;
@property (readonly, atomic) NSInteger pageDepth;
@property (weak, atomic) NForm *currentForm;

//--
- (id) init:(id) tracker;

- (void) start:(NSInteger) timeInterval;
- (void) stop;
- (void) resume;
- (void) pause;
- (long) elapsed;

@end
