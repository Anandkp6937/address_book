#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  FILE*fptr=fopen("contacts.txt","w");
  if(fptr==NULL){
     perror("Error opening file \n");
  }
  else{
     for(int i=0;i<addressBook->contactCount;i++){
          fprintf(fptr,"%s %s %s\n",addressBook->contacts[i].name,
          addressBook->contacts[i].phone,addressBook->contacts[i].email);    
     }
     fclose(fptr);
  }
  

}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE*fptr=fopen("contacts.txt","r");
  addressBook->contactCount = 0;

    if(fptr==NULL){
        printf("Erorr cant open files \n");
    }
    else{
     while (fscanf(fptr, "%49[^,],%19[^,],%49[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3) {
        addressBook->contactCount++;
        if (addressBook->contactCount >= MAX_CONTACTS) break;
    }
    fclose(fptr);
    }
};
