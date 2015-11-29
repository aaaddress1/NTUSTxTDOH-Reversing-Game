#include "stdafx.h"
#include "windows.h"
#include "cstdlib"
//#include "resource.h"

int MyMain()
{
	char data[8] = "Hello!";
	char name[8];

	printf("what's your name?\n");
	scanf("%s", name);
	printf("%s %s\n", data, name);

	if (strcmp(data, "admin"))
		printf("yee!\n");
	else
		printf("WoW! Welcome!\n");

	system("PAUSE");
	return 0;
}

