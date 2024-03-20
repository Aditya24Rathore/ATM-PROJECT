#include<stdio.h>
float withdraw,deposite,amt=0;
void CheckBalance(){
    printf("\nCURRENR BALANCE IS : %.2fRs\n\n",amt);
}
void Deposite(){
    printf("\nEnter Depositing balance : \n\n");
    scanf("%f",&deposite);
    amt+=deposite;
    printf("\n%.2fRs DEPOSITED\n\n",deposite);
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
 int ch;
 do {
    printf(" 1 : CHECK BALANCE \n 2 : DEPOSITE \n 3 : WITHDRAW \n 0 : CANCEL TRANSATION \n");
    printf("\nenter Choice : ");
    scanf("%d",&ch);
        switch(ch){
            case 1: CheckBalance();
                break;

            case 2: Deposite();
                break;

            case 3: Withdraw();
                break;

            case 0: printf("\nCANCELING TRANSACTION...\n\n0");
        }
    } while (ch!=0);
  return 0;
}
