/*
 * =============================================================================
 *
 *       Filename:  skiplist.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 08:31:34 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#include <stdint.h>
#include "config.h"

#define MAXLEVEL (15)

typedef enum {ADD, DEL} OPT;

struct skipnode{
	char key[NESSDB_MAX_KEY_SIZE];
	uint64_t val;
	unsigned opt:24;
	struct skipnode *forward[1];
	struct skipnode *next;
};

struct skiplist {
	int count;
	int size;
	int level;
	char pool_embedded[1024];
	struct skipnode *hdr;
	struct pool *pool;
};

struct skiplist *skiplist_new();

int skiplist_notfull(struct skiplist *list);
int skiplist_insert(struct skiplist * list, char *key, uint64_t val, OPT opt);

void skiplist_free(struct skiplist *list);

int skiplist_insert_node(struct skiplist *list, struct skipnode *node);

struct skipnode *skiplist_lookup(struct skiplist *list, char *data);
#endif
