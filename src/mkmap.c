#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define G2U_ARRAY "gbk_2_uni_tab"
#define U2G_ARRAY "uni_2_gbk_tab"
#define MAX_LEN 65535   // 2字节最大数
static unsigned short g2u_arr[MAX_LEN] = { 0 };
static unsigned short u2g_arr[MAX_LEN] = { 0 };

// 源文件
#define SRC "gbkuni30.txt"

// 生产的头文件
#define DST "gbkuni30.h"

int make_charmap_gb18030()
{
	char buffer[16] = { 0 };
	char* p = NULL;
	FILE* fp_c = NULL;
	FILE* fp = NULL;
	int len = 0;
	int x1 = 0;
	int x2 = 0;
	int i = 0;
	int g2u_max_num = 0, u2g_max_num = 0;
	int cnt = 0;

	fp = fopen(SRC, "r");
	if (fp == NULL)
	{
		printf("open fileerror!!\n");
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	printf("file len: %d\n", len);

	fp_c = fopen(DST, "w+");
	if (fp_c == NULL)
	{
		printf("open fileerror!!\n");
		return -1;
	}

	fprintf(fp_c, "/*********************************************************************************/\n");
	fprintf(fp_c, "/*                         GBK(GB18030) to UNICODE table                         */\n");
	fprintf(fp_c, "/*                                                                               */\n");
	fprintf(fp_c, "/*                        %s   %s                                 */\n", __DATE__, __TIME__);
	fprintf(fp_c, "/* The source file from:                                                         */\n");
	fprintf(fp_c, "/*http://icu-project.org/repos/icu/data/trunk/charset/source/gb18030/gbkuni30.txt*/\n");

	fprintf(fp_c, "/**********************************************************************************/\n");

	fprintf(fp_c, "#ifndef __GBK2UNICODE__H\n");
	fprintf(fp_c, "#define __GBK2UNICODE__H\n\n");

	while (fgets(buffer, 32, fp) != NULL)
	{
		sscanf(buffer, "%x:%x\n", &x1, &x2);

		//printf("%s",buffer);
		//printf("%04x %x\n",x1, x2);
		//fprintf(fp_c, "0x%04x,0x%x,\n", x1, x2);
		g2u_arr[x2] = x1;
		if (x2 > g2u_max_num)
			g2u_max_num = x2;
		u2g_arr[x1] = x2;
		if (x1 > u2g_max_num)
			u2g_max_num = x1;
	}


	fprintf(fp_c, "\n");
	fprintf(fp_c, "static unsigned short %s[] =\n{\n", G2U_ARRAY);

	for (i = cnt = 0; i < g2u_max_num + 1; i++)
	{
		//printf("0x%04x\n",big_buffer[i]);
		fprintf(fp_c, "0x%04x,", g2u_arr[i]);
		cnt++;
		if (cnt % 10 == 0)
		{
			fprintf(fp_c, "   // line num %d \n", cnt / 10 - 1);
		}
	}
	fprintf(fp_c, "\n");
	fprintf(fp_c, "};\n\n");

	fprintf(fp_c, "\n");
	fprintf(fp_c, "static unsigned short %s[] =\n{\n", U2G_ARRAY);

	for (i = cnt = 0; i < u2g_max_num + 1; i++)
	{
		//printf("0x%04x\n",big_buffer[i]);
		fprintf(fp_c, "0x%04x,", u2g_arr[i]);
		cnt++;
		if (cnt % 10 == 0)
		{
			fprintf(fp_c, "   // line num %d \n", cnt / 10 - 1);
		}
	}
	fprintf(fp_c, "\n");
	fprintf(fp_c, "};\n\n");

	fprintf(fp_c, "#endif//__GBK2UNICODE__H\n");
	fprintf(stdout, "Job done!\n");

	fclose(fp);
	fclose(fp_c);

	return 0;
}

int main(int argc, char** argv)
{
	make_charmap_gb18030();
	return 0;
}