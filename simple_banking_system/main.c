#include <stdio.h>
#include <stdlib.h>

struct Bank_Account {
    int id;
    int pin;
    float money;
    // char *owner; // this could be first_name_last_name
};

struct Person {
    char *first_name;
    char *last_name;
    struct Bank_Account *bank_accounts;
};

int create_bank_account(struct Person *data_person, struct Bank_Account *data_bank_account);
int deposit(struct Bank_Account *data_bank_account);
void withdraw();
void balance_check();
void transfer(); // we can do an if check if Bank_Account owner is equal to the person
void listBankAccounts(); 

int main() {
    int choice = -1;
    struct Person *person = NULL;
    struct Bank_Account *bank_account = NULL;

    person = malloc(sizeof(struct Person));
    bank_account = malloc(sizeof(struct Bank_Account));

    if (person == NULL || bank_account == NULL) {
        printf("Sorry memory allocation failed");
        return 1;
    }

    bank_account->id = 0;
    bank_account->pin = 0;
    bank_account->money = 0.0f;

    printf("=========== Welcome to C Bank =========== \n");


    while (choice != 6) {
        printf("How we can help you today?\n");

        printf("1. Create bank account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Transfer\n");
        printf("6. Exit\n");


        // while (getchar() != '\n'); 

        scanf("%d", &choice);


        switch (choice) {
            case 1: 
                create_bank_account(person, bank_account);
                break;
            case 2: 
                deposit(bank_account); 
                break;
            case 3: 
                withdraw();
                break;
            case 4: 
                balance_check();
                break;
            case 5:
                transfer();
                break;
            case 6:
                break;
            default:
                printf("Sorry, invalid option\n");
        }
    }

    free(person);
    person = NULL;
    free(bank_account);
    bank_account = NULL;

    printf("See you!\n");

    return 0;
}

int create_bank_account(struct Person *data_person, struct Bank_Account *data_bank_account) {
    char *first_name, *last_name = NULL;
    int pin = 0000;


    first_name = malloc(20 * sizeof(char));
    last_name = malloc(20 * sizeof(char));

    if (first_name == NULL || last_name == NULL) {
        printf("Sorry memory allocation failed");
        return 1;
    }

    /*
    char *first_name;
    char *last_name;
    struct Bank_Account *bank_accounts;
    */

    while (getchar() != '\n'); 

    printf("Please enter your data\n");
    printf("First Name: ");
    scanf("%s", first_name);
    printf("Last Name: ");
    scanf("%s", last_name);
    printf("Bank Account Pin: ");
    scanf("%d", &pin);

    if (pin < 1000 || pin > 9999) {
        printf("\nPin needs to have 4 digis\n");
        printf("\nBank Account Pin: ");
        scanf("%d", &pin);
    }

    data_person->first_name = first_name;
    data_person->last_name = last_name;
    data_bank_account->id = 0;
    data_bank_account->pin = pin;
    data_bank_account->money = 0;

    printf("Your account has been succesfully created!\n");
    printf("============== Here are your details ==============\n");
    printf("First name: %s\n", data_person->first_name);
    printf("Last name: %s\n", data_person->last_name);
    printf("Id: %d\n", data_bank_account->id);
    printf("Pin: %d\n", data_bank_account->pin);
    printf("Money: %f\n", data_bank_account->money);
    printf("============== End of details ==============\n");

    return  0;
};

int deposit(struct Bank_Account *data_bank_account) {
    if (data_bank_account->pin == 0) {
        printf("No bank account, please create one first\n");
        return 1;
    }

    printf("Your account has been succesfully created!\n");
    printf("============== Here are your details ==============\n");
    printf("Id: %d\n", data_bank_account->id);
    printf("Pin: %d\n", data_bank_account->pin);
    printf("Money: %f\n", data_bank_account->money);
    printf("============== End of details ==============\n");

    return 0;
};

void withdraw() {
};

void balance_check() {
};

void transfer() {
};
