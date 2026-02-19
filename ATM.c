#include<stdio.h>
#include<stdlib.h>
double balance = 0;

int read_pin(void) {
    int enteredPin;

    printf("\n\nEnter the PIN : \n\n");
    scanf("%d",&enteredPin);

    return enteredPin;
}

int generate_pin(void) {
    int generatedPin;

    printf("\n\nGenerate ATM Pin number : \n\n");
    scanf("%d", &generatedPin);

    return generatedPin;
}

void check_balance() {

    printf("\nCURRENT BALANCE IS : %.2f Rs\n\n", balance);
}

void deposit_money(){

    double depositAmount;
    printf("\nEnter Depositing balance : \n\n");
    scanf("%lf", &depositAmount);

    if(depositAmount > 0) {
        balance += depositAmount;
        printf("\n%.2f Rs DEPOSITED\n\n", depositAmount);
    }
    else if(depositAmount <= 0) {
        printf("\n\nInvalid Input\n\n");
    }
}

void withdraw_money() {

    double withdrawAmount;
    printf("\nEnter withdrawing Amount : \n\n");
    scanf("%lf", &withdrawAmount);

    if(withdrawAmount <= 0){
        printf("\n\nInvalid Input\n\n");
    }
    else if(withdrawAmount > balance) {
        printf("\nLow Balance... \n\n");
    }
    else if(withdrawAmount <= balance) {
        balance -= withdrawAmount;
        printf("\nAfter Withdraw Balance is : %.2f Rs\n\n", balance);
    }
}

//! Need to implement the pin validation function
// int validate_pin() {
//     // TODO: Implement PIN validation logic
//     return 0;
// }

int main(){

    int generatedPin,enteredPin;

    generatedPin = generate_pin();
    system("cls");
    enteredPin = read_pin();
    
    int pinAttempts = 0;
    while(generatedPin != enteredPin) {
        pinAttempts++;
        printf("\n\nInvalid PIN\n\n");

        if(pinAttempts == 3) {
            printf("\nCard Blocked!\n");
            return 0;
        }
        enteredPin = read_pin();
    }

    int choice;
 
    do {

        printf("\n**********MENU**********");
        printf("\n\n 1 : CHECK BALANCE \n 2 : DEPOSIT \n 3 : WITHDRAW \n 0 : CANCEL TRANSACTION \n");
        printf("\n************************\n");

        printf("\nenter Choice : ");
        scanf("%d", &choice);

            switch(choice) {
                case 1: check_balance();
                    break;

                case 2: deposit_money();
                    break;

                case 3: withdraw_money();
                    break;

                case 0: printf("\nCANCELING TRANSACTION...\n\n");
                    break;

                default : printf("\n\n**Invalid Choice**\n\n");    
            }
    }while (choice != 0);
        
return 0;
}