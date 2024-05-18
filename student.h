#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_SRN_LENGTH 14
#define NUM_SUBJECTS 5
typedef struct {
    char *name;
    char *srn;
    int semester;
    int (*marks)[3];
    float sgpa;
} Student;
void getStudentDetailsFromFile(FILE *file, Student *student);
void freeStudent(Student *student);
int getGradePoints(char grade);
char calculateGrade(int marks);
float calculateSGPA(int (*marks)[3]);
void displayGradeCard(const Student *student);
#endif
