#ifndef SCONV_H
#define SCONV_H

/*-------------------------------------------*/
/* Integer type definitions for FatFs module */
/*-------------------------------------------*/

#ifdef _WIN32	/* FatFs development platform */

#include <windows.h>
#include <tchar.h>
typedef unsigned __int64 QWORD;


#else			/* Embedded platform */

/* These types MUST be 16-bit or 32-bit */
typedef int				INT;
typedef unsigned int	UINT;

/* This type MUST be 8-bit */
typedef unsigned char	BYTE;

/* These types MUST be 16-bit */
typedef short			SHORT;
typedef unsigned short	WORD;
typedef unsigned short	WCHAR;

/* These types MUST be 32-bit */
typedef long			LONG;
typedef unsigned long	DWORD;

/* This type MUST be 64-bit (Remove this for C89 compatibility) */
typedef unsigned long long QWORD;

#endif

#ifdef __cplusplus
extern "C" {
#endif

int sconv_gbk_to_unicode(const char* gbkstr, int slen, WCHAR* outbuf, int osize);
int sconv_unicode_to_gbk(const WCHAR* wstr, int wlen, char* outbuf, int osize);

//int sconv_utf8_to_unicode(const char* utf8str, int slen, WCHAR* outbuf, int osize);
//int sconv_unicode_to_utf8(const WCHAR* wstr, int wlen, char* outbuf, int osize);

#ifdef __cplusplus
}
#endif

#endif // SCONV_H
