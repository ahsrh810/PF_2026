#include <stdio.h>
#include <string.h>

int main() {
    char sen[100];
    printf("Enter a sentence: ");
    fgets(sen, sizeof(sen), stdin);
    sen[strcspn(sen, "\n")] = '\0';
    
    char *p = strchr(sen, 'a');
    if (p != NULL) {
        printf("First 'a' found at index %ld\n", p - sen);
    } else {
        printf("Letter 'a' not found.\n");
    }

    if (strstr(sen, "good") != NULL) {
        printf("Word 'good' found.\n");
    } else {
        printf("Word 'good' not found.\n");
    }
    return 0;
}
