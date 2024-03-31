#include <stdio.h>
#include "student.h"

int getGradePoints(char grade) {
    switch (grade) {
        case 'S':
            return 10;
        case 'A':
            return 9;
        case 'B':
            return 8;
        case 'C':
            return 7;
        case 'D':
            return 6;
        case 'E':
            return 5;
        case 'F':
            return 0;
        default:
            return -1; 
    }
}

char calculateGrade(int marks) {
    if (marks >= 90) {
        return 'S';
    } else if (marks >= 80) {
        return 'A';
    } else if (marks >= 70) {
        return 'B';
    } else if (marks >= 60) {
        return 'C';
    } else if (marks >= 50) {
        return 'D';
    } else if (marks >= 40) {
        return 'E';
    } else {
        return 'F';
    }
}

float calculateSGPA(int marks[][3], int numSubjects) {
    int totalCredits = 0;
    float totalGradePoints = 0;

    
    int credits[] = {4, 5, 3, 5, 4};

    
    for (int i = 0; i < numSubjects; i++) {
        int totalMarks = 0;
        for (int j = 0; j < 3; j++) {
            totalMarks += marks[i][j];
        }
        int subjectMarks = totalMarks / 2; 
        subjectMarks = subjectMarks + (marks[i][2] * 2) / 5; 
        char grade = calculateGrade(subjectMarks);
        int gradePoints = getGradePoints(grade);
        totalGradePoints += gradePoints * credits[i];
        totalCredits += credits[i];
    }

    
    float sgpa = totalGradePoints / totalCredits;
    return sgpa;
}
