/*
     File:       DiscRecording/DRDevice.h
 
     Contains:   Handles obtaining information about cd/dvd burners connected 
     			 to the computer. 
 
     Version:    Technology: Mac OS X
                 Release:    Mac OS X
 
     Copyright:  (c) 2002 by Apple Computer, Inc., all rights reserved
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/

#import <Foundation/Foundation.h>

#import <DiscRecording/DRCoreDevice.h>
#import <DiscRecording/DRMSF.h>

#import <AvailabilityMacros.h>

/*!
	@class 		DRDevice
	@abstract	Represents a CD or DVD burner connected to the computer.
	@discussion	
				<h3>About Devices</h3>
				A DRDevice represents a physical CD/DVD drive connected to the computer. This class is 
				mainly for informational purposes since the device is configured by the burn 
				engine before beginning to optimally handle the burn. The basis for obtaining the
				device information is through two methods <b>info</b> and <b>status</b>. <b>info</b> returns 
				information pertaining to the drive as a whole and is not affected by the state 
				of any media in the drive. <b>status</b> returns information about the media in the drive as
				well as those bits of information directly affected by the media (maximum burn speed,
				BSD dev node name, etc.)
	
				<h3>Obtaining Device instances</h3>
				DRDevices cannot be created by the programmer. Devices are managed by the burn engine
				and are asked for by client code. The preferred way of obtaining an instance is
				by registering with the <b>DRNotificationCenter</b> and listening for the 
				<i>DRDeviceAppearedNotification</i>. This notification is sent to all
				observers when a device is first detected by the burn engine (such as when a device
				is plugged in or turned on). A client is guaranteed to receive all 
				DRDeviceAppearedNotifications. When a client registers for the 
				DRDeviceAppearedNotification, the engine will ensure that
				the client gets notified of all devices currently connected to the machine. When a device
				is removed, registed observers will receive a DRDeviceDisappearedNotification.
				
				It's also possible to obtain a device instance from its IORegistry path 
				(<b>deviceForIORegistryEntryPath:</b>) or the BSD /dev node name (<b>deviceForBSDName:</b>).
				If you have a reference to a device instance, you can determine if the physical device
				is still valid and connected by sending the <b>isValid</b> method to the instance.
				
				<h3>Device Control</h3>
				There is a limited set of operations that can be performed on a device. The most
				important of these is <i>media reservation</i>. Reserving media is a process by which
				applications arbitrate for blank media. An application registers interest in 
				obtaining a media reservation by caling <b>acquireMediaReservation</b> and gives up
				its interest by calling releaseMediaReservation. asking to acquire a reservation does
				not mean you will get it! Another application may already have the reservation and 
				will refuse to give it up to you. In this case, the only thing to do is to play fair and
				wait until the DRDeviceMediaIsReservedKey indicates that your app has obtained 
				the reservation.
				
				The device tray can be opened (<b>openTray</b>) or closed (<b>closeTray</b>) and media 
				can be ejected (<b>ejectMedia</b>).
*/
@interface DRDevice : NSObject 
{ 
@private
	void*	_ref;
}

/*! 
   	@method 		devices
   	@abstract		Obtains a static list of devices connected to the computer.
	@discussion		Returns all CD/DVD devices connected to the computer at the time this 
					method is called. Since devices can come and go at any time, the output of this 
					method is simply a snapshot of the set of devices connected.
    @result  		An NSArray of DRDevices.
*/
+ (NSArray*) devices;

/*! 
   	@method 		deviceForBSDName:
   	@abstract		Obtains a DRDevice for the device corresponding to the bsd /dev node.
	@discussion		If the device is not an authoring device (i.e., CDR, CDRW, DVR-R, etc), returns nil.
   	@param 			bsdName	The bsd /dev node name.
    @result  		An autoreleased DRDevice object.
*/
+ (DRDevice*) deviceForBSDName:(NSString*)bsdName;

/*! 
   	@method 		deviceForIORegistryEntryPath:
   	@abstract		Obtains a DRDevice for the device at the path.
	@discussion		If the device is not an authoring device (i.e., CDR, CDRW, DVR-R, etc), returns nil.
   	@param 			path	The IORegistry path to the device you wish to obtain a DRDEvice for.
    @result  		An autoreleased DRDevice object.
*/
+ (DRDevice*) deviceForIORegistryEntryPath:(NSString*)path;

