#include <stdio.h>

#define MAX_SIZE 100

int mostFrequentElement(int arr[], int n) {
    int frequency[MAX_SIZE] = {0};
    int maxCount = 0;
    int mostFrequent = arr[0]; 

    // Count the frequency
    for (int i = 0; i < n; i++) {
        frequency[arr[i]]++;
    }


    for (int i = 0; i < n; i++) {
        if (frequency[arr[i]] > maxCount) {
            maxCount = frequency[arr[i]];
            mostFrequent = arr[i];
        } else if (frequency[arr[i]] == maxCount) {

            if (arr[i] < mostFrequent) {
                mostFrequent = arr[i];
            }
        }
    }

    return mostFrequent;
}

int main() {
    int n;
    int arr[MAX_SIZE];


    printf("Enter array size: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = mostFrequentElement(arr, n);
    printf("Most Frequent Element: %d\n", result);

    return 0;
}
