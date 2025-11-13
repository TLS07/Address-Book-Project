/*NAME-T.L.Srinath
Batch-25014f_009
Project-Addressbook*/


#include <stdio.h>
#include "contact.h"

int main() 
{

   AddressBook book; // structure variable
   initialize(&book); // to loads contacts from .csv file or to load dummy contacts
   int option;
   
  while(1){

  // displaying menu

  printf("\n");
  printf("Address Book Menu:\n");
  printf("1. Create contact\n");
  printf("2. search contact\n");
  printf("3. Edit contact\n");
  printf("4. Delete contact\n");
  printf("5. List all contacts\n");
  printf("6. Exit\n\n");


  printf("Enter your choice \n");
  int ret=scanf("%d",&option);

  if(ret!=1){                                // validate wether  entered  is number
   printf("Invalid enter a number\n");
   while(getchar()!='\n');    // clear buffer
   continue;

  }

  if(option<1 || option>6){                                    // vlaidation of choice
   printf("Invalid input. Please enter a number.\n");
   continue;
  }


  // approriate fucntion call   based on option selected frm the user
 switch(option){
   case 1:
   createContact(&book);
   break;

   case 2:
   searchContact(&book);
   break;

   case 3:
   editContact(&book);
   break;

   case 4:
   deleteContact(&book);
   break;

   case 5:
   listContacts(&book);
   break;

   case 6:
   saveAndExit(&book);
   break;
   }
 }
 return 0;

}

