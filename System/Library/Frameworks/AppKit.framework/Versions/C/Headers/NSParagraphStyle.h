/*
        NSParagraphStyle.h
        Copyright (c) 1994-2003, Apple Computer, Inc.  All rights reserved.

	NSParagraphStyle and NSMutableParagraphStyle hold paragraph style information
	NSTextTab holds information about a single tab stop
*/

#import <Foundation/NSObject.h>
#import <AppKit/NSText.h>

typedef enum _NSTextTabType {
    NSLeftTabStopType = 0,
    NSRightTabStopType,
    NSCenterTabStopType,
    NSDecimalTabStopType
} NSTextTabType;

typedef enum _NSLineBreakMode {		/* What to do with long lines */
    NSLineBreakByWordWrapping = 0,     	/* Wrap at word boundaries, default */
    NSLineBreakByCharWrapping,		/* Wrap at character boundaries */
    NSLineBreakByClipping,		/* Simply clip */
    NSLineBreakByTruncatingHead,	/* Truncate at head of line: "...wxyz" */
    NSLineBreakByTruncatingTail,	/* Truncate at tail of line: "abcd..." */
    NSLineBreakByTruncatingMiddle	/* Truncate middle of line:  "ab...yz" */
} NSLineBreakMode;

typedef enum _NSWritingDirection {
    NSWritingDirectionLeftToRight = 0,	/* Left to right writing direction */
    NSWritingDirectionRightToLeft	/* Right to left writing direction */
} NSWritingDirection;

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED
/* An attribute for NSTextTab options.  The value is NSCharacterSet.  The character set is used to determine the tab column terminating character.  The tab itself and newline characters are implied even if non-existent in the character set.
*/
APPKIT_EXTERN NSString *NSTabColumnTerminatorsAttributeName    AVAILABLE_MAC_OS_X_VERSION_10_3_AND_LATER;
#endif /* MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED */

@interface NSTextTab : NSObject <NSCopying, NSCoding> {
    /*All instance variables are private*/
    struct {
	NSTextAlignment alignment:4;
        unsigned int refCount:24;
        unsigned int unused:4;
    } _flags;
    float _location;
    void *_reserved;
}

#if MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED
/* Initializes a text tab with the text alignment, location, and options.  The text alignment is used to determine the position of text inside the tab column.  These are the mapping from/to NSTextTabType.

To NSTextTabType:
NSLeftTextAlignment -> NSLeftTabStopType
NSRightTextAlignment -> NSRightTabStopType
NSCenterTextAlignment -> NSCenterTabStopType
NSJustifiedTextAlignment -> NSLeftTabStopType
NSNaturalTextAlignment -> NSLeftTabStopType or NSRightTabStopType depending on the user setting
NSRightTextAlignment w/ terminator -> NSDecimalTabStopType

From NSTextTabType:
NSLeftTabStopType -> NSLeftTextAlignment
NSRightTabStopType -> NSRightTextAlignment
NSCenterTabStopType -> NSCenterTextAlignment
NSDecimalTabStopType -> NSRightTextAlignment with the decimal character for the user setting
*/
- (id)initWithTextAlignment:(NSTextAlignment)alignment location:(float)loc options:(NSDictionary *)options;

- (NSTextAlignment)alignment;
- (NSDictionary *)options;
#endif /* MAC_OS_X_VERSION_10_3 <= MAC_OS_X_VERSION_MAX_ALLOWED */
- (id)initWithType:(NSTextTabType)type location:(float)loc;
- (float)location;
- (NSTextTabType)tabStopType;
@end

@interface NSParagraphStyle : NSObject <NSCopying, NSMutableCopying, NSCoding> {
    /*All instance variables are private*/
    float _lineSpacing;
    float _paragraphSpacing;
    float _headIndent;
    float _tailIndent;
    float _firstLineHeadIndent;
    float _minimumLineHeight;
    float _maximumLineHeight;
    NSArray *_tabStops;
    struct {
	NSTextAlignment alignment:4;
        NSLineBreakMode lineBreakMode:4;
        unsigned int tabStopsIsMutable:1;
        unsigned int isNaturalDirection:1;
        unsigned int rightToLeftDirection:1;
        unsigned int fixedMultiple:2;
        unsigned int refCount:19;
    } _flags;
    float _defaultTabInterval;
    void *_extraData;
}

+ (NSParagraphStyle *)defaultParagraphStyle;

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_2
+ (NSWritingDirection)defaultWritingDirectionForLanguage:(NSString *)languageName;  // languageName is in ISO lang region format
#endif

- (float)lineSpacing;		/* "Leading": distance between the bottom of one line fragment and top of next (applied between lines in the same container). Can't be negative. This value is included in the line fragment heights in layout manager. */
- (float)paragraphSpacing; 	/* Distance between the bottom of this paragraph and top of next (or the beginning of its paragraphSpacingBefore, if any). */
- (NSTextAlignment)alignment;

/* The following values are relative to the appropriate margin (depending on the paragraph direction) */
   
- (float)headIndent;		/* Distance from margin to front edge of paragraph */
- (float)tailIndent;		/* Distance from margin to back edge of paragraph; if negative or 0, from other margin */
- (float)firstLineHeadIndent;	/* Distance from margin to edge appropriate for text direction */
- (NSArray *)tabStops;		/* Distance from margin to tab stops */

- (float)minimumLineHeight;	/* Line height is the distance from bottom of descenders to top of ascenders; basically the line fragment height. Does not include lineSpacing (which is added after this computation). */
- (float)maximumLineHeight;	/* 0 implies no maximum. */ 

- (NSLineBreakMode)lineBreakMode;

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_2
- (NSWritingDirection)baseWritingDirection;
#endif

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_3
- (float)lineHeightMultiple;	/* Natural line height is multiplied by this factor (if positive) before being constrained by minimum and maximum line height. */
- (float)paragraphSpacingBefore;/* Distance between the bottom of the previous paragraph (or the end of its paragraphSpacing, if any) and the top of this paragraph. */
- (float)defaultTabInterval;	/* Tabs after the last specified in tabStops are placed at integral multiples of this distance (if positive). */ 
#endif

@end

@interface NSMutableParagraphStyle : NSParagraphStyle

- (void)setLineSpacing:(float)aFloat;
- (void)setParagraphSpacing:(float)aFloat;
- (void)setAlignment:(NSTextAlignment)alignment;
- (void)setFirstLineHeadIndent:(float)aFloat;
- (void)setHeadIndent:(float)aFloat;
- (void)setTailIndent:(float)aFloat;
- (void)setLineBreakMode:(NSLineBreakMode)mode;
- (void)setMinimumLineHeight:(float)aFloat;
- (void)setMaximumLineHeight:(float)aFloat;
- (void)addTabStop:(NSTextTab *)anObject;
- (void)removeTabStop:(NSTextTab *)anObject;
- (void)setTabStops:(NSArray *)array;
- (void)setParagraphStyle:(NSParagraphStyle *)obj;
#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_2
- (void)setBaseWritingDirection:(NSWritingDirection)writingDirection;
#endif
#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_3
- (void)setLineHeightMultiple:(float)aFloat;
- (void)setParagraphSpacingBefore:(float)aFloat;
- (void)setDefaultTabInterval:(float)aFloat;
#endif
@end
