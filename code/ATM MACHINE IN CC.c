#include<stdio.h>
int main()
{
	char name;
	unsigned int number;
	unsigned int withdraw,amount,transfer;
	unsigned int character;
   	char c;
			
	printf("%c", c=201);
	for(character = 1; character <= 40; character++) {
		printf("%c", c=205);
	}							
			printf("%c\n", c=187);
    		
			printf("%c\t\t\t\t\t %c\n", c=186, c=186);
			printf("%c\t**Welcome to ATM Machine**\t %c\n", c=186,c=186);
			printf("%c\t\t\t\t\t %c\n", c=186, c=186);
			
		//	printf("%c\n", c=186);
		//	printf("%c", c=186);
		//	printf("%c",  c=186);
	
			printf("%c",200);
	for(character = 1; character <= 40; character++) {
		printf("%c", c=205);
	}
		//printf("%c", c=186);
		printf("%c", c=188);	
		
		
		///////////////////////////////////////////////////////////////////////////////////
		
		//***************************** THIS IS ATM CODE.********************************//
		
		//////////////////////////////////////////////////////////////////////////////////
		
		
			
			printf("\n\n\n Please Enter The Name: ");
			scanf("%s", &name);
			error:
			printf(" Please Enter The Amount: ");
			scanf("%d", &amount);
			printf("\n\t\t\t \"Welcome %s\"\n",&name);
	if(amount <= 0)
	{
		printf(" ERROR!!!!!!!\n\"BHAI ATM PAGAL NH HAI\"\nNeechy Paise Daal\"\n  ");
		goto error;
	}		
	else {
		 	abc:
			printf("\n 1)  Check Balance:\n ");
			printf("2)  Cash Withdraw:\n");
			printf(" 3)  Transfer Balance:\n\n ");
			printf("Enter a Number: ");
			scanf("%d",&number);
			
				if(number == 1)
				{
					printf("\n Your Current Balance is %d\n",amount);
					goto abc;
				}
				
				if(number == 2)
				{
					Withdraw:
					printf("\nEnter your amount to withdraw: ");
					scanf("%d",&withdraw);
					//amount-=withdraw;
					//printf("You Withdraw: %d\n",withdraw);
					//printf("Your current balance is: %d",amount);
					if (withdraw > amount )
					{
						printf("\nError!!!!! \nPlease enter valid balance to withdraw\n\n ");
						goto Withdraw;
					}
					
					else
					{
					//printf("\n\nEnter your correct amount to withdraw: ");
					//scanf("%d",&withdraw);
					amount -= withdraw;
					printf("You Withdraw: %d\n",withdraw);
					printf("Your Now balance is: %d",amount);
					goto abc;
					}
						
				}
				if(number == 3)
				{
					printf("Which Bank do you transfer the amount \n");
					printf("1) Bank AL-Habib \n");
					printf("2) Meezan Bank   \n");
					printf("3) National Bank \n\n");
					printf("Choose Your Bank: ");
					scanf("%d",&number);
					
					printf("\n\n");
					transfer:
					printf("\nEnter your amount to Transfer: ");
					scanf("%d",&transfer);
					
					if(amount < transfer)
					{
						printf("\nError!!!!! \nPlease enter valid balance to Transfer\n\n ");
						goto transfer;
					}
					
					//else if(transfer > withdraw)
					//{
					//	printf("\nError!!!!! \nPlease enter valid balance to Transfer\n\n ");
					//}
					else
					{
					amount-=transfer;
					printf("You Amount has been transfered : %d\n",transfer);
					printf("Your Now balance is: %d",amount);
					goto abc;
					}
				
				}
		}
	return 0;    
}
