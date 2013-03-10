/*
 * =============================================================================
 *
 *       Filename:  log.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 08:46:23 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _LOG_H
#define _LOG_H

#include <stdint.h>
#include "skiplist.h"
#include "util.h"
#include "config.h"

struct log{
	int idx_wfd;
	int db_wfd;
	int islog;
	uint64_t db_alloc;
	char name[FILE_PATH_SIZE];
	char basedir[FILE_PATH_SIZE];
	char log_old[FILE_PATH_SIZE];
	char log_new[FILE_PATH_SIZE];
	struct buffer *buf;
	struct buffer *db_buf;
};


struct log *log_new(const char *basedir, int sln, int islog);

void log_next(struct log *l, int lsn);

uint64_t log_append(struct log *log, struct slice *sk, struct slice *sv);

void log_remove(struct log *log, int lsn);

void log_free(struct log *log);

int log_recovery(struct log *log, struct skiplist *list);

#endif
