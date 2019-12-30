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
   | Authors: Stig Venaas <venaas@uninett.no>                             |
   +----------------------------------------------------------------------+
 */
/* $Id: php_network.h,v 1.1.1.2 2001/07/19 00:20:38 zarzycki Exp $ */

#ifndef _PHP_NETWORK_H
#define _PHP_NETWORK_H

#ifdef PHP_WIN32
# ifndef WINNT
#  define WINNT 1
# endif
# undef FD_SETSIZE
# include "arpa/inet.h"
# define socklen_t unsigned int
#endif

#ifdef HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif



int php_hostconnect(char *host, unsigned short port, int socktype, int timeout);
PHPAPI int php_connect_nonb(int sockfd, struct sockaddr *addr, socklen_t addrlen, struct timeval *timeout);

#endif /* _PHP_NETWORK_H */

/*
 * Local variables:
 * tab-width: 8
 * c-basic-offset: 8
 * End:
 */
