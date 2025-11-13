#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

int validate_number(AddressBook *addressBook, char *number);
int is_duplicate_number(AddressBook *addressBook, char *new_number);
int validate_email(AddressBook *addressBook, char *email);
int is_duplicate_email(AddressBook *addressBook, char *new_email);
void search_name(AddressBook *addressBook);
void search_phone(AddressBook *addressBook);
void search_email(AddressBook *addressBook);
void search_name_edit(AddressBook *addressBook, int f);
void search_phone_edit(AddressBook *addressBook, int f);
void search_email_edit(AddressBook *addressBook, int f);
void edit_contact(AddressBook *addressBook, int *index ,int count);
void delete_contact(AddressBook *addressBook, int *index, int count);





/*function defnation to validate the number is valid
functions checks wheteher there are 10 digits and whether already present in the book */

int validate_number(AddressBook *addressBook, char *number){
    int i,count=0;


    // to check phone number has 10 digits
   for(i=0;number[i]!=0;i++){
    if(number[i] >= '0' && number[i] <= '9'){          //checks if number is b/w 0-9
        count++;
    }
   }
 
   if(count!=10){                                       // valid phone number is of 10  digits
    return 0;                                           // invalid number
   }
   return 1;                                            // valid number
}


int is_duplicate_number(AddressBook *addressBook, char *new_number)
{
    // Loop through all contacts in the address bookk

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // Compare each contact's phone number with the new number
        if (strcmp(addressBook->contacts[i].phone, new_number) == 0)
            return 1;                                                    // Duplicate found
    }
    return 0;                                                          // No duplicate found
}


/* function to validate an email address format

1)we are checking wheter the email has only one @ and there is domain between @ and .com
2)email ends with .com
3)all charcters are lowercase and alphnumeric*/

int validate_email(AddressBook *addressBook, char *email){

    int i=0,len;
    int count_a=0,at_pos=0;


    len=strlen(email);
// to check email has only one '@'
    for(i=0;email[i]!='\0';i++){

        if (email[i]=='@'){
            count_a++;
            at_pos=i;                       // stores positon of @
        }

    }
    if(count_a!=1){
        printf("Email must contain exactly one '@'\n");
        return 0;        //invalid
    }

// ensure there is domain after '@'
    if (at_pos +1 >= len - 4) {
        printf("No domain after @\n");
        return 0; // invalid
    }

// ensure domain between '@' and ',com is only alphabets
    for (i = at_pos + 1; i < len - 4; i++) {
        if (!isalpha(email[i])) {
            printf("Invalid domain character: %c\n", email[i]);
            return 0; // invalid
        }
    }

// to check email ends with .com
    if (!(email[len - 4] == '.' &&
        email[len - 3] == 'c' &&
        email[len - 2] == 'o' &&
        email[len - 1] == 'm')) {
        return 0;                            // invalid
    }

// to check all charcetrs are lower case and alphanumeric
   i=0;
    while (email[i] != '\0') {
        if (isalpha(email[i]) && !islower(email[i])) {
            printf("Invalid character: %c\n", email[i]);
            return 0;                   //invalid
        }
        i++;
    }

    return 1;                           //valid
}



// Function to check if a given email already exists in the address book
int is_duplicate_email(AddressBook *addressBook, char *new_email)
{
    // Loop through all contacts in the address book
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // Compare each contact's email with the new email
        if (strcmp(addressBook->contacts[i].email, new_email) == 0)
            return 1; // Duplicate email found
    }
    return 0; // No duplicate email found
}




// function to search contact by name
void search_name(AddressBook *addressBook){
    char name[20];
    int found=0,i;


    while(1){

        printf("Enter the name:");
        scanf(" %[^\n]",name);

        for(i=0;i<addressBook->contactCount;i++){

            if(strcmp(addressBook->contacts[i].name,name)==0){

                printf("contact found\n\n");
                printf("Name  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n\n\n", addressBook->contacts[i].email);

                found++;
                break;

            }
           
        }
        if(found==0){
            printf("Contact not found\n");
            printf("Try Again\n\n");

            continue;
        }

        break;
    }
}



