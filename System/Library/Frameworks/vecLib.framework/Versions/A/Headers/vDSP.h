/*
     File:       vecLib/vDSP.h
 
     Contains:   AltiVec DSP Interfaces
 
     Version:    vecLib-1.1_8~32
 
     Copyright:  � 2000-2001 by Apple Computer, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/
#ifndef __VDSP__
#define __VDSP__

#ifndef __CORESERVICES__
#include <CoreServices/CoreServices.h>
#endif



#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if PRAGMA_STRUCT_ALIGN
    #pragma options align=mac68k
#elif PRAGMA_STRUCT_PACKPUSH
    #pragma pack(push, 2)
#elif PRAGMA_STRUCT_PACK
    #pragma pack(2)
#endif

struct DSPComplex {
  float               real;
  float               imag;
};
typedef struct DSPComplex               DSPComplex;
struct DSPSplitComplex {
  float *             realp;
  float *             imagp;
};
typedef struct DSPSplitComplex          DSPSplitComplex;
typedef struct OpaqueFFTSetup*          FFTSetup;
typedef SInt32 FFTDirection;
enum {
  kFFTDirection_Forward         = 1,
  kFFTDirection_Inverse         = -1
};

typedef SInt32 FFTRadix;
enum {
  kFFTRadix2                    = 0,
  kFFTRadix3                    = 1,
  kFFTRadix5                    = 2
};

/*
�������������������������������������������������������������������������������
    The criteria to invoke the PowerPC vector implementation is subject to     
    change and become less restrictive in the future.                          
�������������������������������������������������������������������������������
*/
/*
�������������������������������������������������������������������������������
    Functions create_fftsetup and destroy_fftsetup.

    create_fftsetup will allocate memory and setup a weight array used by      
    the FFT. The call destroy_fftsetup will free the array.                    
�������������������������������������������������������������������������������
*/
/*
 *  create_fftsetup()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern FFTSetup 
create_fftsetup(
  UInt32     log2n,
  FFTRadix   radix);


/*
 *  destroy_fftsetup()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
destroy_fftsetup(FFTSetup setup);




/*
�������������������������������������������������������������������������������
    Functions ctoz and ztoc.
    
    ctoz converts a complex array to a complex-split array
    ztoc converts a complex-split array to a complex array
    
    Criteria to invoke PowerPC vector code:    
        1. size > 3
        2. strideC = 2
        3. strideZ = 1
        4. Z.realp and Z.imagp are relatively aligned.
        5. C is 8-byte aligned if Z.realp and Z.imagp are 4-byte- aligned
           or C is 16-byte aligned if Z.realp and Z.imagp are at least
           8-byte aligned.
�������������������������������������������������������������������������������
*/
/*
 *  ctoz()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
ctoz(
  const DSPComplex   C[],
  SInt32             strideC,
  DSPSplitComplex *  Z,
  SInt32             strideZ,
  UInt32             size);


/*
 *  ztoc()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
ztoc(
  const DSPSplitComplex *  Z,
  SInt32                   strideZ,
  DSPComplex               C[],
  SInt32                   strideC,
  UInt32                   size);




/*
�������������������������������������������������������������������������������
    Functions fft_zip and fft_zipt 
    
    In-place Split Complex Fourier Transform with or without temporary memory.
            
      Criteria to invoke PowerPC vector code:    
        
        1. ioData.realp and ioData.imagp must be 16-byte aligned.
        2. stride = 1
        3. 2 <= log2n <= 20
        4. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  Direction can be either
      kFFTDirection_Forward or kFFTDirection_Inverse.
�������������������������������������������������������������������������������
*/
/*
 *  fft_zip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft_zip(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             stride,
  UInt32             log2n,
  FFTDirection       direction);


/*
 *  fft_zipt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft_zipt(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             stride,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2n,
  FFTDirection       direction);




/*
�������������������������������������������������������������������������������
     Functions fft_zop and fft_zopt
     
     Out-of-place Split Complex Fourier Transform with or without temporary
     memory
            
      Criteria to invoke PowerPC vector code:  
        
        1. signal.realp and signal.imagp must be 16-byte aligned.
        2. signalStride = 1
        3. result.realp and result.imagp must be 16-byte aligned.
        4. strideResult = 1
        5. 2 <= log2n <= 20
        6. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  Direction can be either
      kFFTDirection_Forward or kFFTDirection_Inverse.
�������������������������������������������������������������������������������
*/
/*
 *  fft_zop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft_zop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             log2n,
  FFTDirection       direction);


/*
 *  fft_zopt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft_zopt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2n,
  FFTDirection       direction);




/*
�������������������������������������������������������������������������������
    Functions fft_zrip and fft_zript
    
    In-Place Real Fourier Transform with or without temporary memory,
    split Complex Format
            
      Criteria to invoke PowerPC vector code:    
        1. ioData.realp and ioData.imagp must be 16-byte aligned.
        2. stride = 1
        3. 3 <= log2n <= 13
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  Direction can be either
      kFFTDirection_Forward or kFFTDirection_Inverse.
�������������������������������������������������������������������������������
*/
/*
 *  fft_zrip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft_zrip(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             stride,
  UInt32             log2n,
  FFTDirection       direction);


/*
 *  fft_zript()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft_zript(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             stride,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2n,
  FFTDirection       direction);




/*
�������������������������������������������������������������������������������
    Functions fft_zrop and fft_zropt
    
    Out-of-Place Real Fourier Transform with or without temporary memory,
    split Complex Format
            
      Criteria to invoke PowerPC vector code:  
        1. signal.realp and signal.imagp must be 16-byte aligned.
        2. signalStride = 1
        3. result.realp and result.imagp must be be 16-byte aligned.
        4. strideResult = 1
        5. 3 <= log2n <= 13
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  Direction can be either
      kFFTDirection_Forward or kFFTDirection_Inverse.
�������������������������������������������������������������������������������
*/
/*
 *  fft_zrop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft_zrop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             log2n,
  FFTDirection       direction);


/*
 *  fft_zropt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft_zropt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2n,
  FFTDirection       direction);




/*
�������������������������������������������������������������������������������
    Functions fft2d_zip and fft2d_zipt
    
    In-place two dimensional Split Complex Fourier Transform with or without
    temporary memory
            
      Criteria to invoke PowerPC vector code:  
        1. ioData.realp and ioData.imagp must be 16-byte aligned.
        2. strideInRow = 1;
        3. strideInCol must be a multiple of 4
        4. 2 <= log2nInRow <= 12
        5. 2 <= log2nInCol <= 12
        6. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  ( log2n = log2nInRow + log2nInCol ) 
      Direction can be either kFFTDirection_Forward or kFFTDirection_Inverse.
�������������������������������������������������������������������������������
*/
/*
 *  fft2d_zip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft2d_zip(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             strideInRow,
  SInt32             strideInCol,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  FFTDirection       direction);


/*
 *  fft2d_zipt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft2d_zipt(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             strideInRow,
  SInt32             strideInCol,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  FFTDirection       direction);




/*
�������������������������������������������������������������������������������
    Functions fft2d_zop and fft2d_zopt
    
    Out-of-Place two dimemsional Split Complex Fourier Transform with or
    without temporary memory
            
      Criteria to invoke PowerPC vector code:  
        
        1. signal.realp and signal.imagp must be 16-byte aligned.
        2. signalStrideInRow = 1;
        3. signalStrideInCol must be a multiple of 4
        4. result.realp and result.imagp must be 16-byte aligned.
        5. strideResultInRow = 1;
        6. strideResultInCol must be a multiple of 4
        7. 2 <= log2nInRow <= 12
        8. 2 <= log2nInCol <= 12
        9. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.

      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  ( log2n = log2nInRow + log2nInCol ) 
      Direction can be either kFFTDirection_Forward or kFFTDirection_Inverse.
�������������������������������������������������������������������������������
*/
/*
 *  fft2d_zop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft2d_zop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStrideInRow,
  SInt32             signalStrideInCol,
  DSPSplitComplex *  result,
  SInt32             strideResultInRow,
  SInt32             strideResultInCol,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  SInt32             flag);


/*
 *  fft2d_zopt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft2d_zopt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStrideInRow,
  SInt32             signalStrideInCol,
  DSPSplitComplex *  result,
  SInt32             strideResultInRow,
  SInt32             strideResultInCol,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  SInt32             flag);




/*
�������������������������������������������������������������������������������
    Functions fft2d_zrip and fft2d_zript
    
    In-place two dimensional Real Fourier Transform with or without temporary
    memory, Split Complex Format
            
      Criteria to invoke PowerPC vector code:  
        1. ioData.realp and ioData.imagp must be 16-byte aligned.
        2. strideInRow = 1;
        3. strideInCol must be a multiple of 4
        4. 3 <= log2nInRow <= 12
        5. 3 <= log2nInCol <= 13
        6. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.

      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  ( log2n = log2nInRow + log2nInCol ) 
      Direction can be either kFFTDirection_Forward or kFFTDirection_Inverse.
�������������������������������������������������������������������������������
*/
/*
 *  fft2d_zrip()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft2d_zrip(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             strideInRow,
  SInt32             strideInCol,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  FFTDirection       direction);


/*
 *  fft2d_zript()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft2d_zript(
  FFTSetup           setup,
  DSPSplitComplex *  ioData,
  SInt32             strideInRow,
  SInt32             strideInCol,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  FFTDirection       direction);




/*
�������������������������������������������������������������������������������
    Functions fft2d_zrop and fft2d_zropt
    
    Out-of-Place Two-Dimemsional Real Fourier Transform with or without
    temporary memory, Split Complex Format
            
      Criteria to invoke PowerPC vector code:  
        1. signal.realp and signal.imagp must be 16-byte aligned.
        2. signalStrideInRow = 1;
        3. signalStrideInCol must be a multiple of 4
        4. result.realp and result.imagp must be 16-byte aligned.
        5. strideResultInRow = 1;
        6. strideResultInCol must be a multiple of 4
        7. 3 <= log2nInRow <= 12
        8. 3 <= log2nInCol <= 13
        9. bufferTemp.realp and bufferTemp.imagp must be 16-byte aligned.

      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The size of temporary memory for each part
      is the lower value of 4*n and 16k.  ( log2n = log2nInRow + log2nInCol ) 
      Direction can be either kFFTDirection_Forward or kFFTDirection_Inverse.
�������������������������������������������������������������������������������
*/
/*
 *  fft2d_zrop()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft2d_zrop(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStrideInRow,
  SInt32             signalStrideInCol,
  DSPSplitComplex *  result,
  SInt32             strideResultInRow,
  SInt32             strideResultInCol,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  SInt32             flag);


/*
 *  fft2d_zropt()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
fft2d_zropt(
  FFTSetup           setup,
  DSPSplitComplex *  signal,
  SInt32             signalStrideInRow,
  SInt32             signalStrideInCol,
  DSPSplitComplex *  result,
  SInt32             strideResultInRow,
  SInt32             strideResultInCol,
  DSPSplitComplex *  bufferTemp,
  UInt32             log2nInCol,
  UInt32             log2nInRow,
  SInt32             flag);




/*
�������������������������������������������������������������������������������
    Function conv
    
    Floating Point Convolution and Correlation
      
      Criteria to invoke PowerPC vector code:  
        1. signal and result must have relative alignement.
        2. 4 <= lenFilter <= 256
        3. lenResult > 36
        4. signalStride = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  strideFilter can be positive for
      correlation or negative for convolution.
�������������������������������������������������������������������������������
*/
/*
 *  conv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
conv(
  const float   signal[],
  SInt32        signalStride,
  const float   filter[],
  SInt32        strideFilter,
  float         result[],
  SInt32        strideResult,
  SInt32        lenResult,
  SInt32        lenFilter);




/*
�������������������������������������������������������������������������������
    Function vadd
    
    Floating Point Add
    
      Criteria to invoke PowerPC vector code:  
        1. input1 and input2 and result are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  vadd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vadd(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  float         result[],
  SInt32        strideResult,
  UInt32        size);




/*
�������������������������������������������������������������������������������
    Function vsub
    
     Floating Point Substract
      
      Criteria to invoke PowerPC vector code:  
        1. input1 and input2 and result are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  vsub()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vsub(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  float         result[],
  SInt32        strideResult,
  UInt32        size);




/*
�������������������������������������������������������������������������������
    Function vmul
    
    Floating Point Multiply
    
      Criteria to invoke PowerPC vector code:  
        1. input1 and input2 and result must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  vmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vmul(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  float         result[],
  SInt32        strideResult,
  UInt32        size);




/*
�������������������������������������������������������������������������������
    Function vsmul
    
    Floating Point - Scalar Multiply
    
      Criteria to invoke PowerPC vector code:  
        1. input1 and result are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  vsmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vsmul(
  const float    input1[],
  SInt32         stride1,
  const float *  input2,
  float          result[],
  SInt32         strideResult,
  UInt32         size);




/*
�������������������������������������������������������������������������������
    Function vsq
    
    Floating Point Square
      
      Criteria to invoke PowerPC vector code:  
        1. input and result are relatively aligned.
        2. size >= 8
        3. strideInput = 1
        4. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  vsq()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vsq(
  const float   input[],
  SInt32        strideInput,
  float         result[],
  SInt32        strideResult,
  UInt32        size);




/*
�������������������������������������������������������������������������������
    Function vssq
    
    Floating Point Signed Square
      
      Criteria to invoke PowerPC vector code:  
        1. input and result must be all relatively aligned.
        2. size >= 8
        3. strideInput = 1
        4. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  vssq()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vssq(
  const float   input[],
  SInt32        strideInput,
  float         result[],
  SInt32        strideResult,
  UInt32        size);




/*
�������������������������������������������������������������������������������
    Function dotpr
    
    Floating Point Dot product
    
      Criteria to invoke PowerPC vector code:  
        1. input1 and input2 are relatively aligned.
        2. size >= 20
        3. stride1 = 1
        4. stride2 = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  dotpr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
dotpr(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  float *       result,
  UInt32        size);




/*
�������������������������������������������������������������������������������
    Function vam
    
    Floating Point vadd and Multiply
    
      Criteria to invoke PowerPC vector code:  
        1. input1, input2, input_3 and result are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. stride_3 = 1
        6. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  vam()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
vam(
  const float   input1[],
  SInt32        stride1,
  const float   input2[],
  SInt32        stride2,
  const float   input3[],
  SInt32        stride3,
  float         result[],
  SInt32        strideResult,
  UInt32        size);




/*
�������������������������������������������������������������������������������
    Function zconv
    
    Split Complex Convolution and Correlation
      
      Criteria to invoke PowerPC vector code:  
        1. signal->realp, signal->imagp, result->realp, result->imagp
           must be relatively aligned.
        2. 4 <= lenFilter <= 128
        3. lenResult > 20
        4. signalStride = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  strideFilter can be positive for correlation
      or negative for convolution
�������������������������������������������������������������������������������
*/
/*
 *  zconv()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zconv(
  DSPSplitComplex *  signal,
  SInt32             signalStride,
  DSPSplitComplex *  filter,
  SInt32             strideFilter,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  SInt32             lenResult,
  SInt32             lenFilter);




/*
�������������������������������������������������������������������������������
    Function zvadd
    
    Split Complex vadd
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp,
           result.realp, result.imagp must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zvadd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zvadd(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size);




/*
�������������������������������������������������������������������������������
    Function zvsub
    
    Split Complex Substract
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp,
           result.realp, result.imagp must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zvsub()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zvsub(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size);




/*
�������������������������������������������������������������������������������
    Function zvmul
    
    Split Complex Multiply
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp,
           result.realp, result.imagp must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1

      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.  The conjugate value can be 1 or -1.
�������������������������������������������������������������������������������
*/
/*
 *  zvmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zvmul(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size,
  SInt32             conjugate);




/*
�������������������������������������������������������������������������������
    Function zdotpr
    
    Split Complex Dot product
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp are all
           relatively aligned.
        2. size >= 20
        3. stride1 = 1
        4. stride2 = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zdotpr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zdotpr(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  UInt32             size);




/*
�������������������������������������������������������������������������������
    Function zidotpr
    
    Split Complex Inner Dot product
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp must be
           all relatively aligned.
        2. size >= 20
        3. stride1 = 1
        4. stride2 = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zidotpr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zidotpr(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  result,
  UInt32             size);




/*
�������������������������������������������������������������������������������
    Function zrdotpr
    
    Split Complex - Real Dot product
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2 are must be relatively aligned.
        2. size >= 16
        3. stride1 = 1
        4. stride2 = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zrdotpr()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zrdotpr(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  const float        input2[],
  SInt32             stride2,
  DSPSplitComplex *  result,
  UInt32             size);




/*
�������������������������������������������������������������������������������
    Function zvcma
    
    Split Complex Conjugate Multiply And vadd
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2.realp, input2.imagp,
          input_3.realp, input_3.imagp, result.realp, result.imagp
          must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. stride_3 = 1
        6. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zvcma()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zvcma(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  DSPSplitComplex *  input2,
  SInt32             stride2,
  DSPSplitComplex *  input3,
  SInt32             stride3,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size);




/*
�������������������������������������������������������������������������������
    Function zrvadd
    
    Split Complex - Real Add
      
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2, result.realp, result.imagp
           are all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zrvadd()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zrvadd(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  const float        input2[],
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size);




/*
�������������������������������������������������������������������������������
    Function zrvsub
    
    Split Complex - Real Substract
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2, result.realp, result.imagp
           must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zrvsub()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zrvsub(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  const float        input2[],
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size);




/*
�������������������������������������������������������������������������������
    Function zrvmul
    
    Split Complex - Real Multiply
    
      Criteria to invoke PowerPC vector code:  
        1. input1.realp, input1.imagp, input2, result.realp, result.imagp
           must be all relatively aligned.
        2. size >= 8
        3. stride1 = 1
        4. stride2 = 1
        5. strideResult = 1
      
      If any of the above criteria are not satisfied, the PowerPC scalor code
      implementation will be used.
�������������������������������������������������������������������������������
*/
/*
 *  zrvmul()
 *  
 *  Availability:
 *    Mac OS X:         in version 10.0 and later in vecLib.framework
 *    CarbonLib:        not in Carbon, but vecLib is compatible with Carbon
 *    Non-Carbon CFM:   in vecLib 1.0 and later
 */
