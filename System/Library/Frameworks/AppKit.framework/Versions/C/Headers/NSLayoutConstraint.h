/*
	NSLayoutConstraint.h
	Application Kit
	Copyright (c) 2009-2018, Apple Inc.
	All rights reserved.
*/

#import <AppKit/NSWindow.h>
#import <AppKit/NSControl.h>
#import <AppKit/NSView.h>
#import <AppKit/NSAnimation.h>
#import <Foundation/NSGeometry.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <AppKit/NSLayoutAnchor.h>



NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NSLayoutRelation) {
    NSLayoutRelationLessThanOrEqual = -1,
    NSLayoutRelationEqual = 0,
    NSLayoutRelationGreaterThanOrEqual = 1,
};

typedef NS_ENUM(NSInteger, NSLayoutAttribute) {
    NSLayoutAttributeLeft = 1,
    NSLayoutAttributeRight,
    NSLayoutAttributeTop,
    NSLayoutAttributeBottom,
    NSLayoutAttributeLeading,
    NSLayoutAttributeTrailing,
    NSLayoutAttributeWidth,
    NSLayoutAttributeHeight,
    NSLayoutAttributeCenterX,
    NSLayoutAttributeCenterY,
    NSLayoutAttributeLastBaseline,
    NSLayoutAttributeBaseline = NSLayoutAttributeLastBaseline,
    NSLayoutAttributeFirstBaseline NS_ENUM_AVAILABLE_MAC(10_11),
    
    NSLayoutAttributeNotAnAttribute = 0
};


typedef NS_OPTIONS(NSUInteger, NSLayoutFormatOptions) {        
    NSLayoutFormatAlignAllLeft = (1 << NSLayoutAttributeLeft),
    NSLayoutFormatAlignAllRight = (1 << NSLayoutAttributeRight),
    NSLayoutFormatAlignAllTop = (1 << NSLayoutAttributeTop),
    NSLayoutFormatAlignAllBottom = (1 << NSLayoutAttributeBottom),
    NSLayoutFormatAlignAllLeading = (1 << NSLayoutAttributeLeading),
    NSLayoutFormatAlignAllTrailing = (1 << NSLayoutAttributeTrailing),
    NSLayoutFormatAlignAllCenterX = (1 << NSLayoutAttributeCenterX),
    NSLayoutFormatAlignAllCenterY = (1 << NSLayoutAttributeCenterY),
    NSLayoutFormatAlignAllBaseline = (1 << NSLayoutAttributeBaseline),
    NSLayoutFormatAlignAllLastBaseline = NSLayoutFormatAlignAllBaseline,
    NSLayoutFormatAlignAllFirstBaseline NS_ENUM_AVAILABLE_MAC(10_11) = (1 << NSLayoutAttributeFirstBaseline),
    
    NSLayoutFormatAlignmentMask = 0xFFFF,
    
    /* choose only one of these three
     */
    NSLayoutFormatDirectionLeadingToTrailing = 0 << 16, // default
    NSLayoutFormatDirectionLeftToRight = 1 << 16,
    NSLayoutFormatDirectionRightToLeft = 2 << 16,  
    
    NSLayoutFormatDirectionMask = 0x3 << 16,  
};

typedef NS_ENUM(NSInteger, NSLayoutConstraintOrientation) {
    NSLayoutConstraintOrientationHorizontal = 0,
    NSLayoutConstraintOrientationVertical = 1
};

/* Where AppKit's use of priority levels interacts with the user's use, we must define the priority levels involved.  Note that most of the time there is no interaction.  The use of priority levels is likely to be local to one sub-area of the window that is under the control of one author.  
 */
typedef float NSLayoutPriority NS_TYPED_EXTENSIBLE_ENUM NS_AVAILABLE_MAC(10_7);

