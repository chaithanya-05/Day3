#include <stdio.h>

#define MAX_EMPLOYEES 100

// Function prototypes
void sortSalaries(int salaries[], int n);
int findSecondHighest(int salaries[], int n);
int calculateTotalPayroll(int salaries[], int n);

int main() {
    int n;
    int salaries[MAX_EMPLOYEES];

    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Input salaries
    printf("Enter salaries of %d employees: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &salaries[i]);
    }

    // Sort the salaries
    sortSalaries(salaries, n);

    // Display sorted salaries
    printf("Sorted Salaries: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", salaries[i]);
    }
    printf("\n");

    // Find the second highest salary
    int secondHighest = findSecondHighest(salaries, n);
    if (secondHighest != -1) {
        printf("Second Highest Salary: %d\n", secondHighest);
    } else {
        printf("Not enough unique salaries to determine the second highest.\n");
    }

    // Calculate total payroll
    int totalPayroll = calculateTotalPayroll(salaries, n);
    printf("Total Payroll: ₹%d\n", totalPayroll);

    return 0;
}

// Function to sort salaries in ascending order
void sortSalaries(int salaries[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (salaries[i] > salaries[j]) {
              
                temp = salaries[i];
                salaries[i] = salaries[j];
                salaries[j] = temp;
            }
        }
    }
}

// Function to find the second highest salary
int findSecondHighest(int salaries[], int n) {
    int highest = salaries[n - 1];
    int secondHighest = -1;

    for (int i = n - 2; i >= 0; i--) {
        if (salaries[i] < highest) {
            secondHighest = salaries[i];
            break;
        }
    }

    return secondHighest;
}

// Function to calculate total payroll
int calculateTotalPayroll(int salaries[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += salaries[i];
    }
    return total;
}
