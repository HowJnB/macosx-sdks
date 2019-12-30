/*
	NSArrayController.h
	Application Kit
	Copyright (c) 2002-2003, Apple Computer, Inc.
	All rights reserved.
 */

#import <AppKit/NSObjectController.h>

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_3

@class NSArray, NSIndexSet, NSMutableArray, NSMutableIndexSet;

@interface NSArrayController : NSObjectController {
@private
	void *_reserved5;
	void *_reserved6;
	void *_reserved7;
    struct __arrayControllerFlags {
        unsigned int _avoidsEmptySelection:1;
        unsigned int _preservesSelection:1;
        unsigned int _selectsInsertedObjects:1;
        unsigned int _refreshesAllModelObjects:1;
        unsigned int _filterRestrictsInsertion:1;
        unsigned int _overridesArrangeObjects:1;
        unsigned int _explicitlyCannotInsert:1;
        unsigned int _generatedEmptyArray:1;
        unsigned int _isObservingKeyPathsThroughArrangedObjects:1;
        unsigned int _reservedArrayController:23;
    } _arrayControllerFlags;
    NSArray *_sortDescriptors;
    NSMutableIndexSet *_selectionIndexes;
    unsigned int _observedIndexHint;
    NSMutableArray *_objects;
    NSMutableArray *_selectedObjects;
    NSArray *_arrangedObjects;
}

- (void)rearrangeObjects;    // triggers rearranging the content objects for the user interface, including sorting (and filtering if provided by subclasses); subclasses can invoke this method if any parameter that affects the arranged objects changes (for example the filter parameters)
- (void)setSortDescriptors:(NSArray *)sortDescriptors;
- (NSArray *)sortDescriptors;
- (NSArray *)arrangeObjects:(NSArray *)objects;    // returns objects to be arranged in the user interface for the content object array objects - method can be overridden to use a different kind of sort mechanism or to filter the display objects
- (id)arrangedObjects;     // array of all displayed objects (after sorting and potentially filtering)


- (void)setAvoidsEmptySelection:(BOOL)flag;    // default: YES
- (BOOL)avoidsEmptySelection;
- (void)setPreservesSelection:(BOOL)flag;    // default: YES
- (BOOL)preservesSelection;
- (void)setSelectsInsertedObjects:(BOOL)flag;    // default: YES
- (BOOL)selectsInsertedObjects;

// all selection modification methods returning a BOOL indicate through that flag whether changing the selection was successful (changing the selection might trigger an commitEditing call which fails and thus deny's the selection change)
- (BOOL)setSelectionIndexes:(NSIndexSet *)indexes;    // to deselect all: empty index set, to select all: index set with indexes [0...count - 1]
- (NSIndexSet *)selectionIndexes;
- (BOOL)setSelectionIndex:(unsigned int)index;
- (unsigned int)selectionIndex;
- (BOOL)addSelectionIndexes:(NSIndexSet *)indexes;
- (BOOL)removeSelectionIndexes:(NSIndexSet *)indexes;

- (BOOL)setSelectedObjects:(NSArray *)objects;
- (NSArray *)selectedObjects;
- (BOOL)addSelectedObjects:(NSArray *)objects;
- (BOOL)removeSelectedObjects:(NSArray *)objects;

- (void)insert:(id)sender;
- (BOOL)canInsert;    // can be used in bindings controlling the enabling of buttons, for example
- (void)selectNext:(id)sender;
- (void)selectPrevious:(id)sender;
- (BOOL)canSelectNext;
- (BOOL)canSelectPrevious;

- (void)addObject:(id)object;    // overridden to add to the content objects and to the arranged objects if all filters currently applied are matched
- (void)addObjects:(NSArray *)objects;
- (void)insertObject:(id)object atArrangedObjectIndex:(unsigned int)index;    // inserts into the content objects and the arranged objects (as specified by index in the arranged objects) - will raise an exception if the object does not match all filters currently applied
- (void)insertObjects:(NSArray *)objects atArrangedObjectIndexes:(NSIndexSet *)indexes;
- (void)removeObjectAtArrangedObjectIndex:(unsigned int)index;    // removes from the content objects and the arranged objects (as specified by index in the arranged objects)
- (void)removeObjectsAtArrangedObjectIndexes:(NSIndexSet *)indexes;
- (void)removeObject:(id)object;    // removes from the content objects and the arranged objects (if currently contained)
- (void)removeObjects:(NSArray *)objects;

@end

#endif
