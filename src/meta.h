/*
 * =============================================================================
 *
 *       Filename:  meta.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 08:15:01 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _META_H
#define _META_H

#include <stdint.h>
#include <pthread.h>

#include "skiplist.h"
#include "util.h"
#include "config.h"

#define META_NODE_SIZE sizeof(struct meta_node)

struct meta_node{
	char end[NESSDB_MAX_KEY_SIZE];
	char index_name[FILE_NAME_SIZE];
	uint32_t count;
	uint32_t lsn;
};

struct meta {
	uint32_t sn;
	uint32_t size;
	struct meta_node nodes[META_MAX_COUNT];
};

struct meta *meta_new();

void meta_set(struct meta *meta, struct meta_node *node);

void meta_set_byname(struct meta *meta, struct meta_node *node);

void meta_free(struct meta *meta);

struct meta_node *meta_get(struct meta *meta, char *key);
#endif
