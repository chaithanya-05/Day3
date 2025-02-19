#include <stdio.h>
#include <string.h>

int findSubstring(char str[], char sub[]) {
    int strLen = strlen(str);
    int subLen = strlen(sub);

   
    for (int i = 0; i <= strLen - subLen; i++) {
     
        int j;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != sub[j]) {
                break; 
            }
        }
      
        if (j == subLen) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    char str[100];
    char sub[50];

    printf("Enter main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

   
    printf("Enter substring: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = 0; 

  
    int index = findSubstring(str, sub);
    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}
