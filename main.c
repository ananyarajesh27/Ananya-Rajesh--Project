#include <stdio.h>
#include "student.h"

#define NUM_STUDENTS 1
#define NUM_SUBJECTS 5

int main() {
    char names[NUM_STUDENTS][50];
    char srns[NUM_STUDENTS][14]; 
    int semesters[NUM_STUDENTS];
    int marks[NUM_STUDENTS][NUM_SUBJECTS][3]; 
    float sgpas[NUM_STUDENTS];

    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        getStudentDetails(names[i], srns[i], &semesters[i], marks[i], NUM_SUBJECTS);
        sgpas[i] = calculateSGPA(marks[i], NUM_SUBJECTS);
    }

    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        printf("\n---------------------------------------------\n");
        displayGradeCard(names[i], srns[i], semesters[i], marks[i], NUM_SUBJECTS, sgpas[i]);
    }

    return 0;
}
