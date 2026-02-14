#include<stdio.h>
#include<stdlib.h>
double withdraw,deposit,amt=0;

int PIN(int checkPin){
    printf("\n\nEnter the PIN : \n\n");
    scanf("%d",&checkPin);
    return checkPin;
}

int GPIN(int genPin){
    printf("\n\nGenerate ATM Pin number : \n\n");
    scanf("%d",&genPin);
    return genPin;
}
void CheckBalance(){
    printf("\nCURRENT BALANCE IS : %.2fRs\n\n",amt);
}
void Deposit(){
    printf("\nEnter Depositing balance : \n\n");
    scanf("%lf",&deposit);
    amt+=deposit;
    printf("\n%.2fRs DEPOSITED\n\n",deposit);
}
void Withdraw(){
    printf("\nEnter withdrawing Amount : \n\n");
    scanf("%lf",&withdraw);
    if(withdraw<=amt&&withdraw!=0){
    amt-=withdraw;

    printf("\nAfter Withdraw Balance is : %.2fRs\n\n",amt);
    }
    else{
        printf("\nLOW BALANCE... *OR* INVALID INPUT... \n\n");
    }
}

int main(){

    int genPin,checkPin;

    GPIN(genPin);
    system("cls");
    PIN(checkPin);
    
    while(genPin!=checkPin){
        PIN(checkPin);

        if(genPin==checkPin){
            break;
        }
        else{
            printf("\n\nInvalid PIN\n\n");
        }   
    }     
 int ch;
 do {
    printf("\n\n 1 : CHECK BALANCE \n 2 : DEPOSIT \n 3 : WITHDRAW \n 0 : CANCEL TRANSACTION \n");
    printf("\nenter Choice : ");
    scanf("%d",&ch);
        switch(ch){
            case 1: CheckBalance();
                break;

            case 2: Deposit();
                break;

            case 3: Withdraw();
                break;

            case 0: printf("\nCANCELING TRANSACTION...\n\n");
                break;

            default : printf("\n\n**invalid choice**\n\n");    
        }
    } while (ch!=0);
        
  return 0;
}
