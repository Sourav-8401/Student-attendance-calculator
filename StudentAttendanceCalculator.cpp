#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

//initializing a structure with all the details of student. Saved into file f1
struct student{
	int reg_no;
	char name[20];
	int roll;
	int total_CSE101;
	int total_INT308;
	int total_CSE121;
	int total_MTH174;
	int att_CSE101;
	int att_INT308;
	int att_CSE121;
	int att_MTH174;
};


//declaring the functions
int ViewDetails(void); //view details of student

int MarkAttendance(void); //marking attendance

int ViewAttendance(void); //viewing attendance

int AddDetails(void); //adding a student


main() {
	int select;
	
	do {
		printf("Welcome To The Student Attendance Portal!\n");
		printf("Please select one of the following options:\n");
		printf("1. View Student Details\n");
		printf("2. Mark Student Attendance\n");
		printf("3. View Student Attendance\n");
		printf("4. Add Student Details\n");
		printf("5. Exit\n");
		printf("Please enter your selection: ");
		scanf("%d",&select);
		
		// Making a Selection
		switch(select) {
			case 1:
				ViewDetails();
				break;
			case 2:
				MarkAttendance();
				break;
			case 3:
				ViewAttendance();
				break;
			case 4:
				AddDetails();
				break;
			case 5:
				printf("Program Exited! Bye Bye!\n");
				break;
			default:
				printf("Invalid Input");
				printf("\n");
				break;
		}
	}
	while(select != 5);
	
	return 0;
}



int ViewDetails(void) {
	printf("Viewing Student Details\n");
	int i=1;
	FILE *f1 = fopen("students.txt","r");
	if(f1==NULL) {
		printf("Error! Can't open file!");
		return 1;
	}
	
	student viewstu;
	
	while(fread(&viewstu,sizeof(viewstu),1,f1)) {
		printf("Student %d:\n",i);
		printf("Registration No: %d\n",viewstu.reg_no);
		printf("Name: %s\n",viewstu.name);
		printf("Roll No: %d\n",viewstu.roll);
		printf("\n");
		i++;
	}
	fclose(f1);
	
	return 0;
}

int MarkAttendance(void) {
	printf("Marking Attendance\n");
	
	FILE *f1 = fopen("students.txt","r+");
	if(f1==NULL) {
		printf("Error! Can't open file!");
		return 1;
	}
	
	student stu;
	
	int sub,att;
	printf("Please Select the Course you want to mark attendance for:\n");
	printf("1. CSE101\n");
	printf("2. CSE121\n");
	printf("3. INT308\n");
	printf("4. MTH174\n");
	printf("Select Course: ");
	scanf("%d",&sub);
	
	switch(sub) {
		case 1:
			printf("Marking attendance for CSE101:\n");
			printf("Enter 1 for Present and 0 for Absent\n");
			while(fread(&stu,sizeof(stu),1,f1) == 1) {
				printf("%d: ",stu.roll);
				scanf("%d",&att);
				if(att==0) {
					stu.total_CSE101 += 1.0;
					
					//fseek goes back to the starting of that student's details so we can edit it
					
        			fseek(f1, -sizeof(stu), SEEK_CUR);
        			fwrite(&stu, sizeof(stu),1,f1);
        			fseek(f1, 0, SEEK_CUR);
        			
        			//this fseek takes it back to the end
				}
				else if(att==1) {
					stu.reg_no = 888;
					stu.total_CSE101 += 1.0;
					stu.att_CSE101 += 1.0;
        			fseek(f1, -sizeof(stu), SEEK_CUR);
        			fwrite(&stu, sizeof(stu),1,f1);
        			fseek(f1, 0, SEEK_CUR);
				}
				else {
					printf("Invalid Input\n");
					return 1;
				}
			}
			break;
		case 2:
			printf("Marking attendance for CSE121:\n");
			while(fread(&stu,sizeof(stu),1,f1) == 1) {
				printf("%d: ",stu.roll);
				scanf("%d",&att);
				if(att==0) {
					stu.total_CSE121 += 1;
					fseek(f1, -sizeof(stu), SEEK_CUR);
        			fwrite(&stu, sizeof(stu),1,f1);
        			fseek(f1, 0, SEEK_CUR);
				}
				else if(att==1) {
					stu.att_CSE121 += 1;
					stu.total_CSE121 += 1;
					fseek(f1, -sizeof(stu), SEEK_CUR);
        			fwrite(&stu, sizeof(stu),1,f1);
        			fseek(f1, 0, SEEK_CUR);
				}
				else {
					printf("Invalid Input\n");
					return 1;
				}
			}
			break;
		case 3:
			printf("Marking attendance for INT308:\n");
			while(fread(&stu,sizeof(stu),1,f1) == 1) {
				printf("%d: ",stu.roll);
				scanf("%d",&att);
				if(att==0) {
					stu.total_INT308 += 1.00;
					fseek(f1, -sizeof(stu), SEEK_CUR);
        			fwrite(&stu, sizeof(stu),1,f1);
        			fseek(f1, 0, SEEK_CUR);
				}
				else if(att==1) {
					stu.att_INT308 += 1.00;
					stu.total_INT308 += 1.00;
					fseek(f1, -sizeof(stu), SEEK_CUR);
        			fwrite(&stu, sizeof(stu),1,f1);
        			fseek(f1, 0, SEEK_CUR);
				}
				else {
					printf("Invalid Input\n");
					return 1;
				}
			}
			break;
		case 4:
			printf("Marking attendance for MTH174:\n");
			while(fread(&stu,sizeof(stu),1,f1) == 1) {
				printf("%d: ",stu.roll);
				scanf("%d",&att);
				if(att==0) {
					stu.total_MTH174 += 1.00;
					fseek(f1, -sizeof(stu), SEEK_CUR);
        			fwrite(&stu, sizeof(stu),1,f1);
        			fseek(f1, 0, SEEK_CUR);
				}
				else if(att==1) {
					stu.att_MTH174 += 1.00;
					stu.total_MTH174 += 1.00;
					fseek(f1, -sizeof(stu), SEEK_CUR);
        			fwrite(&stu, sizeof(stu),1,f1);
        			fseek(f1, 0, SEEK_CUR);
				}
				else {
					printf("Invalid Input\n");
					return 1;
				}
			}
			break;
		default:
			printf("Invalid Selection\n");
			return 1;
	}
	fclose(f1);
	
	return 0;
}

