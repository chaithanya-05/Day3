#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

// Function to count occurrences of a pattern in the DNA sequence
int countPatternOccurrences(char dna[], char pattern[]) {
    int count = 0;
    int dnaLen = strlen(dna);
    int patternLen = strlen(pattern);
    
    for (int i = 0; i <= dnaLen - patternLen; i++) {
        if (strncmp(&dna[i], pattern, patternLen) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    char dna[MAX_LEN], pattern[MAX_LEN];
    
    // Input DNA sequence
    printf("Enter DNA Sequence: ");
    scanf("%s", dna);
    
    // Input pattern to search
    printf("Enter pattern to search: ");
    scanf("%s", pattern);
    
    // Count occurrences of the pattern
    int occurrences = countPatternOccurrences(dna, pattern);
    
    // Output result
    printf("Pattern found %d time(s) in the DNA sequence.\n", occurrences);
    
    return 0;
}
