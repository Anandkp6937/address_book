#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"



//if user enter a wrong input
void noContactMsg(int found){
	if(!found){
		printf("\n");
		printf("No such contacts..");
		}
};

void  printContact(int i,AddressBook*addressBook){
	printf("\n");
	printf("\n");
	printf(" %s",addressBook->contacts[i].name);
	printf(" %s",addressBook->contacts[i].phone);
	printf(" %s",addressBook->contacts[i].email);
	printf("\n");
	
}

void listContacts(AddressBook *addressBook) 
{
    printf("\n------------------------------------\n");
    for(int i=0;i<addressBook->contactCount;i++){
	printf("%s\t",addressBook->contacts[i].name);
	printf("%s\t",addressBook->contacts[i].phone);
	printf("%s\t",addressBook->contacts[i].email);
	printf("\n ");
    }
}

void initialize(AddressBook *addressBook) {
	//loading addres book from dummy contact
	//populateAddressBook(addressBook);
   //later we use contact.txt file
	populateAddressBook(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
  saveContactsToFile(addressBook);
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    	printf("Enter Name:\n");
    	scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);
    	printf("Enter the phone number \n");
	scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].phone);
	
	printf("Enter mail id: \n");
	scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].email);
	addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
	 /* Define the logic for search */
	int menu=0;
    	char item[200];
    	int found=0;

		printf("1.Search by name \n");
    		printf("2.Search by phone \n");
    		printf("3.Search by email \n");
		scanf(" %d",&menu);
   


	switch(menu){
		case 1:
		//search by name logic
		printf("Enter the name:");
		scanf(" %[^\n]",item);	
		for(int i=0;i<addressBook->contactCount;i++){	
		if(strcmp(addressBook->contacts[i].name,item)==0){
			
			printContact(i,addressBook); //printing the whole details
			found=1;
			
		}
		}
		noContactMsg(found);//calls if no user exist 
		break;

		case 2:
		//search by phone logic
		printf("Enter the phone number:");
		scanf(" %s",item);
		
		for(int i=0;i<addressBook->contactCount;i++){	
		if(strcmp(addressBook->contacts[i].phone,item)==0){
			printContact(i,addressBook);
			found=1;
			
		}
		}
		noContactMsg(found);
		break;

		case 3:
		//search by email logic
		printf("Enter the email id:");
		scanf(" %s",item);
		for(int i=0;i<addressBook->contactCount;i++){	
		if(strcmp(addressBook->contacts[i].email,item)==0){
			printContact(i,addressBook);
			found=1;
			
		}
		}
		noContactMsg(found);
			break;
			
		default:
		printf("Wrong command!");
		break;
		
	}

}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
	char item[100];
	char name[100];
	char phone[100];
	char email[100];
	int found=0;
	printf("\n");
	printf("Enter email or phone number of contact to edit \n");
	scanf(" %s",item);
	for(int i=0;i<addressBook->contactCount;i++){

		if(strcmp(addressBook->contacts[i].email,item)==0 || strcmp(addressBook->contacts[i].phone,item)==0){
	printf("Enter new name:\n");
	scanf(" %[^\n]",name);
	printf("Enter phone number:\n");
	scanf(" %s",phone);

	printf("Enter new mail id:\n");
	scanf(" %s",email);

	strcpy(addressBook->contacts[i].name,name);
	strcpy(addressBook->contacts[i].phone,phone);
	strcpy(addressBook->contacts[i].email,email);
	printf("\n");
	printf("\tNew edited contact is: \n");
	printf("\n");


	printf("%s ",addressBook->contacts[i].name);
	printf("%s ",addressBook->contacts[i].phone);
	printf("%s ",addressBook->contacts[i].email);
		}
		found=1;
	}
	noContactMsg(found);

}

void deleteContact(AddressBook *addressBook)
{
	char item[200];
	int option=0;
	int found=0;
	listContacts(addressBook);
	printf("\n");
	printf("Delete the contact with");
	printf("\n");
	printf("1.Phone number \n");
	printf("2.Email id \n");

	printf("Enter the option:\n");
	scanf("%d",&option);
	typedef struct {
    char name[50];
    char phone[20];
    char email[50];
	} temp;

		int count=(addressBook->contactCount)-1;
	
	switch(option){
		case 1:
		printf("Enter the phone number \n");
		scanf("%s",item);

		for(int i=0;i<addressBook->contactCount;i++){

			if(strcmp(addressBook->contacts[i].phone,item)==0){
				if(i<count){		
				temp temp;
				strcpy(temp.name,addressBook->contacts[count].name);
				strcpy(temp.phone,addressBook->contacts[count].phone);
				strcpy(temp.email,addressBook->contacts[count].email);

				strcpy(addressBook->contacts[count].name,addressBook->contacts[i].name);
				strcpy(addressBook->contacts[count].phone,addressBook->contacts[i].phone);
				strcpy(addressBook->contacts[count].email,addressBook->contacts[i].email);

				strcpy(addressBook->contacts[i].name,temp.name);
				strcpy(addressBook->contacts[i].phone,temp.phone);
				strcpy(addressBook->contacts[i].email,temp.email);

				addressBook->contactCount--;
				listContacts(addressBook);
			}
			else{
				addressBook->contactCount--;
			}
			found=1;
			}	
		}
		noContactMsg(found);
	break;
	case 2:
		printf("Enter the Email id \n");
		scanf("%s",item);
		for(int i=0;i<addressBook->contactCount;i++){
			
			if(strcmp(addressBook->contacts[i].email,item)==0){
				if(i<=count){		
				for(int j=i;j<addressBook->contactCount-1;j++){
					strcpy(addressBook->contacts[i].name,addressBook->contacts[j+1].name);
					strcpy(addressBook->contacts[i].phone,addressBook->contacts[j+1].phone);
					strcpy(addressBook->contacts[i].email,addressBook->contacts[j+1].email);
				}

				addressBook->contactCount--;
				listContacts(addressBook);
	break;
			}
			else{
				addressBook->contactCount--;
			}
			found=1;
			}
			
		}
		noContactMsg(found);
		break;

		default:
		printf("Wrong command");


	}



   
}