static const NSLayoutPriority NSLayoutPriorityRequired NS_AVAILABLE_MAC(10_7) = 1000; // a required constraint.  Do not exceed this.
static const NSLayoutPriority NSLayoutPriorityDefaultHigh NS_AVAILABLE_MAC(10_7) = 750; // this is the priority level with which a button resists compressing its content.  Note that it is higher than NSLayoutPriorityWindowSizeStayPut.  Thus dragging to resize a window will not make buttons clip.  Rather the window frame is constrained.
static const NSLayoutPriority NSLayoutPriorityDragThatCanResizeWindow NS_AVAILABLE_MAC(10_7) = 510; // This is the appropriate priority level for a drag that may end up resizing the window.  This needn't be a drag whose explicit purpose is to resize the window. The user might be dragging around window contents, and it might be desirable that the window get bigger to accommodate.
static const NSLayoutPriority NSLayoutPriorityWindowSizeStayPut NS_AVAILABLE_MAC(10_7) = 500; // This is the priority level at which the window prefers to stay the same size.  It's generally not appropriate to make a constraint at exactly this priority. You want to be higher or lower.
static const NSLayoutPriority NSLayoutPriorityDragThatCannotResizeWindow NS_AVAILABLE_MAC(10_7) = 490; // This is the priority level at which a split view divider, say, is dragged.  It won't resize the window.
static const NSLayoutPriority NSLayoutPriorityDefaultLow NS_AVAILABLE_MAC(10_7) = 250; // this is the priority level at which a button hugs its contents horizontally.
static const NSLayoutPriority NSLayoutPriorityFittingSizeCompression NS_AVAILABLE_MAC(10_7) = 50; // When you issue -[NSView fittingSize], the smallest size that is large enough for the view's contents is computed.  This is the priority level with which the view wants to be as small as possible in that computation.  It's quite low.  It is generally not appropriate to make a constraint at exactly this priority.  You want to be higher or lower.


NS_CLASS_AVAILABLE(10_7, NA)
@interface NSLayoutConstraint : NSObject <NSAnimatablePropertyContainer>
{
    @private
    id _container APPKIT_IVAR;
    __weak id _firstItem APPKIT_IVAR;
    __weak id _secondItem APPKIT_IVAR;
    CGFloat _constant APPKIT_IVAR;
    CGFloat _loweredConstant APPKIT_IVAR;
    id _markerAndPositiveExtraVar APPKIT_IVAR;
    id _negativeExtraVar APPKIT_IVAR;
#if __OBJC2__
    uint64_t _layoutConstraintFlags APPKIT_IVAR;
    float _coefficient APPKIT_IVAR;
    NSLayoutPriority _priority APPKIT_IVAR;
#else
    float _coefficient APPKIT_IVAR;
    NSLayoutPriority _priority APPKIT_IVAR;
    uint64_t _layoutConstraintFlags APPKIT_IVAR;
    id _flange APPKIT_IVAR;
#endif
}

/* Create an array of constraints using an ASCII art-like visual format string.
 */
+ (NSArray<NSLayoutConstraint *> *)constraintsWithVisualFormat:(NSString *)format options:(NSLayoutFormatOptions)opts metrics:(nullable NSDictionary<NSString *, NSNumber *> *)metrics views:(NSDictionary<NSString *, id> *)views;

/* This macro is a helper for making view dictionaries for +constraintsWithVisualFormat:options:metrics:views:.  
 NSDictionaryOfVariableBindings(v1, v2, v3) is equivalent to [NSDictionary dictionaryWithObjectsAndKeys:v1, @"v1", v2, @"v2", v3, @"v3", nil];
 */
#define NSDictionaryOfVariableBindings(...) _NSDictionaryOfVariableBindings(@"" # __VA_ARGS__, __VA_ARGS__, nil)
APPKIT_EXTERN NSDictionary<NSString *, id> * _NSDictionaryOfVariableBindings(NSString * commaSeparatedKeysString, id firstValue, ...); // not for direct use


/* Create constraints explicitly.  Constraints are of the form "view1.attr1 = view2.attr2 * multiplier + constant" 
 If your equation does not have a second view and attribute, use nil and NSLayoutAttributeNotAnAttribute.
 Use of this method is not recommended. Constraints should be created using anchor objects on views and layout guides.
 */
+ (instancetype)constraintWithItem:(id)view1 attribute:(NSLayoutAttribute)attr1 relatedBy:(NSLayoutRelation)relation toItem:(nullable id)view2 attribute:(NSLayoutAttribute)attr2 multiplier:(CGFloat)multiplier constant:(CGFloat)c;

