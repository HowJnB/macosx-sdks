/*
 * Copyright (c) 1998-2001 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef _IOKIT_IO_SCSI_PRIMARY_COMMANDS_DEVICE_H_
#define _IOKIT_IO_SCSI_PRIMARY_COMMANDS_DEVICE_H_

#if defined(KERNEL) && defined(__cplusplus)

// Includes for standard IOKit definitions
#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>
#include <IOKit/IOReturn.h>
#include <IOKit/IOMemoryDescriptor.h>
#include <IOKit/IOSyncer.h>

// Includes for IOKit SCSI Command support definitions
#include <IOKit/scsi-commands/SCSICommandDefinitions.h>
#include <IOKit/scsi-commands/SCSIPrimaryCommands.h>
#include <IOKit/scsi-commands/SCSICmds_INQUIRY_Definitions.h>
#include <IOKit/scsi-commands/IOSCSIProtocolInterface.h>

enum
{
	kSCSIServicesNotification_Suspend	= 0x69000080,
	kSCSIServicesNotification_Resume	= 0x69000090
};

class IOSCSIPrimaryCommandsDevice : public IOSCSIProtocolInterface
{
	
	OSDeclareAbstractStructors ( IOSCSIPrimaryCommandsDevice )
	
private:
	
	SCSIPrimaryCommands *			fSCSIPrimaryCommandObject;

	IOSCSIProtocolInterface *		fProtocolDriver;
	
	// The fProtocolAccessEnabled member variable indicates whether
	// requests coming from the client can be sent to the device.
	// This will be set to true after the Protocol Service driver is successfully 
	// opened and before the call to InitializeDeviceSupport and set to false before 
	// TerminateDeviceSupport is called.
	bool							fProtocolAccessEnabled;

	// The fDeviceAccessEnabled member variable indicates whether
	// requests coming from the client can be sent to the device.
	// This will be set to true after InitializeDeviceSupport is called and
	// set to false before StopDeviceSupport is called.
	bool							fDeviceAccessEnabled;
	bool							fDeviceAccessSuspended;

	static void		TaskCallback ( SCSITaskIdentifier completedTask );
	
protected:
    // Reserve space for future expansion.
    struct IOSCSIPrimaryCommandsDeviceExpansionData { };
    IOSCSIPrimaryCommandsDeviceExpansionData *fIOSCSIPrimaryCommandsDeviceReserved;
	
	UInt8							fDefaultInquiryCount;
	OSDictionary *					fDeviceCharacteristicsDictionary;
	UInt32							fNumCommandsOutstanding;

	virtual void 					free ( void );

	// This flag is set if the device responds to a MODE_SENSE_10 command
	// with the page code set to 0x1A (Power Conditions Mode Page)
	bool							fDeviceSupportsPowerConditions;
	
	// This method will retreive the SCSI Primary Command Set object for
	// the class.  For subclasses, this will be overridden using a
	// dynamic cast on the base command set object of the subclass.
	virtual SCSIPrimaryCommands *	GetSCSIPrimaryCommandObject ( void );
	
	// This method is called by the start method to create all the command
	// objects needed by the class.  For subclasses, this will be overridden
	// to create its needed command set objects.
	virtual bool					CreateCommandSetObjects ( void );

	// This method is called by the free method to free all the command
	// objects needed by the class.  For subclasses, this will be overridden
	// to free its needed command set objects.
	virtual void					FreeCommandSetObjects ( void );
	
	// This method is called by the start method to obtain information from
	// the device with regards to whether it supports the power conditions mode page.
	virtual void					CheckPowerConditionsModePage ( void );
	
	// This will return back the Protocol driver that is used to
	// send service requests to the device.
	virtual IOSCSIProtocolInterface * GetProtocolDriver ( void );
	
	// This will get a new SCSITask for the caller
	virtual SCSITaskIdentifier		GetSCSITask ( void );
	
	// This will release a SCSITask (eventually return it to a pool)
	virtual void					ReleaseSCSITask ( SCSITaskIdentifier request );

	// Call for executing the command synchronously	
	SCSIServiceResponse 			SendCommand ( 	
										SCSITaskIdentifier 	request,
										UInt32 				timeoutDuration );
														
	// Call for executing the command asycnchronously	
	void 							SendCommand ( 
										SCSITaskIdentifier 	request,
										UInt32 				timeoutDuration,
										SCSITaskCompletion 	taskCompletion );
	

	virtual bool 					InitializeDeviceSupport ( void ) = 0;
	virtual void 					StartDeviceSupport ( void ) = 0;
	virtual void 					SuspendDeviceSupport ( void ) = 0;
	virtual void 					ResumeDeviceSupport ( void ) = 0;
	virtual void 					StopDeviceSupport ( void ) = 0;
	virtual void 					TerminateDeviceSupport ( void ) = 0;
	virtual UInt32					GetNumberOfPowerStateTransitions ( void ) = 0;
	
	virtual IOReturn				VerifyDeviceState ( void );
	// Called to clear any power-on/reset status in the drive
	virtual bool					ClearPowerOnReset ( void );
	virtual bool					ClearNotReadyStatus ( void ) = 0;

	bool							IsProtocolAccessEnabled ( void );
	bool							IsDeviceAccessEnabled ( void );
	bool							IsDeviceAccessSuspended ( void );

	bool							SetTaskAttribute ( 
										SCSITaskIdentifier 		request, 
										SCSITaskAttribute 		newAttribute );
	SCSITaskAttribute				GetTaskAttribute ( 
										SCSITaskIdentifier 		request );
	bool							SetTaskState ( 	
										SCSITaskIdentifier 		request,
										SCSITaskState 			newTaskState );
	SCSITaskState					GetTaskState ( 
										SCSITaskIdentifier 		request );
	bool							SetTaskStatus ( 
										SCSITaskIdentifier 		request, 
										SCSITaskStatus 			newStatus );
	SCSITaskStatus					GetTaskStatus ( 
										SCSITaskIdentifier 		request );
	bool							SetDataTransferDirection ( 
										SCSITaskIdentifier 		request, 
										UInt8 					newDirection );
	UInt8							GetDataTransferDirection ( 
										SCSITaskIdentifier 		request );
	bool							SetRequestedDataTransferCount (
										SCSITaskIdentifier 		request, 
										UInt64 					newRequestedCount );
	UInt64							GetRequestedDataTransferCount (
										SCSITaskIdentifier 		request );
	bool							SetRealizedDataTransferCount (
										SCSITaskIdentifier 		request,
										UInt64 					newRealizedDataCount );
	UInt64							GetRealizedDataTransferCount( 
										SCSITaskIdentifier 		request );
	bool							SetDataBuffer( 
										SCSITaskIdentifier 		request, 
										IOMemoryDescriptor * 	newBuffer );
	IOMemoryDescriptor *			GetDataBuffer( 
										SCSITaskIdentifier 		request );
	bool							SetTimeoutDuration( 
										SCSITaskIdentifier 		request, 
										UInt32 					newTimeout );
	UInt32							GetTimeoutDuration( 
										SCSITaskIdentifier 		request );
	bool							SetTaskCompletionCallback( 
										SCSITaskIdentifier 		request,
										SCSITaskCompletion 		newCallback );
	void							TaskCompletedNotification ( 
										SCSITaskIdentifier 		request );

	bool							SetServiceResponse( 
										SCSITaskIdentifier 		request,
										SCSIServiceResponse 	serviceResponse );
	SCSIServiceResponse 			GetServiceResponse( 
										SCSITaskIdentifier 		request );
	bool							SetAutosenseCommand(
										SCSITaskIdentifier 		request,
										UInt8					cdbByte0,
										UInt8					cdbByte1,
										UInt8					cdbByte2,
										UInt8					cdbByte3,
										UInt8					cdbByte4,
										UInt8					cdbByte5 );
	bool							GetAutoSenseData( 	
										SCSITaskIdentifier 		request,
										SCSI_Sense_Data * 		senseData );
	bool							SetApplicationLayerReference( 
										SCSITaskIdentifier 		request,
										void * 					newReferenceValue );
	void *							GetApplicationLayerReference( 
										SCSITaskIdentifier 		request );

	void 							IncrementOutstandingCommandsCount( void );
	static void						sIncrementOutstandingCommandsCount( 
										IOSCSIPrimaryCommandsDevice * self );
	virtual void					HandleIncrementOutstandingCommandsCount( void );
	
public:
	
	bool				init( OSDictionary * propTable );
	virtual bool		start( IOService * provider );
	virtual void		stop( IOService *  provider );
	virtual IOReturn 	message( UInt32 type, IOService *nub, void *arg );
	
	// The setAgressiveness method is called by the power manager
	// to notify us of certain power management settings. We override
	// this method in order to catch the kPMMinutesToSpinDown message
	// in order to set our idle timer.
	virtual IOReturn 	setAggressiveness( UInt32 type, UInt32 minutes );

	// Methods for getting device information strings
	virtual char *		GetVendorString( void );
	virtual char *		GetProductString( void );
	virtual char *		GetRevisionString( void );
	OSDictionary *		GetProtocolCharacteristicsDictionary ( void );
	OSDictionary *		GetDeviceCharacteristicsDictionary ( void );	
	
	// -- SCSI Protocol Interface Methods	--
    // The ExecuteCommand method will take a SCSI Task and transport
    // it across the physical wire(s) to the device
    virtual void    	ExecuteCommand( SCSITaskIdentifier request );
    
    // The AbortCommand method will abort the indicated SCSI Task,
    // if it is possible and the task has not already completed.
    virtual SCSIServiceResponse    AbortCommand( SCSITaskIdentifier request );
    
	// The IsProtocolServiceSupported will return true if the specified
	// feature is supported by the protocol layer.  If the service has a value that must be
	// returned, it will be returned in the serviceValue output parameter.
	virtual bool		IsProtocolServiceSupported( SCSIProtocolFeature feature, void * serviceValue );

	// The HandleProtocolServiceFeature will return true if the specified feature could
	// be handled properly by the protocol layer.
	virtual bool		HandleProtocolServiceFeature( SCSIProtocolFeature feature, void * serviceValue );
	
	// Utility methods for use by all peripheral device objects.
	inline bool 		IsMemoryDescriptorValid(
    						IOMemoryDescriptor * 		dataBuffer );
	
	inline bool 		IsMemoryDescriptorValid(
							IOMemoryDescriptor * 		dataBuffer,
							UInt64						requiredSize );
	
	// SCSI Primary command implementations
	virtual bool		CHANGE_DEFINITION(
							SCSITaskIdentifier			request,
							IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit 			SAVE,
							SCSICmdField7Bit 			DEFINITION_PARAMETER,
							SCSICmdField1Byte 			PARAMETER_DATA_LENGTH,
			 				SCSICmdField1Byte 			CONTROL );
      
	virtual bool		COMPARE(
							SCSITaskIdentifier			request,
							IOMemoryDescriptor 			*dataBuffer,
	 						SCSICmdField1Bit 			PAD,
    						SCSICmdField3Byte 			PARAMETER_LIST_LENGTH,
    						SCSICmdField1Byte 			CONTROL );
            
	virtual bool	    COPY(
							SCSITaskIdentifier			request,
   							IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField1Bit 			PAD,
    						SCSICmdField3Byte 			PARAMETER_LIST_LENGTH,
    						SCSICmdField1Byte 			CONTROL );
      
	virtual bool	    COPY_AND_VERIFY(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField1Bit 			BYTCHK,
    						SCSICmdField1Bit 			PAD,
    						SCSICmdField3Byte 			PARAMETER_LIST_LENGTH,
    						SCSICmdField1Byte 			CONTROL );

	virtual bool		EXTENDED_COPY(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField4Byte 			PARAMETER_LIST_LENGTH,
    						SCSICmdField1Byte 			CONTROL );
	
	virtual bool	    INQUIRY(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField1Bit 			CMDDT,
    						SCSICmdField1Bit 			EVPD,
    						SCSICmdField1Byte 			PAGE_OR_OPERATION_CODE,
    						SCSICmdField1Byte 			ALLOCATION_LENGTH, 
    						SCSICmdField1Byte 			CONTROL );

	virtual bool	    LOG_SELECT(
							SCSITaskIdentifier			request,
							IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit 			PCR,
							SCSICmdField1Bit 			SP,
							SCSICmdField2Bit 			PC,
							SCSICmdField2Byte 			PARAMETER_LIST_LENGTH,
							SCSICmdField1Byte 			CONTROL );  

    virtual bool	    LOG_SENSE(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField1Bit 			PPC,
    						SCSICmdField1Bit 			SP,
    						SCSICmdField2Bit 			PC,
    						SCSICmdField6Bit 			PAGE_CODE,
    						SCSICmdField2Byte 			PARAMETER_POINTER,
    						SCSICmdField2Byte 			ALLOCATION_LENGTH, 
    						SCSICmdField1Byte 			CONTROL );  

    virtual bool	    MODE_SELECT_6(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField1Bit 			PF,
    						SCSICmdField1Bit 			SP,
    						SCSICmdField1Byte 			PARAMETER_LIST_LENGTH, 
    						SCSICmdField1Byte 			CONTROL );  

   	virtual bool	    MODE_SELECT_10(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField1Bit 			PF,
    						SCSICmdField1Bit 			SP,
    						SCSICmdField2Byte 			PARAMETER_LIST_LENGTH, 
    						SCSICmdField1Byte 			CONTROL );  

   	virtual bool	    MODE_SENSE_6(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField1Bit 			DBD,
	   						SCSICmdField2Bit 			PC,
	   						SCSICmdField6Bit 			PAGE_CODE,
	   						SCSICmdField1Byte 			ALLOCATION_LENGTH,
    						SCSICmdField1Byte 			CONTROL );

   	virtual bool	    MODE_SENSE_10(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField1Bit 			LLBAA,
    						SCSICmdField1Bit 			DBD,
	   						SCSICmdField2Bit 			PC,
	   						SCSICmdField6Bit 			PAGE_CODE,
	   						SCSICmdField2Byte 			ALLOCATION_LENGTH,
    						SCSICmdField1Byte 			CONTROL );

  	virtual bool	    PERSISTENT_RESERVE_IN(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
	   						SCSICmdField5Bit 			SERVICE_ACTION,
	   						SCSICmdField2Byte 			ALLOCATION_LENGTH,
    						SCSICmdField1Byte 			CONTROL );

   	virtual bool	    PERSISTENT_RESERVE_OUT(
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
	   						SCSICmdField5Bit 			SERVICE_ACTION,
	   						SCSICmdField4Bit 			SCOPE,
	   						SCSICmdField4Bit 			TYPE,
    						SCSICmdField1Byte 			CONTROL );

    virtual bool	    PREVENT_ALLOW_MEDIUM_REMOVAL( 
							SCSITaskIdentifier			request,
	     					SCSICmdField2Bit 			PREVENT, 
    						SCSICmdField1Byte 			CONTROL );

	virtual bool		READ_BUFFER( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
    						SCSICmdField4Bit 			MODE,
							SCSICmdField1Byte 			BUFFER_ID,
							SCSICmdField3Byte 			BUFFER_OFFSET,
							SCSICmdField3Byte 			ALLOCATION_LENGTH, 
    						SCSICmdField1Byte 			CONTROL );

	virtual bool		RECEIVE( 
							SCSITaskIdentifier			request,
							IOMemoryDescriptor 			*dataBuffer,
		 					SCSICmdField3Byte 			TRANSFER_LENGTH,
    						SCSICmdField1Byte 			CONTROL );

	virtual bool		RECEIVE_DIAGNOSTICS_RESULTS( 
							SCSITaskIdentifier			request,
							IOMemoryDescriptor 			*dataBuffer,
		 					SCSICmdField1Bit 			PCV,
		 					SCSICmdField1Byte			PAGE_CODE,
		 					SCSICmdField2Byte 			ALLOCATION_LENGTH,
    						SCSICmdField1Byte 			CONTROL );

	virtual bool		RELEASE_6( 
							SCSITaskIdentifier			request,
							SCSICmdField1Byte 			CONTROL );

	virtual bool		RELEASE_6( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit 			EXTENT,
							SCSICmdField1Byte 			RESERVATION_IDENTIFICATION,
							SCSICmdField1Byte 			CONTROL );

	virtual bool		RELEASE_10( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit 			THRDPTY,
							SCSICmdField1Bit 			LONGID,
							SCSICmdField1Byte 			THIRD_PARTY_DEVICE_ID,
							SCSICmdField2Byte 			PARAMETER_LIST_LENGTH,
							SCSICmdField1Byte 			CONTROL );

	virtual bool		RELEASE_10( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit 			THRDPTY,
							SCSICmdField1Bit 			LONGID,
							SCSICmdField1Bit 			EXTENT,
							SCSICmdField1Byte 			RESERVATION_IDENTIFICATION,
							SCSICmdField1Byte 			THIRD_PARTY_DEVICE_ID,
							SCSICmdField2Byte 			PARAMETER_LIST_LENGTH,
							SCSICmdField1Byte 			CONTROL );

	virtual bool		REPORT_DEVICE_IDENTIFIER( 
							SCSITaskIdentifier			request,
							IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField4Byte 			ALLOCATION_LENGTH,
							SCSICmdField1Byte 			CONTROL );

   	virtual bool		REPORT_LUNS( 
							SCSITaskIdentifier			request,
   							IOMemoryDescriptor 			*dataBuffer,
				   			SCSICmdField4Byte 			ALLOCATION_LENGTH,
				   			SCSICmdField1Byte 			CONTROL );
    
	virtual bool	    REQUEST_SENSE(
							SCSITaskIdentifier			request,
   							IOMemoryDescriptor 			*dataBuffer,
			    			SCSICmdField1Byte 			ALLOCATION_LENGTH, 
			    			SCSICmdField1Byte 			CONTROL );
 	
 	virtual bool		RESERVE_6( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Byte 			CONTROL );

 	virtual bool		RESERVE_6( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit 			EXTENT,
							SCSICmdField1Byte 			RESERVATION_IDENTIFICATION,
							SCSICmdField2Byte 			PARAMETER_LIST_LENGTH,
							SCSICmdField1Byte 			CONTROL );

	virtual bool		RESERVE_10( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit 			THRDPTY,
							SCSICmdField1Bit 			LONGID,
							SCSICmdField1Byte 			THIRD_PARTY_DEVICE_ID,
							SCSICmdField2Byte 			PARAMETER_LIST_LENGTH,
							SCSICmdField1Byte 			CONTROL );

	virtual bool		RESERVE_10( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit 			THRDPTY,
							SCSICmdField1Bit 			LONGID,
							SCSICmdField1Bit 			EXTENT,
							SCSICmdField1Byte 			RESERVATION_IDENTIFICATION,
							SCSICmdField1Byte 			THIRD_PARTY_DEVICE_ID,
							SCSICmdField2Byte 			PARAMETER_LIST_LENGTH,
							SCSICmdField1Byte 			CONTROL );

	virtual bool		SEND( 
							SCSITaskIdentifier			request,
							IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField1Bit			AER,
		 					SCSICmdField3Byte 			TRANSFER_LENGTH,
    						SCSICmdField1Byte 			CONTROL );

  	virtual bool		SEND_DIAGNOSTICS( 
							SCSITaskIdentifier			request,
    						IOMemoryDescriptor 			*dataBuffer,
				  		 	SCSICmdField3Bit 			SELF_TEST_CODE,
				  		 	SCSICmdField1Bit 			PF,
				  		 	SCSICmdField1Bit 			SELF_TEST,
				  		 	SCSICmdField1Bit 			DEVOFFL,
				  		 	SCSICmdField1Bit 			UNITOFFL,
				  	 		SCSICmdField2Byte 			PARAMETER_LIST_LENGTH,
				  	 		SCSICmdField1Byte 			CONTROL );

	virtual bool		SET_DEVICE_IDENTIFIER( 
							SCSITaskIdentifier			request,
							IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField5Bit 			SERVICE_ACTION,
							SCSICmdField4Byte 			PARAMETER_LIST_LENGTH,
							SCSICmdField1Byte 			CONTROL );
    
    virtual bool	    TEST_UNIT_READY(  
							SCSITaskIdentifier			request,
	    					SCSICmdField1Byte 			CONTROL );
 
	virtual bool		WRITE_BUFFER( 
							SCSITaskIdentifier			request,
	    					IOMemoryDescriptor 			*dataBuffer,
							SCSICmdField4Bit 			MODE,
							SCSICmdField1Byte 			BUFFER_ID,
							SCSICmdField3Byte 			BUFFER_OFFSET,
							SCSICmdField3Byte 			PARAMETER_LIST_LENGTH,
							SCSICmdField1Byte 			CONTROL );

private:
	// Space reserved for future expansion.
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 1 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 2 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 3 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 4 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 5 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 6 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 7 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 8 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 9 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 10 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 11 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 12 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 13 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 14 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 15 );
    OSMetaClassDeclareReservedUnused( IOSCSIPrimaryCommandsDevice, 16 );
};

#endif	/* defined(KERNEL) && defined(__cplusplus) */

#endif /* _IOKIT_IO_SCSI_PRIMARY_COMMANDS_DEVICE_H_ */