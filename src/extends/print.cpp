#pragma once

#ifndef _PRINT_
#define _PRINT_

#include <fstream>
#include <iostream>
#include "Note.hpp"
#include <iomanip>
#include "./FileHelper.cpp"

using namespace std;

void PrintHeader() {
  cout << "==============================================================="
    << endl;

  cout << setfill(' ') << right << "| " << setw(5) << "№" << " | "
    << setw(20) << left << "Fullname" << " | "
    << setw(12) << "Tel" << " | "
    << setw(15) << "Birthday" << " |"
    << endl;

  cout << "---------------------------------------------------------------"
    << endl;
}

void PrintRow(Note note, int index = 0) {
  cout << "| " << setw(3) << right << index + 1 << " | "
    << setw(20) << left << note.fullName << " |"
    << setw(13) << right << note.tel << " | ";

  cout << setfill('0') << right
    << setw(2) << to_string(note.birthday[0]) << "."
    << setw(2) << to_string(note.birthday[1])  << "." 
    << setw(4) << to_string(note.birthday[2]) 
    << setfill(' ') << setw(7) << " |"
    << endl;
}

void Print(char* fname)
{
  PrintHeader();

  ifstream f(fname, ios::binary);
  f.seekg(0, ios::end);
  int size = f.tellg() / sizeof(Note);
  f.seekg(0, ios::beg);

  for (int i = 0; i < size; i++)
  {
    PrintRow(FileHelper::fRead<Note>(f, i), i);

    if (i < size - 1)
      cout << "---------------------------------------------------------------"
        << endl;
  }

  f.close();

  cout << "==============================================================="
    << endl;
  cout << endl;
}

void Print(char* fname, int index)
{
  PrintHeader();

  ifstream f(fname, ios::binary);
  
  PrintRow(FileHelper::fRead<Note>(f, index));

  f.close();

  cout << "==============================================================="
    << endl;
  cout << endl;
}

#endif