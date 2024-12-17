#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 

int count_a(const char *word) { 
    int count = 0; 
    for (int i = 0; word[i] != '\0'; i++) { 
        if (word[i] == 'a' || word[i] == 'A') { 
            count++; 
        } 
    } 
    return count; 
} 

int main() { 
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. \n"
    "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. \n"
    "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. \n"
    "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    char *pch; 
    char max_word[100] = "";
    int max_count = 0;
    pch = strtok(str, " ,.-\n"); 
    while (pch != NULL) { 
        int current_count = count_a(pch); // Подсчёт a
        if (current_count > max_count) { 
            max_count = current_count; 
            strcpy(max_word, pch);
        } 
        pch = strtok(NULL, " ,.-"); 
    } 
    printf("Слово с максимальным количеством 'a': %s, количество 'a': %dn", max_word, max_count);
    return 0; 
}
