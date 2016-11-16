#include <stdio.h>
#include "sconv.h"

int main(int argc, char** argv)
{
    const char* p= "【我a是b中文】(1234)5《很多汉字》★{，。} ※┠╂◎☆§№";
	int size = sconv_gbk_to_unicode(p, -1, NULL, 0);
	WCHAR* unicode_str = new WCHAR[size / 2 + 1];
	size = sconv_gbk_to_unicode(p, -1, unicode_str, size);
	unicode_str[size / 2] = 0;

	printf("unicode: \n");
    for (int i = 0, cnt = 0; i < size / 2; i++, cnt++)
    {
        printf("%04x ", unicode_str[i]);
		if (cnt % 8 == 7) {
			printf("\n");
		}
    }
	printf("\n\n");

	size = sconv_unicode_to_gbk(unicode_str, -1, NULL, 0);
	char* ansi_str = new char[size + 1];
	size = sconv_unicode_to_gbk(unicode_str, -1, ansi_str, size);
	ansi_str[size] = 0;
	printf("ansi: %s\n", ansi_str);
	for (int i = 0, cnt = 0; i < size; i++, cnt++)
	{
		printf("%02x ", (unsigned char)ansi_str[i]);
		if (cnt % 16 == 15) {
			printf("\n");
		}
	}
	printf("\n\n");

	size = sconv_unicode_to_utf8(unicode_str, -1, NULL, 0);
	char* utf8_str = new char[size + 1];
	size = sconv_unicode_to_utf8(unicode_str, -1, utf8_str, size);
	utf8_str[size] = 0;
	printf("utf8: \n");
	for (int i = 0, cnt = 0; i < size; i++, cnt++)
	{
		printf("%02x ", (unsigned char)utf8_str[i]);
		if (cnt % 16 == 15) {
			printf("\n");
		}
	}
	printf("\n\n");

	size = sconv_utf8_to_unicode(utf8_str, -1, NULL, 0);
	WCHAR* unicode = new WCHAR[size / 2 + 1];
	size = sconv_utf8_to_unicode(utf8_str, -1, unicode, size);
	unicode[size / 2] = 0;
	printf("unicode: \n");
	for (int i = 0, cnt = 0; i < size / 2; i++, cnt++)
	{
		printf("%04x ", unicode[i]);
		if (cnt % 8 == 7) {
			printf("\n");
		}
	}
	printf("\n\n");
}