/* If a constraint's priority level is less than NSLayoutPriorityRequired, then it is optional.  Higher priority constraints are met before lower priority constraints.
 Constraint satisfaction is not all or nothing.  If a constraint 'a == b' is optional, that means we will attempt to minimize 'abs(a-b)'.
 This property may only be modified as part of initial set up or when optional.  After a constraint has been added to a view, an exception will be thrown if the priority is changed from/to NSLayoutPriorityRequired.
 */
@property NSLayoutPriority priority;

/* When a view is archived, it archives some but not all constraints in its -constraints array.  The value of shouldBeArchived informs NSView if a particular constraint should be archived by NSView.
 If a constraint is created at runtime in response to the state of the object, it isn't appropriate to archive the constraint - rather you archive the state that gives rise to the constraint.  Since the majority of constraints that should be archived are created in Interface Builder (which is smart enough to set this prop to YES), the default value for this property is NO.
 */
@property BOOL shouldBeArchived;

/* accessors
 firstItem.firstAttribute {==,<=,>=} secondItem.secondAttribute * multiplier + constant
 Access to these properties is not recommended. Use the `firstAnchor` and `secondAnchor` properties instead.
 */
@property (readonly, nullable, weak) id firstItem;
@property (readonly) NSLayoutAttribute firstAttribute;
@property (readonly, nullable, weak) id secondItem;
@property (readonly) NSLayoutAttribute secondAttribute;

/* accessors
 firstAnchor{==,<=,>=} secondAnchor * multiplier + constant
 */
@property (readonly, copy) NSLayoutAnchor *firstAnchor NS_AVAILABLE(10_12, 10_0);
@property (readonly, copy, nullable) NSLayoutAnchor *secondAnchor NS_AVAILABLE(10_12, 10_0);
@property (readonly) NSLayoutRelation relation;
@property (readonly) CGFloat multiplier;

/* Unlike the other properties, the constant may be modified after constraint creation.  Setting the constant on an existing constraint performs much better than removing the constraint and adding a new one that's just like the old but for having a new constant.
 */
@property CGFloat constant;

/* The receiver may be activated or deactivated by manipulating this property.  Only active constraints affect the calculated layout.  Attempting to activate a constraint whose items have no common ancestor will cause an exception to be thrown.  Defaults to NO for newly created constraints. */
@property (getter=isActive) BOOL active NS_AVAILABLE(10_10, 8_0);

/* Convenience method that activates each constraint in the contained array, in the same manner as setting active=YES. This is often more efficient than activating each constraint individually. */
+ (void)activateConstraints:(NSArray<NSLayoutConstraint *> *)constraints NS_AVAILABLE(10_10, 8_0);

/* Convenience method that deactivates each constraint in the contained array, in the same manner as setting active=NO. This is often more efficient than deactivating each constraint individually. */
+ (void)deactivateConstraints:(NSArray<NSLayoutConstraint *> *)constraints NS_AVAILABLE(10_10, 8_0);

@end

@interface NSLayoutConstraint (NSIdentifier)

/* Name a constraint by setting its identifier. The identifier is output in the constraint's description. Identifiers starting with NS are reserved by the system.
 */
@property (nullable, copy) NSString * identifier;

@end





#pragma mark Installing Constraints

/* A constraint is typically installed on the closest common ancestor of the views involved in the constraint. 
 It is required that a constraint be installed on _a_ common ancestor of every view involved.  The numbers in a constraint are interpreted in the coordinate system of the view it is installed on.  A view is considered to be an ancestor of itself (as with other NSView API).
 */
@interface NSView (NSConstraintBasedLayoutInstallingConstraints)

/* 
 These properties aid concise creation of simple constraints.  Views can be constrained using simple code like the following:
 [view.topAnchor constraintEqualToAnchor:otherView.bottomAnchor constant:10].active=YES;
 
 See NSLayoutAnchor.h for more details.
 */
