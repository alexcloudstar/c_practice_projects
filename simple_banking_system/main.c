#include <stdio.h>
#include <stdlib.h>

struct Bank_Account {
    int id;
    int pin;
    float money;
};

struct Person {
    char *first_name;
    char *last_name;
    struct Bank_Account *bank_accounts;
    int num_accounts;
};

int create_bank_account(struct Person *data_person, struct Bank_Account *data_bank_account);
int deposit(struct Person *data_person);
int withdraw(struct Person *data_person);
int balance_check(struct Person *data_person);
void transfer(struct Person *data_person);
void listBankAccounts(struct Person *data_person);
struct Bank_Account *find_account(struct Person *data_person, int id);

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
        printf("6. List Bank Accounts\n");
        printf("7. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                create_bank_account(person, bank_account);
                break;
            case 2: 
                deposit(person); 
                break;
            case 3: 
                withdraw(person); 
                break;
            case 4: 
                balance_check(person);
                break;
            case 5:
                transfer(person);
                break;
            case 6:
                listBankAccounts(person);
                break;
            case 7:
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

    if(data_person->num_accounts == 0) {
        printf("Please enter your data\n");
        printf("First Name: ");
        scanf("%s", first_name);
        printf("Last Name: ");
        scanf("%s", last_name);


        data_person->first_name = first_name;
        data_person->last_name = last_name;
    }

    printf("Bank Account Pin: ");
    scanf("%d", &pin);

    if (pin < 1000 || pin > 9999) {
        printf("\nPin needs to have 4 digis\n");
        printf("\nBank Account Pin: ");
        scanf("%d", &pin);
    }

    data_person->bank_accounts = realloc(data_person->bank_accounts, (data_person->num_accounts + 1) * sizeof(struct Bank_Account));

    if (data_person->bank_accounts == NULL) {
        printf("Sorry memory allocation failed");
        return 1;
    }

    struct Bank_Account *new_account = &data_person->bank_accounts[data_person->num_accounts];

    new_account->id = data_person->num_accounts + 1;
    new_account->pin = pin;
    new_account->money = 0;

    data_person->num_accounts++;

    printf("Your account has been successfully created!\n");
    printf("Account ID: %d\n", new_account->id);

    return  0;
};

struct Bank_Account *find_account(struct Person *data_person, int id) {
    for (int i = 0; i < data_person->num_accounts; i++) {
        if(data_person->bank_accounts[i].id == id) {
            return &data_person->bank_accounts[i];
        } 
    }

    return NULL;
}

int deposit(struct Person *data_person) {
    int id;
    printf("Enter account ID: ");
    scanf("%d", &id);

    struct Bank_Account *account = find_account(data_person, id);

    if (account == NULL) {
        printf("Account not found\n");
        return 1;
    }

    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    account->money += amount;
    printf("Deposit successful! New balance: %.2f\n", account->money);

    return 0;
};

int withdraw(struct Person *data_person) {
    int id;
    printf("Enter account ID: ");
    scanf("%d", &id);

    struct Bank_Account *account = find_account(data_person, id);
    if (account == NULL) {
        printf("Account not found\n");
        return 1;
    }

    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (account->money < amount) {
        printf("Insufficient funds\n");
        return 1;
    }

    account->money -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", account->money);

    return 0;
}

int balance_check(struct Person *data_person) {
    int id;
    printf("Enter account ID: ");
    scanf("%d", &id);

    struct Bank_Account *account = find_account(data_person, id);
    if (account == NULL) {
        printf("Account not found\n");
        return 1;
    }

    printf("Account ID: %d\n", account->id);
    printf("Balance: %.2f\n", account->money);

    return 0;
}

void transfer(struct Person *data_person) {
    int from_id, to_id;
    printf("Enter your source account ID: ");
    scanf("%d", &from_id);
    printf("Enter the destination account ID: ");
    scanf("%d", &to_id);

    struct Bank_Account *from_account = find_account(data_person, from_id);
    struct Bank_Account *to_account = find_account(data_person, to_id);

    if (from_account == NULL || to_account == NULL) {
        printf("Invalid account ID(s)\n");
        return;
    }

    float amount;
    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    if (from_account->money < amount) {
        printf("Insufficient funds in source account\n");
        return;
    }

    from_account->money -= amount;
    to_account->money += amount;

    printf("Transfer successful!\n");
    printf("New balance of source account (ID: %d): %.2f\n", from_account->id, from_account->money);
    printf("New balance of destination account (ID: %d): %.2f\n", to_account->id, to_account->money);
}

void listBankAccounts(struct Person *data_person) {
    if (data_person == NULL || data_person->num_accounts == 0 || data_person->bank_accounts == NULL) {
        printf("No accounts found or invalid data.\n");
        return;
    }

    printf("Listing all accounts for %s %s:\n", 
           data_person->first_name ? data_person->first_name : "Unknown", 
           data_person->last_name ? data_person->last_name : "Unknown");

    for (int i = 0; i < data_person->num_accounts; i++) {
        struct Bank_Account *account = &data_person->bank_accounts[i];
        printf("Account ID: %d, Balance: %.2f\n", account->id, account->money);
    }
}

