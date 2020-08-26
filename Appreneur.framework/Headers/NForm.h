#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NForm : NSObject {
    
}

@property (nullable, readonly, strong, atomic) id origin;
@property (nullable, readonly) NSString *name;
@property (nullable, strong, atomic) NForm *prev;
@property (atomic) NSInteger depth;
@property (readonly) BOOL destroyed;
//--

+ (nonnull NForm *) create:(nonnull UIViewController *) viewController;
+ (nonnull NForm *) create:(nonnull NSString *) name withViewController:(nonnull UIViewController *) viewController;
//+ (nonnull NForm *) createWithURI:(nonnull NSString *) uri;
+ (nonnull NForm *) createWithWebURI:(nonnull NSString *) uri withPrev:(nullable NForm *) prev;

+ (nullable NSString *) viewControllerName: (nullable UIViewController *) controller;
+ (nonnull NSMutableDictionary *) forms;
+ (nullable NForm *) find:(nullable id) origin;
//+ (void) clearAfter:(nullable NForm *) form;

- (long) formTime;
- (nonnull NForm *) start;
- (void) resume;
- (void) pause;
- (void) destroy;

- (nullable NSString *) prevName;
- (NSInteger) prevDepth;

// --

- (void) trackEvent: (nonnull NSString *) eventId;
- (void) trackPurchase: (nonnull NSString *) name count: (NSInteger) count amount: (double) usd;
- (void) trackPayment: (nonnull NSString *) name count: (NSInteger) count amount: (double) usd;
- (void) trackAccount: (nullable NSString *) userId name: (nullable NSString *) name photoUrl: (nullable  NSString *) photoUrl gender: (nullable NSString *) gender yearOfBirth: (NSInteger) yearOfBirth;
- (void) trackAccountForFacebookJSONObject: (nonnull id) jsonObject;

- (void) trackError: (nonnull id) error;
- (void) trackAdImpression;
- (void) trackAdClick;
- (nonnull NForm *) dialog: (nonnull NSString *) name;

- (void) setOnDestroyListener: (void (^_Nullable)(NSObject *_Nullable, NSError *_Nullable)) handler;
- (void) setOnPauseListener: (void (^_Nullable)(NSObject *_Nullable, NSError *_Nullable)) handler;

@end


@interface NDialog : NForm {
}

@end
