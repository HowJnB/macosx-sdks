/*
     File:       DiscRecording/DRFolder.h
 
     Contains:   ObjC interface to folder objects used in filesystem creation.
 
     Version:    Technology: Mac OS X
                 Release:    Mac OS X
 
     Copyright:  (c) 2002 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/

#import <Foundation/Foundation.h>
#import <DiscRecording/DRFSObject.h>

/*!
	@class		DRFolder
	@abstract	represents a folder to be created on the disc.
	@discussion	DRFolders can be either a pointer to a real folder on disk or can be a "virtual" folder. 
				A DRFolder pointing to a real folder cannot have it's contents changed - only
				those files/folders which are children of the actual folder on disk will 
				be included on the resulting disc. "Virtual" folders are entirely created 
				programatically and any virtual folder structure can exist and be burned 
				to disc.
*/
@interface DRFolder : DRFSObject
{ }

/*! 
   	@method 		folderWithPath:
   	@abstract		Creates a "real" folder object
	@discussion		Creates and initializes a DRFolder object that will use the folder contents of
					the folder located at path as a source.
   	@param 			path	The path to an existing file.
    @result  		An autoreleased DRFolder object.
*/
+ (DRFolder*) folderWithPath:(NSString*)path;

/*! 
   	@method 		initWithPath:
   	@abstract		Initializes a "real" file object
	@discussion		Initializes a DRFolder object that will use the folder contents of
					the folder located at path as a source.
   	@param 			path	The path to an existing folder.
    @result  		A DRFolder object.
*/
- (id) initWithPath:(NSString*)path;

@end

@interface DRFolder (VirtualFolders)

/*! 
   	@method 		virtualFolderWithName:
   	@abstract		Creates a "virtual" folder object
	@discussion		Creates and initializes a DRFolder object that will be populated with 
					specified DRFile and DRFolder objects at runtime.
   	@param 			name	The name of the folder on the output disc.
    @result  		An autoreleased DRFolder object.
*/
+ (DRFolder*) virtualFolderWithName:(NSString*)name;

/*! 
   	@method 		initWithName:
   	@abstract		Initializes a "virtual" file object
	@discussion		Initializes a DRFolder object that will be populated with 
					specified DRFile and DRFolder objects at runtime.
   	@param 			name	The name of the folder on the output disc.
    @result  		A DRFolder object.
*/
- (id) initWithName:(NSString*)name;

/*! 
   	@method 		makeVirtual
   	@abstract		Changes the real DRFolder object into a "virtual" DRFolder object.
	@discussion		The virtual folder created in this way is a snapshot of the on-disk
					folder at the moment of the call.  The newly created virtual folder
					will contain <b>real</b> folder and file objects corresponding to the
					on-disk children of the original on-disk folder.
								
					If the on-disk folder is modified (eg, if the folder attributes change, 
					or if children are added to or removed from the on-disk tree):
					<i>during</i> this call, the virtual folder <b>may or may not</b> reflect the changes.
					If modified <i>after</i> this call, the virtual folder <b>will</b> not reflect
					the changes.
*/
- (void) makeVirtual;

/*! 
   	@method 		addChild:
   	@abstract		Adds an object reference (either a file or folder) as a child of
					a virtual folder object.
	@discussion		This method only applies to virtual folders.  Real folders
					are considered "leaf nodes" and cannot have children.
	@param			child	The child to add to the folder
*/
- (void) addChild:(DRFSObject*)child;

/*! 
   	@method 		removeChild:
   	@abstract		Removes an object reference (either a file or folder) as a child of
					a virtual folder object.
	@discussion		This method only applies to virtual folders.  Real folders
					are considered "leaf nodes" and cannot have children.
	@param			child	The child to remove from the folder
*/
- (void) removeChild:(DRFSObject*)child;

/*! 
   	@method 		count
   	@abstract		Returns the number of children of a virtual folder. 
   	@discussion		This method returns a
					"shallow" count of only those children that are immediately contained 
					within the virtual folder.
					
					This method only applies to virtual folders.  Real folders
					are considered "leaf nodes" and should not be passed into this call.
	@result			A count of the number of children.
*/
- (uint32_t) count;

/*! 
   	@method 		children
   	@abstract		Returns an array containing the children of a virtual folder.
	@discussion		The order of children in the array is arbitrary -- since the various filesystems being
					generated may have different sorting requirements, there is no one true
					way to sort the children.  The ordering will change only when children
					are added or removed.  You should sort the children according to the needs
					of your display, and in a consistent manner.
								
					This function only applies to virtual folders.  Real folders
					are considered "leaf nodes" and should not be passed into this call.
	@param			An NSArray of DRFile and DRFolder objects.
*/
- (NSArray*) children;

@end
