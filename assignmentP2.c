#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

// Function to sort patients based on emergency level
void sortPatients(char names[][50], int levels[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (levels[j] < levels[j + 1]) {

                int tempLevel = levels[j];
                levels[j] = levels[j + 1];
                levels[j + 1] = tempLevel;

    
                char tempName[50];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);
            }
        }
    }
}

// Function to display the top 3 critical patients
void displayTopPatients(char names[][50], int levels[], int n) {
    printf("Top 3 Critical Patients:\n");
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
}

int main() {
    int n;
    char names[MAX_PATIENTS][50];
    int levels[MAX_PATIENTS];

    // Input number of patients
    printf("Enter number of patients: ");
    scanf("%d", &n);

    // Input patient data
    printf("Patient Data:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. ", i + 1);
        scanf("%s - Level %d", names[i], &levels[i]);
    }

    // Sort patients by emergency level
    sortPatients(names, levels, n);

    // Display sorted patients
    printf("\nSorted by Emergency Level:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - Level %d\n", i + 1, names[i], levels[i]);
    }

    // Display top 3 critical patients
    displayTopPatients(names, levels, n);

    return 0;
}