int ViewAttendance(void) {
	printf("Viewing Attendance\n");
	
	FILE *f1 = fopen("students.txt","r");
	if(f1==NULL) {
		printf("Error! Can't open file!");
		return 1;
	}
	
	student stu;
	
	while(fread(&stu,sizeof(stu),1,f1)) {
		printf("Roll No: %d\n",stu.roll);
		float aggregate,CSE101, CSE121, INT308, MTH174;
		
		//changing int into float because int division less than 1 will result in 0
		
		aggregate = ((float(stu.att_CSE101)+float(stu.att_CSE121)+float(stu.att_INT308)+float(stu.att_MTH174))/(float(stu.total_CSE101)+float(stu.total_CSE121)+float(stu.total_INT308)+float(stu.total_MTH174)))*100;
		CSE101 = (float(stu.att_CSE101)/float(stu.total_CSE101))*100;
		CSE121 = (float(stu.att_CSE121)/float(stu.total_CSE121))*100;
		INT308 = (float(stu.att_INT308)/float(stu.total_INT308))*100;
		MTH174 = (float(stu.att_MTH174)/float(stu.total_MTH174))*100;
		
		printf("Aggregate Attendance: %.2f\n",aggregate);
		printf("CSE101 Attendance: %.2f\n",CSE101);
		printf("CSE121 Attendance: %.2f\n",CSE121);
		printf("INT308 Attendance: %.2f\n",INT308);
		printf("MTH174 Attendance: %.2f\n",MTH174);
		printf("\n");
	}
	fclose(f1);
	
	return 0;
}

int AddDetails(void) {
	printf("Adding New Student Details\n");
	student addstu;
	int slct;
	printf("\nPlease enter the student's Registration Number: ");
	scanf("%d",&addstu.reg_no);
	printf("\nPlease enter the student's Name: ");
	scanf("%s",&addstu.name);
	printf("\nPlease enter the student's Roll Number: ");
	scanf("%d",&addstu.roll);
	
	//if student has attended classes prior to addition into this program, we can enter their attendance details manually
	
	printf("\nHas the student attended classes before? (Enter 0 for No and 1 for Yes): ");
	scanf("%d",&slct);
	if(slct == 1) {
			printf("\nPlease enter the total number of CSE101 classes the student has had: ");
			scanf("%d",&addstu.total_CSE101);
			printf("\nPlease enter the total number of CSE101 classes the student has attended: ");
			scanf("%d",&addstu.att_CSE101);			
			printf("\nPlease enter the total number of CSE121 classes the student has had: ");
			scanf("%d",&addstu.total_CSE121);
			printf("\nPlease enter the total number of CSE121 classes the student has attended: ");
			scanf("%d",&addstu.att_CSE121);
			printf("\nPlease enter the total number of INT308 classes the student has had: ");
			scanf("%d",&addstu.total_INT308);
			printf("\nPlease enter the total number of INT308 classes the student has attended: ");
			scanf("%d",&addstu.att_INT308);
			printf("\nPlease enter the total number of MTH174 classes the student has had: ");
			scanf("%d",&addstu.total_MTH174);
			printf("\nPlease enter the total number of MTH174 classes the student has attended: ");
			scanf("%d",&addstu.att_MTH174);
	}
	
	//in case of new admission initial values are zero
	
	else {
		addstu.att_CSE101 = 0;
		addstu.att_CSE121 = 0;
		addstu.att_INT308 = 0;
		addstu.att_MTH174 = 0;
		addstu.total_CSE101 = 0;
		addstu.total_CSE121 = 0;
		addstu.total_INT308 = 0;
		addstu.total_MTH174 = 0;
		
	}
	
	FILE *f1 = fopen("students.txt","a");
	if(f1==NULL) {
		printf("Error! Can't open file!");
		return 1;
	}
	else {
		fwrite(&addstu, sizeof(addstu),1,f1);
		printf("\nStudent Details Successfully Saved!\n");
		printf("\n");
	}
	fclose(f1);
	return 0;
}

