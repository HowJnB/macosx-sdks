/*
        NSSound.h
	Application Kit
	Copyright (c) 1997-2001, Apple Computer, Inc.
	All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSBundle.h>
#import <AppKit/AppKitDefines.h>

@class NSData, NSURL, NSPasteboard;

APPKIT_EXTERN NSString * const NSSoundPboardType;

@interface NSSound : NSObject <NSCopying, NSCoding> {
@private
    id _delegate;
    NSString *_name;
    NSURL *_url;
    unsigned int _flags;
    NSData *_data0;
    NSData *_data1;
    void *_channel;
    void *_buffer;
    void *_reserved1;
}

+ (id)soundNamed:(NSString *)name;
    /* If this finds & creates the sound, only name is saved when archived */

- (id)initWithContentsOfURL:(NSURL *)url byReference:(BOOL)byRef;
    /* When archived, byref ? saves url : saves contents */

- (id)initWithContentsOfFile:(NSString *)path byReference:(BOOL)byRef;

- (id)initWithData:(NSData *)data;
    /* Whether the data comes in from disk, or via this method, NSSound expects
     * it to have a proper magic number, sound header, and data, for the formats
     * it understands, currently: AIFF, WAV, [NeXT] SND. */

- (BOOL)setName:(NSString *)string;
- (NSString *)name;

// Pasteboard support
+ (BOOL)canInitWithPasteboard:(NSPasteboard *)pasteboard;
+ (NSArray *)soundUnfilteredFileTypes;
+ (NSArray *)soundUnfilteredPasteboardTypes;
- (id)initWithPasteboard:(NSPasteboard *)pasteboard;
- (void)writeToPasteboard:(NSPasteboard *)pasteboard;

// Sound operations
- (BOOL)play;		/* sound is played asynchronously */
- (BOOL)pause;		/* returns NO if sound not paused */
- (BOOL)resume;		/* returns NO if sound not resumed */
- (BOOL)stop;
- (BOOL)isPlaying;

- (id)delegate;
- (void)setDelegate:(id)aDelegate;

@end

@interface NSObject (NSSoundDelegateMethods)

- (void)sound:(NSSound *)sound didFinishPlaying:(BOOL)aBool;

@end

@interface NSBundle (NSBundleSoundExtensions)

- (NSString *)pathForSoundResource:(NSString *)name;
    /* May return nil if no file found */

@end

