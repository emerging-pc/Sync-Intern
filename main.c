//Task 1- BUG TRACKER

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void filebug(int id)
{
	printf("--------FILING THE BUG--------\n");

	//Current Time
	time_t CurrTime;
	time(&CurrTime);

	char name[20], bugtype[50], bugdes[1000], bugpri[30];
	int status;
	FILE* ptr;

	//User name
	printf("Enter your name:\n");
	scanf("%s", name);
	char ids[10];
	strcat(name, ids);
	char ex[]=".txt";
	strcat(name, ex);

	//Name of the Bug
	printf("Filename :%s\n", name);
	ptr=fopen(name, "w");

	//Case NULL
	if(ptr == NULL) printf("cannot create file!!!\n");
	fprintf(ptr, "DATE AND TIME : %s",ctime(&CurrTime));
	fprintf(ptr, "BUG ID : %d\n", id);
	fprintf(ptr, "\n");

	// Bug ID
	printf("BUG ID:%d\n", id);
	fprintf(ptr, "BUG FILED BY: %s\n",name);
	fprintf(ptr, "\n");
	printf("Enter bug type:\n");
	scanf(" %[^\n]", bugtype);

	// Bug Type
	fprintf(ptr, "TYPE OF BUG: %s",bugtype);
	fprintf(ptr, "\n");

	// Bug Priority
	printf("Enter bug priority:\n");
	scanf(" %[^\n]s", bugpri);
	fprintf(ptr, "BUG PRIORITY: %s\n",bugpri);
	fprintf(ptr, "\n");

	// Bug Description
	printf("Enter the bug description:\n");
	scanf(" %[^\n]s", bugdes);
	fprintf(ptr, "BUG DESCRIPTION: %s\n",bugdes);
	fprintf(ptr, "\n");
	printf("Status of bug:\n1. NOT ASSIGNED\n2.IN PROCESS\n 3.FIXED\n4.DELIVERED\n ENTER YOUR CHOICE:");

	int j;
	scanf("%d", &j);

	// Date and time of Bug Creation
	fprintf(ptr, "DATE AND TIME: %s",ctime(&CurrTime));
	fprintf(ptr, "BUG STATUS:");

	//Status of the Bug
	switch (j) {
	case 1:
		fprintf(ptr, "NOT ASSIGNED\n");
		break;
	case 2:
		fprintf(ptr, "IN PROCESS\n");
		break;
	case 3:
		fprintf(ptr, "FIXED\n");
		break;
	case 4:
		fprintf(ptr, "DELIVERED\n");
		break;
	default:
		printf("invalid choice\n");
		break;
	}
	fclose(ptr);
}

// Function for status of the Bug
void changestatus()
{
	printf("--------Change status--------\n");

	// Current Time
	time_t CurrTime;
	time(&CurrTime);

	FILE* file;
	char name[50];

	// Bug File name
	printf("Enter file name:\n");
	scanf("%s", name);
	char ex[] = ".txt";
	strcat(name, ex);
	file = fopen(name, "a");
	printf("\n 1. NOT ASSIGNED\n 2.IN PROCESS\n 3.FIXED\n 4.DELIVERED\n ENTER YOUR CHOICE:");

	int k;
	scanf("%d", &k);
	fprintf(file, "\n");
	fprintf(file, "DATE AND TIME : %s",ctime(&CurrTime));
	fprintf(file, "BUG STATUS:");

	// Changing the status with user input
	switch (k) {
	case 1:
		fprintf(file, "NOT ASSIGNED\n");
		break;
	case 2:
		fprintf(file, "IN PROCESS\n");
		break;
	case 3:
		fprintf(file, "FIXED\n");
		break;
	case 4:
		fprintf(file, "DELIVERED\n");
		break;
	default:
		printf("invalid choice\n");
		break;
	}
	fclose(file);
}

// Function for Bug Tracker
void report()
{
	printf("--------REPORT--------\n");
	FILE* fp;
	char name[50];
	
	// Ask the Filename
	printf("Enter file name:\n");
	scanf("%s", name);
	char ex[] = ".txt";
	strcat(name, ex);
	fp = fopen(name, "r");
	char ch;
	ch = getc(fp);
	while (ch != EOF) {
		printf("%c", ch);
		ch = getc(fp);
	}
	fclose(fp);
	getch();
}

// Driver Code
void main()
{
	printf("--------BUG TRACKER--------\n");
	int number, i = 1;
	int id = 0;
	while (i != 0) {
		printf("\n1. NEW BUG\n2. STATUS CHANGE OF THE BUG\n3. BUG REPORT\n4. EXIT");
		printf("\n\n ENTER YOUR CHOICE:");
		scanf("%d", &number);
		switch (number) {
		case 1:
			id++;
			filebug(id);
			break;
		case 2:
			changestatus();
			break;
		case 3:
			report();
			break;
		case 4:
			i = 0;
			break;
		default:
			printf("\ninvalid entry");
			break;
		}
	}
}