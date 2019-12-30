/* This is a machine generated file, changes made here will
 * be removed then the source file is updated.
 */

#ifndef _APPLE_GRAPHICS_CONTROL_USER_COMMAND_H_
#define _APPLE_GRAPHICS_CONTROL_USER_COMMAND_H_

#ifdef KERNEL
#error This is a USERLAND header, dont load this in kernel code
#else
#if defined(_APPLE_GRAPHICS_CONTROL_COMMAND_H_)
#error You are loading a kernel header into USERLAND, dont.
#endif
#endif

#define APPLE_GRAPHICS_DEVICE_CONTOL_VERSION 0x205
#define APPLE_GRAPHICS_DEVICE_CONTROL_SERVICE "AppleGraphicsDeviceControl"

/* our magic attributes */

#define ATTRIBUTE_ONLINE        '!off'
#define ATTRIBUTE_SETMODE       'mset'
#define ATTRIBUTE_SETEDID       'edid'
#define ATTRIBUTE_DOCONTROL     'dctl'

#define kAGDCVendorCmdFlag      (1 << 31)

#define AGDC_EDID_BLOCKSIZE 128
/* You should use these macros to pack and unpack the
 * detailed timing structs.. UserCode should only be using
 * AGDCDetailedTimingInformation_t
 */
#define _AGDC_FIELD_COPY(src, dest, x)		dest->x = src->x
#define  _AGDC_CONVERT_(_src, tsrc, _dest, tdest)         \
   do {                                                 \
    tsrc *src = _src;                                   \
    tdest *dest = _dest;                                \
    dest = dest;                                        \
    src = src;                                          \
	_AGDC_FIELD_COPY(src, dest, horizontalScaledInset);	\
	_AGDC_FIELD_COPY(src, dest, verticalScaledInset);	\
	_AGDC_FIELD_COPY(src, dest, scalerFlags);           \
	_AGDC_FIELD_COPY(src, dest, horizontalScaled);		\
	_AGDC_FIELD_COPY(src, dest, verticalScaled);		\
	_AGDC_FIELD_COPY(src, dest, signalConfig);          \
	_AGDC_FIELD_COPY(src, dest, signalLevels);          \
	_AGDC_FIELD_COPY(src, dest, pixelClock);            \
	_AGDC_FIELD_COPY(src, dest, minPixelClock);         \
	_AGDC_FIELD_COPY(src, dest, maxPixelClock);         \
	_AGDC_FIELD_COPY(src, dest, horizontalActive);		\
	_AGDC_FIELD_COPY(src, dest, horizontalBlanking);	\
	_AGDC_FIELD_COPY(src, dest, horizontalSyncOffset);	\
	_AGDC_FIELD_COPY(src, dest, horizontalSyncPulseWidth);	\
	_AGDC_FIELD_COPY(src, dest, verticalActive);		\
	_AGDC_FIELD_COPY(src, dest, verticalBlanking);		\
	_AGDC_FIELD_COPY(src, dest, verticalSyncOffset);	\
	_AGDC_FIELD_COPY(src, dest, verticalSyncPulseWidth);\
	_AGDC_FIELD_COPY(src, dest, horizontalBorderLeft);	\
	_AGDC_FIELD_COPY(src, dest, horizontalBorderRight);	\
	_AGDC_FIELD_COPY(src, dest, verticalBorderTop);		\
	_AGDC_FIELD_COPY(src, dest, verticalBorderBottom);	\
	_AGDC_FIELD_COPY(src, dest, horizontalSyncConfig);	\
	_AGDC_FIELD_COPY(src, dest, horizontalSyncLevel);	\
	_AGDC_FIELD_COPY(src, dest, verticalSyncConfig);	\
	_AGDC_FIELD_COPY(src, dest, verticalSyncLevel);		\
	_AGDC_FIELD_COPY(src, dest, numLinks);              \
    } while (0)