@property (readonly, strong) NSLayoutXAxisAnchor *leadingAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutXAxisAnchor *trailingAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutXAxisAnchor *leftAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutXAxisAnchor *rightAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutYAxisAnchor *topAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutYAxisAnchor *bottomAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutDimension *widthAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutDimension *heightAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutXAxisAnchor *centerXAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutYAxisAnchor *centerYAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutYAxisAnchor *firstBaselineAnchor NS_AVAILABLE(10_11, 9_0);
@property (readonly, strong) NSLayoutYAxisAnchor *lastBaselineAnchor NS_AVAILABLE(10_11, 9_0);

@property (readonly, copy) NSArray<NSLayoutConstraint *> *constraints NS_AVAILABLE_MAC(10_7);	// This property is deprecated and should be avoided.  Instead, create IB outlets or otherwise maintain references to constraints you need to reference directly.

- (void)addConstraint:(NSLayoutConstraint *)constraint NS_AVAILABLE_MAC(10_7);	// This method is deprecated and should be avoided.  Instead, set NSLayoutConstraint's active property to YES.
- (void)addConstraints:(NSArray<NSLayoutConstraint *> *)constraints NS_AVAILABLE_MAC(10_7);	// This method is deprecated and should be avoided.  Instead use +[NSLayoutConstraint activateConstraints:].
- (void)removeConstraint:(NSLayoutConstraint *)constraint NS_AVAILABLE_MAC(10_7);	// This method is deprecated and should be avoided.  Instead set NSLayoutConstraint's active property to NO.
- (void)removeConstraints:(NSArray<NSLayoutConstraint *> *)constraints NS_AVAILABLE_MAC(10_7);	// This method is deprecated and should be avoided.  Instead use +[NSLayoutConstraint deactivateConstraints:].

@end

#pragma mark Core Layout Methods

/* To render a window, the following passes will occur, if necessary.  
 
 update constraints
 layout
 display
 
 Please see the conceptual documentation for a discussion of these methods.
 */

@interface NSWindow (NSConstraintBasedLayoutCoreMethods)
- (void)updateConstraintsIfNeeded NS_AVAILABLE_MAC(10_7);
- (void)layoutIfNeeded NS_AVAILABLE_MAC(10_7);
@end

@interface NSView (NSConstraintBasedLayoutCoreMethods) 
- (void)updateConstraintsForSubtreeIfNeeded NS_AVAILABLE_MAC(10_7);
- (void)updateConstraints NS_AVAILABLE_MAC(10_7) NS_REQUIRES_SUPER;
@property BOOL needsUpdateConstraints NS_AVAILABLE_MAC(10_7);

- (void)layoutSubtreeIfNeeded NS_AVAILABLE_MAC(10_7);
- (void)layout NS_AVAILABLE_MAC(10_7);
@property BOOL needsLayout NS_AVAILABLE_MAC(10_7);
@end

#pragma mark Compatibility and Adoption

@interface NSView (NSConstraintBasedCompatibility) 

/* by default, the autoresizing mask on a view gives rise to constraints that fully determine the view's position.  To do anything interesting with constraints, you need to turn that off. IB will turn it off.
 */
@property BOOL translatesAutoresizingMaskIntoConstraints NS_AVAILABLE_MAC(10_7);

/* constraint based layout engages lazily when someone tries to use it.  If you do all of your constraint set up in -updateConstraints, you might never even receive updateConstraints if no one makes a constraint.  To fix this chicken and egg problem, override this method to return YES if your view needs the window to use constraint based layout.  
 */
@property (class, readonly) BOOL requiresConstraintBasedLayout NS_AVAILABLE_MAC(10_7);

@end

#pragma mark Separation of Concerns

@interface NSView (NSConstraintBasedLayoutLayering)

/* Constraints do not actually relate the frames of the views, rather they relate the "alignment rects" of views.  This is the same as the frame unless overridden by a subclass of NSView.  Alignment rects are the same as the "layout rects" shown in Interface Builder 3.  Typically the alignment rect of a view is what the end user would think of as the bounding rect around a control, omitting ornamentation like shadows and engraving lines.  The edges of the alignment rect are what is interesting to align, not the shadows and such.  
 */

