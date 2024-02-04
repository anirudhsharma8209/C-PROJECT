#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include"Depart.c"
#include"Employee.c"
#include"Allow.c"
#include"Deduct.c"
int main(){
	// Cases Choice
	int Mchoice, Echoice, Dchoice, Achoice;
	char Pchoice;

	// Structure Variables
	Department *D1 = NULL;
	Employee *E1 = NULL;
	Allowance *A1 = NULL;
	Deduction *D = NULL;
	textcolor(GREEN);
	while(1){
		Main:
		system("cls");
		printf("Entering To Program"); Loading(); system("cls");
		printf("\n\t\t * * * * * * * * * * * * * * * * * * * * * * * * ");		
		printf("\n\t\t  <--: P A Y R O L L - M A N A G E M E N T :--> ");
		printf("\n\t\t * * * * * * * * * * * * * * * * * * * * * * * * \n");		
		printf("\n\t : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : \n");		
		printf("\n\t * Enter : [1] --> D E P A R T M E N T - M A N A G E M E N T * \n");
		printf("\n\t * Enter : [2] --> E M P L O Y E E - M A N A G E M E N T     * \n");
		printf("\n\t * Enter : [3] --> P A Y R O L L - M A N A G E M E N T       * \n");
		printf("\n\t * Enter : [4] --> P A Y S L I P - M A N A G E M E N T       * \n");
		printf("\n\t * Enter : [5] --> E X I T - T H E - P R O G R A M           * \n");
		printf("\n\t : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : \n");		
		printf("\n\t Enter Number To Start Your Working : --> ");
		scanf("%d",&Mchoice);
		switch(Mchoice){
			case 1:
			while(1){
				system("cls");
				printf("Entering To Department"); Loading(); system("cls");
				printf("\n\t\t <--: W E L C O M E - T O - D E P A R T M E N T :--> ");
				printf("\n\t   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
				printf("\n\t   * Enter : [1] --> I N S E R T - D E P A R T M E N T (S)   * \n ");
				printf("\n\t   * Enter : [2] --> D I S P L A Y - D E P A R T M E N T (S) * \n");
				printf("\n\t   * Enter : [3] --> R E M O V E - D E P A R T M E N T (S)   * \n");
				printf("\n\t   * Enter : [4] --> S E A R C H - D E A P A R T M E N T (S) * \n");
				printf("\n\t   * Enter : [5] --> B A C K - F R O M - C U R R E N T       * \n");
				printf("\n\t   * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
				printf("\n\t   Enter Your Choice : --> "); fflush(stdin);
				scanf("%d",&Dchoice);
				switch(Dchoice){
					case 1:			
					InsertDepart(D1);
					getch(); break;
					case 2:
					PrintDepart(D1);
					getch(); break;
					case 3:		
					DeleteDepart(D1);
					getch(); break;
					case 4:					
					SearchDepart(D1);
					getch(); break;
					case 5:	
					system("cls"); printf("Exiting From Department"); Loading(); system("cls"); goto Main; break;
					default:
						system("cls");
						printf("\n\n Error Occurs.....");
						printf("\n Invalid - Selection.....!!!");														
					getch(); printf("Reentering To Progam"); Loading();
				}
			}
			getch(); break;
			case 2:
			while(1){
				system("cls");		
				printf("Entering To Employee"); Loading(); system("cls");
				printf("\n\t <--: W E L C O M E - T O - E M P L O Y E E - S E C T I O N :--> \n");
				printf("\n\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
				printf("\n\t | Enter : [1] --> A D D - E M P L O Y E E (S) - R E C O R D S   |\n");
				printf("\n\t | Enter : [2] --> L I S T - E M P L O Y E E (S) - R E C O R D S |\n");
				printf("\n\t | Enter : [3] --> S E A R C H - E M P L O Y E E - R E C O R D S |\n");				
				printf("\n\t | Enter : [4] --> M O D I F Y - E M P L O Y E E - R E C O R D s |\n");
				printf("\n\t | Enter : [5] --> R E M O V E - E M P L O Y E E - R E C O R D S |\n");
				printf("\n\t | Enter : [6] --> B A C K - F R O M - C U R R E N T - S E C.    |");
				printf("\n\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ");
				printf("\n\n\t  Enter Your Choice : --> ");
				scanf("%d",&Echoice);
				switch(Echoice){
					case 1:
					InsertEmployee(E1, D1);
					getch(); break;
					case 2:		
					ListEmployee(E1);
					getch(); break;
					case 3:			
					SearchEmployee(E1);
					getch(); break;				
					case 4:
					ReadEmployee();
					UpdateEmployee(D1, E1);
					getch(); break;
					case 5:
					DeleteEmployee(E1);
					getch(); break;
					case 6:
					system("cls"); printf("Exiting From Employee"); Loading(); goto Main; break;
					default:
						system("cls");
						printf("\n\n Error Occurs.....");
						printf("\n Invalid - Selection.....!!!");														
					getch(); printf("Reentering To Progam"); Loading();
				}
			}
			getch(); break;
			case 3:
			while(1){
				Ded:
				system("cls");
				printf("\n\t\t <--: W E L C O M E - T O - P A Y R O L L :--> \n");
				printf("\n\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
				printf("\n\t * \t Enter : [A] --> A L L O W A N C E - S E C T I O N    *\n");
				printf("\n\t * \t Enter : [D] --> D E D U C T I O N - S E C T I O N    *\n");
				printf("\n\t * \t Enter : [B] --> B A C K - F R O M - C U R R E N T    *\n");
				printf("\n\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
				printf("\n\t Enter Your Choie : --> ");
				fflush(stdin);
				scanf("%c",&Pchoice);
				switch(Pchoice){
					case 'A':
					while(1){
						system("cls");
						printf("\n\t\t <--: W E L C O M E - T O - A L L O W A N C E :--> \n");
						printf("\n\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =  \n");
						printf("\n\t * \t Enter : [1] --> A D D - A L L O W A N C E           * \n");
						printf("\n\t * \t Enter : [2] --> L I S T - A L L O W A N C E (S)     * \n");						
						printf("\n\t * \t Enter : [3] --> B A C K - F R O M - C U R R E N T   * \n");
						printf("\n\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
						printf("\n\t Enter Your Choice : --> ");
						fflush(stdin);
						scanf("%d",&Achoice);
						switch(Achoice){
							case 1:
							ScaningAllow(A1, D1);
							getch(); break;
							case 2:
							ListAllow(A1);
							getch(); break;									
							case 3:
							system("cls"); printf("Returing To Payroll Section"); Loading();
							goto Ded; break;
							default:
								system("cls");
								printf("\n\n Error Occurs.....");
								printf("\n Invalid - Selection.....!!!");														
							getch(); printf("Reentering To Progam"); Loading();
						}
 					}
					getch(); break;
					case 'D':
					while(1){
						system("cls");
						printf("\n\t\t <--: W E L C O M E - T O - D E D U C T I O N :--> \n");
						printf("\n\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
						printf("\n\t * \t Enter : [1] --> A D D - D E D U C T I O N            * \n");
						printf("\n\t * \t Enter : [2] --> L I S T - D E D U C T I O N          * \n ");						
						printf("\n\t * \t Enter : [3] --> B A C K - F R O M - C U R R E N T    *\n");
						printf("\n\t = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
						printf("\n\t Enter Your Choice : --> ");
						scanf("%d",&Dchoice);
						switch(Dchoice){
							case 1:
							AddDeduction(D, E1);
							getch(); break;
							case 2:
							ListDeduction(D);
							getch(); break;														
							case 3:
							system("cls");
								printf("Returing To Payroll Section"); Loading();
							goto Ded; break;
							default:
								system("cls");
								printf("\n\n Error Occurs.....");
								printf("\n Invalid - Selection.....!!!");														
							getch(); printf("Reentering To Progam"); Loading();							
						}
					}
					getch(); break;
					case 'B':
					system("cls"); printf("Returing To Main Menu"); Loading(); system("cls"); goto Main; break;
					default:
						system("cls");
						printf("\n\n Error Occurs.....");
						printf("\n Invalid - Selection.....!!!");														
					getch(); printf("Reentering To Progam"); Loading();
				}
			}
			getch(); break;
			case 4:
			system("cls"); printf("Entering To Payroll Section"); Loading(); system("cls");
			PayRoll(E1, D1, A1, D);
			getch(); break;
			case 5:				
				system("cls"); printf("Exiting The Program"); Loading(); exit(0); break;
			default :
				system("cls");
				printf("\n\n Error Occurs.....");
				printf("\n Invalid - Selection.....!!!");				
				getch(); printf("Reentering To Progam"); Loading();
			}
		}
	}
int PayRoll(Employee *E1, Department *D1, Allowance *A1, Deduction *D){
		int Payslip, TotalAll = 0, TotalDed = 0, TotalAmt = 0, FinalAmt = 0;
		int APer = 0, DPer = 0, TempEnum, FinalAllow = 0, FianlDeduct = 0, TempId, Access = 0;
		char Return, TempDepart[20], TempAllow[20], TempDed[20], TempEmp[20], TempName[20], Temprary[20];
		FILE *FP1 = NULL;
		FILE *FP2 = NULL;
		FILE *FP3 = NULL;
		FILE *FP4 = NULL;		
		Repeat:
		system("cls");
		printf("\n\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
		printf("\n \t ---: W E L C O M E - T O - P A Y R O L L - M A N E G E M E N T :--- \n");
		printf("\n\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
		printf("\n\t\t --: E M P L O Y E E (S) - D E T A I L S :-- \n");
		printf("\n\t ID \t\t Name \t\t Gender \t Salary(P/ M) ");
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
		FP1 = fopen("Employee.txt","r");
		FP2 = fopen("Depart.txt","r");
		FP3 = fopen("Allow.txt","r");	
		FP4 = fopen("Deduct.txt","r");	
		while(!feof(FP1)){
			fscanf(FP1, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);									
			printf("\n\t %d \t\t %s \t %c \t\t %d ",E1->Enum, E1->Name, E1->Gender, E1->Salary);			 			
		}
		fclose(FP1); fclose(FP2); fclose(FP3); fclose(FP4);
		printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n");
		printf("\n\t Enter Employee Id For PaySlip Generation : --> ");		
		scanf("%d",&Payslip);		
		system("cls");		
		FP1 = fopen("Employee.txt","r");
		FP2 = fopen("Depart.txt","r");
		FP3 = fopen("Allow.txt","r");
		FP4 = fopen("Deduct.txt","r");
		while(!feof(FP1)){			
			fscanf(FP1, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);									
			if(Payslip == E1->Enum){
				TempId = E1->DesignationId;
				printf("\n -> %d",TempId);
				system("cls");						
				printf("\n\t\t ---: P A Y S L I P - G E N E R A T I O N :--- ");
				printf("\n\n\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");	
				TempEnum = E1->Enum;			
				strcpy(TempName , E1->Name);
				printf("\n\t |Id :-> %d \t\t\t\t Name :-> %s |",E1->Enum, E1->Name);				
				while(!feof(FP2)){					
					fscanf(FP2, "%d %s %s %s %d",&D1->DepartNum, D1->DepartName, D1->DepartHead, D1->P1.PostName, &D1->P1.PostSalary);																																	
					D1->DepartNum - 1;
					if(TempId == D1->DepartNum){					
						printf("\n\t |Department : -> %s    |    DepartMentId : -> %d |",D1->DepartName, D1->DepartNum);																			
						strcpy(Temprary, D1->DepartName);
					}
				}		
				printf("\n\t |Allowance  \t\t\t\t\t  Deduction|");
				printf("\n\t |\t\t Employee Details Are Here.....!!!! \t  |");
				printf("\n\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");						
				fscanf(FP1, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);				
				FP1 = fopen("Employee.txt","r");
				while(!feof(FP1)){										
					fscanf(FP1, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);																			
					if(Payslip == E1->Enum){
						TotalAmt = E1->Salary * 12;
						printf("\n\t Basic Salary : --> %d(P/ M) \t\t\t %d(P/ A) \n",E1->Salary, TotalAmt);																
					}
				}
				fclose(FP1);				
				FP3 = fopen("Allow.txt","r");
				FP4 = fopen("Depart.txt","r");
				while(!feof(FP4)){
					fscanf(FP4, "%d %s %s %s %d",&D1->DepartNum, D1->DepartName, D1->DepartHead, D1->P1.PostName, &D1->P1.PostSalary);																																	
					if((D1->DepartNum - 900) == TempEnum){
						strcpy(TempDepart, D1->DepartName);								
						while(!feof(FP3)){
							fscanf(FP3, "%d %s %d %s", &A1->AllNum, A1->AllName, &A1->AllPer, A1->AllDeprt);										
							strcpy(TempAllow, A1->AllDeprt);						
							if(strcmp(Temprary, TempAllow) == 0){																						
								APer = (TotalAmt / 100)*A1->AllPer;
								printf("\n\t Less : Allowances Of Employee (%d) [%s] is : -->   %d",A1->AllPer, A1->AllName ,APer);								
								FinalAllow += APer;																							
							}									
						}					
					}
				}								
				fclose(FP3); fclose(FP4);				
				FP3 = fopen("Deduct.txt","r");
				FP4 = fopen("Employee.txt","r");
				while(!feof(FP4)){
					fscanf(FP4, "%d %s %d %c %d",&E1->Enum, E1->Name, &E1->DesignationId, &E1->Gender, &E1->Salary);									
					if(E1->Enum == TempEnum){						
						strcpy(TempEmp, E1->Name);			
						// printf("%s",TempEmp);
						while(!feof(FP3)){
							fscanf(FP3, "%d %s %d %s",&D->DedNum, D->DedName, &D->DedPer, D->DedToEmp);
							strcpy(TempDed, D->DedToEmp);									
							if(strcmp(TempEmp, TempDed) == 0){								
								DPer = (TotalAmt / 100)*D->DedPer;
								fscanf(FP3, "%d %s %d %s",&D->DedNum, D->DedName, &D->DedPer, D->DedToEmp);								
								printf("\n\t Add : Deduction To Employee (%d) [%s] is : ->   %d", D->DedPer, D->DedName, DPer);								
								FianlDeduct += DPer;								
							}
						}
					}					
				}
				fclose(FP3); fclose(FP4);		
				// printf("\n -> %d -> %d",FinalAllow, FianlDeduct);
				FinalAmt = (TotalAmt - FinalAllow) + FianlDeduct;
				printf("\n\n\t Net Bill Amount Of Employee : -->\t\t    %d",FinalAmt);
				printf("\n\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  \n");
				printf("\n\t     Note :- ---> P R O C C E S S - C O M P L E T E D <--- \n");
				printf("\n\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  ");	
				break;									
			}
		}
		fclose(FP1); fclose(FP2); fclose(FP3); fclose(FP4);
}
int Loading(){
	int i;
	for(i = 1; i< 10; i++){
		delay(150);	
		printf(". ");
	}	
}