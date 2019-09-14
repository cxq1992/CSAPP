#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hex_to_num(char hex)
{
	if (hex >= '0' && hex <= '9')
	{
		return hex - '0';
	}
	if (hex >= 'a' && hex <= 'f')
	{
		return hex - 'a' + 10;
	}
	if (hex >= 'A' && hex <= 'F')
	{
		return hex - 'A' + 10;
	}
	return -1;
}
void hex2dd(char * hex_num)
{
	int len = strlen(hex_num);
	if (len != 10)
	{
		fprintf(stderr, "Invalid hex num: %s", hex_num);
		exit(-1);
	}
	char dd[16] = { '\0' };
	int i = 2;
	int offset = 0;
	while (i < len)
	{
		int tmp = hex_to_num(hex_num[i++]);
		if (tmp == -1)
		{
			fprintf(stderr, "Invalid hex_num: %s", hex_num);
			exit(-1);
		}
		tmp <<= 4;
		int tmp_2 = hex_to_num(hex_num[i++]);
		if (tmp_2 == -1)
		{
			fprintf(stderr, "Invalid hex_num: %s", hex_num);
			exit(-1);
		}
		tmp |= tmp_2;
		offset += sprintf(dd + offset, "%d.", tmp);
		//printf("%d", tmp);
	}
	printf("%s", dd);
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: hex2dd hex_num ...");
		return -1;
	}
	for (int i = 1; i < argc; ++i)
	{
		hex2dd(argv[i]);
	}
}