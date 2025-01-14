#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRADES_PER_STUDENT 3

struct student {
    char *name;
    int grades[GRADES_PER_STUDENT];
};

struct student* create_student(char *name, int grades[3]);
void print_student_data(struct student *s);
void free_student(struct student *s);
float calc_avg(int grades[GRADES_PER_STUDENT]);

int main() {
    int student_grades[GRADES_PER_STUDENT][GRADES_PER_STUDENT] = {
        { 90, 75, 82 },
        { 99, 89, 33 }
    };

    struct student *s1 = create_student("Alex", student_grades[0]);
    struct student *s2 = create_student("Bob", student_grades[1]);

    print_student_data(s1);
    printf("-------------\n");
    print_student_data(s2);

    free_student(s1);
    free_student(s2);

    return 0;
}


struct student* create_student(char *name, int grades[3]) {
    struct student *new_student = NULL;
    new_student = malloc(sizeof(struct student));
    new_student->name = malloc(15 * sizeof(char));

    if(new_student == NULL || new_student->name == NULL) {
        printf("Failed to add memory to new student\nBye now!");
        exit(1);
    }

    strcpy(new_student->name, name);

    for (int i = 0; i < GRADES_PER_STUDENT; i++) {
        new_student->grades[i] = grades[i]; 
    }

    return new_student;
}


void print_student_data(struct student *s) {
    int grades[GRADES_PER_STUDENT] = {
        s->grades[0], s->grades[1], s->grades[2]
    };

    printf("Student name: %s\n", s->name);
    printf("Grades: %d %d %d\n", grades[0], grades[1], grades[2]);
    printf("Student average is: %.2f\n", calc_avg(grades));
};

void free_student(struct student *s) {
    free(s->name);
    free(s);
}

float calc_avg(int grades[GRADES_PER_STUDENT]) {
    float avg = 0;

    for (int i = 0; i < GRADES_PER_STUDENT; i++) {
        avg += grades[i]; 
    }

    return avg / GRADES_PER_STUDENT;
}
