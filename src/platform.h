/*
 * =============================================================================
 *
 *       Filename:  platform.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/13/2012 10:09:57 PM
 *       Revision:  r1
 *       Compiler:  gcc (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5
 *
 *         Author:  Wang Wei (sofartogo), wangwei881116@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _PLATFORM_H
#define _PLATFORM_H

#ifndef O_BINARY 
#define O_BINARY (0)
#endif


//#if defined(__linux__)
//#define open open64
//#define lseek lseek64
//#define fstat fstat64
//#define LSM_CREAT_FLAGS (O_RDWR | O_TRUNC | O_CREAT | O_BINARY | O_LARGEFILE)
//#define LSM_OPEN_FLAGS (O_RDWR | O_BINARY | O_LARGEFILE)
//#else 
//#define open64 open 
#define LSM_CREAT_FLAGS (O_RDWR | O_TRUNC | O_CREAT | O_BINARY)
#define LSM_OPEN_FLAGS (O_RDWR | O_BINARY)
//#endif 

#endif
