/*
 * =============================================================================
 *
 *       Filename:  index.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 05:32:06 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _INDEX_H
#define _INDEX_H 

#include <pthread.h>
#include "skiplist.h"
#include "util.h"

struct idx_park {
	struct skiplist *list;
	int lsn;
};

struct index {
	int lsn;
	int db_rfd;
	int meta_lsn;
	int bg_merge_count;
	int mtbl_add_count;
	int mtbl_rem_count;
	int max_mtbl;
	int max_mtbl_size;
	uint64_t bloom_hits;

	char basedir[FILE_PATH_SIZE];
	char name[FILE_NAME_SIZE];
	struct log *log;
	struct sst *sst;
	struct skiplist *list;
	struct idx_park *park;
	pthread_attr_t attr;
	pthread_mutex_t merge_mutex;
};

struct index *index_new(const char *basedir, int max_mtbl_size, int tolog);

int index_add(struct index *idx, struct slice *sk, struct slice *sv);

void index_free(struct index* idx);

int index_get(struct index *idx, struct slice *sk, struct slice *sv);
#endif