/*!
	@method			isValid
	@abstract		Returns whether or not the device represented by the receiver is still attached
					to the computer.
	@discussion		Because of the way some physical interconnects work, a device
					which is unplugged and replugged in does not necessarily look like the same
					device to the computer and would be invalid in that instance. 
	@result			Returns <i>YES</i> if device is valid and <i>NO</i> if not.
*/
- (BOOL) isValid;

/*!
	@method			info
	@abstract		Returns a dictionary of information describing the device.
	@discussion		The information returned include the types of media the devive can write to, how 
					it's connected and it's identifying information such as the vendor and product name.
*/
- (NSDictionary*) info;

/*!
	@method			status
	@abstract		Returns a dictionary of information describing the media in the device.
	@discussion		In addition to information about the media (type, space available/used, etc),
					the dictionary returned includes those pieces of information about the device 
					itself which are in part determined by the media (i.e., maximum burn speed).
*/
- (NSDictionary*) status;

/*!
	@method			openTray
	@abstract		Commands the device to open it's tray.
	@discussion		Does nothing if the device does not have a tray (slotload). If there is media in
					the drive this method will do nothing and return false. In this case use 
					<b>ejectMedia</b> to eject the media and open the tray. 
	@result			Returns <i>YES</i> if the tray could be opened and <i>NO</i> if not.
*/
- (BOOL) openTray;

/*!
	@method			closeTray
	@abstract		Commands the device to close its tray.
	@discussion		Does nothing if the device does not have a tray (slotload).
	@result			Returns <i>YES</i> if the tray could be closed and <i>NO</i> if not.
*/
- (BOOL) closeTray;

/*!
	@method			ejectMedia
	@abstract		Commands the device to eject the media.
	@discussion		This command first unmounts any volumes associated with the media and
					then eject the media from the drive. If the media could not be ejected, 
					most likely this is because a volume associated with the media could not be unmounted.
	@result			Returns <i>YES</i> if the media could be ejected and <i>NO</i> if not.
*/
- (BOOL) ejectMedia;

/*!
	@method			acquireExclusiveAccess
	@abstract		Attempts to acquire an exclusive access session with the device.
	@discussion		Acquiring exclusive access to the device prevents any process
					other than the one acquiring access from communicating with the
					device. So once exclusive access is granted, the device is unusable by any other process. 
					Because of this all volumes mounted from media in the drive must be unmounted
					before exclusive access can be granted. 
	
					Exclusive access can be acquired multiple times. Each time this method
					is called, a call to <b>releaseExclusiveAccess</b> must be made at a later time,
					otherwise the process will never release its exclusive access.
	@result			Returns <i>YES</i> if the exclusinve access is acquired and <i>NO</i> if not.
*/
- (BOOL) acquireExclusiveAccess;

/*!
	@method			releaseExclusiveAccess
	@abstract		Releases the latest exclusive access request for the device.
	@discussion		A call to this method must be made for every call to <b>acquireExclusiveAccess</b>, 
					otherwise the process will never release its exclusive access.
*/
- (void) releaseExclusiveAccess;

/*!
	@method			acquireMediaReservation
	@abstract		Indicate an interest in the blank media reservation.
	@discussion		Blank media participates in a reservation system thats allows applications to express
					their claim on blank media to other applications.  Indicating an interest in the reservation
					isn't enough to assume its been acquired, as there are likely to be other applications in
					the system whom have also indicated an interest in the blank media reservation.  You will
					receive a DRDeviceStatusChangedNotification with a value of <tt>TRUE</tt> for the
					DRDeviceMediaIsReservedKey when the blank media reservation has been acquired.
					
					This function may be called multiple times. Each time it is called, a call to
					<b>releaseMediaReservation</b> must be made at a later time, otherwise the process will
					never fully rescind its interest in the blank media reservation.
*/
- (void) acquireMediaReservation;

/*!
	@method			releaseMediaReservation
	@abstract		Releases any media reservation that might be in place for the device.
	@discussion		If media is inserted and reserved, then the reservation will be passed 
					on to the next process with a reservation request.
*/
- (void) releaseMediaReservation;

/*!
	@method			isEqualToDevice:
	@abstract		Compares the receiver to another device.
	@param			otherDevice	Another DRDevice instance to compare to the receiver.
	@result			Returns <i>YES</i> if the receiver is equal to otherDevice.
*/
- (BOOL) isEqualToDevice:(DRDevice*) otherDevice;

