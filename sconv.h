#ifndef SCONV_H
#define SCONV_H

/*-------------------------------------------*/
/* Integer type definitions for FatFs module */
/*-------------------------------------------*/

typedef unsigned short	WCHAR;

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
