/*
	NSEvent.h
	Application Kit
	Copyright (c) 1994-2001, Apple Computer, Inc.
	All rights reserved.
*/

#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>
#import <Foundation/NSGeometry.h>

@class NSGraphicsContext, NSWindow;

typedef enum _NSEventType {		/* various types of events */
	NSLeftMouseDown		= 1,
	NSLeftMouseUp		= 2,
	NSRightMouseDown	= 3,
	NSRightMouseUp		= 4,
	NSMouseMoved		= 5,
	NSLeftMouseDragged	= 6,
	NSRightMouseDragged	= 7,
	NSMouseEntered		= 8,
	NSMouseExited		= 9,
	NSKeyDown		= 10,
	NSKeyUp			= 11,
	NSFlagsChanged		= 12,
	NSAppKitDefined		= 13,
	NSSystemDefined		= 14,
	NSApplicationDefined	= 15,
	NSPeriodic		= 16,
	NSCursorUpdate		= 17,
        NSScrollWheel		= 22,
        NSOtherMouseDown	= 25,
        NSOtherMouseUp		= 26,
        NSOtherMouseDragged	= 27
} NSEventType;

enum {					/* masks for the types of events */
	NSLeftMouseDownMask		= 1 << NSLeftMouseDown,
	NSLeftMouseUpMask		= 1 << NSLeftMouseUp,
	NSRightMouseDownMask		= 1 << NSRightMouseDown,
	NSRightMouseUpMask		= 1 << NSRightMouseUp,
	NSMouseMovedMask		= 1 << NSMouseMoved,
	NSLeftMouseDraggedMask		= 1 << NSLeftMouseDragged,
	NSRightMouseDraggedMask		= 1 << NSRightMouseDragged,
	NSMouseEnteredMask		= 1 << NSMouseEntered,
	NSMouseExitedMask		= 1 << NSMouseExited,
	NSKeyDownMask			= 1 << NSKeyDown,
	NSKeyUpMask			= 1 << NSKeyUp,
	NSFlagsChangedMask		= 1 << NSFlagsChanged,
	NSAppKitDefinedMask		= 1 << NSAppKitDefined,
	NSSystemDefinedMask		= 1 << NSSystemDefined,
	NSApplicationDefinedMask	= 1 << NSApplicationDefined,
	NSPeriodicMask			= 1 << NSPeriodic,
	NSCursorUpdateMask		= 1 << NSCursorUpdate,
        NSScrollWheelMask		= 1 << NSScrollWheel,
	NSOtherMouseDownMask		= 1 << NSOtherMouseDown,
	NSOtherMouseUpMask		= 1 << NSOtherMouseUp,
	NSOtherMouseDraggedMask		= 1 << NSOtherMouseDragged,
	NSAnyEventMask			= 0xffffffffU
};

static inline unsigned int NSEventMaskFromType(NSEventType type) { return (1 << type); }

/* Device-independent bits found in event modifier flags */
enum {
	NSAlphaShiftKeyMask =		1 << 16,
	NSShiftKeyMask =		1 << 17,
	NSControlKeyMask =		1 << 18,
	NSAlternateKeyMask =		1 << 19,
	NSCommandKeyMask =		1 << 20,
	NSNumericPadKeyMask =		1 << 21,
	NSHelpKeyMask =			1 << 22,
	NSFunctionKeyMask =		1 << 23
};

@interface NSEvent : NSObject <NSCopying, NSCoding> {
    /*All instance variables are private*/
    NSEventType _type;
    NSPoint _location;
    unsigned int _modifierFlags;
    int _WSTimestamp;
    NSTimeInterval _timestamp;
    int _windowNumber;
    NSWindow *_window;
    NSGraphicsContext* _context;
    union {
	struct {
	    int eventNumber;
	    int	clickCount;
	    float pressure;
	} mouse;
	struct {
	    NSString *keys;
	    NSString *unmodKeys;
	    unsigned short keyCode;
	    BOOL isARepeat;
	} key;
	struct {
	    int eventNumber;
	    int	trackingNumber;
	    void *userData;
	} tracking;
        struct {
            float    deltaX;
            float    deltaY;
            float    deltaZ; 
        } scrollWheel;
 	struct {
	    int subtype;
	    int data1;
	    int data2;
	} misc;
    } _data;
    void *_eventRef;
}


