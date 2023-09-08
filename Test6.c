/*File:PCD Assignment
  Group:7
  Group member : 1.Harrison Tiu Shao Hang
				 2.Wong Zhi Teng
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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

int main()
{
	int c, mode, courseintake;
	int  totalCreditHour = 0;
	int  totalCreditHourAllSem = 0;
	double totalQualityPoint = 0.0;
	double totalQualityPointAllSem = 0.0;
	const char STAFFID[MAX_ID_LENGTH] = "KPKL20238", STUDENTID[MAX_ID_LENGTH] = "KPKL23912";
	char enteredid[MAX_ID_LENGTH], staffname[MAX_ID_LENGTH], studentname[MAX_ID_LENGTH], studentID[MAX_ID_LENGTH], semesterSession[MAX_ID_LENGTH], studentName2[MAX_ID_LENGTH], studentID2[MAX_ID_LENGTH];

	/*Welcome page*/
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
	printf("Please select Mode\n");
	printf("----------------\n");
	printf("1.Staff Administrator Mode\n");
	printf("2.Student Mode\n");
	printf("\n");
	scanf("%d", &c);

	/*Log in section*/
		if (c == 1)
		{
			while (1)
			{
			printf("\n");
			printf("===========================================\n");
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
				printf("============================\n");
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
				printf("1.Name: %s\n", studentname);
				printf("2.Student ID : %s \n", studentID);
				printf("\n");

				for (int i = 1; i <= 3; ++i)
				{
					printf("Please enter current semester session : ");
					scanf("%s", &semesterSession);
					printf("\n");

					printf("Please enter number of course intake : ");
					scanf("%d", &courseintake);
					printf("\n");

					for (int i = 1; i <= courseintake; ++i)
					{
						char courseCode[12];
						int creditHour;
						char grade[3];
						double qualityPoint = 0.0;

						printf("Please Enter student's course details %d: \n", i);
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
							printf("Invalid grade entered for Course %d\n", i);
							continue;
						}

						totalQualityPoint += qualityPoint * creditHour;
						totalCreditHour += creditHour;
					}

					totalQualityPointAllSem += totalQualityPoint;
					totalCreditHourAllSem += totalCreditHour;

					if (totalCreditHour > 0) {
						double gpa = totalQualityPoint / totalCreditHour;
						printf("\nStudent's GPA: %.2f\n", gpa);
					}
					else
					{
						printf("No courses entered. GPA cannot be calculated.\n");
					}
				}
				if (totalCreditHourAllSem > 0)
				{
					double cgpa = totalQualityPointAllSem / totalCreditHourAllSem;
					printf("\nStudent's CGPA: %.2f", cgpa);
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
					printf("No courses entered. CGPA cannot be calculated.\n");
				}
				break;
			}
			else
			{
				printf("\n");
				printf("Invalid StaffID.\n");
				printf("Please try again.\n");
			}
		}
		}
		else
		{
			printf("\n");
			printf("===============================\n");
			rewind(stdin);
			printf("You have selected Student Mode.\n");
			printf("\n");
			printf("Please enter your name : ");
			gets(studentName2);
			printf("Please enter student id to log in (e.g.KPKL12345) : ");
			scanf("%s", &enteredid);
			if (strcmp(studentName2, studentname) == 0);
			{
				if (strcmp(enteredid, studentID) == 0);
				{
					printf("\n");
					printf("Login Successful\n");
					printf("\n");


					/*Stundet UI*/
					printf("============================\n");
					printf("Welcome back to KOLEJ PASAR");
					printf("\n");
					printf("Student Name : %s \n", studentName2);
					printf("\n");
					printf("-----------------------------\n");
					printf("Check Your Result\n");
					printf("Please select mode by using 1\n");
					printf("Please select mode : ");
					scanf("%d", &mode);
					printf("=========================\n");
					printf("Please check your result:\n");
					printf("%s `s result is: ", studentName2);
					printf("Semester 1 GPA: \n");
					printf("Semester 2 GPA: \n");
					printf("Semester 3 GPA: \n");
					printf("Student`s CGPA: \n");

				}
			}

		}
		return 0;

	}
