#include "sconv.h"
#include "gbkuni30.h"

int sconv_gbk_to_unicode(const char *gbkstr, int slen, WCHAR *outbuf, int osize)
{
	int ret = -1;
	int cnt = 0, i = 0, cb;
	const unsigned char *p = gbkstr;
	WCHAR *op = outbuf;
	unsigned char c1;
	WCHAR c, chr;

	do {
		if (gbkstr == 0) {
			break;
		}
		if (slen < 0) {
			slen = 0;
			while (*p++) {
				++slen;
			}
			p = gbkstr;
		}
		while (i < slen) {
			c1 = *p;
			if (c1 < 0x80) {
				chr = c1;
				cb = 1;
			}
			else {
				if (i + 1 >= slen) {
					break;
				}
				c = c1 << 8 | *(p + 1);
				chr = gbk_2_uni_tab[c];
				if (0 == chr) {
					chr = '?';
				}
				cb = 2;
			}

			i += cb;
			p += cb;

			if (op) {
				if (cnt + 2 <= osize) {
					*op++ = chr;
				}
				else {
					break;
				}
			}
			cnt += 2;
		}
		ret = cnt;
	} while (0);

	return ret;
}

int sconv_unicode_to_gbk(const WCHAR *wstr, int wlen, char *outbuf, int osize)
{
	int ret = -1;
	int cnt = 0, i, cb;
	const WCHAR *p = wstr;
	char *op = outbuf;
	WCHAR c, chr;

	do {
		if (0 == wstr) {
			break;
		}
		if (wlen < 0) {
			wlen = 0;
			while (*p++) {
				++wlen;
			}
			p = wstr;
		}
		for (i = 0; i < wlen; ++i, ++p) {
			c = *p;
			if (c < 0x80) {
				cb = 1;
				chr = c;
			}
			else {
				chr = uni_2_gbk_tab[c];
				if (0 == chr) {
					chr = '?';
				}
				cb = 2;
			}
			if (op) {
				if (cnt + cb <= osize) {
					if (cb == 1) {
						*op++ = (char)chr;
					}
					else {
// 						if (0x81 && chr >= 0x100) {
// 							*op++ = (char)(chr >> 8);
// 						}
						*op++ = (char)(chr >> 8);
						*op++ = (char)chr;
					}
				}
				else {
					break;
				}
			}
			cnt += cb;
		}
		ret = cnt;
	} while (0);
	return ret;
}