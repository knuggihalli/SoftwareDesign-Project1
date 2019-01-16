
#include <stdio.h>

//functions
void pr(char s[], float x);
void welcome();
void options();
void pin(float *pin);
void balance();

//MAIN
int main(){
  //vars
  float p = 0;//bit flip for pin
  float b = 5000;//balance
  float numt = 0;// number transactions
  float recipt = 0;//recipt
  float val; // what user does
  float limmit = 1000;
  float dlimmit = 1000;
  float take,give,leave; //Withdrawl amount

  welcome();//Start
  pin(&p);//Get pin and all attempts

  if(p == 0){pr("Fail",0);}else{//The user will either enter or fail
    int x = 0;
    while(x<1){
      options();//Passed now what?
      printf("What will you do [enter a number]:");
      scanf("%f", &val);

      if(val == 1){//balance
        printf("\n");
        printf("Balance: $%.1f\n", b);
        numt++;
      }else if(val == 2){//Withdrawl
        printf("\n");
        printf("Choose $20,$40,$60,$80,$100... [$%.1f limmit]: \n", limmit);
        printf("How much will you withdraw [enter an amount]:");
        scanf("%f", &take);

        if(limmit > 0 && (int)take%20 == 0 && limmit>take){
          limmit = limmit - take;
          b = b - take;
          float output = take/20;
          printf("\n");
          printf("Balance: $%.1f\n", b);
          printf("Limmit: $%.1f\n", limmit);
          printf("Output: %.0f $20 bills \n", output);
          numt++;
        }else{
          printf("You have either hit your limmit for today or have given an invalid input \n");
          printf("Remember all inputs should be an increment of $20 \n");
          numt++;
        }
      }else if(val == 3){//deposit
        printf("\n");
        printf("Deposit nickels, dimes or quarters...\n");
        printf("insert coin...");
        scanf("%f", &give);

        if(((int)give % 5) == 0 && give < dlimmit && (give != 10 && give != 15)){
          dlimmit = dlimmit - give;
          b = b + give;
          printf("\n");
          printf("Balance: $%.1f\n", b);
          printf("Limmit: $%.1f\n", dlimmit);
          numt++;
        }else{
          printf("You have hit your limmit \n");
          numt++;
        }
      }else if(val == 4){//exit
        printf("\n");
        printf("Exit");
        printf("Recipt? [1=yes 2=no]:");
        scanf("%f", &leave);

        if(leave == 1){
          printf("\n");
          pr("Thank you have a good day.", 0);
          printf("Balance: $%.1f\n", b);
          printf("Withdrawl Limmit: $%.1f\n", limmit);
          printf("Deposit Limmit: $%.1f\n", dlimmit);
          printf("Transactions: %.0f\n", numt);
          printf("\n");
          x = 2;
        }else{
          pr("Thank you have a good day.", 0);
          x = 2;
        }
      }else{
        pr("Not a valid input try again", 0);
      }
    }

  }

  return 0;
}

//Generic Function to print UI for string
void pr(char s[], float x) {
  if(x > 0){
    printf("%s: %.1f \n", s,x);
  }else if(x == -1){
    printf("=================================\n");
  }else{
    printf("%s \n", s);
  }
}

//try all pins from user
void pin(float *pin){
    *pin = 1;
}

//welcome
void welcome(){
  printf("Welcome to \"Your Bank of Choice\" \n");
  printf("Please enter your pin below \n");
  printf("=================================\n");
}

//Balance
void balance(){

}

//options
void options(){
  printf("\n");
  pr("-",-1);
  pr("The types of ATM transictions are:", 0);
  printf("\n");
  pr("\t 1.Balance", 0);
  pr("\t 2.Withdrawl", 0);
  pr("\t 3.Deposit", 0);
  pr("\t 4.Exit", 0);
  printf("\n");
}
