#include <stdio.h>
#include "student.h"

#define NUM_STUDENTS 1
#define NUM_SUBJECTS 5

int main() {
    Student students[NUM_STUDENTS];
    FILE *file = fopen("students.csv", "r");

    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (feof(file)) {
            break;
        }
        getStudentDetailsFromFile(file, &students[i]);
        students[i].sgpa = calculateSGPA(students[i].marks);
    }

    fclose(file);

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\n---------------------------------------------\n");
        displayGradeCard(&students[i]);
        freeStudent(&students[i]);
    }

    return 0;
}
