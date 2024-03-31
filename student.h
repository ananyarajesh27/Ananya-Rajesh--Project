#ifndef STUDENT_H
#define STUDENT_H

void getStudentDetails(char *name, char *srn, int *semester, int marks[][3], int numSubjects);
char calculateGrade(int marks);
void displayGradeCard(const char *name, const char *srn, int semester, int marks[][3], int numSubjects, float sgpa);
int getGradePoints(char grade);
float calculateSGPA(int marks[][3], int numSubjects);

#endif



