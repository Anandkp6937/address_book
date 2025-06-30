#include <stdio.h>
#include "contact.h"

int main() {
       int choice=0;
       AddressBook var1;
       initialize(&var1);

do{
	 printf("\n");
       printf("\n");
 	printf("\033[1m \t Address menu \033[0m\n");
	printf("\033[1;32m------------------------------------\033[0m\n"); // Red
       printf("1.Create contact \n");
       printf("2.Edit contact \n");
       printf("3.Search contact \n");
       printf("4.Delete contact \n");
       printf("5.List all contact \n");
       printf("6.Save contact to file \n");
       printf("7.Exit. \n");
       printf("--------------------------------------------- \n");
       printf("Enter your choice \U0001F600: ");
       scanf(" %d",&choice);
       printf("\n");

    switch(choice){
       case 1:
	 printf("Create contact\n");
        createContact(&var1);
       break;
        case 2:
	       printf("Edit  contact\n");
             editContact(&var1);
       break;
        case 3:

	       printf("Search  contact\n");
               searchContact(&var1);
       break;
        case 4:
	       printf("\t List of current contacts \n");
              deleteContact(&var1);
       break;
        case 5:
	       printf("\t Contact List\n");
              listContacts(&var1);
       break;
        case 6:

	       printf("Save contact\n");
       break;
        case 7:
        printf("Saving the contact and exiting...\n");
       break;

       default:
       printf("nothing to do");
 
    }
}while(choice !=7);
 return 0;
}



    
      