extern void 
zrvmul(
  DSPSplitComplex *  input1,
  SInt32             stride1,
  const float        input2[],
  SInt32             stride2,
  DSPSplitComplex *  result,
  SInt32             strideResult,
  UInt32             size);





#ifndef USE_NONE_APPLE_STANDARD_DATATYPES
#define USE_NONE_APPLE_STANDARD_DATATYPES 1
#endif  /* !defined(USE_NONE_APPLE_STANDARD_DATATYPES) */

#if USE_NONE_APPLE_STANDARD_DATATYPES
enum {
  FFT_FORWARD                   = kFFTDirection_Forward,
  FFT_INVERSE                   = kFFTDirection_Inverse
};

enum {
  FFT_RADIX2                    = kFFTRadix2,
  FFT_RADIX3                    = kFFTRadix3,
  FFT_RADIX5                    = kFFTRadix5
};


typedef DSPComplex                      COMPLEX;
typedef DSPSplitComplex                 COMPLEX_SPLIT;
#endif  /* USE_NONE_APPLE_STANDARD_DATATYPES */


#if PRAGMA_STRUCT_ALIGN
    #pragma options align=reset
#elif PRAGMA_STRUCT_PACKPUSH
    #pragma pack(pop)
#elif PRAGMA_STRUCT_PACK
    #pragma pack()
#endif

#ifdef __cplusplus
}
#endif

#endif /* __VDSP__ */

