//
//  RCTSpotifyError.h
//  RCTSpotify
//
//  Created by Luis Finke on 2/15/18.
//  Copyright © 2018 Facebook. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RCTSpotifyErrorCode : NSObject

@property (readonly) NSString* name;
@property (readonly) NSString* code;
@property (readonly) NSString* message;
@property (readonly) NSDictionary* reactObject;

-(void)reject:(void(^)(NSString*,NSString*,NSError*))promiseRejector;

@end

#define DECLARE_SPOTIFY_ERROR_CODE(errorName) \
	RCTSpotifyErrorCode* RCTSpotifyErrorCode##errorName();

DECLARE_SPOTIFY_ERROR_CODE(AlreadyInitialized)
DECLARE_SPOTIFY_ERROR_CODE(NotInitialized)
DECLARE_SPOTIFY_ERROR_CODE(NotImplemented)
DECLARE_SPOTIFY_ERROR_CODE(NotLoggedIn)
DECLARE_SPOTIFY_ERROR_CODE(MissingOption)
DECLARE_SPOTIFY_ERROR_CODE(NullParameter)
DECLARE_SPOTIFY_ERROR_CODE(ConflictingCallbacks)
DECLARE_SPOTIFY_ERROR_CODE(BadResponse)
DECLARE_SPOTIFY_ERROR_CODE(PlayerNotReady)
DECLARE_SPOTIFY_ERROR_CODE(SessionExpired)

#undef DECLARE_SPOTIFY_ERROR_CODE



@interface RCTSpotifyError : NSObject

-(id)initWithCode:(NSString*)code message:(NSString*)message;
-(id)initWithCode:(NSString*)code error:(NSError*)error;
-(id)initWithCodeObj:(RCTSpotifyErrorCode*)code;
-(id)initWithCodeObj:(RCTSpotifyErrorCode*)code message:(NSString*)message;
-(id)initWithError:(NSError*)error;

+(instancetype)errorWithCode:(NSString*)code message:(NSString*)message;
+(instancetype)errorWithCode:(NSString*)code error:(NSError*)error;
+(instancetype)errorWithCodeObj:(RCTSpotifyErrorCode*)code;
+(instancetype)errorWithCodeObj:(RCTSpotifyErrorCode*)code message:(NSString*)message;
+(instancetype)errorWithError:(NSError*)error;

-(void)reject:(void(^)(NSString*,NSString*,NSError*))promiseRejector;

@property (readonly) NSString* code;
@property (readonly) NSString* message;
@property (readonly) NSDictionary* reactObject;

@end
