#include<stdio.h>
#include<conio.h>
#include<string.h>
int EmpId();
void UpdateEmployee();
void ReadEmployee();
int TotalCount();
int TotalCount(){
	int Count = 0;
	char Temp;
	FILE *FP = NULL;
	FP = fopen("Employee.txt","r");
	while(!feof(FP)){
		Temp = getc(FP);
		if(Temp == '\n'){
			Count++;
		}
	}
	fclose(FP);
	return Count;
}
void ScaningEmployee(struct Employee *E1, struct Department *D1);
typedef struct Employee{
    int Enum;
	char Name[20];
	int DesignationId;
	char Gender;
	int Salary;
} Employee;
Employee *Arr;
void InsertEmployee(Employee *E1, Department *D1){
    FILE *FP1 = NULL;
    FILE *FP2 = NULL;
    FILE *FP3 = NULL;
    int TInsert, i;
	system("cls");
	printf("\n \t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
	printf("\n\t       <---: P R O V I D E - E M P L O Y E E - D E T A I L S :---> ");
    printf("\n \t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	Rsize:
    printf("\n\t\t Enter Total Employee (S) To Insert : --> ");
    scanf("%d",&TInsert);    
	if(TInsert == ' '){
		printf("\n\t\t No Selection Happen...\n"); goto Rsize;
	}
	else{
		E1 = (Employee *)calloc(sizeof(Employee), TInsert);
		for(i = 0; i < TInsert; i++){
			ScaningEmployee(E1, D1);
			FP3 = fopen("Employee.txt","a");
				fprintf(FP3, "\n %d \t %s \t %d \t %c \t %d",E1[i].Enum, E1[i].Name, E1[i].DesignationId, E1[i].Gender, E1[i].Salary);	 	
			fclose(FP3);
		}    
	}    
}
void SearchEmployee(Employee *E1){
	FILE *FP = NULL;
	int EmpSrch, Access = 0;
	system("cls");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t\t Enter Employee Id For Search : --> ");
	scanf("%d",&EmpSrch);
	FP = fopen("Employee.txt","r");
	while(!feof(FP)){
		fscanf(FP, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);
		if(E1->Enum == EmpSrch){
			Access = 1;			
			printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	    	printf("\n Record Found :---> \n");
			printf("\n\t Id \t Name \t DesignationId \t Gender     Salary(P /M)  ");
			printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
			printf("\n\t %d \t %s     %d \t %c \t    %d",E1->Enum, E1->Name, E1->DesignationId, E1->Gender, E1->Salary);			
		}		
	}
	if(Access == 0){
		printf("\n\t\t There is No Such Type Of Record Available...!!! \n");
	}
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t\t      --->> Press Any Key To Main Menu <<--- \n");
	fclose(FP);
}
void ScaningEmployee(Employee *E1, Department *D1){
	FILE *FP1 = NULL;
	FILE *FP2 = NULL;
	FILE *Check = NULL;
	int k, i, Temp, TempId, Access = 0, Final;
	char TempName[20];    
    printf("\n\t\t Employee Number/ Identy : --> ");
    fflush(stdin);
    E1->Enum = EmpId() + 1;
    printf("%d",E1->Enum);
    fflush(stdin);
	Name:
    printf("\n\n\t\t Enter Employee Name : --> ");
    gets(TempName);
	for(i = 0 ; i < strlen(TempName); i++){
		if(TempName[i] >= 'a' && TempName[i] <= 'z' || TempName[i] >= 'A' && TempName[i] <= 'Z' || TempName[i] == ' '){
			Access = 1;			
		}
		else if(TempName[0] == 13){
			Access = 2;
			break;	
		}		
		else{
			Access = 3;
		}
	}		
	if(Access == 1){
		strcpy(E1->Name, TempName);
	}	
	else if(Access == 2){
		printf("\n\t Invalid Selection...");
		goto Name;
	}
	else{
		printf("\n\t Invalid Selection...");goto Name; 
	}
    fflush(stdin);
    printf("\n\t\t\t ---: Select Department Id :--- \n");
    printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\n\t Department Detils : ---> ");
    FP1 = fopen("Depart.txt","r");		
	while(!feof(FP1)){ 			
		k = getc(FP1);
		printf("%c",k);
	}
    fclose(FP1);	
    printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	DepartId:
    printf("\n\t\t Select Department Id : --> ");
    fflush(stdin);
    scanf("%d",&TempId);	    
	Check = fopen("Depart.txt","r");
	while(!feof(Check)){
		fscanf(Check,"%d %s %s %s %d",&D1->DepartNum,D1->DepartName, D1->DepartHead, D1->P1.PostName, &D1->P1.PostSalary);		
		if(TempId != D1->DepartNum){		
			Access = 1;				
		}		
		else if(TempId == D1->DepartNum){			
			Access = 2; break;
		}
	}
	if(Access == 1){
		printf("\n\t\t\t Invalid Id Selection...!!!");
		goto DepartId;			
	}
	else if(Access == 2){
		E1->DesignationId = TempId;		
	}
	fclose(Check);
    a:
    printf("\n\t\t Select Employee Gender : --> ");
    fflush(stdin);
    scanf("%c",&E1->Gender);
    if(E1->Gender == 'M' || E1->Gender == 'F' || E1->Gender == 'm' || E1->Gender == 'f'){
		
    }
    else{
		printf("\n\t\t Inavlid Gender....");
		goto a;
    }
    printf("\n\t\t Salary Of Employee : --> ");
    FP2 = fopen("Depart.txt","r");
    while(1){
    	fscanf(FP2,"%d %s %s %s %d",&D1->DepartNum,D1->DepartName, D1->DepartHead, D1->P1.PostName, &D1->P1.PostSalary);		
    	if(D1->DepartNum == E1->DesignationId){
    		Temp = 1;			
    		E1->Salary = D1->P1.PostSalary;	
		}	    		
    	if(getc(FP2) == EOF)
    		break;
	}
	fclose(FP2);
    printf("%d",E1->Salary);
    if(Temp == 0)
        printf("\n\t\t Department Not Found....");        
    printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");    	
    printf("\n\t\t      --->> Press Any Key To Main Menu <<--- \n");
}
void ListEmployee(Employee *E1){
	int i;
	char Temp;
	FILE *FP = NULL;
	system("cls");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t\t <---: E M P L O Y E E (S) - D E T A I L S :--> \n");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t Id \t Name \t\t Designation \t Gender \t Salary(P /M)  ");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
	FP = fopen("Employee.txt","r");
	while(!feof(FP)){
		fscanf(FP, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);
		printf("\n\t %d \t %s \t %d \t\t %c \t\t %d",E1->Enum, E1->Name, E1->DesignationId, E1->Gender, E1->Salary);		
	}
	fclose(FP);
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t\t      --->> Press Any Key To Main Menu <<--- \n");
}
// void UpdateEmployee(Employee *E1, Department *D1){
// 	int EmpId;
// 	int Temp = 0;
// 	char Data[20], k;
// 	FILE *FP = NULL;
// 	FILE *FP1 = NULL;
//     FILE *FP2 = NULL;
// 	system("cls");
// 	fflush(stdin);
// 	printf("\n ---: P L E A S E - P R O V I D E - D E T A I L S - F O R - U P D A T I O N :---");
// 	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
// 	printf("\n\t\t Enter Employee Id For Updation : ");
// 	scanf("%d",&EmpId);
// 	FP = fopen("Employee.txt","r");
// 	FP1 = fopen("Temp.txt","a");
// 	while(!feof(FP)){		
// 		fscanf(FP, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);		
// 		if(E1->Enum == EmpId){
// 			Temp = 1;
// 			fflush(stdin);
// 			printf("\n\t\t Current Employee Id : %d",E1->Enum);									
// 			fflush(stdin);
// 			printf("\n\n\t\t Enter Employee Name : ");
//             fflush(stdin);
// 			gets(E1->Name);			
//             printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");   						
// 			printf("\n\t\t ---: S E L E C T - D E P A R T M E N T - I D :---- ");
// 			printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");   
// 			printf("\nDepartId  DepartName  DepartHead  DepartPostId  DepartPostName  DepartPostSalary \n");							
// 			printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "); 
// 			FP2 = fopen("Depart.txt","r");
// 			k = getc(FP2);
// 			while(!feof(FP2)){		
// 				printf("%c",k);
// 				k = getc(FP2);
// 			}				
// 			fclose(FP2);
// 			printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");   
// 			printf("\n\t\t Select Employee Designation Id : ");
// 			fflush(stdin);
// 			scanf("%d",&E1->DesignationId);			
// 			fflush(stdin);
// 			printf("\n\t\t Enter New Employee Gender : ");
//             fflush(stdin);	
// 			scanf("%c",&E1->Gender);				
// 			printf("\n\t\t Employee Salary : ");	            
// 			FP2 = fopen("Depart.txt","r");
// 			while(1){
//                 fscanf(FP2,"%d %s %s %d %s %d",&D1->DepartNum,D1->DepartName, D1->DepartHead, &D1->P1.PostID, D1->P1.PostName, &D1->P1.PostSalary);		
//                 if(E1->DesignationId == D1->DepartNum){
//                     Temp = 1;
//                     E1->Salary = D1->P1.PostSalary;	
//                 }	    		
//                 if(getc(FP2) == EOF)
//                     break;
// 			}								
// 			fclose(FP2);
// 			fflush(stdin);			
// 			printf("%d",E1->Salary);
// 			if(Temp == 0)
// 				printf("\n\t\t --: D E P A R T M E N T - N O T - F O U N D :-- \n");			
// 			fflush(stdin);
// 			fprintf(FP1, "\n \t %d \t %s \t %d \t %c \t %d",E1->Enum, E1->Name, E1->DesignationId, E1->Gender, E1->Salary);
// 			printf("\n\t\t\t Note :- --> R E C O R D - U P D A T E D <-- \n");			
// 		}
// 		else{
// 			fprintf(FP1, "\n \t %d \t %s \t %d \t %c \t %d",E1->Enum, E1->Name, E1->DesignationId, E1->Gender, E1->Salary);
// 		}	
// 	}
// 	if(Temp == 0)
// 		printf("\n\t\t Note :- --> R E C O R D - N O T - F O U N D <-- \n");
// 	fclose(FP);
// 	fclose(FP1);
		
// 	FP = fopen("Employee.txt","w");
// 	fclose(FP);

//     FP1 = fopen("Temp.txt","r");
// 	FP = fopen("Employee.txt","a");
	
// 	while(!feof(FP1)){
// 		fscanf(FP1, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);		
// 		fprintf(FP, "\n \t %d \t %s \t %d \t %c \t %d",E1->Enum, E1->Name, E1->DesignationId, E1->Gender, E1->Salary);
// 	}
// 	fclose(FP);
// 	fclose(FP1);	
//     printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");   
// 	printf("\n\n\t\t\t -->> E M P L O Y E E - U P D A T E D <<--");
// }
void DeleteEmployee(Employee *E1){
	int EmpSrch, Access = 0;
	FILE *FP1 = NULL;
	FILE *FP2 = NULL;
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
	printf("\n\t\t Enter Employee Id For Delete : --> ");
	scanf("%d",&EmpSrch);
	FP1 = fopen("Employee.txt","r");
	FP2 = fopen("Temp.txt","a");
	while(!feof(FP1)){		
		fscanf(FP1, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);
		if(E1->Enum != EmpSrch){
			Access = 1;						
			fprintf(FP2, "\n %d \t %s \t %d \t %c \t %d",E1->Enum, E1->Name, E1->DesignationId, E1->Gender, E1->Salary);	 	
		}		
	}
	if(Access == 1){
		printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		printf("\n\t\t\t  Record Deleted Successfully...!!! ");		
	}
	else{
		printf("\n\t\t\t There Is No Such Type of Record...!!!");
	} 
	fclose(FP1);
	fclose(FP2);
	remove("Employee.txt");
	rename("Temp.txt","Employee.txt");
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t\t      --->> Press Any Key To Main Menu <<--- \n");
}
void ReadEmployee(){
	char String[20];
	int Idx = 0, k = 0, CountRec;
	FILE *FP = NULL;
	CountRec = TotalCount();
	Arr = (Employee *)calloc(sizeof(Employee), CountRec);
	FP = fopen("Employee.txt","r");
	k = getc(FP);
	while(k != -1){
		fscanf(FP, "%s", String);
		(Arr + Idx)->Enum = atoi(String);
		fscanf(FP, "%s", String);
		strcpy((Arr + Idx)->Name, String);
		fscanf(FP, "%s", String);
		(Arr + Idx)->DesignationId = atoi(String);
		fscanf(FP, "%s", String);
		(Arr + Idx)->Gender = String[0];
		fscanf(FP, "%s", String);
		(Arr + Idx)->Salary = atoi(String);
		Idx++;
		k = getc(FP);
	}
	fclose(FP);
}
void UpdateEmployee(Department *D1, Employee *E1){
	int Data = 0;
	int k, Idx, i, CountRec = TotalCount();
	char Temp, Gc;
	FILE *FP = NULL;
	FILE *FP1 = NULL;
	FILE *FP2 = NULL;	
	system("cls");
	printf("\n     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  ");
	printf("\n\t       <---: P R O V I D E - D E T A I L S - F O R - U P D A T E :---> ");
    printf("\n     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  \n");
	printf("\n\t\t\t Enter Employee Id : ");
	scanf("%d",&Data);	
	Idx = 0;
	k = -1;
	while(Idx != CountRec){
		if(Data == (Arr + Idx)->Enum){
			k = Idx;
		}
		Idx++;
	}
	if(k == -1){				
		printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		printf("\n\t\t There is No Such Type of Record  Available...!!!");
		printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
		printf("\n\t\t\t <---: Press Any To Continue :---> ");
	}
	else{		
		fflush(stdin);		
		printf("\n\t\t Enter Emplyee Name : --> ");
		fflush(stdin);
		gets((Arr + k)->Name);
		printf("\n\t\t\t ---: Select Department Id :--- \n");
		printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
		FP1 = fopen("Depart.txt","r");
		while(!feof(FP1)){
			Temp = getc(FP1);
			printf("%c",Temp);
		}
		printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
		fclose(FP1);
		printf("\n\t\t Select Designation Id : --> ");
    	FP2 = fopen("Depart.txt","r");
		fflush(stdin);
		scanf("%d",&(Arr + k)->DesignationId);
		fflush(stdin);
		a:
		printf("\n\t\t Enter Gender : ");
		fflush(stdin);
		scanf("%c",&(Arr + k)->Gender);
		if((Arr + k)->Gender == 'M' || (Arr + k)->Gender == 'F' || (Arr + k)->Gender == 'm' || (Arr + k)->Gender == 'f'){
			
   		 }
    	else{
			printf("\n\t\t Inavlid Gender....");
			goto a;
    	}    	
		printf("\n\t\t Enter Employee Salary : --> ");
    	while(1){
    		fscanf(FP2,"%d %s %s %s %d",&D1->DepartNum,D1->DepartName, D1->DepartHead, D1->P1.PostName, &D1->P1.PostSalary);		
    		if(D1->DepartNum == E1->DesignationId){
	    		Temp = 1;			
    			E1->Salary = D1->P1.PostSalary;	
			}	    		
    		if(getc(FP2) == EOF)
    			break;
		}
		fclose(FP2);
		fflush(stdin);
		printf("%d",(Arr + k)->Salary);
		// scanf("%d",&(Arr + k)->Salary);
		FP = fopen("Employee.txt","w");		
		for(i = 0 ; i < CountRec; i++){
			fprintf(FP, "\n\t %d \t %s \t %d \t %c \t %d", (Arr + i)->Enum, (Arr + i)->Name, (Arr + i)->DesignationId, (Arr + i)->Gender, (Arr + i)->Salary);
		}
		fclose(FP);
		printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");   
		printf("\n\t\t Upadte Successfully...!!!");
	}
}

int EmpId(){
    int Count = 100;
    char Temp;
    FILE *FP = NULL;
    FP = fopen("Employee.txt","r");
    while(!feof(FP)){
        Temp = getc(FP);
        if(Temp == '\n'){
            Count++;
        }
    }
    return Count;
    fclose(FP);
}