@end

/*" Convenience methods for accessing the various keys contained in the
	dictionary returned by <b>info</b>. Each time you want to burn to a disc, an
	instance of this class needs to be created. If you want all (or even a few bits)
	of this information it's much more efficient to call <b>info</b> yourself and
	then extract the needed values from the dictionary. "*/
	
@interface DRDevice (InfoConvenience)

/*!
	@method		writesCD
	@discussion	Reports the device's ability to burn to CD-type media.
	@result		Returns <i>YES</i> if the device has the ability to write to CD-R media.
*/
- (BOOL) writesCD;


/*!
	@method		writesDVD
	@discussion	Reports the device's ability to burn to DVD-type media.
	@result		Returns <i>YES</i> if the device has the ability to write to DVD-R media.
*/
- (BOOL) writesDVD;


/*!
	@method		displayName
	@discussion	Returns an NSString suitable for display in the user interface.
*/
- (NSString*) displayName;


/*!
	@method		ioRegistryEntryPath
	@discussion	Returns the path to the device in the IO Registry.
*/
- (NSString*) ioRegistryEntryPath;

@end

/*" Convienience methods for accessing the various keys contained in the 
	dictionary returned by <b>status</b>. If you want all (or even a few bits) 
	of this information it's much more efficient to get status yourself 
	and then extract the needed values from the dictionary. "*/

@interface DRDevice (StatusConvenience)


/*!
	@method		mediaIsPresent
	@discussion	Reports the presence of the media.
*/
- (BOOL) mediaIsPresent;


/*!
	@method		mediaIsTransitioning
	@discussion	Returns <i>YES</i> if the media is in transition (spinning up or down for example).
*/
- (BOOL) mediaIsTransitioning;


/*!
	@method		mediaIsBusy
	@discussion	Returns <i>YES</i> if the media is in use by some process - even the one making this call.
*/
- (BOOL) mediaIsBusy;


/*!
	@method		mediaType
	@discussion	Returns the type of media currently inserted into the device.
*/
- (NSString*) mediaType;


/*!
	@method		mediaIsBlank
	@discussion	Returns <i>YES</i> the media in the device is blank.
*/
- (BOOL) mediaIsBlank;


/*!
	@method		mediaIsAppendable
	@discussion	Returns <i>YES</i> if the media in the device can have more data appended to any existing data.
*/
- (BOOL) mediaIsAppendable;


/*!
	@method		mediaIsErasable
	@discussion	Returns <i>YES</i> if the media can be erased (i.e., CD-RW, DVD-RW, etc).
*/
- (BOOL) mediaIsErasable;


/*!
	@method		mediaIsReserved
	@discussion	Returns <i>YES</i> if the application calling this method currently holds the reservation on the media.
*/
- (BOOL) mediaIsReserved;


/*!
	@method		mediaSpaceUsed
	@discussion	Returns the amount of used space on the media.
*/
- (DRMSF*) mediaSpaceUsed;


/*!
	@method		mediaSpaceFree
	@discussion	Returns the amount of free space on the media.
*/
- (DRMSF*) mediaSpaceFree;


/*!
	@method		trayIsOpen
	@discussion	Reports the tray state of the device.
	@result		Returns <i>YES</i> if the device has a tray and it is open.
*/
- (BOOL) trayIsOpen;


/*!
	@method		bsdName
	@discussion	Returns the bsd /dev node name.
*/
- (NSString*) bsdName;

@end

#if 0
#pragma mark Device Burn Speeds
#endif

/*!
	@const	DRDeviceBurnSpeed_CD_1x		176.4 KB/sec.
*/
extern const float	DRDeviceBurnSpeedCD1x		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const	DRDeviceBurnSpeed_DVD_1x	1385.0 KB/sec.
*/
extern const float	DRDeviceBurnSpeedDVD1x		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceBurnSpeed_Max
	@discussion	A value representing the maximum speed a device can burn. The actual speed will
				vary from device to device.
*/
extern const float	DRDeviceBurnSpeedMax		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

#if 0
#pragma mark Device Notifications
#endif