/* these messages are valid for all events */
- (NSEventType)type;
- (NSPoint)locationInWindow;
- (unsigned int)modifierFlags;
- (NSTimeInterval)timestamp;
- (NSWindow *)window;
- (int)windowNumber;
- (NSGraphicsContext*)context;

/* these messages are valid for all mouse down/up/drag events */
- (int)clickCount;
- (float)pressure;
- (int)buttonNumber;	// for NSOtherMouse events, but will return valid constants for NSLeftMouse and NSRightMouse
/* these messages are valid for all mouse down/up/drag and enter/exit events */
- (int)eventNumber;

/* these messages are valid for scroll wheel events and mouse move/drag events */
- (float)deltaX;	
- (float)deltaY;	
- (float)deltaZ;	// 0 for most scroll wheel and mouse events

/* these messages are valid for keyup and keydown events */
- (NSString *)characters;
- (NSString *)charactersIgnoringModifiers;
  /* the chars that would have been generated, regardless of modifier keys (except shift) */
- (BOOL)isARepeat;
/* this message is valid for keyup, keydown and flagschanged events */
- (unsigned short)keyCode;		/* device-dependent key number */

/* these messages are valid for enter and exit events */
- (int)trackingNumber;
- (void *)userData;

/* these messages are valid for kit, system, and app-defined events */
- (short)subtype;
- (int)data1;
- (int)data2;

/* used for initial delay and periodic behavior in tracking loops */
+ (void)startPeriodicEventsAfterDelay:(NSTimeInterval)delay withPeriod:(NSTimeInterval)period;
+ (void)stopPeriodicEvents;

/* apps will rarely create these objects */
+ (NSEvent *)mouseEventWithType:(NSEventType)type location:(NSPoint)location modifierFlags:(unsigned int)flags timestamp:(NSTimeInterval)time windowNumber:(int)wNum context:(NSGraphicsContext*)context eventNumber:(int)eNum clickCount:(int)cNum pressure:(float)pressure;
+ (NSEvent *)keyEventWithType:(NSEventType)type location:(NSPoint)location modifierFlags:(unsigned int)flags timestamp:(NSTimeInterval)time windowNumber:(int)wNum context:(NSGraphicsContext*)context characters:(NSString *)keys charactersIgnoringModifiers:(NSString *)ukeys isARepeat:(BOOL)flag keyCode:(unsigned short)code;
+ (NSEvent *)enterExitEventWithType:(NSEventType)type location:(NSPoint)location modifierFlags:(unsigned int)flags timestamp:(NSTimeInterval)time windowNumber:(int)wNum context:(NSGraphicsContext*)context eventNumber:(int)eNum trackingNumber:(int)tNum userData:(void *)data;
+ (NSEvent *)otherEventWithType:(NSEventType)type location:(NSPoint)location modifierFlags:(unsigned int)flags timestamp:(NSTimeInterval)time windowNumber:(int)wNum context:(NSGraphicsContext*)context subtype:(short)subtype data1:(int)d1 data2:(int)d2;

// global mouse coordinates
+ (NSPoint)mouseLocation;

@end


