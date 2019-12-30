/*
     File:       DiscRecording/DRErase.h
 
     Contains:   Handles erasing a disc and obtaining status about that erasure.
 
     Version:    Technology: Mac OS X
                 Release:    Mac OS X
 
     Copyright:  (c) 2002 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/

#import <Foundation/Foundation.h>

#import <DiscRecording/DRCoreErase.h>
#import <DiscRecording/DRDevice.h>

#import <AvailabilityMacros.h>


/*!
	@class		DRErase
	@abstract	A DRErase object handles the process of erasing a rewritable CD or DVD disc.
	@discussion	Each time you want to erase a disc, an instance of this class needs to be created.
	
				When an instance is created, you pass in an instance of DRDevice to let the object 
				know what device to erase. This object is retained for the life of the DRErase instance. 
			
				A DRErase object will send out notifications through the DRNotificationCenter mechanism to 
				broadcast the erase state to any interested observers. However, if for some reason you don't want
				to use notifications, you can poll the erase object at any time for the current status using
				<b>status</b>. This is not recommended in any application using a run loop, because it involves polling.

				Here's an example that shows you how to use this class:
				
				<code>
				- (void) doErase
				{
					DRDevice*       device;
					DRErase*        erase;
				
					<i>...determine correct device to erase...</i>
					
					erase = [[DRErase alloc] initWithDevice:device];
					
					// we'll do a quick erase. It's typically all that's needed.
					[erase setEraseType:DREraseTypeQuick];
					
					// register to receive notification about the erase status.
					[[DRNotificationCenter currentRunLoopCenter] addObserver:self
																	selector:&#x40;selector(eraseNotification:)
																		name:DREraseStatusChangedNotification 
																	  object:erase];
								   
					 // start the erase                            
					 [erase start];
				}
				
				- (void) eraseNotification:(NSNotification*)notification
				{
					DRErase*        erase = [notification object];
					NSDictionary*   status = [notification userInfo];
					
					<i>...do what you wish with the notification...</i>
				}
				</code>
*/
@interface DRErase : NSObject 
{ 
@private
	void*	_ref;
}

/*!
	@method			eraseForDevice:
	@abstract		Creates and returns an erase object.
	@discussion		An erase object created with this method is ready to erase media.
   	@param 			device	Device to use for the erase.
    @result  		An autoreleased DRErase object.
*/
+ (DRErase*) eraseForDevice:(DRDevice*)device;

/*!
	@method			initWithDevice:
	@abstract		Initializes an erase object.
	@discussion		An erase object created with this method is ready to erase media.
   	@param 			device	Device to use for the erase.
    @result  		A DRErase object.
*/
- (id) initWithDevice:(DRDevice*)device;

/*!
	@method			start
	@abstract		Begin the process of erasing media.
	@discussion		This method only kicks off the erase. Once the erasure starts,
					control returns to the caller. The caller can monitor the progress 
					of the erase by listening for a notification or by polling <b>status</b>.
*/
- (void) start;

/*!
	@method			status
	@abstract		Returns a dictionary containing the status of the erase.
	@discussion		The same dictionary is returned 
					through the DREraseStatusChangedNotification notification.
*/
- (NSDictionary*) status;

/*! 
   	@method 		properties
   	@abstract		Returns the properties dictionary of the erase.
    @result  		An NSDictionary containing the properties of the erase.
*/
- (NSDictionary*) properties;

/*! 
   	@method 		setProperties:
   	@abstract		Sets the properties dictionary of the erase
   	@param 			properties	NSDictionary of the properties to set.
*/
- (void) setProperties:(NSDictionary*)properties;

/*! 
   	@method 		device
   	@abstract		Returns the device being used for the erase.
    @result  		The DRDevice the erase will use.
*/
- (DRDevice*) device;

@end

@interface DRErase (PropertyConvenienceMethods)

/*!
	@method			eraseType
	@abstract		Returns the type of erase to be performed.
	@result			An NSString
*/
- (NSString*) eraseType;

/*!
	@method			setEraseType:
	@abstract		Sets the type of erase to perform.
	@param			type	The type of erase.
*/
- (void) setEraseType:(NSString*)type;

@end

#if 0
#pragma mark Erase Properties
#endif
/*!
	@const		DREraseTypeKey
	@discussion	The key for the erase's properties dictionary storing the type of 
				erase to perform 
*/
extern NSString* const DREraseTypeKey			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*" 
	@const		DREraseTypeQuick
	@discussion	Perform a quick erase, doing the minimal amount of work to make the 
				disc appear blank. This operation typically takes only a minute or two. 
				This is the default for an erase object.
*/
extern NSString* const DREraseTypeQuick			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!	
	@const		DREraseTypeComplete	
	@discussion	Perform a complete erase, erasing every byte on the
				disk. This operation is slow (on the order of 30 minutes) to complete.
*/
extern NSString* const DREraseTypeComplete		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

#if 0
#pragma mark Erase State
#endif
/*
	@const		DREraseStatusChangedNotification
	@discussion	Posted by a DRNotificationCenter when the status of the
				erase operation has changed. 
				
				 The object associated with this notification
				is the erase object sending it and the userInfo contains a dictionary
				detailing the status.
*/
extern NSString* const DREraseStatusChangedNotification	AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

