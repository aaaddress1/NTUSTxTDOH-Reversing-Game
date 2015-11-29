#include <iostream>

int main()
{
	char n[] = "KEY=sexy&!know!t";

	int val = 0;
	int extr = 0;
	printf("Len: %lu\n" , strlen(n));
	for (int i = 0; i < strlen(n); ++i)
	{
		val += n[i] * i + extr;
		extr += (val%10) +( val/10);
	}

	printf("%d\n" , val);
	// 26216b6e
	printf("%d" , *(int*)(n+0) ^ 0x3d59454b);//KEY=
	printf("%d" , *(int*)(n+4) ^ 0x79786573);//sexy
	printf("%d" , *(int*)(n+8) ^ 0x6E6B2126);//&!kn
	printf("%d" , *(n+0x0C) ^ 'o');
	printf("%d" , *(n+0x0E) ^ '!');
	return 0;
}