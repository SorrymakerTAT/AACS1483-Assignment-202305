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
	printf("K     K     O      L        EEEEEEE   J            PPPPPP        A         SSSSSSS        A        RRRRRRR \n");
	printf("K   K     O   O    L        EE        J            P    P      A   A       S            A   A      R     R \n");
	printf("K K      O     O   L        EEEE      J    J       PPPPPP     AAAAAAA      SSSSSSS     AAAAAAA     RRRRRRR \n");
	printf("K   K     O   O    L        EE        J    J       P         A       A           S    A       A    R R     \n");
	printf("K     K     O      LLLLLLL  EEEEEEE     J          P        A         A    SSSSSSS   A         A   R    R  \n");
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