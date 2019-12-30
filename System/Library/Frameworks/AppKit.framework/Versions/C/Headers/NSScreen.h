/*
	NSScreen.h
	Application Kit
	Copyright (c) 1994-2003, Apple Computer, Inc.
	All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSGeometry.h>
#import <AppKit/NSGraphics.h>

@class NSArray;

typedef struct NSScreenAuxiliary NSScreenAuxiliaryOpaque;

@interface NSScreen : NSObject {
/*All instance variables are private*/
@private
    NSRect _frame;
    NSWindowDepth _depth;
    int _screenNumber;
    NSScreenAuxiliaryOpaque *_auxiliaryStorage;
}

+ (NSArray *)screens;		/* All screens; first one is "zero" screen */
+ (NSScreen *)mainScreen;	/* Screen with key window */
+ (NSScreen *)deepestScreen;

- (NSWindowDepth)depth;
- (NSRect)frame;
- (NSRect)visibleFrame;
- (NSDictionary *)deviceDescription;

- (const NSWindowDepth *)supportedWindowDepths; /* 0 terminated */

@end