/*!
	@const	 	DRDeviceAppearedNotification
	@discussion	Posted by a DRNotificationCenter when a device is added to the system.

				This notification is registered for only by name. 
				
				The object associated with this notification
				is the the device that has appeared. The userInfo is the same dictionary 
				returned by <b>info</b> for that device. 
*/
extern NSString* const DRDeviceAppearedNotification	AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceDisappearedNotification
	@discussion	Posted by a DRNotificationCenter when a device is removed from the system.
	
				The object associated with this notification
				is the the device that has disappeared. The userInfo is the same dictionary 
				returned by <b>info</b> for that device. 
*/
extern NSString* const DRDeviceDisappearedNotification	AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const	 	DRDeviceStatusChangedNotification
	@discussion	Posted by a DRNotificationCenter when the media
				in a device changes state. This can include being ejected, inserted, becoming busy, 
				etc. 
				
				The object for this notification is the device who's media is changing state.
				The userInfo for this notification is the same dictionary returned by <b>status</b> for 
				that device. 
*/
extern NSString* const DRDeviceStatusChangedNotification	AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

#if 0
#pragma mark Device Information
#endif

/*!
	@const		DRDeviceSupportLevelKey	
	@discussion	The info key whose value is an NSString describing the support level 
				the device enjoys from the engine.
*/
extern NSString* const DRDeviceSupportLevelKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceIORegistryEntryPathKey
	@discussion	The info key whose value is an NString containing the path 
				of the device in the IO Registry.
*/
extern NSString* const DRDeviceIORegistryEntryPathKey			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceWriteCapabilitiesKey
	@discussion	The info key whose value is an NSDictionary containing 
				the capabilities of the device for writing different kinds of media.
*/
extern NSString* const DRDeviceWriteCapabilitiesKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceVendorNameKey
	@discussion	The info key whose value is an NString containing the vendor name 
				extracted from the device.
*/
extern NSString* const DRDeviceVendorNameKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceProductNameKey
	@discussion	The info key whose value is an NString containing the product name 
				extracted from the device.
*/
extern NSString* const DRDeviceProductNameKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceFirmwareRevisionKey
	@discussion	The info key whose value is an NString containing the firmeware revision 
				extracted from the device.
*/
extern NSString* const DRDeviceFirmwareRevisionKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectKey
	@discussion	The info key whose value is an NString describing the connection 
				of the device to the computer.
*/
extern NSString* const DRDevicePhysicalInterconnectKey			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectLocationKey
	@discussion	The info key whose value is an NString describing the location 
				of the device (internal/external/unknown).
*/
extern NSString* const DRDevicePhysicalInterconnectLocationKey	AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceSupportLevelNone
	@discussion	The value of DRDeviceSupportLevelKey that indicates 
				this device is not supported.
*/
extern NSString* const DRDeviceSupportLevelNone					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceSupportLevelVendorSupported
	@discussion	The value of DRDeviceSupportLevelKey that indicates 
				this device has been tested by a third party for support.
*/
extern NSString* const DRDeviceSupportLevelVendorSupported		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceSupportLevelAppleSupported
	@discussion	The value of DRDeviceSupportLevelKey that indicates 
				this device has been tested by Apple for support.
*/
extern NSString* const DRDeviceSupportLevelAppleSupported		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceSupportLevelAppleShipping
	@discussion	The value of DRDeviceSupportLevelKey that indicates 
				this device is shipping in some Apple machine.
*/
extern NSString* const DRDeviceSupportLevelAppleShipping		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const 		DRDeviceCanWriteKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write to some type of media.
*/
extern NSString* const DRDeviceCanWriteKey						AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanWriteCDKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write to some type of CD based media.
*/
extern NSString* const DRDeviceCanWriteCDKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanWriteCDRKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write to CD-R media.
*/
extern NSString* const DRDeviceCanWriteCDRKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanWriteCDRWKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write to CD-RW media.
*/
extern NSString* const DRDeviceCanWriteCDRWKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanWriteDVDKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write to some type of DVD based media.
*/
extern NSString* const DRDeviceCanWriteDVDKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanWriteDVDRKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write to DVD-R media.
*/
extern NSString* const DRDeviceCanWriteDVDRKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanWriteDVDRWKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write to DVD-RW media.
*/
extern NSString* const DRDeviceCanWriteDVDRWKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanWriteDVDRAMKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write to DVD-RAM media.
*/
extern NSString* const DRDeviceCanWriteDVDRAMKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanTestWriteCDKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can perform a test burn to CD media.
*/
extern NSString* const DRDeviceCanTestWriteCDKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanTestWriteDVDKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can perform a test burn to DVD media.
*/
extern NSString* const DRDeviceCanTestWriteDVDKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanWriteCDTextKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device can write CD-Text data to media.
*/
extern NSString* const DRDeviceCanWriteCDTextKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanUnderrunProtectCDKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device supports burn underrun protection when writing to CD media.
*/
extern NSString* const DRDeviceCanUnderrunProtectCDKey			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCanUnderrunProtectDVDKey
	@discussion	One of the keys in the dictionary associated with DRDeviceWriteCapabilitiesKey.
				NSNumber indicating if the device supports burn underrun protection when writing to DVD media.
