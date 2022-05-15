#pragma once

#ifndef _CREATENOTE_
#define _CREATENOTE_

#include <iostream>
#include <string>
#include "Note.hpp"

using namespace std;

Note createNote() {
  Note note;

  cout << "Новий запис:" << endl;

  cin.get(); cin.sync();

  cout << " Прізвище та ім'я: "; getline(cin, note.fullName);
  cout << endl;
  cout << " Номер телефону: "; cin >> note.tel;
  cout << endl;
  
  cout << " День народження  : "; cin >> note.birthday[0];
  cout << " Місяць народження: "; cin >> note.birthday[1];
  cout << " Рік народження   : "; cin >> note.birthday[2];

  cout << endl;

  return note;
}

#endif // !_CREATENOTE_