// Function to search for a contact by phone number
void search_phone(AddressBook *addressBook){
    int i,found=0;
    char number[20];
    int flag=0;

    while(!flag){
        printf("Enter the number: ");
        scanf("%s",number);
        while ((getchar()) != '\n');
    
        flag=validate_number(  addressBook,number);

        if(flag){
            for(i=0;i<addressBook->contactCount;i++){

                if (strcmp(number, addressBook->contacts[i].phone) == 0) // Match found
                {
                    // Print contact details
                    printf("contact \n\n");
                    printf("Name : %s\n", addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n\n", addressBook->contacts[i].email);
                    found++;
                    break;
                }

            }
        }

        if (!flag){
        printf("Invalid number\nTry again\n\n");
        }

    }

    if(found==0){
        printf("Number not found\n");
    }

}



// Function to search for a contact by email address
void search_email(AddressBook *addressBook)
{
    char email[30];               // To store the email entered by the user
    int found = 0, i ,flag=0;

    while (!flag) // Loop until a valid email is entered
    {
        printf("Enter the Email to search:");
         scanf(" %[^\n]", email);      // Read the email input including spaces
                         
        flag = validate_email(addressBook, email); // Validate email format

        if (flag) // If the email is valid
        {
            for (i = 0; i < addressBook->contactCount; i++) // Search through all contacts
            {
                if (strcmp(email, addressBook->contacts[i].email) == 0) // Match found
                {
                    // Print contact details
                    printf("contact  Found\n\n");
                    printf("Name : %s\n", addressBook->contacts[i].name);
                    printf("Phone : %s\n", addressBook->contacts[i].phone);
                    printf("Email : %s\n\n", addressBook->contacts[i].email);
                    found++; // Increment match counter
                    break;
                }
            }
        }
        if (!flag) // If email format is invalid
        {
            printf("Invalid email !\n\n");
        }
    }

    // If no matching email was found
    if (found == 0)
    {
        printf("Email not found\n");
    }
}




// to search by name and edit the contact or delete the conatct based on flag
void search_name_edit(AddressBook *addressBook, int f)
{
    char name[30];         //to store name entered by user
    int count=0,i;         
    int name_index[MAX_CONTACTS];

    while(1){
        printf("Enter the name: ");
        scanf(" %[^\n]", name);
        while (getchar() != '\n'); // Clear input buffer

    
        for(i=0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].name,name)==0)
            {
                name_index[count++]=i;
            }
        }


        if(count==0){
            printf("Contact is not found\n");
            continue;
        }
        else{
            if(f){
                edit_contact(addressBook,name_index,count);
                break;
            }
            else{
                delete_contact(addressBook,name_index,count);
                break;
            }
        }

        break;
    }

}










// Function to search for a contact by phone number and either edit or delete it based on the flag 'f'
void search_phone_edit(AddressBook *addressBook, int f)
{
    int i, count = 0;                                             
    char new_number[20];                                          // To store the phone number entered by the user
    int number_index[MAX_CONTACTS];                                         

    while (1)                                                    // Loop until a valid number is entered and found
    {
        printf("Enter the contact number: ");
        scanf(" %[^\n]", new_number);   // Read phone number including spaces
        while (getchar() != '\n'); // Flush newline

        // Basic validation function
        if (!validate_number(addressBook, new_number)) // Check if number is valid
        {
            printf("Invalid number format!\n");
            continue; // Prompt again if invalid
        }

        count = 0;                                      // Reset count for each attempt
        for (i = 0; i < addressBook->contactCount; i++) // Loop through contacts
        {
            if (strcmp(addressBook->contacts[i].phone, new_number) == 0) // Match found
                number_index[count++] = i;                               // Store index and increment count
        }

        if (count == 0) // No matches found
        {
            printf("Contact number not found.\n");
        }
        else // At least one match found
        {
            if (f)                                                 // If flag is set, perform edit
            {
                edit_contact(addressBook, number_index, count);
                break;
            }
            else                                                     // If flag is not set, perform delete
            {
                delete_contact(addressBook, number_index, count);
                break;
            }
        }
    }
}








// Function to search for a contact by email and either edit or delete it based on the flag 'f'
void search_email_edit(AddressBook *addressBook, int f)
{
    int i, count = 0;                                              
    char new_email[50];                                             // To store the email entered by the user
    int email_index[MAX_CONTACTS];                                   // Array to store the indices of matched contacts

    while (1) // Keep prompting until a valid email is found and processed
    {
        printf("Enter the contact email: ");
      
        scanf(" %[^\n]", new_email);      // Read the email input including spaces
        while (getchar() != '\n');
                                         

                                                                   
        if (!validate_email(addressBook, new_email))                          // Validate the email format
        {
            printf("Invalid email format!\n");
            continue;                                                        // Prompt again if invalid
        }

        count = 0;                                                            // Reset match count before searching
        for (i = 0; i < addressBook->contactCount; i++)                      // Loop through all contacts
        {
            // If email matches, store the index
            if (strcmp(addressBook->contacts[i].email, new_email) == 0)
                email_index[count++] = i;
        }

        if (count == 0)                                                       // No match found
        {
            printf("Contact email not found.\n");
        }
        else                                                                  // One or more matches found
        {
            if (f)                                                           // If flag is set, perform edit
            {
                edit_contact(addressBook, email_index, count);
                break;
            }
            else                                                             // If flag is not set, perform delete
            {
                delete_contact(addressBook, email_index, count);
                break;
            }
        }
    }
}



