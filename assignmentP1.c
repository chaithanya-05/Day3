#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE_LENGTH 100

// Function prototypes
void sortBooks(char books[][MAX_TITLE_LENGTH], int n);
int searchBook(char books[][MAX_TITLE_LENGTH], int n, const char *title);

int main() {
    int n;
    char books[MAX_BOOKS][MAX_TITLE_LENGTH];

    // Input number of books
    printf("Enter number of books: ");
    scanf("%d", &n);
    getchar(); 
    // Input book titles
    printf("Book Titles:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. ", i + 1);
        fgets(books[i], MAX_TITLE_LENGTH, stdin);
      
        books[i][strcspn(books[i], "\n")] = 0;
    }

   
    sortBooks(books, n);

    // Display sorted list
    printf("\nSorted List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, books[i]);
    }

    // Search for a specific book
    char searchTitle[MAX_TITLE_LENGTH];
    printf("\nEnter book title to search: ");
    fgets(searchTitle, MAX_TITLE_LENGTH, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0; 

    // Search for the book
    if (searchBook(books, n, searchTitle)) {
        printf("Book found in the library.\n");
    } else {
        printf("Book not found in the library.\n");
    }

    return 0;
}

// Function to sort books alphabetically
void sortBooks(char books[][MAX_TITLE_LENGTH], int n) {
    char temp[MAX_TITLE_LENGTH];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(books[i], books[j]) > 0) {
              
                strcpy(temp, books[i]);
                strcpy(books[i], books[j]);
                strcpy(books[j], temp);
            }
        }
    }
}

// Function to search for a book
int searchBook(char books[][MAX_TITLE_LENGTH], int n, const char *title) {
    for (int i = 0; i < n; i++) {
        if (strcmp(books[i], title) == 0) {
            return 1; 
        }
    }
    return 0; 
}
