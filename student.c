#include <stdio.h>
#include "student.h"

void getStudentDetails(char *name, char *srn, int *semester, int marks[][3], int numSubjects) {
    
    char *subjects[] = {"Maths", "PSWC", "Mechanical", "Physics", "Electrical"};
    char *exams[] = {"ISA1", "ISA2", "ESA"};

    printf("Enter student name: ");
    scanf("%s", name);

    printf("Enter srn: ");
    scanf("%s", srn);

    printf("Enter semester: ");
    scanf("%d", semester);

    printf("Enter marks for %d subjects for each of the 3 examinations:\n", numSubjects);
    for (int i = 0; i < numSubjects; i++) {
        printf("Subject: %s\n", subjects[i]);
        for (int j = 0; j < 3; j++) {
            printf("Enter marks for %s: ", exams[j]);
            scanf("%d", &marks[i][j]);
        }
    }
}

