#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRADES_PER_STUDENT 3

struct student {
    char *name;
    int grades[GRADES_PER_STUDENT];
};

float calc_avg(int grades[GRADES_PER_STUDENT]);

int main() {
    struct student s_1 = {
        "Alex",
        {40, 70, 60}
    };

    struct student *s_1_ptr = NULL;

    s_1_ptr = malloc(sizeof(struct student) + 15 * sizeof(char));
    s_1_ptr->name = malloc(15 * sizeof(char));


    if(s_1_ptr == NULL) {
        printf("Memory alocation for s1 ptr");
        return 1;
    }

    if(s_1_ptr->name == NULL) {
        printf("Memory alocation for s1 ptr name");
        return 1;
    }

    strcpy(s_1_ptr->name, "Alex");

    s_1_ptr->grades[0] = 40;
    s_1_ptr->grades[1] = 70;
    s_1_ptr->grades[2] = 60;

    printf("Student %s, have the following grades:\nGrade 1: %d\nGrade 2: %d\nGrade 3: %d\n", s_1_ptr->name, s_1_ptr->grades[0], s_1_ptr->grades[1], s_1_ptr->grades[2]);
    
    float avg = calc_avg(s_1_ptr->grades);

    printf("Student %s, have an average of %.2f\n", s_1_ptr->name, avg);

    free(s_1_ptr->name);
    free(s_1_ptr);
    s_1_ptr = NULL;

    return 0;
}

float calc_avg(int grades[GRADES_PER_STUDENT]) {
    float avg = 0;

    for (int i = 0; i < GRADES_PER_STUDENT; i++) {
        avg += grades[i]; 
    }

    return avg / GRADES_PER_STUDENT;
};
