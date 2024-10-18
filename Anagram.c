#include <stdio.h>
#include <stdlib.h>  // For malloc and free
#include <string.h>  // For strlen
#include <stdbool.h> // For bool type

bool isAnagram(const char* s, const char* t) {
    int sizeS = strlen(s);
    int sizeT = strlen(t);

    // If lengths are not equal, they can't be anagrams
    if (sizeS != sizeT) {
        return false;
    }

    // Create a frequency array to count occurrences of each character
    int freq[256] = {0};  // Assuming ASCII characters

    // Count frequencies in the first string
    for (int i = 0; i < sizeS; i++) {
        freq[(unsigned char)s[i]]++;
    }

    // Decrease frequencies based on the second string
    for (int i = 0; i < sizeT; i++) {
        freq[(unsigned char)t[i]]--;
        if (freq[(unsigned char)t[i]] < 0) {
            return false;  // If any count goes below 0, they are not anagrams
        }
    }

    return true;
}

int main() {
    char *ptr = "car";
    char *t = "rac";

    if (isAnagram(ptr, t)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
