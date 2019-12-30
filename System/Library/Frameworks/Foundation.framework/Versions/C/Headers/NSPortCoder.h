/*	NSPortCoder.h
	Copyright 1994-2002, Apple, Inc. All rights reserved.
*/

#import <Foundation/NSCoder.h>

@class NSConnection, NSPort, NSArray;

@interface NSPortCoder : NSCoder

- (BOOL)isBycopy;
- (BOOL)isByref;
- (NSConnection *)connection;
- (void)encodePortObject:(NSPort *)aport;
- (NSPort *)decodePortObject;

// Transport
+ portCoderWithReceivePort:(NSPort *)rcvPort sendPort:(NSPort *)sndPort components:(NSArray *)comps;
- (id)initWithReceivePort:(NSPort *)rcvPort sendPort:(NSPort *)sndPort components:(NSArray *)comps;
- (void)dispatch;

@end

@interface NSObject (NSDistributedObjects)

- (Class)classForPortCoder;

- (id)replacementObjectForPortCoder:(NSPortCoder *)coder;

@end
