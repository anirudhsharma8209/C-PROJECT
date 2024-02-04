#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int PostId();
int DeptId();
typedef struct PostInfo{	
	char PostName[20];
	int PostSalary;
} Post;
typedef struct Department{
	int DepartNum;
	char DepartName[20];
	char DepartHead[20];
	Post P1;
} Department;
void InsertDepart(Department *D1){
    int i, TDepart, Sc;
    char Dc[20], Pc[20], THead[20], AddMore;
    FILE *FP = NULL;
    FILE *Check = NULL;
    system("cls");
    printf("\n \t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n\t    ---: P R O V I D E  - D E P A R T M E N T - D E T A I L S :--- ");
    printf("\n \t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\n\t\t Enter Total Department (S) To Insert : --> "); 
    fflush(stdin);
    scanf("%d",&TDepart);
    FP = fopen("Depart.txt","a");
    D1 = (Department *)calloc(sizeof(Department), TDepart);
    for(i = 0; i < TDepart; i++){
        printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
        fflush(stdin);
        printf("\n\t\t Department Number/ Identy : --> ");
        D1->DepartNum = DeptId() + 1;
        printf("%d",D1->DepartNum);
        Top1:               
        printf("\n\n\t\t Enter Department Name :--> ");
        gets(Dc);
        for(i = 0 ; i < strlen(Dc); i++){
            if(Dc[i] >= 'a' && Dc[i] <= 'z' || Dc[i] >= 'A' && Dc[i] <= 'Z' || Dc[i] == ' '){
                strcpy(D1->DepartName, Dc);
            }
            else{
                printf("\n\t\t Invalid Name....!!!");
                goto Top1;
            }
        }        
        Name:
        printf("\n\t\t Enter Department Head Name : --> ");
        fflush(stdin);
        gets(THead);         	       
        for(i = 0 ; i < strlen(THead); i++){
            if(THead[i] >= 'a' && THead[i] <= 'z' || THead[i] >= 'A' && THead[i] <= 'Z' || THead[i] == ' ')
                strcpy(D1->DepartHead, THead);
            else{
                printf("\n\t\t Invalid Name....!!!");
                goto Name;
            }
        }        
        Add:
        printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
        printf("\n\t\t ---: P R O V I D E - P O S T - D E T A I L S :--- ");      
        Top2:                
        printf("\n\n\t\t Enter Post Name : --> ");
        gets(Pc);        
        for(i = 0; i < strlen(Pc); i++){
            if(Pc[i] >= 'a' && Pc[i] <= 'z' || Pc[i] >= 'A' && Pc[i] <= 'Z' || Pc[i] == ' '){
		strcpy(D1->P1.PostName, Pc);
            }
            else{
                printf("\n\t Invalid Name....!!!");
                goto Top2;
            }
        }
        fflush(stdin);             
        Num:  
        printf("\n\t\t Enter Emoloyee Salary (P /M) : --> ");
        scanf("%d",&Sc);
        if(Sc >= 'a' && Sc <= 'z' || Sc >= 'A' && Sc <= 'Z' || Sc == ' '){
            printf("\n\t\t Numbers Allowed Only...!!!");
            goto Num;            
        }
        else{
            D1->P1.PostSalary = Sc;
        }
        printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
        printf("\n\t\t\t ---->> Process - Completed <<---- \n");    
	    fprintf(FP, "\n\t %d \t %s \t %s \t %s \t %d",D1->DepartNum, D1->DepartName, D1->DepartHead, D1->P1.PostName, D1->P1.PostSalary);
        // printf("\n\t Do You Want To Add More Post in This Department : --> (Y/ N) ");
        // fflush(stdin);
        // scanf("%c",&AddMore);
        // if(AddMore == 'Y' || AddMore == 'y'){
        //     goto Add;
        // }
        // else{
        //     printf("\n\t\t %s Department have This Post : %s ",D1->DepartName, D1->P1.PostName);
        // }
    }
    fclose(FP);    
}
void PrintDepart(Department *D1){
    char Temp;
    FILE *FP = NULL;
    system("cls");
    printf("\n\t   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\n\t\t ---: D E P A R T M E N T (S) - D E T A I L :--- \n");
    printf("\n\t   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\n\t Id \t DName \t\t DHead \t\t PostName  \t PostSalary ");							
    printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    FP = fopen("Depart.txt","r");
    while(!feof(FP)){
        Temp = getc(FP);
        printf("%c",Temp);
    }
    fclose(FP);
    printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\n\t\t      --->> Press Any Key To Main Menu <<--- \n");
}
int SearchDepart(Department *D1){
    int TempId, Access = 0;
    FILE *FP = NULL;
    system("cls");
    printf("\n\t   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
    printf("\n\t\t\t Enter Department Identy : --> ");
    scanf("%d",&TempId);
    FP = fopen("Depart.txt","r");
    while(1){
	fscanf(FP,"%d %s %s %s %d",&D1->DepartNum,D1->DepartName, D1->DepartHead, D1->P1.PostName, &D1->P1.PostSalary);
	if(D1->DepartNum == TempId){
	    Access = 1;		    	    
	    printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	    printf("\n Record Found :---> \n");
        printf("\n\t Id \t DName \t\t DHead \t\t PostName  \t PostSalary ");	
	    printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	    printf("\n\t %d \t %s \t %s \t %s \t %d",D1->DepartNum, D1->DepartName, D1->DepartHead, D1->P1.PostName, D1->P1.PostSalary);
        if(getc(FP) == EOF)
            break;
        }
	}
    if(Access == 0){
		printf("\n\t\t There is No Such Type Of Record Available...!!! \n");
    }    
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t\t      --->> Press Any Key To Main Menu <<--- \n");
    fclose(FP);
}
void DeleteDepart(Department *D1){
	int DepartId, Access = 0;
	FILE *FP = NULL;
	FILE *FP1 = NULL;	
	system("cls");
	printf("\n\t   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t\t Enter Department Id For Remove : --> ");
	fflush(stdin);
	scanf("%d",&DepartId);		
    FP = fopen("Depart.txt","r+");
	FP1 = fopen("Temp.txt","a+");
	while(!feof(FP)){		
		fscanf(FP,"%d %s %s %s %d",&D1->DepartNum, D1->DepartName, D1->DepartHead, D1->P1.PostName, &D1->P1.PostSalary);		        
		if(D1->DepartNum != DepartId){
			Access = 1;						
			fprintf(FP1, "\n \t %d \t %s \t %s \t %s \t %d",D1->DepartNum, D1->DepartName, D1->DepartHead, D1->P1.PostName, D1->P1.PostSalary);
		}	       
	}
	if(Access == 1)
		printf("\n\t\t\t Record Deleted Succussfully...!!");
	else
		printf("\n\t\t There is No Such Type Of Record Available...!!! \n");	    	    
	fclose(FP);
	fclose(FP1);
	remove("Depart.txt");
	rename("Temp.txt","Depart.txt");	
	printf("\n * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
	printf("\n\t\t      --->> Press Any Key To Main Menu <<--- \n");
}


// Auto Generate ID Department
int DeptId(){
    int Count = 1000;
    char Temp;
    FILE *FP = NULL;
    FP = fopen("Depart.txt","r");
    while(!feof(FP)){
        Temp = getc(FP);
        if(Temp == '\n'){
            Count++;
        }
    }
    return Count;
    fclose(FP);
}
// Auto Generate Id Post 
int PostId(){
    int Count = 100;
    char Temp;
    FILE *FP = NULL;
    FP = fopen("Depart.txt","r");
    while(!feof(FP)){
        Temp = getc(FP);
        if(Temp == '\n'){
            Count++;
        }
    }
    return Count;
    fclose(FP);
}
