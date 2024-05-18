#include "student.h"

void getStudentDetailsFromFile(FILE *file, Student *student) {
    char buffer[256];
    char *subjects[] = {"Maths", "PSWC", "Mechanical", "Physics", "Electrical"};

    
    if (fgets(buffer, sizeof(buffer), file)) {
        
        student->name = malloc(MAX_NAME_LENGTH * sizeof(char));
        student->srn = malloc(MAX_SRN_LENGTH * sizeof(char));
        student->marks = malloc(NUM_SUBJECTS * sizeof(int[3]));

        
        sscanf(buffer, "%49[^,],%13[^,],%d", student->name, student->srn, &student->semester);

        char *token = strtok(buffer, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");

        for (int i = 0; i < NUM_SUBJECTS; i++) {
            for (int j = 0; j < 3; j++) {
                token = strtok(NULL, ",");
                student->marks[i][j] = atoi(token);
            }
        }
    }
}

void freeStudent(Student *student) {
    free(student->name);
    free(student->srn);
    free(student->marks);
}
