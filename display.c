#include <stdio.h>
#include "student.h"

void displayGradeCard(const Student *student) {
    char *subjects[] = {"Maths", "PSWC", "Mechanical", "Physics", "Electrical"};
    // char *exams[] = {"ISA1", "ISA2", "ESA"}; // Unused variable
    int credits[] = {4, 5, 3, 5, 4}; // Credits per subject

    printf("\nGrade Card for %s (SRN: %s, Semester: %d)\n", student->name, student->srn, student->semester);
    printf("--------------------------------------------------------\n");

    printf("Subject\t\tISA1\tISA2\tESA\tCredits\tGrade\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("%-10s", subjects[i]);
        for (int j = 0; j < 3; j++) {
            printf("\t%d", student->marks[i][j]);
        }
        // Calculate subject marks and grade
        int totalMarks = student->marks[i][0] + student->marks[i][1] + student->marks[i][2];
        int subjectMarks = totalMarks / 2 + (student->marks[i][2] * 2) / 5;
        char grade = calculateGrade(subjectMarks);
        // Print credits and letter grade
        printf("\t%d\t%c\n", credits[i], grade);
    }

    // Print SGPA
    printf("\nSGPA: %.2f\n", student->sgpa);
}

