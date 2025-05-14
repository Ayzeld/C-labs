#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[50];    // Формат: "Фамилия И.О." (с пробелом)
    char group[20];
    int grades[3];
} Student;

void InputString(char *buffer, size_t size, const char *prompt) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void printStudent(const Student *s) {
    printf("%s, %s, оценки: %d %d %d\n", s->name, s->group, s->grades[0], s->grades[1], s->grades[2]);
}

void searchInFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Ошибка при открытии файла");
        return;
    }
    int choice;
    char input[10];
    bool running = true;
    while (running) {
        printf("\nВыберите поле для поиска:\n"
               "1 - Фамилия и инициалы\n"
               "2 - Номер группы\n"
               "3 - Оценка\n"
               "0 - Выход\n"
               "Ваш выбор: ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Неверный ввод. Попробуйте снова.\n");
            continue;
        }
        Student s;
        int found = 0;
        rewind(fp);
        switch (choice) {
            case 1: {
                char query[50];
                InputString(query, sizeof(query), "Введите фамилию и инициалы (например, Иванов А.А.): ");
                // Читаем ФИО как строку до группы, группу и оценки
                while (fscanf(fp, "%49[^0-9] %19s %d %d %d", 
                            s.name, s.group, &s.grades[0], &s.grades[1], &s.grades[2]) == 5) {
                    s.name[strcspn(s.name, " \t\n")] = '\0';
                    if (strcmp(s.name, query) == 0) {
                        found = 1;
                        printStudent(&s);
                    }
                }
                break;
            }
            case 2: {
                char query[20];
                InputString(query, sizeof(query), "Введите номер группы: ");
                while (fscanf(fp, "%49[^0-9] %19s %d %d %d", 
                            s.name, s.group, &s.grades[0], &s.grades[1], &s.grades[2]) == 5) {
                    s.name[strcspn(s.name, " \t\n")] = '\0';
                    if (strcmp(s.group, query) == 0) {
                        found = 1;
                        printStudent(&s);
                    }
                }
                break;
            }
            case 3: {
                int grade;
                printf("Введите оценку: ");
                scanf("%d", &grade);
                while (getchar() != '\n'); 
                while (fscanf(fp, "%49[^0-9] %19s %d %d %d", 
                            s.name, s.group, &s.grades[0], &s.grades[1], &s.grades[2]) == 5) {
                    s.name[strcspn(s.name, " \t\n")] = '\0';
                    bool printed = false;
                    for (int i = 0; i < 3; i++) {
                        if (s.grades[i] == grade && !printed) {
                            found = 1;
                            printStudent(&s);
                            printed = true;
                        }
                    }
                }
                break;
            }
            case 0:
                running = false;
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
        if (!found && choice >= 1 && choice <= 3) {
            printf("Ничего не найдено.\n");
        }
        rewind(fp);
    }
    fclose(fp);
}

int main() {
    const char *filename = "Wedomost.dat";
    searchInFile(filename);
    return 0;
}
