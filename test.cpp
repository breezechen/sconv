#include <stdio.h>
#include "sconv.h"

int main(int argc, char** argv)
{
    const char* p= "我是中文12345";
	int size = sconv_gbk_to_unicode(p, -1, NULL, 0);
	WCHAR* unicode_str = new WCHAR[size / 2 + 1];
	size = sconv_gbk_to_unicode(p, -1, unicode_str, size);
	unicode_str[size / 2] = 0;

    for (int i = 0; i < size / 2; i++)
    {
        printf("unicode: %x\n", unicode_str[i]);
    }

	printf("\n\n");

	size = sconv_unicode_to_gbk(unicode_str, -1, NULL, 0);
	char* ansi_str = new char[size + 1];
	size = sconv_unicode_to_gbk(unicode_str, -1, ansi_str, size);
	ansi_str[size] = 0;
	printf("%s\n", ansi_str);
	for (int i = 0; i < size; i++)
	{
		printf("ansi hex: %x\n", (unsigned char)ansi_str[i]);
	}
}