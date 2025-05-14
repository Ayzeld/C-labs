#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_l 1024

void reverse(char *str) {
    if (str == NULL) return;
    size_t length = strlen(str);
    for (size_t i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Ошибка при открытии файла на чтение");
        return 1;
    }

    char line[max_l];
    char longest[max_l] = "";

    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) > strlen(longest)) {
            strncpy(longest, line, max_l - 1);
            longest[max_l - 1] = '\0';
        }
    }
    fclose(file);

    if (longest[0] != '\0') {
        // Убираем перевод строки перед реверсом
        longest[strcspn(longest, "\n")] = '\0';
        reverse(longest);

        file = fopen(argv[1], "a");
        if (!file) {
            perror("Ошибка при открытии файла для дозаписи");
            return 1;
        }

        fprintf(file, "\nПеревёрнутая самая длинная строка: %s\n", longest);
        fclose(file);
    }

    return 0;
}
