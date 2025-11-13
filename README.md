# Address-Book-Project

📒 Address Book Management System in C

Author: T.L. Srinath
Batch: 25014f_009

A command-line based Address Book application developed in C, allowing users to efficiently manage contact information. This project supports creation, search, edit, deletion, and persistent storage of contacts in a .csv file. Built using modular C programming, it demonstrates robust input validation, file handling, and menu-driven user interaction, simulating the functionality of real-world contact management systems.

📌 Project Overview

Traditional paper-based address books are inefficient and prone to errors. This project provides a digital solution with a terminal-based interface, enabling:

Real-time interaction with the user

Persistent storage of contacts in CSV format

Input validation for name, phone, and email

Duplicate prevention for phone numbers and emails

Modular code structure for scalability and maintainability

⚙️ Technologies & Tools Used

Programming Language: C

Compiler: GCC

Interface: Terminal / Command-line

Data Storage: CSV file (addressBook.csv)

Code Structure: Modular files

main.c – Program entry & menu interface

contact.c / contact.h – Core contact operations

file.c / file.h – File handling (load & save)

func_def.c / func_def.h – Validation, search, edit, delete functions

populate.c / populate.h – Dummy contacts initialization

🧠 Features & Functionalities

The system is menu-driven, supporting the following operations:

Create Contact

Add a new contact with validated name, phone number, and email

Prevents duplicate entries

Search Contact

Search by Name, Phone Number, or Email

Displays matching contact information

Edit Contact

Edit existing contact details after searching

Validation ensures updated data is correct and unique

Delete Contact

Remove contact from the address book

Prompts user for confirmation when multiple matches exist

List Contacts

Displays all stored contacts in a formatted table

Save & Exit

Writes all contacts to addressBook.csv for persistent storage

🔐 Input Validation Rules

Email:

Must contain exactly one @

Domain must contain only alphabets and end with .com

Lowercase alphanumeric characters only

Example: john.doe@example.com

Phone Number:

Exactly 10 digits

Numeric only

Example: 9876543210

Name:

Alphabetic characters only

No numbers or special characters

Example: Alice Smith

Invalid entries are rejected with clear error messages.

💡 Additional Features

Stores contacts in .csv format for external viewing or modification

Handles hundreds of contacts efficiently

Modular and maintainable codebase

Can load dummy contacts for testing purposes

🧩 How It Works

Initialize

Loads contacts from addressBook.csv if it exists, or populates dummy contacts.

Menu Interaction

Displays options to create, search, edit, delete, list contacts, or exit.

Validation & Operations

Ensures phone, email, and name are valid

Prevents duplicates

Updates the address book in memory

Persistent Storage

Saves all contacts to addressBook.csv on exit
