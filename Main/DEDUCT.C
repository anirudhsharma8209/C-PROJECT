#include<stdio.h>
#include<conio.h>
int DeductId();
void ScaningDeduction(struct Deduction *D, struct Employee *E1);
typedef struct Deduction{
	int DedNum;
	char DedName[20];
	int DedPer;
	char DedToEmp[20];
} Deduction;
void AddDeduction(Deduction *D, Employee *E1){
	FILE *FP = NULL;
	int TDed, EmpId, i;
	char k;
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t\t Enter Total Deduction To Add : ");
	scanf("%d",&TDed); system("cls");
	D = (Deduction *)calloc(sizeof(Deduction), TDed);
	FP = fopen("Deduct.txt","a");
	for(i = 0; i < TDed; i++){
		ScaningDeduction(D, E1);
		fprintf(FP, "\n\t %d \t\t %s \t\t %d \t\t %s",D->DedNum, D->DedName, D->DedPer, D->DedToEmp);
	}
	fclose(FP);
}
void ScaningDeduction(Deduction *D, Employee *E1){
	FILE *FP = NULL;
	FILE *Check = NULL;
	int EmpId;
	char Temp[20];
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t\t ---: P R O V I D E - D E D U C T I O N - D E T A I L S :--- ");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t\t Enter Deduction Number/ Identy : --> ");
	D->DedNum = DeductId() + 1;
	printf("%d",D->DedNum);
	fflush(stdin);
	printf("\n\n\t\t Enter Deduction Type/ Name : --> ");
	gets(D->DedName);	
	printf("\n\t\t Enter Deduction Percentage : --> ");
	scanf("%d",&D->DedPer);
	fflush(stdin);
	FP = fopen("Employee.txt","r");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t --: S E L E C T - E M P L O Y E E - I D - F O R - D E D U C T I O N :--> ");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	while(!feof(FP)){
		fscanf(FP, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);
		printf("\n\t\t %d \t %s \t %d \t%c \t %d",E1->Enum, E1->Name, E1->DesignationId, E1->Gender, E1->Salary);
	}
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	fclose(FP);
	printf("\n\t\t Select Employee Id For Deduction : --> ");
	fflush(stdin);
	scanf("%d",&EmpId);
	FP = fopen("Employee.txt","r");
	fflush(stdin);
	while(!feof(FP)){
		fscanf(FP, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);
		if(E1->Enum == EmpId){
			strcpy(D->DedToEmp, E1->Name);
		}
	}
	fclose(FP);
	fflush(stdin);
	printf("\n\t\t Deduction Alloted To : --> %s",D->DedToEmp);
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t\t ---: P R O C E S S - C O M P L E T E D :--- \n");
	return;
}
void ListDeduction(Deduction *D){
	FILE *FP = NULL;
	char Temp;
    system("cls");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t\t    ---: D E D U C T I O N - T Y P E S :--- \n");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t Identy \t Name \t\t Percentage \t Employee Allot");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	FP = fopen("Deduct.txt","r");
	while(!feof(FP)){		
        Temp = getc(FP);
        printf("%c",Temp);
	}
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t\t Note :- --> Press Any Key To Main Menu <-- \n");
	fclose(FP);
}
void AppliedDeduction(Deduction *D, Employee *E1, Department *D1){
	FILE *FP1 = NULL;
	FILE *FP2 = NULL;
	system("cls");
	printf("\n\t   ---: D E D U C T I O N - T O - E M P L O Y E E (S) :---\n");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t DIdenty \t EmployeeName \t Percentage \t Deduction \n");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	FP1 = fopen("Employee.txt","r");
	while(!feof(FP1)){

	}
	fclose(FP1);
}
int DeductId(){
    int Count = 1000;
    char Temp;
    FILE *FP = NULL;
    FP = fopen("Deduct.txt","r");
    while(!feof(FP)){
        Temp = getc(FP);
        if(Temp == '\n')
        Count++;
    }
    return Count;
    fclose(FP);
}