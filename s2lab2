#include <stdio.h>
#include <stdlib.h>

// Структура узла
struct node {
    int data;
    struct node *next;
    struct node *alt;
};

// Функция для создания нового узла
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode->alt = NULL;
    return newNode;
}

// Добавление узла в конец списка
void append(struct node** head, int data) {
    struct node** temp = head;
    while (*temp) temp = &(*temp)->next;
    *temp = createNode(data);
}

// Вывод списка
void printList(struct node* head) {
    for (; head; head = head->next) printf("%d ", head->data);
    printf("\n");
}

// Создание списка
struct node* createList() {
    struct node* head = NULL;
    int data;
    printf("Введите числа (0 для завершения): ");
    while (scanf("%d", &data), data) append(&head, data);
    return head;
}

// Навигация по списку
void navigateList(struct node* start) {
    struct node* current = start;
    char command;
    printf("Управление: D(6) - вправо, W(8) - альт. путь, Q - выход.\n");
    while (1) {
        printf("Текущее значение: %d\nВведите команду: ", current->data);
        scanf(" %c", &command);
        if (command == 'Q' || command == 'q') break;
        else if ((command == 'D' || command == '6') && current->next) current = current->next;
        else if ((command == 'W' || command == '8') && current->alt) current = current->alt;
        else printf("Нельзя двигаться в выбранном направлении.\n");
    }
}

int main() {
    struct node *list1 = createList(), *list2 = createList();
    for (struct node *t1 = list1, *t2 = list2; t1 && t2; t1 = t1->next, t2 = t2->next)
        t1->alt = t2;
    printList(list1);
    printList(list2);
    navigateList(list1);
    return 0;
}
