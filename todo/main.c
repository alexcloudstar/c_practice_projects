#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TODOS 10

struct Todo {
    int id;
    char *name;
    bool isCompleted;
};

int addTodo(struct Todo *todos, int *count);
int listTodos(struct Todo *todos, int count);
int completeTodo(struct Todo *todos, int todo_id);

int main() {
    struct Todo *todos = NULL;
    int choice = -1;
    int count = 0;

    todos = malloc(MAX_TODOS * sizeof(struct Todo));

    if(todos == NULL) {
        printf("Memory allocation for todos failed.");
        return 1;
    }

    for (int i = 0; i < MAX_TODOS; i++) {
        todos[i].name = NULL;
    }

    while (choice != 4) {
        printf("Please select one of the options:\n");
        printf("1. Add Todo\n");
        printf("2. List todo's\n");
        printf("3. Complete todo\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addTodo(todos, &count);
                break;
            case 2:
                listTodos(todos, count);
                break;
            case 3:
                completeTodo(todos, 0);
                break;
            case 4:
                break;
            default:
                printf("Invalid option\n");
        }
    };

    for (int i = 0; i < 100; i++) {
        if (todos[i].name != NULL) {
            free(todos[i].name);
        }
    }

    free(todos);

    todos = NULL;

    return 0;
}

int addTodo(struct Todo *todos, int *count) {
    char *input = NULL;
    input = malloc(100 * sizeof(char));

    if(input == NULL) {
        printf("Memory allocation for todos failed.");
        return 1;
    }

    todos[*count].name = malloc(strlen(input) + 1);

    if(todos[*count].name == NULL) {
        printf("Memory allocation for todos failed.");
        return 1;
    }

    while (getchar() != '\n'); 

    printf("Enter your todo: ");
    scanf("%[^\n]", input);

    todos[*count].id = *count;
    strcpy(todos[*count].name, input);
    todos[*count].isCompleted = false;

    free(input);
    input = NULL;

    (*count)++;

    printf("Todo added succesfully\n");

    return 0;
};

int listTodos(struct Todo *todos, int count) {
    for (int i = 0; i < count; i++) {
        printf("\n---- Todo %d -----\n", todos[i].id + 1);
        printf("Name: %s\n", todos[i].name);
        printf("Is completed: %s\n", todos[i].isCompleted ? "yes" : "no");
        printf("---------------\n");
    }

    return 0;
};

int completeTodo(struct Todo *todos, int todo_id) {
    int input = -1;
    printf("What todo you want to complete? ");
    scanf("%d", &input);

    if(input < 0 || input > MAX_TODOS) {
        printf("Nope");
        return -1;
    }

    todos[input-1].isCompleted = !todos[input-1].isCompleted; 

    printf("\n Todo marked as completed\n");

    return 0;
};
