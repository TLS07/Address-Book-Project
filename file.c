#include <stdio.h>
#include "file.h"
#include "contact.h"

/*Reads contacts from "book.csv" and stores them in the AddressBook structure.*/
void loadContactsFromFile(AddressBook *addressBook) 
{
    
    FILE *fp;                                    // file pointer
    fp=fopen("book.csv","r");                    //opening book,csv file in read mode
 
    if(fp==NULL){                               // checking file has opened or not
        fprintf(stderr,"Failed to open the file\n");
        return;
    }
    int i=0;


    
    // loading contacts from book.csv file to adddressbook structure
    while(i <MAX_CONTACTS){
        int ret =fscanf(fp,"%30[^,],%30[^,],%30[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        i++;


        if (ret !=3){                   // used to break the loop after loading last contact
        break;
       }
       
    }
    addressBook->contactCount=i-1;
    fclose(fp);
}




// to save contacts from addressbook to book.csv file
void saveContactsToFile(AddressBook *addressBook) 
{
    /*Saves all contacts from the AddressBook structure into a CSV file ("book.csv")*/

    FILE *fp;                                                    // file pointer
    fp=fopen("book.csv","w");                                    // open file in write mode
    if(fp==NULL){                                                // to check file is opend or not
        fprintf(stderr,"Failed to open the file \n");
        return ;
    }
    for(int i=0;i<addressBook->contactCount;i++){                // to save contacts to csv file
        fprintf(fp,"%s,",addressBook->contacts[i].name);
        fprintf(fp,"%s,",addressBook->contacts[i].phone);
        fprintf(fp,"%s\n",addressBook->contacts[i].email);
    }

    printf("contacts saved sucessfully\n");
    printf("Exiting......\n");

    fclose(fp);                                                  //close file pointer
}


