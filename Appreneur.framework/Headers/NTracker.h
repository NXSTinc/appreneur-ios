//
//  NTracker.h
//
//  Copyright (c) 2013 NXST Inc. All rights reserved.
//
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import "NLog.h"


/**
 *  NTracker
 *
 *  @version 1.6
 *  @since 1.0
 */
@interface NTracker : NSObject {
}

@property (strong, atomic, nonnull) id session;
@property (nullable) id formLifecycleTracker;

/**
 *  Returns the instance object associated with the current NTracker singleton class.
 *
 *  @version 1.0
 *  @since 1.0
 *  @return Singleton instance
 */
+ (nonnull NTracker *) instance;

/**
 *  Returns the instance object associated with the current NTracker singleton class.
 *
 *  @version 1.0
 *  @since 1.0
 *
 *  @param context UIApplication
 *  @param launchOptions NSDictionary
 *  @return Singleton instance
 */
+ (nonnull id) init: (nonnull UIApplication *) context withLaunchOptions: (nullable NSDictionary *)launchOptions;

+ (void) verbose: (BOOL) on;
+ (BOOL) isConfigurationEnabled:(nullable NSString *) key;

- (nonnull NBuilder *) track:(nonnull NSString *) type;
- (nonnull NBuilder *) track:(nonnull NSString *) type withEnabledKey:(nullable NSString *) key;

- (BOOL) checkTrackerSelfPushMessage:(nonnull NSDictionary *) message;
- (void) handleInAppMessageNofiticationMessage: (NSDictionary *_Nonnull) message withContentHandler:(void (^_Nonnull)(UNNotificationContent * _Nonnull contentToDeliver))contentHandler;
- (void) registerPushToken:(nonnull NSData *) token;
- (void) keepAlive;

- (void) latitude:(double) latitude longitude:(double) longitude;

//--


@end
