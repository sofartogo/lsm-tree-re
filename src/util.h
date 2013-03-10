/*
 * =============================================================================
 *
 *       Filename:  util.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 04:32:27 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _UTIL_H
#define _UTIL_H
#include <stdint.h>
#ifdef _WIN32
#include <winsock.h>
#else 
#include <arpa/inet.h>
#define O_BINARY 0
#endif

#define FILE_ERR(a) (a == -1)

#ifdef __CHECKER__ 
#define FORCE __attribute__((force))
#else 
#define FORCE 
#endif 

#ifdef __CHECKER__
#define BITWISE __attribute__((bitwise))
#else 
#define BITWISE 
#endif

typedef uint16_t BITWISE __be16;
typedef uint32_t BITWISE __be32;
typedef uint64_t BITWISE __be64;

static inline __be32 to_be32(uint32_t x)
{
	return (FORCE __be32) htonl(x);
}

static inline __be64 to_be64(uint64_t x)
{
#if (BYTE_ORDER == LITTLE_ENDIAN)
	return (FORCE __be64) (((uint64_t) htonl((uint32_t) x) << 32) | 
			htonl((uint32_t) (x >>32)));
#else 
	return (FORCE __be64) x;
#endif
}

static inline uint32_t from_be32(__be32 x)
{
	return ntohl((FORCE uint32_t) x);
}
static inline uint64_t from_be64(__be64 x)
{
#if (BYTE_ORDER == LITTLE_ENDIAN)
	return ((uint64_t) ntohl((uint32_t)(FORCE uint64_t) x) << 32) |
			ntohl((uint32_t) ((FORCE uint64_t) x >> 32));
#else 
	return (FORCE uint64_t) x;
#endif
}

struct slice{
	char* data;
	int len;
};

void ensure_dir_exists(const char *path);

#endif
