#ifndef SCONV_H
#define SCONV_H

typedef unsigned short  wchar;

#ifdef __cplusplus
extern "C" {
#endif

// @slen: string lenth, in characters. 
//        if this parameter is -1, the function processes the entire input string, 
//          excluding the terminating null character. 
// @osize: the size of outbuf, in bytes.
// return : if outbuf is null, return needed buf size, in bytes.
//          otherwise return the size of converted data filled in outbuf, in bytes.
int sconv_gbk_to_unicode(const char *gbkstr, int slen, wchar *outbuf, int osize);

// @wlen: string len of wstr, in characters.
int sconv_unicode_to_gbk(const wchar *wstr, int wlen, char *outbuf, int osize);

int sconv_utf8_to_unicode(const char *utf8str, int slen, wchar *outbuf, int osize);
int sconv_unicode_to_utf8(const wchar *wstr, int wlen, char *outbuf, int osize);

#ifdef __cplusplus
}
#endif

#endif // SCONV_H
