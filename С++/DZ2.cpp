#include <iostream>
#include <vector>
#include <algorithm>

// Функция пузырьковой сортировки
void bubbleSort(std::vector<char>& arr, int& comparisons, int& swaps) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}

int main() {
    // Часть 1: Сортировка массива из ФИО "Янин Алексей"
    std::vector<char> fio = {'Я', 'н', 'и', 'н', ' ', 'А', 'л', 'е'};
    int comp = 0, swaps = 0;

    std::cout << "Исходный массив: ";
    for (char c : fio) std::cout << c << " ";
    std::cout << "\n";

    bubbleSort(fio, comp, swaps);

    std::cout << "Отсортированный массив: ";
    for (char c : fio) std::cout << c << " ";
    std::cout << "\nСравнения: " << comp << ", Пересылки: " << swaps << "\n\n";

    // Часть 2: Таблица трудоемкости для массивов разного размера
    std::vector<int> sizes = {100, 200, 300, 400, 500};
    std::cout << "N\tM+C (Убыв.)\tM+C (Случ.)\tM+C (Возр.)\n";

    for (int size : sizes) {
        std::vector<char> decreasing(size), increasing(size), random(size);

        for (int i = 0; i < size; i++) {
            decreasing[i] = 'Z' - i; // Убывающий массив
            increasing[i] = 'A' + i; // Возрастающий массив
            random[i] = 'A' + rand() % 26; // Случайный массив
        }

        int comp_dec = 0, swaps_dec = 0;
        int comp_inc = 0, swaps_inc = 0;
        int comp_rand = 0, swaps_rand = 0;

        bubbleSort(decreasing, comp_dec, swaps_dec);
        bubbleSort(increasing, comp_inc, swaps_inc);
        bubbleSort(random, comp_rand, swaps_rand);

        std::cout << size << "\t" << comp_dec + swaps_dec << "\t\t"
                  << comp_rand + swaps_rand << "\t\t" << comp_inc + swaps_inc << "\n";
    }

    return 0;
}
