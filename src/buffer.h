/*
 * =============================================================================
 *
 *       Filename:  buffer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 10:19:39 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _BUF_H
#define _BUF_H

#include <stdint.h>

struct buffer {
	char *buf;
	int NUL;
	int buflen;
};

struct buffer *buffer_new(size_t reserve);

void buffer_clear(struct buffer *b);

void buffer_putint(struct buffer *b, int val);

void buffer_putnstr(struct buffer *b, const char *str, size_t n);

void buffer_putlong(struct buffer *b, uint64_t val);

char *buffer_detach(struct buffer *b);

void buffer_free(struct buffer *b);


uint32_t u32_from_big(unsigned char *buf);

uint64_t u64_from_big(unsigned char *buf);


#endif

