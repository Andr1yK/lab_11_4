#pragma once

#ifndef _SORT_
#define _SORT_

#include <fstream>
#include "Note.hpp"
#include "./FileHelper.cpp"
#include "./getCondition.cpp"

void Sort(char* fname) {
  fstream f(fname, ios::binary | ios::in | ios::out);

  int countsSwap = 0;
  int size = FileHelper::getSize<Note>(f);

  do
  {
    countsSwap = 0;

    for (int i = 1; i < size; i++) {
      const Note current = FileHelper::fRead<Note>(f, i);
      const Note prev = FileHelper::fRead<Note>(f, i - 1);;

      if (getCondition(current, prev)) {
        countsSwap++;
        FileHelper::fChange<Note>(f, i, i - 1);
      }
    }
  } while (countsSwap > 0);
}

#endif // !_SORT_
