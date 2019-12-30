/*
	NSScriptClassDescription.h
	Copyright (c) 1997-2013, Apple Inc.
	All rights reserved.
*/

#import <Foundation/NSClassDescription.h>

@class NSScriptCommandDescription;

@interface NSScriptClassDescription : NSClassDescription {
    @private
    NSString *_suiteName;
    NSString *_objcClassName;
    FourCharCode _appleEventCode;
    NSObject *_superclassNameOrDescription;
    NSArray *_attributeDescriptions;
    NSArray *_toOneRelationshipDescriptions;
    NSArray *_toManyRelationshipDescriptions;
    NSDictionary *_commandMethodSelectorsByName;
    id _moreVars;
}

/* Return the class description for a class or, if it is not scriptable, the first superclass that is.
*/
+ (NSScriptClassDescription *)classDescriptionForClass:(Class)aClass;

/* Initialize, given a scripting suite name, class name, and class declaration dictionary of the sort that is valid in .scriptSuite property list files.
*/
- (id)initWithSuiteName:(NSString *)suiteName className:(NSString *)className dictionary:(NSDictionary *)classDeclaration;

/* Return the suite name or class name provided at initialization time.
*/
- (NSString *)suiteName;
- (NSString *)className;

/* Return the name of the Objective-C that implements the described scriptable class.
*/
- (NSString *)implementationClassName;

/* Return the scripting class description of the superclass of the class described by the receiver.
*/
- (NSScriptClassDescription *)superclassDescription;

/* Return the primary four character code used to identify the described class in Apple events.
*/
- (FourCharCode)appleEventCode;

/* Return YES if the four character code identifies the described class in Apple events. Return NO otherwise.
*/
- (BOOL)matchesAppleEventCode:(FourCharCode)appleEventCode;

/* Return YES if the described class or one of its superclasses is explicitly declared to support the described command, NO otherwise.
*/
- (BOOL)supportsCommand:(NSScriptCommandDescription *)commandDescription;

/* If the described class or one of its superclasses is explicitly declared to support the described command and the declaration includes a method name, return the selector for the class' handler method for the command. Return NULL otherwise.
*/
- (SEL)selectorForCommand:(NSScriptCommandDescription *)commandDescription;

/* Return the name of the declared type of the keyed attribute, to-one relationship, or to-many relationship.
*/
- (NSString *)typeForKey:(NSString *)key;

/* Return the class description for the keyed attribute, to-one relationship, or to-many relationship.
*/
- (NSScriptClassDescription *)classDescriptionForKey:(NSString *)key;

/* Return the four character code that identifies the keyed attribute, to-one relationship, or to-many relationship in Apple events.
*/
- (FourCharCode)appleEventCodeForKey:(NSString *)key;

/* Given a four character code used to identify a property or element class in Apple events, return the key identifying the corresponding attribute, to-one relationship or to-many relationship.
*/
- (NSString *)keyWithAppleEventCode:(FourCharCode)appleEventCode;

/* Return the value of the DefaultSubcontainerAttribute entry of the class declaration dictionary provided when the receiver was instantiated, or nil if there was no such entry.
*/
- (NSString *)defaultSubcontainerAttributeKey;

/* Return YES if creation of objects for the relationship specified by the key, in containers of the class described by the receiver, requires an explicitly specified insertion location. Return NO otherwise. For example, NSCreateCommand uses this method to determine whether or not a specific Make command must have an at parameter.
*/
- (BOOL)isLocationRequiredToCreateForKey:(NSString *)toManyRelationshipKey;

/* Return whether the described class has a property identified by the key, whether it's a to-many relationship, whether it's readable, or whether it's writable, respectively.
*/
- (BOOL)hasPropertyForKey:(NSString *)key NS_AVAILABLE(10_5, NA);
- (BOOL)hasOrderedToManyRelationshipForKey:(NSString *)key NS_AVAILABLE(10_5, NA);
- (BOOL)hasReadablePropertyForKey:(NSString *)key NS_AVAILABLE(10_5, NA);
- (BOOL)hasWritablePropertyForKey:(NSString *)key NS_AVAILABLE(10_5, NA);

@end

@interface NSScriptClassDescription(NSDeprecated)

/* A method that was deprecated in Mac OS 10.5. You should use -hasWritablePropertyForKey: instead.
*/
- (BOOL)isReadOnlyKey:(NSString *)key NS_DEPRECATED(10_0, 10_5, NA, NA);

@end

@interface NSObject(NSScriptClassDescription)

/* Return the four character code identifying the receiver's class in Apple events.
*/
- (FourCharCode)classCode;

/* Return the Objective-C name of the receiver's class.
*/
- (NSString *)className;

@end
