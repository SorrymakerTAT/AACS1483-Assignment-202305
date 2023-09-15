/*File:PCD Assignment
  Group:7
  Group member : 1.Harrison
				 2.Wong Zhi Teng
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#pragma warning(disable : 4996)
#define MAX_ID_LENGTH 40
#define A_PLUS 4.00
#define A  4.00
#define A_MINUS 3.75
#define B_PLUS  3.50
#define B  3.00
#define B_MINUS 2.75
#define C_PLUS  2.50
#define C  2.00
#define F  0.00

char studentID[MAX_ID_LENGTH];

bool isSameID(char studententeredid[], char studentID[]) {
	return strcmp(studententeredid, studentID) == 0;
}


double gpa = 0.0;
double gpaData[3];
int counter = 0;
int choose, mode, courseintake;
int  totalCreditHourAllSem = 0;
double totalQualityPointAllSem = 0.0;
const char STAFFID[MAX_ID_LENGTH] = "KPKL20238";
char enteredid[MAX_ID_LENGTH], staffname[MAX_ID_LENGTH], semester[MAX_ID_LENGTH], studentname[MAX_ID_LENGTH];
double cgpa = 0;


int main()
{



	/*Welcome page*/
	while (1) {
		printf("-------------------------------------------------------------------------------------------------------------\n");
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
		printf("-------------------------------------------------------------------------------------------------------------\n");
		printf("\n");
		printf("        Mode\n");
		printf("------------------------------------------------\n");
		printf("1.Staff Administrator Mode\n");
		printf("2.Student Mode\n");
		printf("3.Exit\n");
		printf("------------------------------------------------\n");
		printf("\n");
		printf("Enter number to select mode : ");
		scanf("%d", &choose);

		/*Log in section*/

		if (choose == 1)
		{
			printf("\n");
			printf("-----------------------------\n");
			rewind(stdin);
			printf("You have selected Staff Administrator Mode.\n");
			printf("\n");
			printf("Please enter your name : ");
			gets(staffname);
			printf("Please enter staff id to log in (e.g.KPKL12345) : ");
			scanf("%s", &enteredid);
			if (strcmp(enteredid, STAFFID) == 0)
			{

				printf("\n");
				printf("Login Successful\n");
				printf("\n");

				/*Staff UI*/
				printf("-----------------------------\n");
				printf("Welcome back to KOLEJ PASAR");
				printf("\n");
				printf("Staff Name : %s \n", staffname);
				printf("\n");
				printf("-----------------------------\n");
				printf("1.Enter Student's Result\n");
				printf("Please select mode by using 1:\n");
				printf("Please select mode : ");
				scanf("%d", &mode);
				printf("\n");
				/*Enter student's detail section*/
				printf("Please enter student's detail\n");
				rewind(stdin);
				printf("1.Name          : ");
				scanf("%[^\n]", studentname);
				printf("2.Student ID    : ");
				rewind(stdin);
				scanf("%s", &studentID);
				rewind(stdin);
				printf("\n");
				printf("Student found\n");
				printf("1.Name: %s  \n", studentname);
				printf("2.Student ID : %s\n", studentID);
				printf("\n");
				/*Enter student semester and course intake detail*/
				for (int i = 1; i <= 3; ++i)
				{
					int  totalCreditHour = 0;
					double totalQualityPoint = 0.0;
					printf("------------------------------------------------\n");
					printf("Please enter current semester : ");
					scanf("%s", &semester);
					printf("------------------------------------------------\n");
					printf("\n");

					printf("Please enter number of course intake : ");
					scanf("%d", &courseintake);
					printf("\n");
					/*Calculate CGPA*/
					for (int j = 1; j <= courseintake; ++j)
					{
						char courseCode[12];
						int creditHour;
						char grade[3];
						double qualityPoint = 0.0;

						printf("Please Enter student's course %d details : \n", j);
						printf("1.Course code : ");
						scanf("%s", &courseCode);
						rewind(stdin);
						printf("2.Credit hour : ");
						scanf("%d", &creditHour);
						rewind(stdin);
						printf("3.Grade obtained : ");
						scanf("%s", &grade);
						rewind(stdin);
						printf("\n");

						switch (grade[0])
						{
						case'A':
						case'a':
							if (grade[1] == '+')
								qualityPoint = A_PLUS;
							else if (grade[1] == '-')
								qualityPoint = A_MINUS;
							else
								qualityPoint = A;
							break;
						case'B':
						case'b':
							if (grade[1] == '+')
								qualityPoint = B_PLUS;
							else if (grade[1] == '-')
								qualityPoint = B_MINUS;
							else
								qualityPoint = B;
							break;
						case'C':
						case'c':
							if (grade[1] == '+')
								qualityPoint = C_PLUS;
							else
								qualityPoint = C;
							break;
						case'F':
						case'f':
							qualityPoint = F;
							break;
						default:
							printf("Invalid grade entered for Course %d\n", j);
							continue;
						}

						totalQualityPoint += qualityPoint * creditHour;
						totalCreditHour += creditHour;
					}

					totalQualityPointAllSem += totalQualityPoint;
					totalCreditHourAllSem += totalCreditHour;

					if (totalCreditHour > 0) {
						gpa = totalQualityPoint / totalCreditHour;
						printf("\nStudent's semester%s's GPA: %.2f\n", semester, gpa);
					}
					else
					{
						printf("No courses entered. GPA cannot be calculated.\n");
					}
					gpaData[counter] = gpa;
					counter++;
				}


				if (totalCreditHourAllSem >= 21)
				{
					cgpa = totalQualityPointAllSem / totalCreditHourAllSem;
					printf("\nStudent's CGPA: %.2f\n", cgpa);
					if (cgpa > 3.75)
					{
						printf("[Good,keep going]\n");
					}
					else
					{
						printf("Need to put more effort\n");
					}
				}
				else
				{
					printf("Credit hour doesn't meet the minimum requirements.\n");
				}
				int choose2;
				do {
					printf("1.Back to menu\n");
					printf("2.Exit\n");
					printf("Please select mode: ");
					scanf("%d", &choose2);
					printf("\n");

					if (choose2 == 1) {
						continue;
					}
					else if (choose2 == 2) {
						return 0;
					}
					else {
						printf("Invalid option. Please try again.\n");
					}
				} while (choose2 != 1);

			}
			else
			{
				printf("\n");
				printf("Invalid StaffID.\n");
				printf("Please try again.\n");
			}
		}
		else if (choose == 2)
		{
			char studententeredid[MAX_ID_LENGTH];
			printf("\n");
			printf("===============================\n");
			printf("You have selected Student Mode.\n");
			printf("\n");
			printf("Please enter student id to log in (e.g.KPKL12345) : ");
			scanf("%s", &studententeredid);
			if (isSameID(studententeredid, studentID) == true)
			{
				printf("\n");
				printf("Login Successful\n");
				printf("\n");


				/*Stundet UI*/
				printf("============================\n");
				printf("Welcome back to KOLEJ PASAR");
				printf("\n");
				printf("Student Name : %s \n", studentname);
				printf("\n");
				printf("-----------------------------\n");
				printf("Check Your Result\n");
				printf("Please select mode by using 1\n");
				printf("Please select mode : ");
				scanf("%d", &mode);
				/*Student Result*/
				printf("=========================\n");
				printf("Please check your result:\n");
				printf(" %s's GPA in semester 1 is %.2f\n ", studentname, gpaData[0]);
				printf("%s's GPA in semester 2 is %.2f\n ", studentname, gpaData[1]);
				printf("%s's GPA in semester 3 is %.2f\n ", studentname, gpaData[2]);
				printf("%s's CGPA score is %.2f\n", studentname, cgpa);
				if (cgpa >= 3.75 && cgpa < 3.90)
				{
					printf(" Congratulation, your are in the Dean's List\n");
				}
				else if (cgpa >= 3.90)
				{
					printf(" Congratulation, your are in the President's List\n");
				}
				else
				{
					printf(" Don't be disappointed, continue to work hard\n");
				}
			}
			else
			{
				printf("Invalid Student Id\n");
				printf("Please try again\n");
				printf("\n");
				main();
			}
		}
		else if (choose == 3)
		{
			printf("Good Bye! Have a nice day\n");
			return 0;
		}
		/*Wrong selection alert*/
		else
		{
			printf("You can only select 3 mode\n");
			printf("Please try again \n");
			main();
		}
	}
	return 0;
}