#include "student.h"

void getStudentDetails(Student *student) {
    char *subjects[] = {"Maths", "PSWC", "Mechanical", "Physics", "Electrical"};
    char *exams[] = {"ISA1", "ISA2", "ESA"};
    int i, j;

    student->name = malloc(MAX_NAME_LENGTH * sizeof(char));
    student->srn = malloc(MAX_SRN_LENGTH * sizeof(char));

    printf("Enter student name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = '\0'; // remove newline character

    printf("Enter SRN: ");
    fgets(student->srn, MAX_SRN_LENGTH, stdin);
    student->srn[strcspn(student->srn, "\n")] = '\0'; // remove newline character

    printf("Enter semester: ");
    scanf("%d", &student->semester);

    student->marks = malloc(NUM_SUBJECTS * sizeof(int[3]));
    printf("Enter marks for %d subjects for each of the 3 examinations:\n", NUM_SUBJECTS);
    for (i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject: %s\n", subjects[i]);
        for (j = 0; j < 3; j++) {
            printf("Enter marks for %s: ", exams[j]);
            scanf("%d", &student->marks[i][j]);
        }
    }
    getchar(); // consume newline character after scanf
}

void freeStudent(Student *student) {
    free(student->name);
    free(student->srn);
    free(student->marks);
}