*/
extern NSString* const DRDeviceCanUnderrunProtectDVDKey			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectFireWire
	@discussion	One of the possible values of the DRDevicePhysicalInterconnectKey.
				Device is connected through Firewire.
*/
extern NSString* const DRDevicePhysicalInterconnectFireWire		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectUSB
	@discussion	One of the possible values of the DRDevicePhysicalInterconnectKey.
				Device is connected through USB.
*/
extern NSString* const DRDevicePhysicalInterconnectUSB			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectATAPI
	@discussion	One of the possible values of the DRDevicePhysicalInterconnectKey.
				Device is connected on an ATAPI bus.
*/
extern NSString* const DRDevicePhysicalInterconnectATAPI		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectSCSI
	@discussion	One of the possible values of the DRDevicePhysicalInterconnectKey.
				Device is connected on a SCSI bus.
*/
extern NSString* const DRDevicePhysicalInterconnectSCSI			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectLocationInternal
	@discussion	One of the possible values of the DRDevicePhysicalInterconnectLocationKey.
				Device is connected to the machine internally.
*/
extern NSString* const DRDevicePhysicalInterconnectLocationInternal		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectLocationExternal
	@discussion	One of the possible values of the DRDevicePhysicalInterconnectLocationKey.
				Device is connected to the machine externally.
*/
extern NSString* const DRDevicePhysicalInterconnectLocationExternal		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDevicePhysicalInterconnectLocationUnknown
	@discussion	One of the possible values of the DRDevicePhysicalInterconnectLocationKey.
				It's not known how the device is connected.
*/
extern NSString* const DRDevicePhysicalInterconnectLocationUnknown		AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

#if 0
#pragma mark Device Status
#endif

/*!
	@const		DRDeviceIsBusyKey
	@discussion	One of the keys in the dictionary returned by the status method.
				NSNumber indicating if the device is busy or not.
*/
extern NSString* const DRDeviceIsBusyKey						AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceIsTrayOpenKey
	@discussion	One of the keys in the dictionary returned by the status method.
				NSNumber indicating if the device's tray is open or not.
*/
extern NSString* const DRDeviceIsTrayOpenKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMaximumWriteSpeedKey
	@discussion	One of the keys in the dictionary returned by the status method.
				NSNumber containing the maximum burning speed of this device.
*/
extern NSString* const DRDeviceMaximumWriteSpeedKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceCurrentWriteSpeedKey
	@discussion	One of the keys in the dictionary returned by the status method.
				NSNumber containing the current burning speed of this device.
*/
extern NSString* const DRDeviceCurrentWriteSpeedKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceBurnSpeedsKey
	@discussion	One of the keys in the dictionary returned by the status method.
				NSArray containing the possible burn speeds available to use.
				This key may not be present if no media is inserted.
*/
extern NSString* const DRDeviceBurnSpeedsKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaStateKey
	@discussion	One of the keys in the dictionary returned by the status method.
				NSString describing the state of the media.
*/
extern NSString* const DRDeviceMediaStateKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaInfoKey
	@discussion	One of the keys in the dictionary returned by the status method.
				NSDictionary of information describing the media currently in the device. 
				This key may not be present if no media is inserted.
*/
extern NSString* const DRDeviceMediaInfoKey						AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaStateMediaPresent
	@discussion	One of the possible values for the DRDeviceMediaStateKey.
				Device contains media of some type.
*/
extern NSString* const DRDeviceMediaStateMediaPresent			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaStateInTransition
	@discussion	One of the possible values for the DRDeviceMediaStateKey.
				The media is transitioning from one state to another (i.e., being spun up/down).
