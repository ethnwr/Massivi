#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

// Функция для сортировки пузырьком (улучшенная версия)
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Если в проходе не было обменов, массив уже отсортирован
    }
}

// Функция для сортировки выбором
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

// Функция для подсчета количества перестановок
int countSwaps(vector<int>& arr, int n) {
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swaps++;
        }
    }
    return swaps;
}

using namespace std;

// Структура для хранения данных пользователя
struct User {
    string mobileNumber;
    string homeNumber;
};

// Сортировка по мобильным номерам
bool sortByMobile(const User& a, const User& b) {
    return a.mobileNumber < b.mobileNumber;
}

// Сортировка по домашним номерам
bool sortByHome(const User& a, const User& b) {
    return a.homeNumber < b.homeNumber;
}
void optimizedBubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Если на шаге не было перестановок, массив отсортирован
        if (!swapped) {
            break;
        }
    }
}

// Функция для выполнения операции "переворота"
void flip(vector<int>& pancakes, int start, int end) {
    while (start < end) {
        swap(pancakes[start], pancakes[end]);
        start++;
        end--;
    }
}

// Функция для сортировки оладий
int sortPancakes(vector<int>& pancakes) {
    int n = pancakes.size();
    int operations = 0;

    // Идем по оладьям с конца
    for (int i = n - 1; i > 0; i--) {
        // Находим максимальный радиус в текущем диапазоне
        int maxIndex = max_element(pancakes.begin(), pancakes.begin() + i + 1) - pancakes.begin();

        // Если максимальный радиус не на последнем месте
        if (maxIndex != i) {
            // Переворачиваем оладьи до максимального радиуса
            flip(pancakes, 0, maxIndex);
            operations++;

            // Переворачиваем все оладьи до последнего места
            flip(pancakes, 0, i);
            operations++;
        }
    }

    return operations;
}

int main() {
    
      // Задаем количество пользователей
      int numUsers;
      cout << "Введите количество пользователей: ";
      cin >> numUsers;

      // Создаем массивы для хранения данных пользователей
      User users[numUsers];

      // Ввод данных пользователей
      for (int i = 0; i < numUsers; ++i) {
          cout << "\nВведите данные для пользователя " << i + 1 << ":" << endl;
          cout << "Мобильный номер: ";
          cin >> users[i].mobileNumber;
          cout << "Домашний номер: ";
          cin >> users[i].homeNumber;
      }

      // Меню для пользователя
      int choice;
      do {
          cout << "\nМеню:\n";
          cout << "1. Отсортировать по мобильным номерам\n";
          cout << "2. Отсортировать по домашним номерам\n";
          cout << "3. Вывести данные пользователей\n";
          cout << "4. Выход\n";
          cout << "Введите ваш выбор: ";
          cin >> choice;

          switch (choice) {
              case 1:
                  // Сортировка по мобильным номерам
                  sort(users, users + numUsers, sortByMobile);
                  cout << "Сортировка по мобильным номерам выполнена.\n";
                  break;
              case 2:
                  // Сортировка по домашним номерам
                  sort(users, users + numUsers, sortByHome);
                  cout << "Сортировка по домашним номерам выполнена.\n";
                  break;
              case 3:
                  // Вывод данных пользователей
                  cout << "\nДанные пользователей:\n";
                  for (int i = 0; i < numUsers; ++i) {
                      cout << "Пользователь " << i + 1 << ":" << endl;
                      cout << "Мобильный номер: " << users[i].mobileNumber << endl;
                      cout << "Домашний номер: " << users[i].homeNumber << endl;
                  }
                  break;
              case 4:
                  cout << "Выход из программы.\n";
                  break;
              default:
                  cout << "Неверный выбор. Попробуйте снова.\n";
          }
      } while (choice != 4);
    
  //задание 2
  vector<int> arr = {5, 1, 4, 2, 8};

  cout << "Исходный массив: ";
  for (int i : arr) {
    cout << i << " ";
  }
  cout << endl;

  optimizedBubbleSort(arr);

  cout << "Отсортированный массив: ";
  for (int i : arr) {
    cout << i << " ";
  }
  cout << endl;

//задание 3 

vector<int> pancakes = {3, 2, 1, 4, 5};
int operations = sortPancakes(pancakes);
cout << "Количество операций: " << operations << endl;

// Вывод отсортированного списка оладий
for (int pancake : pancakes) {
    cout << pancake << " ";
}
cout << endl;

//задание 4
    srand(time(0)); // Инициализация генератора случайных чисел

    // Тестирование на 10 массивах
    for (int test = 1; test <= 10; test++) {
        cout << "Тест " << test << endl;

        vector<int> arr(1000);
        // Генерация случайных чисел
        for (int i = 0; i < 1000; i++) {
            arr[i] = rand() % 1000; // Случайные числа от 0 до 999
        }

        // Сортировка пузырьком и подсчет перестановок
        vector<int> bubbleArr = arr;
        bubbleSort(bubbleArr);
        int bubbleSwaps = countSwaps(bubbleArr, 1000);
        cout << "Перестановок в пузырьковой сортировке: " << bubbleSwaps << endl;

        // Сортировка выбором и подсчет перестановок
        vector<int> selectionArr = arr;
        selectionSort(selectionArr);
        int selectionSwaps = countSwaps(selectionArr, 1000);
        cout << "Перестановок в сортировке выбором: " << selectionSwaps << endl;

        cout << endl;
    }

    return 0;
}
