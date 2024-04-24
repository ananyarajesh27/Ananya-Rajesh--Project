#include <stdio.h>
#include "student.h"

#define NUM_STUDENTS 1
#define NUM_SUBJECTS 5

int main() {
    Student students[NUM_STUDENTS];
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        getStudentDetails(&students[i]);
        students[i].sgpa = calculateSGPA(students[i].marks);
    }

    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\n---------------------------------------------\n");
        displayGradeCard(&students[i]);
    }

    return 0;
}

