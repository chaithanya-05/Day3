#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 10

//Calculate total marks
void calculateTotalMarks(int marks[][MAX_SUBJECTS], int n, int m, int totalMarks[]) {
    for (int i = 0; i < n; i++) {
        totalMarks[i] = 0; 
        for (int j = 0; j < m; j++) { 
            totalMarks[i] += marks[i][j]; 
        }
    }
}

void sortStudents(int totalMarks[], int n) {
    // Simple bubble sort for sorting total marks in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (totalMarks[j] < totalMarks[j + 1]) {
                // Swap total marks
                int temp = totalMarks[j];
                totalMarks[j] = totalMarks[j + 1];
                totalMarks[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, m;
    int marks[MAX_STUDENTS][MAX_SUBJECTS];
    int totalMarks[MAX_STUDENTS];

    // Input number of students and subjects
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("Enter number of subjects: ");
    scanf("%d", &m);

    // Input marks for each student
    for (int i = 0; i < n; i++) {
        printf("Enter marks for Student %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%d", &marks[i][j]);
        }
    }

    // Calculate total marks for each student
    calculateTotalMarks(marks, n, m, totalMarks);

    // Sort students based on total marks
    sortStudents(totalMarks, n);

    // Display total marks for each student
    printf("\nSorted Total Marks:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: Total Marks = %d\n", i + 1, totalMarks[i]);
    }

    return 0;
}
