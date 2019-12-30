/*
 *  Saturn.h
 *  Saturn
 *  Created by Andrew Pinski on Mon Dec 16 2002.
 *
 *  Copyright (c) 2002-2003 Apple Computer, Inc., all rights reserved.
 *
 */

#ifndef __cplusplus
#include <stdbool.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void startSaturn (void);
void stopSaturn (void);
void initSaturn (const char *path, bool full, bool usePMCs, int pmcNumber, int pmcEvent);


#ifdef __cplusplus
}
#endif