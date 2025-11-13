#include "contact.h"
// Dummy contact data
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};


/*function to count number of conatcts*/
void populateAddressBook(AddressBook* addressBook)
{
    // 1. find contactCount -> clue to find contactCount => sizeof(arr)/sizeof(arr[0]) = size;
    // copy dummy contacts to our array -> contacts[contactcount]
    // use loop and looping has to be done for addressBook->contactCount times 

    int size = sizeof(dummyContacts) / sizeof(dummyContacts[0]);            // find total size of dummy contacts

    for (int i = 0; i < size; i++) {                                       // load dummy conatcs to addressbokk structure
        addressBook->contacts[i] = dummyContacts[i];
    }
    addressBook->contactCount = size;

}
