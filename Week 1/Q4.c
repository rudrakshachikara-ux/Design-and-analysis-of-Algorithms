#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[200];
    char clean[200];
    int i, j = 0;
    int left, right;
    int palindrome = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove spaces */
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            clean[j++] = str[i];
        }
    }

    clean[j] = '\0';

    left = 0;
    right = j - 1;

    while (left < right) {
        if (clean[left] != clean[right]) {
            palindrome = 0;
            break;
        }

        left++;
        right--;
    }

    if (palindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");

    return 0;
}
