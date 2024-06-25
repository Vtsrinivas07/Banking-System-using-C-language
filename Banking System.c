#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[200];
    long int accno;
    int password;
    char gender[10];
    long int phoneno;
    int balance;
} User;

void balance_enquiry(User *users, int user_count) {
    long int accnum;
    int i;
    printf("Enter account number: ");
    scanf("%ld", &accnum);

    for (i = 0; i < user_count; i++) {
        if (users[i].accno == accnum) {
            printf("Your account balance is %d\n", users[i].balance);
            return;
        }
    }
    printf("Invalid account number\n");
}

void money_transfer(User *users, int user_count) {
    int transfer_method;
    int i, j, confirmation;
    long int accnum1, accnum2, phonenum1, phonenum2;
    int pass1, amount;

    printf("Press 1 for amount transfer through Account number or 2 for amount transfer using Mobile number: ");
    scanf("%d", &transfer_method);

    if (transfer_method == 1) {
        printf("Enter Account number: ");
        scanf("%ld", &accnum1);
        printf("Enter Password: ");
        scanf("%d", &pass1);

        for (i = 0; i < user_count; i++) {
            if (users[i].accno == accnum1 && users[i].password == pass1) {
                break;
            }
        }
        if (i == user_count) {
            printf("Invalid account number or password\n");
            return;
        }

        printf("Account number : %ld \n", users[i].accno);
        printf("Account holder name : %s \n", users[i].name);
        printf("Gender : %s \n", users[i].gender);
        printf("Press 1 if the account details are correct else press 2 if the details are wrong \n");
        scanf("%d", &confirmation);

        if (confirmation != 1) {
            printf("Please retry the payment\n");
            return;
        }

        printf("Enter Account number to which you are transferring: ");
        scanf("%ld", &accnum2);
        if (accnum2 == accnum1) {
            printf("Please use different account details to continue\n");
            return;
        }

        for (j = 0; j < user_count; j++) {
            if (users[j].accno == accnum2) {
                break;
            }
        }
        if (j == user_count) {
            printf("Invalid target account number\n");
            return;
        }

        printf("Account number : %ld \n", users[j].accno);
        printf("Account holder name : %s \n", users[j].name);
        printf("Gender : %s \n", users[j].gender);
        printf("Press 1 if the account details are correct else press 2 if the details are wrong \n");
        scanf("%d", &confirmation);

        if (confirmation != 1) {
            printf("Please retry the payment\n");
            return;
        }

        printf("Enter the amount to be transferred: ");
        scanf("%d", &amount);
        if (users[i].balance >= amount) {
            users[i].balance -= amount;
            users[j].balance += amount;
            printf("Please hold while the payment is processing…. \n");
            printf("Payment of %d rupees is successful \n", amount);
            printf("Amount of %d rupees is deducted from your bank account and the remaining bank balance is %d rupees \n", amount, users[i].balance);
            printf("Thank you\n");
        } else {
            printf("Insufficient balance \n");
        }
    } else if (transfer_method == 2) {
        printf("Enter Phone number: ");
        scanf("%ld", &phonenum1);
        printf("Enter Password: ");
        scanf("%d", &pass1);

        for (i = 0; i < user_count; i++) {
            if (users[i].phoneno == phonenum1 && users[i].password == pass1) {
                break;
            }
        }
        if (i == user_count) {
            printf("Invalid phone number or password\n");
            return;
        }

        printf("Phone number : %ld \n", users[i].phoneno);
        printf("Account number : %ld \n", users[i].accno);
        printf("Account holder name : %s \n", users[i].name);
        printf("Gender : %s \n", users[i].gender);
        printf("Press 1 if the account details are correct else press 2 if the details are wrong \n");
        scanf("%d", &confirmation);

        if (confirmation != 1) {
            printf("Please retry the payment\n");
            return;
        }

        printf("Enter Phone number linked with the bank account you are transferring to: ");
        scanf("%ld", &phonenum2);
        if (phonenum2 == phonenum1) {
            printf("Please use a different phone number\n");
            return;
        }

        for (j = 0; j < user_count; j++) {
            if (users[j].phoneno == phonenum2) {
                break;
            }
        }
        if (j == user_count) {
            printf("Invalid target phone number\n");
            return;
        }

        printf("Phone number : %ld \n", users[j].phoneno);
        printf("Account number : %ld \n", users[j].accno);
        printf("Account holder name : %s \n", users[j].name);
        printf("Gender : %s \n", users[j].gender);
        printf("Press 1 if the account details are correct else press 2 if the details are wrong \n");
        scanf("%d", &confirmation);

        if (confirmation != 1) {
            printf("Please retry the payment\n");
            return;
        }

        printf("Enter the amount to be transferred: ");
        scanf("%d", &amount);
        if (users[i].balance >= amount) {
            users[i].balance -= amount;
            users[j].balance += amount;
            printf("Please hold while the payment is processing…. \n");
            printf("Payment of %d rupees is successful \n", amount);
            printf("Amount of %d rupees is deducted from your bank account and the remaining bank balance is %d rupees \n", amount, users[i].balance);
            printf("Thank you\n");
        } else {
            printf("Insufficient balance \n");
        }
    } else {
        printf("Entered input is invalid\n");
    }
}

void add_user(User **users, int *user_count) {
    *users = realloc(*users, (*user_count + 1) * sizeof(User));
    if (*users == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter account holder name: ");
    scanf("%s", (*users)[*user_count].name);
    printf("Enter account number: ");
    scanf("%ld", &(*users)[*user_count].accno);
    printf("Enter password: ");
    scanf("%d", &(*users)[*user_count].password);
    printf("Enter gender: ");
    scanf("%s", (*users)[*user_count].gender);
    printf("Enter phone number: ");
    scanf("%ld", &(*users)[*user_count].phoneno);
    printf("Enter initial balance: ");
    scanf("%d", &(*users)[*user_count].balance);

    (*user_count)++;
}

void print_user_details(User *users, int user_count) {
    int i;
    printf("\nUser Details:\n");
    for (i = 0; i < user_count; i++) {
        printf("Name: %s, Account Number: %ld, Gender: %s, Phone Number: %ld, Balance: %d\n",
               users[i].name, users[i].accno, users[i].gender, users[i].phoneno, users[i].balance);
    }
}

int main() {
    User *users = NULL;
    int user_count = 0;
    int choice;

    while (1) {
        printf("\n-----------------------");
        printf("\n    State Bank ");
        printf("\n-----------------------");
        printf("\n1. Balance enquiry");
        printf("\n2. Money transfer");
        printf("\n3. Add new user");
        printf("\n4. Display all users");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                balance_enquiry(users, user_count);
                break;
            case 2:
                money_transfer(users, user_count);
                break;
            case 3:
                add_user(&users, &user_count);
                print_user_details(users, user_count); 
                break;
            case 4:
                print_user_details(users, user_count); 
                break;
            case 5:
                free(users);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
