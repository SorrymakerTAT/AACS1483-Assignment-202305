/*File:PCD Assignment
  Group:7
  Group member : 1.Harrison
				 2.Wong Zhi Teng
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable : 4996)
#define STR "KPKL20238"

int main()
{
	int c;
	char studentid[11];

	/*Welcome page*/
	printf("-----------------------------\n");
	printf("WELCOME TO");
	printf("\n");
	printf("\n");
	printf("KK    KK     OO      LL        EEEEEEE   JJ          PPPPPP        A         SSSSSSS        A        RRRRRRR  \n");
	printf("KK  KK     OO  OO    LL        EE        JJ          PP  PP      AA AA       SS           AA AA      RR   RR  \n");
	printf("KKKK      OO    OO   LL        EEEE      JJ          PPPPPP     AAAAAAA      SSSSSSS     AAAAAAA     RRRRRRR  \n");
	printf("KK  KK     OO  OO    LLLLLLL   EE        JJ   JJ     PP        AA     AA          SS    AA     AA    RR RR    \n");
	printf("KK    KK     OO      LLLLLLL   EEEEEEE    JJJJ       PP       AA       AA    SSSSSSS   AA       AA   RR    RR \n");
	printf("\n");

	/*Mode selected page*/
	printf("-----------------------------\n");
	printf("\n");
	printf("KOLEJ PASAR Mode\n");
	printf("----------------\n");
	printf("1.Student Mode\n");
	printf("2.Staff Administrator Mode\n");
	printf("Please Mode : ");
	scanf("%d", &c);
	if (c == 1)                                                                   /*Log in section*/
	{
		printf("You have selected Student Mode\n");
		printf("Please enter student id to log in (e.g.KPKL12345) : ");
		scanf("%s", studentid);
	}
	else
	{
		printf("You have selected Staff Administrator Mode");
	}

	if (studentid == STR);
	printf("Login Sucessful\n");

	return 0;
}