#define CONVERT_AGDC_TO_OS_TIMING_DATA(src, dest)       _AGDC_CONVERT_(src, AGDCDetailedTimingInformation_t, dest, IODetailedTimingInformationV2)
#define CONVERT_OS_TO_AGDC_TIMING_DATA(src, dest)       _AGDC_CONVERT_(src, IODetailedTimingInformationV2, dest, AGDCDetailedTimingInformation_t)





















#pragma pack(push)
#pragma pack(1)















typedef enum {
    kAGDCVendorInfo             = 0x1,                  // may be called without a WL
    kAGDCVendorEnableController = 0x2,                  // may be called without a WL







    // 0x100 - 0x1ff PM = Power Management
    kAGDCPMInfo                 = 0x100,
    kAGDCPMStateCeiling         = 0x101,
    kAGDCPMStateFloor           = 0x102,
    kAGDCPMPState               = 0x103,
    kAGDCPMPowerLimit           = 0x104,
    
    // 0x600 – 0x6ff                                    Reserved
    
    // 0x700
    kAGDCFBPerFramebufferCMD   = 0x700,
    kAGDCFBOnline              = 0x701,
    kAGDCFBSetEDID             = 0x702,
    kAGDCFBSetMode             = 0x703,
    kAGDCFBInjectEvent         = 0x704,
    kAGDCFBDoControl           = 0x705,
    
    //
    // 0x800 – 0x8ff Reserved for common debug!!!
    //
    
    kAGDCMultiLinkConfig           = 0x920,
    kAGDCLinkConfig                = 0x921,
    



    
    
    kAGDCGPUCapability             = 0x980,                 // may be called without a WL
    kAGDCStreamAssociate           = 0x981,
    kAGDCStreamRequest             = 0x982,
    kAGDCStreamAccessI2C           = 0x983,
    kAGDCStreamAccessI2CCapability = 0x984,
    kAGDCStreamAccessAUX           = 0x985,
    kAGDCStreamGetEDID             = 0x986,
    kAGDCStreamSetState            = 0x987,
} kAGDCCommand_t;

typedef  enum {
    kAGDCVendorClassReserved             = 0,
    kAGDCVendorClassIntegratedGPU        = 1,
    kAGDCVendorClassDiscreteGPU          = 2,
    kAGDCVendorClassOtherHW              = 3,
    kAGDCVendorClassOtherSW              = 4,
    kAGDCVendorClassAppleGPUPolicyManager = 5,              // AGDCPolicy
    kAGDCVendorClassAppleGPUPowerManager = 6,               // AGPM
} kAGDCVendorClass_t;

typedef struct {
    uint32_t                        Version;
    char                            VendorString[32];
    uint32_t                        VendorID;
    kAGDCVendorClass_t              VendorClass;
} AGDCVendorInfo_t;

typedef struct {
    uint32_t                        enabled;
} AGDCVendorControllerEnable_t;

typedef struct {
    uint32_t                        port;                   // Port Number 1->n
    uint32_t                        stream;                 // 0 or MST address
} AGDCStreamAddress_t;

typedef struct {
    struct {
        uint64_t		portMap;
        uint64_t		MSTPortMap;
        uint64_t		ddcTransportMap;
        uint64_t		auxTransportMap;
        struct {
            uint32_t	DVI;
            uint32_t	DP;
            uint32_t	MST;
            uint32_t	maximum;
        }               numberOfStreams;
        uint32_t        numberOfFramebuffers;




        uint64_t        _reserved[9];                   // kernel is 64 bit, user is 32/64.. pointers are not safe!!!

        uint64_t		_reserved_a;
        uint64_t		_reserved_b;
        uint64_t		_reserved_c;
        uint64_t		_reserved_d;
    }                   gpu;
} AGDCGPUCapability_t;

typedef struct {
    int32_t                 id;
    AGDCStreamAddress_t	    address;                    // for GET this is an output, otherwise both are inputs to a driver
} AGDCStreamAssociate_t;

typedef struct {
    struct {
        AGDCStreamAddress_t address;                    // Input, a hint which ports are in the set we want to bind
    }                       link[4];
    int32_t                 id;                         // Ouput FB
    int32_t                 groupID;                    // Output preferred groupID (if any) -1 otherwise.
} AGDCStreamRequest_t;

