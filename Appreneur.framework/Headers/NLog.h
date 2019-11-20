//
//  NLog.h
//
//  Copyright (c) 2013 NXST Inc. All rights reserved.
//
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NForm.h"

#define TRACK_FORM              @"page"
#define TRACK_FORM_RESUME       @"page.resume"
#define TRACK_FORM_PAUSE        @"page.pause"
#define TRACK_FORM_DESTROY      @"page.destroy"
#define TRACK_EVENT	            @"action"
#define TRACK_ERROR             @"error"
#define TRACK_UNCAUGHTED        @"error.uncaught"
#define TRACK_AD_CLICK          @"ad.click"
#define TRACK_AD_IMPRESSION     @"ad.impression"
#define TRACK_SIGNIN            @"signin"
#define TRACK_SIGNOUT           @"signout"
#define TRACK_SUBSCRIBE         @"subscribe"
#define TRACK_UNSUBSCRIBE       @"unsubscribe"
#define TRACK_PURCHASE          @"purchase"
#define TRACK_PAYMENT           @"payment"
#define TRACK_USER              @"user"
#define TRACK_APNs              @"push.token"
#define TRACK_REMOTE_MESSAGE    @"push.message"
#define TRACK_REFERRER_PACKAGE  @"referrer.package"

#define GENDER_MALE  @"M"
#define GENDER_FEMALE  @"F"
#define GENDER_OTHER  @"O"

// reverved 
#define AD_TYPE_BANNER  @"B"
#define AD_TYPE_INTERSTITIAL  @"I"
#define AD_TYPE_VIDEO  @"V"
#define AD_TYPE_NATIVE  @"N"


typedef NS_ENUM(NSInteger, Gender) {
    UNKNOWN,
    MALE,
    FEMALE,
    OTHER
};


@interface NLog : NSObject {
    
}

@property (strong, atomic) NSString             *sessionId;
@property                  long                 requestSeq;
@property                  long                 ts;
@property (strong, atomic) NSString             *userId;
@property (strong, atomic) NSString             *appVer;
@property                  double               latitude;
@property                  double               longitude;
@property                  BOOL                 needFlush;
@property                  BOOL                 immediately;

- (NLog *) init: (NSString *)type;

@end


//----------------

@interface NBuilder : NSObject {
    
}

- (NBuilder *) init: (NSString *)type withSubmitHandler: (void (^)(NLog *, NSError *)) handler;

- (NBuilder *) sessionTime: (long) seconds;

- (NBuilder *) form: (NForm *) form;

- (NBuilder *) formInit: (NForm *) form;

- (NBuilder *) formPause: (NForm *) form;

- (NBuilder *) formResume: (NForm *) form;

- (NBuilder *) formClose: (NForm *) form;

- (NBuilder *) error: (id) error;

- (NBuilder *) exception: (id) exception;

- (NBuilder *) event: (NSString *) eventId withForm: (NForm *) form;

- (NBuilder *) purchase: (NSString *) name count:(NSInteger) count amount:(double) amount currency:(NSString*) currency withForm: (NForm *) form;

- (NBuilder *) payment: (NSString *) name count:(NSInteger) count amount:(double) amount currency:(NSString*) currency withForm: (NForm *) form;

- (NBuilder *) params: (NSDictionary *) params;

- (NBuilder *) param: (NSString *) key value: (id) value;

- (NBuilder *) apns: (NSData *) token;

- (NBuilder *) account: (NSString *) userId name: (NSString *) userName photoUrl: (NSString *) photoUrl gender: (NSString *) gender yearOfBirth: (NSInteger) yearOfBirth;

- (NBuilder *) pushToken: (NSString *) pushToken;

- (BOOL) submit: (NSError **) error;

@end