/* These two methods should be inverses of each other.  AppKit will call both as part of layout computation.
 They may be overridden to provide arbitrary transforms between frame and alignment rect, though the two methods must be inverses of each other.
 However, the default implementation uses -alignmentRectInsets, so just override that if it's applicable.  It's easier to get right. If you do override these be sure to account for the top of your frame being either minY or maxY depending on the superview's flippedness.
 A view that displayed an image with some ornament would typically override these, because the ornamental part of an image would scale up with the size of the frame.  
 Set the NSUserDefault NSShowAlignmentRects to YES to see alignment rects drawn.
 */
- (NSRect)alignmentRectForFrame:(NSRect)frame NS_AVAILABLE_MAC(10_7);
- (NSRect)frameForAlignmentRect:(NSRect)alignmentRect NS_AVAILABLE_MAC(10_7);

/* override this if the alignment rect is obtained from the frame by insetting each edge by a fixed amount.  This is only called by alignmentRectForFrame: and frameForAlignmentRect:.
 */
@property (readonly) NSEdgeInsets alignmentRectInsets NS_AVAILABLE_MAC(10_7);

/* override this to provide the distance between NSLayoutAttributeTop and NSLayoutAttributeFirstBaseline.  NSView's implementation returns zero.
 */
@property (readonly) CGFloat firstBaselineOffsetFromTop NS_AVAILABLE_MAC(10_11);

/* override this to provide the distance between NSLayoutAttributeBottom and NSLayoutAttributeLastBaseline (or NSLayoutAttributeBaseline).  NSView's implementation returns zero.
 */
@property (readonly) CGFloat lastBaselineOffsetFromBottom NS_AVAILABLE_MAC(10_11);

@property (readonly) CGFloat baselineOffsetFromBottom NS_AVAILABLE_MAC(10_7); // Deprecated. Override lastBaselineOffsetFromBottom instead.


/* Override this method to tell the layout system that there is something it doesn't natively understand in this view, and this is how large it intrinsically is.  A typical example would be a single line text field.  The layout system does not understand text - it must just be told that there's something in the view, and that that something will take a certain amount of space if not clipped.  
 
 In response, AppKit will set up constraints that specify (1) that the opaque content should not be compressed or clipped, (2) that the view prefers to hug tightly to its content. 
 
 A user of a view may need to specify the priority of these constraints.  For example, by default, a push button 
 -strongly wants to hug its content in the vertical direction (buttons really ought to be their natural height)
 -weakly hugs its content horizontally (extra side padding between the title and the edge of the bezel is acceptable)
 -strongly resists compressing or clipping content in both directions. 
 
 However, in the case of the scope bar in Finder, the buttons only weakly resist compressing content in the horizontal direction.  You can make the window small enough that buttons start truncating their contents.  Thus, Finder wants to lower the priority with which these buttons resist compressing content.
 
 The default 'strong' and 'weak' priorities referred to above are NSLayoutPriorityDefaultHigh and NSLayoutPriorityDefaultLow.  
 
 Note that not all views have an intrinsicContentSize.  A horizontal slider has an intrinsic height, but no intrinsic width - the slider artwork has no intrinsic best width.  A horizontal NSSlider returns (NSViewNoIntrinsicMetric, <slider height>) for intrinsicContentSize.  An NSBox returns (NSViewNoIntrinsicMetric, NSViewNoIntrinsicMetric).  The _intrinsic_ content size is concerned only with data that is in the view itself, not in other views.
 */
APPKIT_EXTERN const CGFloat NSViewNoInstrinsicMetric NS_DEPRECATED_WITH_REPLACEMENT_MAC("NSViewNoIntrinsicMetric", 10_7, 10_14);
APPKIT_EXTERN const CGFloat NSViewNoIntrinsicMetric NS_AVAILABLE_MAC(10_11); // -1

@property (readonly) NSSize intrinsicContentSize NS_AVAILABLE_MAC(10_7);
- (void)invalidateIntrinsicContentSize NS_AVAILABLE_MAC(10_7); // call this when something changes that affects the intrinsicContentSize.  Otherwise AppKit won't notice that it changed.  

