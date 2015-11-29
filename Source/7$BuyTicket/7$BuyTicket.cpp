#include "stdafx.h"
#include "windows.h"
#include "cstdlib"
//#include "resource.h"
int val(char *data)
{
	char temp[9];
	sprintf(temp,"%8s",data);
	return atoi(temp);
}
void myMain()
{
	int Money = 7;
	char price[4] = "7";
	char inputCount[4] = "0";

	printf("Hello! now you have money: %d\n",Money);
	
	printf("Please buy more than one tickets for me!\n\n");
	printf("How many tickets do you want to buy? \n");
	printf("Ticket price: %d\n", atol(price));
	
	scanf("%s", &inputCount);
	printf("\nTicket price: %d\n", val(price));
	printf("You want to buy %d tickets.\n", val(inputCount));

	if (val(inputCount) *val(price) > Money)
		printf("You don't have enough money!\n");
	else if (val(price) != 1)
		printf("You need to cheat me and set the price to $1\n");
	else 
		printf("Ok! you are the 7$ hacker!\n");

	system("PAUSE");
}

