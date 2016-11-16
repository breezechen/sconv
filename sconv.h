#ifndef SCONV_H
#define SCONV_H

typedef unsigned short  wchar;

#ifdef __cplusplus
extern "C" {
#endif

int sconv_gbk_to_unicode(const char *gbkstr, int slen, wchar *outbuf, int osize);
int sconv_unicode_to_gbk(const wchar *wstr, int wlen, char *outbuf, int osize);

int sconv_utf8_to_unicode(const char *utf8str, int slen, wchar *outbuf, int osize);
int sconv_unicode_to_utf8(const wchar *wstr, int wlen, char *outbuf, int osize);

#ifdef __cplusplus
}
#endif

#endif // SCONV_H
