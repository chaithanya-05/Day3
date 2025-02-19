#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char *start, char *end) {
    char temp;
    while (start < end) {
        // Swap characters
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseWords(char str[]) {
    char *word_start = NULL;
    char *temp = str; 

    //Reverse
    while (*temp) {
        
        if ((word_start == NULL) && (*temp != ' ')) {
            word_start = temp; 
        }
        
        if (word_start && ((*temp == ' ') || (*(temp + 1) == '\0'))) {
            
            char *word_end = (*temp == ' ') ? temp - 1 : temp;
            reverseString(word_start, word_end); 
            word_start = NULL; 
        }
        temp++;
    }
}

int main() {
    char str[MAX_LENGTH];

    // Input a sentence
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    // Reverse the words in the sentence
    reverseWords(str);

    // Output the reversed sentence
    printf("Reversed Sentence: %s\n", str);

    return 0;
}
