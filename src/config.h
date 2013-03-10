/*
 * =============================================================================
 *
 *       Filename:  config.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 05:36:57 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef __CONFIG_H
#define __CONFIG_H

#define MTBL_MAX_COUNT (6000000) /* max count in memtable */
#define FILE_PATH_SIZE (1024) /* file full path */
#define FILE_NAME_SIZE (256) /* file name size */
#define NESSDB_MAX_KEY_SIZE (24) /* max key size */
#define META_MAX_COUNT (10000) /* max meta count */
#define LOG_BUFFER_SIZE (2048) /* log buffer size */
#define SST_MAX_COUNT (65536) /* one sst's max count entries */

#endif
