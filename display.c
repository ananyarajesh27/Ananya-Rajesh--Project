#include <stdio.h>
#include "student.h"

void displayGradeCard(const char *name, const char *srn, int semester, int marks[][3], int numSubjects, float sgpa) {
    char *subjects[] = {"Maths", "PSWC", "Mechanical", "Physics", "Electrical"};
    char *exams[] = {"ISA1", "ISA2", "ESA"};
    int credits[] = {4, 5, 3, 5, 4}; // Credits per subject

    printf("\nGrade Card for %s (SRN: %s, Semester: %d)\n", name, srn, semester);
    printf("--------------------------------------------------------\n");

    printf("Subject\t\tISA1\tISA2\tESA\tCredits\tGrade\n");
    for (int i = 0; i < numSubjects; i++) {
        printf("%-10s", subjects[i]);
        for (int j = 0; j < 3; j++) {
            printf("\t%d", marks[i][j]);
        }
        // Calculate subject marks and grade
        int totalMarks = marks[i][0] + marks[i][1] + marks[i][2];
        int subjectMarks = totalMarks / 2 + (marks[i][2] * 2) / 5;
        char grade = calculateGrade(subjectMarks);
        // Print credits and letter grade
        printf("\t%d\t%c\n", credits[i], grade);
    }

    // Print SGPA
    printf("\nSGPA: %.2f\n", sgpa);
}

