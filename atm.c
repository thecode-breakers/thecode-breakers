// A simple ATM machine system.......


#include<stdio.h>
#include<conio.h>
int main()
{
   int pin,pin1=4321,c=1,ch,amt,balance=5000;
   printf("Welcome to the Western Bank\n");
   start:
   printf("Enter the pin number\n");
   scanf("%d", &pin);
   if(pin == pin1)
   {
      printf("Please select your choice\n");
       printf("1.Deposit \n2.Withdraw \n3.Checkbalance \n4.Change pin number \n");
        scanf("%d", &ch);
      switch( ch )
      {
        case 1:printf("Enter the amount:\n");
                 scanf("%d", &amt);
                 if(amt<=20000)
                 {
                     balance = balance+amt;
                     printf("%d",balance);
                 }
                 else
                 {
                     printf("The maximum number of deposit is 20000\n");
                 }
                   break;
        case 2:printf("Enter the amount:\n");
                 scanf("%d", &amt);
                   if(amt<=20000)
                   {
                      if(amt<=balance)
                      {
                          balance = balance-amt;
                          printf("After deducting %d ,current balance:%d\n",amt,balance);
                      }
                      else
                      {
                          printf("Insufficient balance\n");
                      }
                   }
                   else{
                    printf("The maximum number of withdraw is 20000\n");
                   }
                      break;
        case 3:printf("Your balance = %d\n",balance);
                 break;
        case 4:printf("Enter the new pin");
                scanf("%d",&pin1);
                  printf("Your pin is successfully updated....!\nLogin Again\n");
                    goto start;
                       break;

      }
   }
   else
   {
    printf("Please enter the valid pin\n");
       if(c<3)
       {
           c++;
           goto start;
       }
   }
   printf("Press 1 to continue...\n");
     scanf("%d",&ch);
   if(ch==1)
   {
       goto start;
   }
     printf("Thanks for using our Software Application\n");
}
