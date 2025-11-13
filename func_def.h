#ifndef FUNC_DEF_H
#define FUNC_DEF_H

#include "contact.h"

// Validation functions
int validate_number(AddressBook *addressBook, char *number);
int is_duplicate_number(AddressBook *addressBook, char *new_number);
int validate_email(AddressBook *addressBook, char *email);
int is_duplicate_email(AddressBook *addressBook, char *new_email);

// Basic search functions
void search_name(AddressBook *addressBook);
void search_phone(AddressBook *addressBook);
void search_email(AddressBook *addressBook);

// Search + edit/delete functions
void search_name_edit(AddressBook *addressBook, int f);
void search_phone_edit(AddressBook *addressBook, int f);
void search_email_edit(AddressBook *addressBook, int f);

// Edit/delete helpers
void edit_contact(AddressBook *addressBook, int *index ,int count);
void delete_contact(AddressBook *addressBook, int *index, int count);

#endif
