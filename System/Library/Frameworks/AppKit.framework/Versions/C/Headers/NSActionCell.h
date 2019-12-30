/*
        NSActionCell.h
	Application Kit
	Copyright (c) 1994-2003, Apple Computer, Inc.
	All rights reserved.
*/

#import <AppKit/NSCell.h>

@interface NSActionCell : NSCell
{
    /*All instance variables are private*/
    int	_tag;        
    id	_target;     
    SEL	_action;     
    id	_controlView;      
}

- (NSView *)controlView;
- (void)setFont:(NSFont *)fontObj;
- (void)setAlignment:(NSTextAlignment)mode;
- (void)setBordered:(BOOL)flag;
- (void)setBezeled:(BOOL)flag;
- (void)setEnabled:(BOOL)flag;
- (void)setFloatingPointFormat:(BOOL)autoRange left:(unsigned int)leftDigits right:(unsigned int)rightDigits;
- (void)setImage:(NSImage *)image;
- (id)target;
- (void)setTarget:(id)anObject;
- (SEL)action;
- (void)setAction:(SEL)aSelector;
- (int)tag;
- (void)setTag:(int)anInt;
- (NSString *)stringValue;
- (int)intValue;
- (float)floatValue;
- (double)doubleValue;
- (void)setObjectValue:(id<NSCopying>)obj;

@end
