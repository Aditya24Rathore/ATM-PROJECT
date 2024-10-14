#include<stdio.h>
#include<stdlib.h>

// Global variables to store transaction details and ATM PINs
float withdraw,deposit,amt=0;
int genpin,checkPin;

// Function to prompt user to enter their PIN
int EnterPIN(){
    printf("\n\nENTER PIN : \n\n");
    scanf("%d",&checkPin);
    return checkPin;
}

// Function to prompt user to generate a new ATM PIN
int GenratePIN(){
    printf("\n\nGENERATE ATM PIN NUMBER : \n\n");
    scanf("%d",&genpin);
    return genpin;
}

// Function to display the current balance
void CheckBalance(){
    printf("\nCURRENR BALANCE IS : %.2fRs\n\n",amt);
}

// Function to deposit money into the account
void Deposit(){
    printf("\nEnter Depositing balance : \n\n");
    scanf("%f",&deposit);
    amt+=deposit;
    printf("\n%.2fRs DEPOSITED\n\n",deposit);
}

// Function to withdraw money from the account
void Withdraw(){
    printf("\nEnter withdrawing Amount : \n\n");
    scanf("%f",&withdraw);
    // Check if the withdrawal amount is valid
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

    // Clear the screen after generating the PIN
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    int countdown=0;
    do {
        countdown++;
        EnterPIN();
    // Verify the entered PIN
        if(genpin==checkPin){
            break;
        }
        else{
            system("cls");
            printf("\n\nINVALID PIN\n\n");
        }
        // If 3 invalid attempts are made, terminate the program
        if(countdown==3){
            printf("ALL THREE ATTEMPTS ARE USED TRY AGAIN LATER....\n\n");
            return 0;
        }   
    } while (genpin!=checkPin);
 int ch;
 do {
    // Main ATM operations menu
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
