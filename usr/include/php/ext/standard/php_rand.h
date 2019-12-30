/*
   +----------------------------------------------------------------------+
   | PHP version 4.0                                                      |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2001 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.02 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://www.php.net/license/2_02.txt.                                 |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Rasmus Lerdorf <rasmus@lerdorf.on.ca>                       |
   |          Zeev Suraski <zeev@zend.com>                                |
   |          Pedro Melo <melo@ip.pt>                                     |
   |                                                                      |
   | Based on code from: Shawn Cokus <Cokus@math.washington.edu>          |
   +----------------------------------------------------------------------+
 */
/* $Id: php_rand.h,v 1.1.1.3 2001/07/19 00:20:20 zarzycki Exp $ */

#ifndef PHP_RAND_H
#define	PHP_RAND_H

#include <stdlib.h>

#ifndef RAND_MAX
#define RAND_MAX (1<<15)
#endif

#if HAVE_LRAND48
#define PHP_RAND_MAX 2147483647
#else
#define PHP_RAND_MAX RAND_MAX
#endif

/* Define rand Function wrapper */
#ifdef HAVE_RANDOM
#define php_rand() random()
#else
#ifdef HAVE_LRAND48
#define php_rand() lrand48()
#else
#define php_rand() rand()
#endif
#endif

/* Define srand Function wrapper */
#ifdef HAVE_SRANDOM
#define php_srand(seed) srandom((unsigned int)seed)
#else
#ifdef HAVE_SRAND48
#define php_srand(seed) srand48((long)seed)
#else
#define php_srand(seed) srand((unsigned int)seed)
#endif
#endif

#endif	/* PHP_RAND_H */
