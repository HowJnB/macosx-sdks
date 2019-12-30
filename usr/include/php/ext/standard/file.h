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
   +----------------------------------------------------------------------+
*/

/* $Id: file.h,v 1.1.1.5 2001/12/14 22:13:20 zarzycki Exp $ */

/* Synced with php 3.0 revision 1.30 1999-06-16 [ssb] */

#ifndef FILE_H
#define FILE_H

PHP_MINIT_FUNCTION(file);
PHP_MSHUTDOWN_FUNCTION(file);

PHP_FUNCTION(tempnam);
PHP_NAMED_FUNCTION(php_if_tmpfile);
PHP_NAMED_FUNCTION(php_if_fopen);
PHP_FUNCTION(fclose);
PHP_FUNCTION(popen);
PHP_FUNCTION(pclose);
PHP_FUNCTION(feof);
PHP_FUNCTION(fread);
PHP_FUNCTION(fgetc);
PHP_FUNCTION(fgets);
PHP_FUNCTION(fscanf);
PHP_FUNCTION(fgetss);
PHP_FUNCTION(fgetcsv);
PHP_FUNCTION(fwrite);
PHP_FUNCTION(fflush);
PHP_FUNCTION(rewind);
PHP_FUNCTION(ftell);
PHP_FUNCTION(fseek);
PHP_FUNCTION(mkdir);
PHP_FUNCTION(rmdir);
PHP_FUNCTION(fpassthru);
PHP_FUNCTION(readfile);
PHP_FUNCTION(umask);
PHP_FUNCTION(rename);
PHP_FUNCTION(unlink);
PHP_FUNCTION(copy);
PHP_FUNCTION(file);
PHP_FUNCTION(set_socket_blocking); /* deprecated */
PHP_FUNCTION(socket_set_blocking);
PHP_FUNCTION(socket_set_timeout);
PHP_FUNCTION(socket_get_status);
PHP_FUNCTION(set_file_buffer);
PHP_FUNCTION(get_meta_tags);
PHP_FUNCTION(flock);
PHP_FUNCTION(fd_set);
PHP_FUNCTION(fd_isset);
PHP_FUNCTION(select);
#if (!defined(PHP_WIN32) && !defined(__BEOS__) && HAVE_REALPATH) || defined(ZTS)
PHP_FUNCTION(realpath);
#endif
PHP_NAMED_FUNCTION(php_if_ftruncate);
PHP_NAMED_FUNCTION(php_if_fstat);

/* temporary function for testing streams */
PHP_FUNCTION(fopenstream);

PHPAPI int php_set_sock_blocking(int socketd, int block);
PHPAPI int php_file_le_fopen(void);
PHPAPI int php_file_le_stream(void);
PHPAPI int php_file_le_popen(void);
PHPAPI int php_file_le_socket(void);
PHPAPI int php_copy_file(char *src, char *dest TSRMLS_DC);

#define META_DEF_BUFSIZE 8192

typedef enum _php_meta_tags_token {
	TOK_EOF = 0,
	TOK_OPENTAG,
	TOK_CLOSETAG,
	TOK_SLASH,
	TOK_EQUAL,
	TOK_SPACE,
	TOK_ID,
	TOK_STRING,
	TOK_OTHER
} php_meta_tags_token;

typedef struct _php_meta_tags_data {
  FILE *fp;
  int socketd;
  int issock;
  int ulc;
  int lc;
  char *input_buffer;
  char *token_data;
  int token_len;
  int in_meta;
} php_meta_tags_data;

php_meta_tags_token php_next_meta_token(php_meta_tags_data *);

typedef struct {
  int fgetss_state;
  int pclose_ret;
  HashTable ht_fsock_keys;
  HashTable ht_fsock_socks;
  struct php_sockbuf *phpsockbuf;
  size_t def_chunk_size;
} php_file_globals;

#ifdef ZTS
#define FG(v) TSRMG(file_globals_id, php_file_globals *, v)
extern int file_globals_id;
#else
#define FG(v) (file_globals.v)
extern php_file_globals file_globals;
#endif


#endif /* FILE_H */

