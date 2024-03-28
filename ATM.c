#include<stdio.h>
#include<stdlib.h>
float withdraw,deposit,amt=0;
int genpin,checkPin;

int EnterPIN(){
    printf("\n\nENTER PIN : \n\n");
    scanf("%d",&checkPin);
    return checkPin;
}

int GenratePIN(){
    printf("\n\nGENERATE ATM PIN NUMBER : \n\n");
    scanf("%d",&genpin);
    return genpin;
}
void CheckBalance(){
    printf("\nCURRENR BALANCE IS : %.2fRs\n\n",amt);
}
void Deposit(){
    printf("\nEnter Depositing balance : \n\n");
    scanf("%f",&deposit);
    amt+=deposit;
    printf("\n%.2fRs DEPOSITED\n\n",deposit);
}
void Withdraw(){
    printf("\nEnter withdrawing Amount : \n\n");
    scanf("%f",&withdraw);
    if(withdraw<=amt&&withdraw!=0){
    amt-=withdraw;

    printf("\nAfter Withhdraw Balance is : %.2fRs\n\n",amt);
    }
    else{
        printf("\nLOW BALANCE... *OR* INVALID INPUT... \n\n");
    }
}

int main(){
    GenratePIN();
    system("cls");
    int condown=0;
    do {
        condown++;
        EnterPIN();

        if(genpin==checkPin){
            break;
        }
        else{
            system("cls");
            printf("\n\nINVALID PIN\n\n");
        }
        if(condown==3){
            printf("ALL THREE ATTEMPTS ARE USED TRY AGAIN LATER....\n\n");
            return 0;
        }   
    } while (genpin!=checkPin);
 int ch;
 do {
    printf("\n\n 1 : CHECK BALANCE \n 2 : DEPOSIT \n 3 : WITHDRAW \n 0 : CANCEL TRANSATION \n");
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