typedef struct {
    AGDCStreamAddress_t     address;
    struct {
        uint16_t            device;
        uint16_t            speed;
        struct {
            uint16_t        length;
            uint8_t         buffer[256];
        }                   write;
        struct {
            uint16_t        length;
            uint8_t         buffer[256];
        }                   read;
        uint16_t            status;
    }                       i2c;
} AGDCStreamAccessI2C_t;

typedef struct {
    AGDCStreamAddress_t     address;
    struct {
        uint16_t            width;
        uint16_t            minSpeed;
        uint16_t            maxSpeed;
        uint16_t            burstSize;
    }                       i2c;
} AGDCStreamAccessI2CCapability_t;

typedef struct {
    AGDCStreamAddress_t     address;
    uint32_t				AuxRegister;
    struct {
        uint8_t             size;
        union {
            uint8_t         b[16];
            uint16_t		s[8];
            uint32_t		l[4];
        }                   data;
        uint16_t			status;
    }                       aux;
} AGDCStreamAccessAUX_t;


typedef struct {
    AGDCStreamAddress_t	address;
    uint32_t		block;
    uint8_t         data[128];      // 128
    uint32_t		status;
} AGDCStreamGetEDID_t;





typedef struct  {
    uint32_t      horizontalScaledInset;          // pixels
    uint32_t      verticalScaledInset;            // lines
    
    uint32_t      scalerFlags;
    uint32_t      horizontalScaled;
    uint32_t      verticalScaled;
    
    uint32_t      signalConfig;
    uint32_t      signalLevels;
    
    uint64_t      pixelClock;                     // Hz
    
    uint64_t      minPixelClock;                  // Hz - With error what is slowest actual clock
    uint64_t      maxPixelClock;                  // Hz - With error what is fasted actual clock
    
    uint32_t      horizontalActive;               // pixels
    uint32_t      horizontalBlanking;             // pixels
    uint32_t      horizontalSyncOffset;           // pixels
    uint32_t      horizontalSyncPulseWidth;       // pixels
    
    uint32_t      verticalActive;                 // lines
    uint32_t      verticalBlanking;               // lines
    uint32_t      verticalSyncOffset;             // lines
    uint32_t      verticalSyncPulseWidth;         // lines
    
    uint32_t      horizontalBorderLeft;           // pixels
    uint32_t      horizontalBorderRight;          // pixels
    uint32_t      verticalBorderTop;              // lines
    uint32_t      verticalBorderBottom;           // lines
    
    uint32_t      horizontalSyncConfig;
    uint32_t      horizontalSyncLevel;            // Future use (init to 0)
    uint32_t      verticalSyncConfig;
    uint32_t      verticalSyncLevel;              // Future use (init to 0)
    uint32_t      numLinks;
} AGDCDetailedTimingInformation_t;

typedef struct {
    int32_t                         id;
    AGDCStreamAddress_t             address;
    AGDCDetailedTimingInformation_t	timing;
    uint32_t                        horizontalOffset;
    uint32_t                        verticalOffset;
} AGDCStreamConfig_t;

typedef struct {
    AGDCStreamConfig_t                  link[4];
    struct {
        int32_t                         id;
        int32_t                         groupID;
        AGDCStreamAddress_t             address;
        AGDCDetailedTimingInformation_t	timing;
        uint32_t                        singleTiming;
    }                                   target;
    uint32_t                            valid;
} AGDCMultiLinkConfig_t;

typedef enum {
    kAGDCLinkConfigFlag_Online          = (1 << 0),
    kAGDCLinkConfigFlag_MayGroup        = (1 << 1),
    kAGDCLinkConfigFlag_IsFixed         = (1 << 2),
    kAGDCLinkConfigFlag_IsAssociated	= (1 << 3),
    kAGDCLinkConfigFlag_IsGrouped       = (1 << 4),
} AGDCLinkConfigFlags_t;

