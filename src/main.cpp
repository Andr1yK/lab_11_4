#include <iostream>
#include <string>

#include "./extends/SaveToFile.cpp"
#include "./extends/Note.hpp"
#include "./extends/print.cpp"
#include "./extends/search.cpp"
#include "./extends/appendToFile.cpp"
#include "./extends/Sort.cpp"

using namespace std;

int main()
{
  const int N = 10;
  fstream f;

  Note notes[N] = {
    {"Sheikh Barnard",    "380634161835", {14, 9,  2014} },
    {"Atlanta Gall",      "380925229621", {4, 12,  2020} },
    {"Uma Noble",         "380633648116", {21, 5,  1998} },
    {"Siddharth Ferry",   "380507585956", {7,  4,  1974} },
    {"Jaxon Leal",        "380506986742", {12, 8,  2000} },
    {"Santino Read",      "380683046862", {23, 3,  2010} },
    {"Shana Flores",      "380631996430", {17, 5,  1998} },
    {"Louisa Irwin",      "380503792270", {5,  9,  1974} },
    {"Anita Dominguez",   "380665919172", {1,  7,  2003} },
    {"Eathan Roach",      "380683038390", {7,  7,  2010} },
  };

  char fname[100] = "test";
  cout << " Введіть ім'я файлу: "; cin.getline(fname, 99);

  SaveToFile(fname, notes, N);

  int findedIndex;
  string findTel;

  int menuItem;
  do {
    cout << endl << endl;
    cout << "Виберіть дію:" << endl << endl;
    cout << " [1] - вивід даних на екран" << endl;
    cout << " [2] - пошук за номером" << endl;
    cout << " [3] - додати дані в файл" << endl;
    cout << " [4] - відсортувати файл" << endl;

    cout << endl;
    cout << " [9] - змінити файл" << endl;

    cout << endl;

    cout << " [0] - вихід та завершення роботи програми" << endl << endl;
    cout << "Введіть значення: "; cin >> menuItem;
    cout << endl << endl << endl;

    switch (menuItem)
    {
    case 1:
      Print(fname);
      break;

    case 2:
      cin.get(); cin.sync();

      cout << " Введіть номер телефону: "; getline(cin, findTel);

      if ((findedIndex = Search(fname, findTel)) >= 0)
        Print(fname, findedIndex);
      else
        cout << "Запис з таким телефонним номером не знайдено" << endl;

      break;

    case 3:
      appendToFile(fname);
      break;

    case 4:
      Sort(fname);
      break;

    case 9:
      cin.get();
      cin.sync();

      cout << " Введіть ім'я файлу: "; cin.getline(fname, 99);
      break;

    case 0:
      break;

    default:
      cout << "Ви ввели помилкове значення! "
        "Слід ввести число - номер вибраного пункту меню" << endl;
    }
  } while (menuItem != 0);


  return 0;
}