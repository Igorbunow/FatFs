/******************************************************************************/
/**
@file		log.h
@author
@date		Mar, 2021
@brief      Lod library header.
@details	This header contains logging macro and functions
*/
/******************************************************************************/

#if !defined(LOG_H_)
#define LOG_H_

#if defined(__cplusplus)
extern "C" {
#endif

//#define DEBUG_PRINT

#define LOG_LEVEL_MAX    	4
#define LOG_LEVEL_HIGH   	3
#define LOG_LEVEL_MIDDLE 	2
#define LOG_LEVEL_LOW    	1
#define LOG_LEVEL_ERR_ONLY  0

#ifdef DEBUG_PRINT
	#define DEBUG_PRINT_(LOG_LEVEL, TYPE, LEN, ...)	fprintf(stderr, "\n %s : %s:%d: %s()", TYPE, __FILE__, __LINE__, __func__); \
												fprintf(stderr,  __VA_ARGS__)
#else //DEBUG_PRINT
	#define DEBUG_PRINT_(LOG_LEVEL, TYPE, LEN, ...)
#endif //DEBUG_PRINT



#if defined(__cplusplus)
}
#endif

#endif /* LOG_H_ */
