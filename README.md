📒 Address Book Management System in C

Author: T.L. Srinath

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

Create Contact – Add a new contact with validated name, phone number, and email. Prevents duplicate entries.

Search Contact – Search by Name, Phone Number, or Email and display matching contact details.

Edit Contact – Edit existing contact details with validation and duplicate prevention.

Delete Contact – Remove contact from the address book with confirmation.

List Contacts – Display all stored contacts in a formatted table.

Save & Exit – Writes all contacts to addressBook.csv for persistent storage.

🔐 Input Validation Rules

Email: Must contain exactly one @, a valid domain, and end with .com. Only lowercase alphanumeric characters.

Example: john.doe@example.com

Phone Number: Exactly 10 digits, numeric only.

Example: 9876543210

Name: Alphabetic characters only, no numbers or special characters.

Example: Alice Smith

Invalid entries are rejected with clear error messages.

💡 Additional Features

Stores contacts in .csv format for external viewing or modification

Handles hundreds of contacts efficiently

Modular and maintainable codebase

Can load dummy contacts for testing purposes
