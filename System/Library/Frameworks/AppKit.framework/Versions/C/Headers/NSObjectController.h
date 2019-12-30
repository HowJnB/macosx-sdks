/*
	NSObjectController.h
	Application Kit
	Copyright (c) 2002-2003, Apple Computer, Inc.
	All rights reserved.
 */

#import <AppKit/NSController.h>
#import <AppKit/NSMenu.h>

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_3

@class NSArray;

@interface NSObjectController : NSController {
@private
	void *_reserved3;
	void *_reserved4;
    struct __objectControllerFlags {
        unsigned int _editable:1;
        unsigned int _automaticallyPreparesContent:1;
        unsigned int _hasLoadedData:1;
        unsigned int _explicitlyCannotAdd:1;
        unsigned int _explicitlyCannotRemove:1;
        unsigned int _reservedObjectController:27;
    } _objectControllerFlags;
    NSString *_objectClassName;
    Class _objectClass;
    NSArray *_contentObjectArray;
@protected    // all instance variables are private
	id _content;
    id _objectHandler;
}

- (id)initWithContent:(id)content;

- (void)setContent:(id)content;
- (id)content;

- (id)selection;    // an object representing all objects to be affected by editing as a singleton, returning special marker objects like NSMultipleSelectionMarker if necessary - in the concrete case of NSObjectController, returns an object that is used to access the content object
- (NSArray *)selectedObjects;    // array of all objects to be affected by editing (if controller supports a selection mechanisms, the selected objects, otherwise all content objects) - in the concrete case of NSObjectController, returns an array with the content object

- (void)setAutomaticallyPreparesContent:(BOOL)flag;    // if YES, controllers will automatically invoke prepareContent when loaded from a nib file
- (BOOL)automaticallyPreparesContent;
- (void)prepareContent;    // typically overridden in subclasses which know how to get their content (from the file system or so) - default implementation creates a new object and populates the controller with it

- (void)setObjectClass:(Class)objectClass;    // sets the object class used when creating new objects
- (Class)objectClass;
- (id)newObject;    // creates a new object when adding/inserting objects (default implementation assumes the object class has a standard init method without arguments) - the returned object should not be autoreleased
- (void)addObject:(id)object;    // sets the content object of the controller - if the controller's content is bound to another object or controller through a relationship key, the relationship of the 'master' object will be changed
- (void)removeObject:(id)object;    // if the object is the current content object of the controller, clears the content - if the controller's content is bound to another object or controller through a relationship key, the relationship of the 'master' object will be cleared

- (void)setEditable:(BOOL)flag;    // determines whether controller allows adding and removing objects
- (BOOL)isEditable;
- (void)add:(id)sender;    // creates a new object and adds it through addObject:
- (BOOL)canAdd;    // can be used in bindings controlling the enabling of buttons, for example
- (void)remove:(id)sender;    // removes content object through removeObject:
- (BOOL)canRemove;    // can be used in bindings controlling the enabling of buttons, for example
- (BOOL)validateMenuItem:(id <NSMenuItem>)menuItem;    // used to automatically disable menu items for action methods of the controller (for example if canAdd returns NO, menu items with the add: action are disabled)

@end

#endif