/* Unicodes we reserve for function keys on the keyboard,  OpenStep reserves the range 0xF700-0xF8FF for this purpose.  The availability of various keys will be system dependent. */
enum {
	NSUpArrowFunctionKey		= 0xF700,
	NSDownArrowFunctionKey		= 0xF701,
	NSLeftArrowFunctionKey		= 0xF702,
	NSRightArrowFunctionKey		= 0xF703,
	NSF1FunctionKey			= 0xF704,
	NSF2FunctionKey			= 0xF705,
	NSF3FunctionKey			= 0xF706,
	NSF4FunctionKey			= 0xF707,
	NSF5FunctionKey			= 0xF708,
	NSF6FunctionKey			= 0xF709,
	NSF7FunctionKey			= 0xF70A,
	NSF8FunctionKey			= 0xF70B,
	NSF9FunctionKey			= 0xF70C,
	NSF10FunctionKey		= 0xF70D,
	NSF11FunctionKey		= 0xF70E,
	NSF12FunctionKey		= 0xF70F,
	NSF13FunctionKey		= 0xF710,
	NSF14FunctionKey		= 0xF711,
	NSF15FunctionKey		= 0xF712,
	NSF16FunctionKey		= 0xF713,
	NSF17FunctionKey		= 0xF714,
	NSF18FunctionKey		= 0xF715,
	NSF19FunctionKey		= 0xF716,
	NSF20FunctionKey		= 0xF717,
	NSF21FunctionKey		= 0xF718,
	NSF22FunctionKey		= 0xF719,
	NSF23FunctionKey		= 0xF71A,
	NSF24FunctionKey		= 0xF71B,
	NSF25FunctionKey		= 0xF71C,
	NSF26FunctionKey		= 0xF71D,
	NSF27FunctionKey		= 0xF71E,
	NSF28FunctionKey		= 0xF71F,
	NSF29FunctionKey		= 0xF720,
	NSF30FunctionKey		= 0xF721,
	NSF31FunctionKey		= 0xF722,
	NSF32FunctionKey		= 0xF723,
	NSF33FunctionKey		= 0xF724,
	NSF34FunctionKey		= 0xF725,
	NSF35FunctionKey		= 0xF726,
	NSInsertFunctionKey		= 0xF727,
	NSDeleteFunctionKey		= 0xF728,
	NSHomeFunctionKey		= 0xF729,
	NSBeginFunctionKey		= 0xF72A,
	NSEndFunctionKey		= 0xF72B,
	NSPageUpFunctionKey		= 0xF72C,
	NSPageDownFunctionKey		= 0xF72D,
	NSPrintScreenFunctionKey	= 0xF72E,
	NSScrollLockFunctionKey		= 0xF72F,
	NSPauseFunctionKey		= 0xF730,
	NSSysReqFunctionKey		= 0xF731,
	NSBreakFunctionKey		= 0xF732,
	NSResetFunctionKey		= 0xF733,
	NSStopFunctionKey		= 0xF734,
	NSMenuFunctionKey		= 0xF735,
	NSUserFunctionKey		= 0xF736,
	NSSystemFunctionKey		= 0xF737,
	NSPrintFunctionKey		= 0xF738,
	NSClearLineFunctionKey		= 0xF739,
	NSClearDisplayFunctionKey	= 0xF73A,
	NSInsertLineFunctionKey		= 0xF73B,
	NSDeleteLineFunctionKey		= 0xF73C,
	NSInsertCharFunctionKey		= 0xF73D,
	NSDeleteCharFunctionKey		= 0xF73E,
	NSPrevFunctionKey		= 0xF73F,
	NSNextFunctionKey		= 0xF740,
	NSSelectFunctionKey		= 0xF741,
	NSExecuteFunctionKey		= 0xF742,
	NSUndoFunctionKey		= 0xF743,
	NSRedoFunctionKey		= 0xF744,
	NSFindFunctionKey		= 0xF745,
	NSHelpFunctionKey		= 0xF746,
	NSModeSwitchFunctionKey		= 0xF747
};


enum {		/* event subtypes for NSAppKitDefined events */
    NSWindowExposedEventType		= 0,
    NSApplicationActivatedEventType	= 1,
    NSApplicationDeactivatedEventType	= 2,
    NSWindowMovedEventType 		= 4,
    NSScreenChangedEventType		= 8,
    NSAWTEventType			= 16
};

enum {		/* event subtypes for NSSystemDefined events */
    NSPowerOffEventType			= 1
};
