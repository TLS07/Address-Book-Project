
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "func_def.h"

//functions declartions
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void saveAndExit(AddressBook *addressBook);
void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook) ;
void deleteContact(AddressBook *addressBook) ;





// to print contacts of the book
void listContacts(AddressBook *addressBook)  
{
    int i=0;
    printf("Total Number of contacts:%d\n",addressBook->contactCount);        // to print no. of conatacts
    printf("%-7s%-15s%-15s%-30s\n","S.no","Name","Phone.No","Email");
    printf("-------------------------------------------------------------------------\n");

    for(i=0;i<addressBook->contactCount;i++){
    
    printf("%-7d",i+1);
    printf("%-15s",addressBook->contacts[i].name);
    printf("%-15s",addressBook->contacts[i].phone);
    printf("%-30s",addressBook->contacts[i].email);
    printf("\n");
   
    }

}


//to load contacts from book.csv file or load dummy contacts to addressbook
void initialize(AddressBook *addressBook) 
{
   // copy dummy contacts to array 
   addressBook->contactCount = 0;            // Initialize contact count to 0
//    populateAddressBook(addressBook);  

   // to load contacts from book.csv file
   loadContactsFromFile(addressBook);
   
}




// to save contacts and exit the program
void saveAndExit(AddressBook *addressBook) 
{
    saveContactsToFile(addressBook);
    exit(0);
    // not required now 
}




// to add new contact to the address book 
void createContact(AddressBook *addressBook) 
{
    // read name , pho.no , email id
    char name[50];
    char phone[20];
    char email[50];

    // to read name
    printf("Enter Name: ");
    scanf(" %[^\n]", name);
    while (getchar() != '\n');// to clear buffer

    strcpy(addressBook->contacts[addressBook->contactCount].name,name); 
    printf("Name added sucessfully\n");


    // To read phone number
    while(1){

    printf("Enter Phone.No:");
    scanf("%s",phone);
    while (getchar() != '\n');

    if(!validate_number( addressBook,phone)){              // validate the number entered
        printf("Invalid number\n");
        printf("Try again\n\n");
        continue;
    }

    if(is_duplicate_number(addressBook,phone)){            // check number duplicate is present
        printf("Phone number  already available\n");
        printf("Try again\n\n");
    }
    else{
        strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);   // store number
        printf("Phone number added successfully\n");
        break;
     }
    }

    // to read Email
    while(1){

    printf("Enter the Email ID:");
    scanf("%s",email);

    if(!validate_email(addressBook,email)){                // validate the entered  email
        printf("Invalid email\n\n");
        continue;
    }

    if(is_duplicate_email(addressBook,email)){             // check email is already  exist in the book
        printf("Email already available\n");
        printf("Try again\n\n");

    }
    else{
        strcpy(addressBook->contacts[addressBook->contactCount].email, email); // Store email
        printf("Email added successfully\n");
        break;
     }  

    }
    printf("contact added successfully\n\n");
    addressBook->contactCount++;                    // increase count of contacts
}




// to seacrh contacts of book
void searchContact(AddressBook *addressBook) 
{

    int option=0;
    printf("Select anyone of the method to search\n");
    printf("1. By Name\n");
    printf("2. By Number\n");
    printf("3. By Email\n");
    printf("4.Press 4 to goto main menu\n\n");
    
    


    while(1)
    {
        printf("Enter your choice: ");
        if(scanf("%d",&option)!=1){                 // to vildate input is integer

            while (getchar() != '\n'); // Clear invalid input from buffer
            printf("Invalid input.Please enter a number between 1 and 4.\n\n");
            continue;
        }

        // validate the option 
        if(option <1 || option>4){
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            continue;
        }

        switch(option){
            case 1:
            search_name(addressBook); // Search by name
            return;

            case 2:
            search_phone(addressBook); // Search by phone
            return;

            case 3:
            search_email(addressBook); // Search by email
            return;

            case 4:
            printf("Returning to main menu..\n\n");
            return; // back to main

            default:
            printf("Invalid choice.\n Please enter 1 to 4.\n"); // Wrong option
            continue;

        }
    }
}



// to edit contacts of the book
void editContact(AddressBook *addressBook) 
{

    int option;
    while(1)
    {
    //menu
    printf("Select any one of the method to search and edit contact\n");
    printf("1. Name\n");
    printf("2. Phone No.\n");
    printf("3. Email\n");
    printf("4. Back to main menu\n\n");

    
    printf("Enter your choice: ");
    
    if (scanf("%d", &option) != 1) {         // validate number is entered
            while (getchar() != '\n');  // clear buffer
            printf("Invalid input. Please enter a number.\n\n");
            continue;
        }

     // validate the option 
        if(option <1 || option>4){
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            continue;
        }

    switch(option){
        case 1:
        search_name_edit(addressBook,1);      //edit by name  
        break;

        case 2:
        search_phone_edit(addressBook,1);      // edit by phone
        break;

        case 3:
        search_email_edit(addressBook,1);      //edit by email
        break;

        case 4:
        return;

        default:
        printf("Invalid choice, Plz try again\n\n");
        continue;

        }

        break;    //exit after editing

    }
}





// to delete conatct from the  book
void deleteContact(AddressBook *addressBook) 
{
    int option = 0;
    while (1)
    {
    // displaying menu

    printf("Select one to search\n");
    printf("1.name\n");
    printf("2.phone\n");
    printf("3.email\n");
    printf("4.To return main menu\n\n");

    printf("Choose one option:");

    if (scanf("%d", &option) != 1) {      //validate enter is number

        while (getchar() != '\n'); // clear input buffer
        printf("Invalid input. Please enter a number.\n\n");
        continue;

    }

     // validate the option 
        if(option <1 || option>4){
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            continue;
        }


    switch (option)
    {
    case 1:
        search_name_edit(addressBook, 0); // Delete by name
        break;
    case 2:
        search_phone_edit(addressBook, 0); // Delete by phone
        break;
    case 3:
        search_email_edit(addressBook, 0); // Delete by email
        break;
    case 4:
        return; // Back to main menu
    default:
        printf("Invalid Please enter the valid one\n\n"); // Invalid input
        continue;
    }

    break; // Exit after delete
    }

}
