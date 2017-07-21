// cc sizeof.c && ./a.out
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned char buf[4];
	long n = 0xdeadbeef12345678;
	int i;

	printf("buf:%d, long:%d\n", sizeof(buf), sizeof(long));
	memcpy(buf, &n, sizeof(n));
	for (i = 0 ; i < sizeof(buf) ; i++) {
		printf("%02x\n", buf[i]);
	}

	return 0;
}

