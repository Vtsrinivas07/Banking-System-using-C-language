# Banking-System-using-C-language
This repository contains a simple bank management system implemented in C. The system allows users to perform basic banking operations such as balance inquiry, money transfer, adding new users, and displaying all user details. The program uses structures to manage user data and provides a console-based interface for interaction.

Features
Balance Inquiry: Check the current balance of a user's account using the account number.
Money Transfer: Transfer money between accounts either by account number or phone number. The system verifies user details before processing the transaction.
Add New User: Add a new user to the system by entering details like name, account number, password, gender, phone number, and initial balance.
Display All Users: Print the details of all users in the system.
Usage
Balance Inquiry:

Select option 1 from the menu.
Enter the account number to view the balance.
Money Transfer:

Select option 2 from the menu.
Choose transfer method: by account number or phone number.
Enter required details and verify before transferring the amount.
Add New User:

Select option 3 from the menu.
Enter the new user's details.
Display All Users:

Select option 4 from the menu.
View the details of all registered users.
Exit:

Select option 5 from the menu to exit the program.
Code Structure
User Structure: Holds information about a user, including name, account number, password, gender, phone number, and balance.
balance_enquiry(): Function to check and display the balance for a given account number.
money_transfer(): Function to transfer money between accounts after validating user details.
add_user(): Function to add a new user to the system.
print_user_details(): Function to print details of all users.
main(): Entry point of the program, displaying the menu and handling user choices.