// to edit the contact 
void edit_contact(AddressBook *addressBook, int *index ,int count){
    int i,f=1,select =1;
    char edit_name[50],edit_number[50],edit_email[50];


    // to show all the matched contacts
    printf("These are the matched conatcts:\n");

    for(i=0;i<count;i++){
        printf("Contact\n");
        printf("Name  : %s\n",addressBook->contacts[index[i]].name);
        printf("Phone : %s\n",addressBook->contacts[index[i]].phone);
        printf("Email : %s\n\n",addressBook->contacts[index[i]].email);
        f++;
    }

    if (count>1){
        while(1){
            printf(" Select one contact (1 to %d): ",count);
            scanf("%d",&select);
            while (getchar() != '\n'); // clear newline

            if(select>=1 && select<=count){
                break;
            }
            else{
                printf("Invalid input\nTry again\n");
            }
        }
    }


    select = index[select-1];  // map number to actual conatct index


    // Asking what to edit

    printf("Choose what to edit:\n");
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("4. Back to main menu\n");

    int option;

    while(1){
        printf("Select option: ");
        scanf("%d",&option);
        while (getchar() != '\n'); // flush newline

        switch(option){
            // to edit name
            case 1:
            printf("Enter the new name: ");
            scanf(" %[^\n]", edit_name);
            while (getchar() != '\n');

            strcpy(addressBook->contacts[select].name,edit_name);
            break;


            case 2:
            while(1){
                // to edit phone number
                printf("Enter the new number: ");
                scanf(" %[^\n]", edit_number);
                while (getchar() != '\n');

                if(!validate_number(addressBook,edit_number)){            //validation of number
                    printf("Invalid number.\n");
                    continue;
                }
                if(!is_duplicate_number(addressBook,edit_number)){        // check for duplicate of number
                    strcpy(addressBook->contacts[select].phone,edit_number);
                    break;
                }
                else{
                    printf("Duplicate number. Try again.\n");
                    continue;
                }
                break;
            }
            break;

            case 3:
            while(1){
                // to enter new email
                printf("Enter the new email: ");
                scanf(" %[^\n]", edit_email);
                while (getchar() != '\n');

                if(!validate_email(addressBook,edit_email)){                     //validate email
                    printf("Invalid email.\n");
                    continue;
                }
                if(!is_duplicate_email(addressBook,edit_email)){                // to check for duplicates
                    strcpy(addressBook->contacts[select].email,edit_email);
                    break;
                }
                else{
                    printf("Duplicate email.\nTry again\n");
                    continue;
                }
                break;
            }
            break;


            case 4:
            // to go back to meu
            return ;


            default:  // invalid option
            printf("Invalid input. Choose  again\n");
            continue;
        }
        break;

        
    }

    printf("\nSuccessfully edited conatct: \n");
    printf("Name : %s\n",addressBook->contacts[select].name);
    printf("Phone : %s\n",addressBook->contacts[select].phone);
    printf("Email : %s\n\n",addressBook->contacts[select].email);
}



// Function to delete a selected contact from the address book
void delete_contact(AddressBook *addressBook, int *index, int count)
{
    int i, select = 1, f = 1; // 'select' stores user's selection, 'f' is used for display numbering

    // Display all matching contacts
    printf("These are the matches contacts:\n");
    for (i = 0; i < count; i++)
    {
        printf("\ncontact %d\n", f);
        printf("Name : %s\n", addressBook->contacts[index[i]].name);
        printf("Phone : %s\n", addressBook->contacts[index[i]].phone);
        printf("Email : %s\n", addressBook->contacts[index[i]].email);
        f++;
    }

    // If there are multiple matches, prompt the user to select one
    if (count > 1)
    {
        while (1)
        {
            printf("Select the one contact  from (1 to %d): ", count);
            scanf("%d", &select);               // Take user input
            if (select >= 1 && select <= count) // Validate input range
                break;
            printf("Invalid selection\n");
        }
    }

    // Convert user selection to actual index in contact array
    select = index[select - 1];

    // Shift all contacts after the selected one to the left by one position
    for (i = select; i < addressBook->contactCount; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    // Decrease total contact count
    addressBook->contactCount--;

    printf("\nContact deleted successfully.\n\n");
}