- (NSLayoutPriority)contentHuggingPriorityForOrientation:(NSLayoutConstraintOrientation)orientation NS_AVAILABLE_MAC(10_7);
- (void)setContentHuggingPriority:(NSLayoutPriority)priority forOrientation:(NSLayoutConstraintOrientation)orientation NS_AVAILABLE_MAC(10_7);

- (NSLayoutPriority)contentCompressionResistancePriorityForOrientation:(NSLayoutConstraintOrientation)orientation NS_AVAILABLE_MAC(10_7);
- (void)setContentCompressionResistancePriority:(NSLayoutPriority)priority forOrientation:(NSLayoutConstraintOrientation)orientation NS_AVAILABLE_MAC(10_7);
@end

@interface NSControl (NSConstraintBasedLayoutLayering)
/* should be called by a cell on its -controlView
 */
- (void)invalidateIntrinsicContentSizeForCell:(NSCell *)cell NS_AVAILABLE_MAC(10_7);
@end

#pragma mark Window anchoring

@interface NSWindow (NSConstraintBasedLayoutAnchoring)
/* If changes in the interior content (and thus, constraints) of a window force the window to get smaller or larger, what part of the window stays motionless?  By default, the top left corner of the window is anchored in place.  
 */
- (NSLayoutAttribute)anchorAttributeForOrientation:(NSLayoutConstraintOrientation)orientation;
- (void)setAnchorAttribute:(NSLayoutAttribute)attr forOrientation:(NSLayoutConstraintOrientation)orientation;
@end

#pragma mark Size To Fit
@interface NSView (NSConstraintBasedLayoutFittingSize)
/* like sizeToFit, but for arbitrary views, and returns the size rather than changing the view's frame.  This considers everything in the receiver's subtree.
 */
@property (readonly) NSSize fittingSize NS_AVAILABLE_MAC(10_7);
@end

#pragma mark Debugging

/* Everything in this section should be used in debugging only, never in shipping code.  These methods may not exist in the future - no promises.  
 
 
 set default NSShowAlignmentRects to YES to see alignment rects drawn.  Useful in conjunction with NSShowAllViews, which shows frames.
 the existing -[NSView _subtreeDescription] is also very useful
 */
@interface NSView (NSConstraintBasedLayoutDebugging)

/* This returns a list of all the constraints that are affecting the current location of the receiver.  The constraints do not necessarily involve the receiver, they may affect the frame indirectly.
 Pass NSLayoutConstraintOrientationHorizontal for the constraints affecting NSMinX([self frame]) and NSWidth([self frame]), or NSLayoutConstraintOrientationVertical for the constraints affecting NSMinY([self frame]) and NSHeight([self frame]).
 */
- (NSArray<NSLayoutConstraint *> *)constraintsAffectingLayoutForOrientation:(NSLayoutConstraintOrientation)orientation NS_AVAILABLE_MAC(10_7);

/* If there aren't enough constraints in the system to uniquely determine layout, we say the layout is ambiguous.  For example, if the only constraint in the system was x = y + 100, then there are lots of different possible values for x and y.  This situation is not automatically detected by AppKit, due to performance considerations and details of the algorithm used for layout.  
 The symptom of ambiguity is that views sometimes jump from place to place, or possibly are just in the wrong place.
 -hasAmbiguousLayout runs a check for whether there is any other frame the receiver could have that could also satisfy the constraints.
 -exerciseAmbiguousLayout does more.  It randomly changes the frames of views in your window to another of their valid possible layouts.  Making the UI jump back and forth can be helpful for figuring out where you're missing a constraint.  
 */
@property (readonly) BOOL hasAmbiguousLayout NS_AVAILABLE_MAC(10_7);
- (void)exerciseAmbiguityInLayout NS_AVAILABLE_MAC(10_7); 
@end

@interface NSWindow (NSConstraintBasedLayoutDebugging)
/* This draws a visual representation of the given constraints in the receiver window.  It's a nice way to understand exactly what a collection of constraints specifies.  
 */
- (void)visualizeConstraints:(nullable NSArray<NSLayoutConstraint *> *)constraints NS_AVAILABLE_MAC(10_7);
@end

NS_ASSUME_NONNULL_END