*/
extern NSString* const DRDeviceMediaStateInTransition			AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaStateNone
	@discussion	One of the possible values for the DRDeviceMediaStateKey.
				No media is present in the device.
*/
extern NSString* const DRDeviceMediaStateNone					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSString containing the type of media inserted in the device.
*/
extern NSString* const DRDeviceMediaTypeKey						AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaBSDNameKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSString containing the BSD /dev node name assigned to the media in the device.
*/
extern NSString* const DRDeviceMediaBSDNameKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaIsBlankKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSNumber indicating if data bas previously been written to the media.
*/
extern NSString* const DRDeviceMediaIsBlankKey					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaIsAppendableKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSNumber indicating that data can be appended to the exisiting data (if any).
*/
extern NSString* const DRDeviceMediaIsAppendableKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaIsErasableKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSNumber indicating if this media can be erased.
*/
extern NSString* const DRDeviceMediaIsErasableKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaIsReservedKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSNumber indicating that the media is reserved for exclusive use by 
									the current process.
*/
extern NSString* const DRDeviceMediaIsReservedKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaFreeSpaceKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				MSF value of the amount of space available on the media to be written to.
*/
extern NSString* const DRDeviceMediaFreeSpaceKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaUsedSpaceKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				MSF value of the amount of space currently used for exising data.
*/
extern NSString* const DRDeviceMediaUsedSpaceKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaBlocksFreeKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSNumber containing the amount of space available (in blocks) on the media to be written to.
*/
extern NSString* const DRDeviceMediaBlocksFreeKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaBlocksUsedKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSNumber containing the amount of space currently used (in blocks) for exising data.
*/
extern NSString* const DRDeviceMediaBlocksUsedKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;


/*!
	@const		DRDeviceMediaTrackCountKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSNumber containing the number of tracks present on the media.
*/
extern NSString* const DRDeviceMediaTrackCountKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaSessionCountKey
	@discussion	One of the keys in the dictionary DRDeviceMediaInfoKey.
				NSNumber containing the sessions of tracks present on the media.
*/
extern NSString* const DRDeviceMediaSessionCountKey				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeCDROM
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				Media is a CD-ROM.
*/
extern NSString* const DRDeviceMediaTypeCDROM					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeCDR
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				Media is a CD-R.
*/
extern NSString* const DRDeviceMediaTypeCDR						AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeCDRW
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				Media is a CD-RW.
*/
extern NSString* const DRDeviceMediaTypeCDRW					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeDVDROM
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				Media is a DVD-ROM.
*/
extern NSString* const DRDeviceMediaTypeDVDROM					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeDVDRAM
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				Media is a DVD-RAM.
*/
extern NSString* const DRDeviceMediaTypeDVDRAM					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeDVDR
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				Media is a DVD-R.
*/
extern NSString* const DRDeviceMediaTypeDVDR					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeDVDRW
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				Media is a DVD-RW.
*/
extern NSString* const DRDeviceMediaTypeDVDRW					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeDVDPlusRW
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				Media is a DVD+RW.
*/
extern NSString* const DRDeviceMediaTypeDVDPlusRW				AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const		DRDeviceMediaTypeUnknown
	@discussion	One of the possible values of the DRDeviceMediaTypeKey.
				The type of the media cannot be determined.
*/
extern NSString* const DRDeviceMediaTypeUnknown					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const DRDeviceMediaClassKey
	@discussion	A key for the dictionary for DRDeviceMediaInfoKey. The value of this key 
				is a NSString containing the class of media present in the drive.
*/
extern NSString* const DRDeviceMediaClassKey						AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const	DRDeviceMediaClassCD
	@discussion	One possible value of the DRDeviceMediaClassKey. Indicates the media
				is some type of CD based media.
*/
extern NSString* const DRDeviceMediaClassCD						AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const	DRDeviceMediaClassDVD
	@discussion	One possible value of the DRDeviceMediaClassKey. Indicates the media
				is some type of DVD based media.
*/
extern NSString* const DRDeviceMediaClassDVD						AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

/*!
	@const	DRDeviceMediaClassUnknown
	@discussion	One possible value of the DRDeviceMediaClassKey.  Indicates the media
				class is unknown.
*/
extern NSString* const DRDeviceMediaClassUnknown					AVAILABLE_MAC_OS_X_VERSION_10_2_AND_LATER;

