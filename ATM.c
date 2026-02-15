#include<stdio.h>
#include<stdlib.h>
double amt = 0;

int PIN(void) {
    int checkPin;

    printf("\n\nEnter the PIN : \n\n");
    scanf("%d",&checkPin);

    return checkPin;
}

int Gen_Pin(void) {
    int genPin;

    printf("\n\nGenerate ATM Pin number : \n\n");
    scanf("%d", &genPin);

    return genPin;
}

void CheckBalance() {

    printf("\nCURRENT BALANCE IS : %.2f Rs\n\n", amt);
}

void Deposit(){

    double deposit;
    printf("\nEnter Depositing balance : \n\n");
    scanf("%lf", &deposit);
    if(deposit > 0) {
        amt += deposit;
        printf("\n%.2f Rs DEPOSITED\n\n", deposit);
    }
    else
        printf("\nWrong Amount");
}

void Withdraw() {

    double withdraw;
    printf("\nEnter withdrawing Amount : \n\n");
    scanf("%lf", &withdraw);
    if(withdraw <= amt && withdraw > 0) {
        amt -= withdraw;

    printf("\nAfter Withdraw Balance is : %.2f Rs\n\n", amt);
    }
    else {
        printf("\nLOW BALANCE... *OR* INVALID INPUT... \n\n");
    }
}

int main(){

    int genPin,checkPin;

    genPin = Gen_Pin();
    system("cls");
    checkPin = PIN();
    
    while(genPin!=checkPin){
        printf("\n\nInvalid PIN\n\n");
        checkPin = PIN();
    }

 int Option;
 
    do {

        printf("\n**********MENU**********");
        printf("\n\n 1 : CHECK BALANCE \n 2 : DEPOSIT \n 3 : WITHDRAW \n 0 : CANCEL TRANSACTION \n");

        printf("\nenter Choice : ");
        scanf("%d", &Option);

            switch(Option) {
                case 1: CheckBalance();
                    break;

                case 2: Deposit();
                    break;

                case 3: Withdraw();
                    break;

                case 0: printf("\nCANCELING TRANSACTION...\n\n");
                    break;

                default : printf("\n\n**Invalid Choice**\n\n");    
            }
    }while (Option != 0);
        
  return 0;
}