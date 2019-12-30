/* CoreGraphics - CGBase.h
 * Copyright (c) 2000 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGBASE_H_
#define CGBASE_H_

#ifdef __cplusplus
#  define CG_EXTERN_C_BEGIN extern "C" {
#  define CG_EXTERN_C_END   }
#else
#  define CG_EXTERN_C_BEGIN
#  define CG_EXTERN_C_END
#endif

CG_EXTERN_C_BEGIN

#if defined(__WIN32__)
#  if defined(CG_BUILDING_CG)
#    define CG_EXTERN __declspec(dllexport) extern
#  else
#    define CG_EXTERN __declspec(dllimport) extern
#  endif
#  if defined(CG_DEBUG)
#    define CG_PRIVATE_EXTERN CG_EXTERN
#  else
#    define CG_PRIVATE_EXTERN extern
#  endif
#endif

#if !defined(CG_EXTERN)
#  define CG_EXTERN extern
#endif

#if !defined(CG_PRIVATE_EXTERN)
#  define CG_PRIVATE_EXTERN __private_extern__
#endif

#if !defined(CG_INLINE)
#  if defined(__GNUC__)
#    define CG_INLINE static __inline__
#  elif defined(__MWERKS__) || defined(__cplusplus)
#    define CG_INLINE static inline
#  else
#    define CG_INLINE static    
#  endif
#endif

#if !defined(__GNUC__) && !defined(__MWERKS__)
#  define __attribute__(attribute)
#endif

CG_EXTERN_C_END

#endif	/* CGBASE_H_ */
