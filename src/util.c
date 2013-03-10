/*
 * =============================================================================
 *
 *       Filename:  util.c
 *
 *    Description:  
 *
 *        Version:  0.0.1
 *        Created:  12/13/2012 06:02:24 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

static void _portable_mkdir(const char *path)
{
#ifdef _WIN32
	_mkdir(path);
#else 
	mkdir(path, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH);
#endif
}

static void _mkdirs(const char *path)
{
	char tmp[256] = {0};
	char *p = NULL;
	size_t len;
	snprintf(tmp, sizeof tmp, "%s", path);
	len = strlen(tmp);
	if (tmp[len-1] == '/') {
		tmp[len-1] = 0;
	}
	for (p = tmp + 1; *p; p++) {
		if (*p == '/') {
			*p = 0;
			_portable_mkdir(tmp);
			*p = '/';
		}
	}
	_portable_mkdir(tmp);
}

void ensure_dir_exists(const char *path)
{
	struct stat st;
	if (stat(path, &st) != 0) {
		_mkdirs(path);
	}
}