typedef enum {
    kAGDCStreamStateRelease     = 0,
    kAGDCStreamStateEnabled     = 1,
    kAGDCStreamStateInvalid     = 0x80000000,
} AGDCStreamState_t;

typedef struct {
    int32_t                         id;         // input framebuffer field
    int32_t                         groupID;	// output
    uint64_t                        flags;		// output, AGDCLinkConfigFlags_t
    AGDCDetailedTimingInformation_t timing;     // output, DetailedTiming
    AGDCStreamAddress_t             address;	// output, encoded PortNumber
    AGDCStreamState_t               state;      // output
} AGDCLinkConfig_t;

typedef void *    AGDCLinkAvailable_t __deprecated;

typedef enum {
    kAGDCRegisterLinkInsert             = 0,
    kAGDCRegisterLinkRemove             = 1,
    kAGDCRegisterLinkChange             = 2,
    kAGDCRegisterLinkChangeMST          = 3,
    kAGDCRegisterLinkFramebuffer        = 4,                                // V106+
    kAGDCRegisterLinkChangeWakeProbe	= 0x80,
} kAGDCRegisterLinkControlEvent_t;



typedef struct {                                                            // Deprecated in V203
} AGDCGetLinkMaster_t __deprecated;
typedef  AGDCGetLinkMaster_t AGDCRegisterLinkMaster_t __deprecated;

typedef struct {
    AGDCStreamAddress_t     address;
    AGDCStreamState_t       state;
} AGDCStreamSetState_t;

typedef struct {
    int32_t                 id;
    uint32_t                state;
} AGDCFBOnline_t;

typedef AGDCFBOnline_t kAppleAFBOnline_t   __deprecated;

typedef struct {
    int32_t                 id;
    uint32_t                modeID;
    uint32_t                width;
    uint32_t                height;
    uint32_t                depth;
    uint32_t                reserved[7];
} AGDCFBSetMode_t;

typedef AGDCFBSetMode_t    kAppleAFBSetMode_t __deprecated;

typedef struct {
    int32_t                 id;
    uint32_t                size;
    uint8_t                 data[2*128];
} AGDCEDID_t;

typedef AGDCEDID_t       kAppleAFBEdid_t __deprecated;

typedef struct {
    int32_t                 id;
    uint32_t                eventID;
} AGDCFBInjectEvent_t;

typedef AGDCFBInjectEvent_t    kAppleAFBinjectEvent_t __deprecated;

typedef struct {
    int32_t                 id;
    uint64_t                payload[4];
} AGDCFBDoControl_t;

typedef AGDCFBDoControl_t kAppleAFBdoControl_t __deprecated;

typedef struct {
    union {
        AGDCFBOnline_t          online;
        AGDCFBSetMode_t         mode;
        AGDCEDID_t              edid;
        AGDCFBInjectEvent_t     event;
        AGDCFBDoControl_t       control;
        AGDCStreamSetState_t    streamset;
    };
} AGDCFBCommandPacket_t __deprecated;

typedef AGDCFBCommandPacket_t kAppleAFBCommandPacket_t __deprecated;

typedef struct {
    uint32_t                    NumPStates;
    uint32_t                    NumPowerLimits;
    uint32_t                    ControlType;
} AGDCPMInfo_t;

typedef enum {
    kAGDCPMUpInterruptHint      = 0,
    kAGDCPMDownInterruptHint    = 1,
} kAGDCPMCallbackEvent_t;

typedef struct {
    uint32_t                    version;
    struct {
        uint32_t                currentPState;
        uint32_t                suggestedPState;
        uint32_t                coreBusyness;
        uint32_t                memoryBusyness;
        uint32_t                mclkFloor;
    }                           gpu;
} kAGDCPMCallbackInfo_t;

typedef struct {
    void *cookie;
    int (*handler)(
                    void *obj,
                    kAGDCPMCallbackEvent_t event,
                    kAGDCPMCallbackInfo_t *data);
} AGDCPMRegisterCallback_t;









#pragma pack(pop)


#endif
