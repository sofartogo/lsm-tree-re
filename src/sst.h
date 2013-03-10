/*
 * =============================================================================
 *
 *       Filename:  sst.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 08:05:10 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _SST_H
#define _SST_H

#include <pthread.h>
#include <stdint.h>
#include "meta.h"
#include "util.h"
#include "config.h"
#include "skiplist.h"

struct mutexer{
	volatile int lsn;
	pthread_mutex_t mutex;
};

struct sst_block{
	char key[NESSDB_MAX_KEY_SIZE];
	__be64 offset;
}__attribute__((packed));


struct sst {
	char basedir[FILE_PATH_SIZE];
	char name[FILE_NAME_SIZE];
	uint32_t lsn;
	struct meta *meta;
	struct bloom *bloom;
	struct mutexer mutexer;
};

struct sst *sst_new(const char *basedir);

void sst_merge(struct sst *sst, struct skiplist *list, int fromlog);

void sst_free(struct sst *sst);

uint64_t sst_getoff(struct sst *sst, struct slice *sk);
#endif
