#pragma once

#ifndef _SEARCH_F_
#define _SEARCH_F_

#include "Note.hpp"
#include <string>
#include "./FileHelper.cpp"

int Search(char* fname, const std::string tel) {
  ifstream f(fname, ios::binary);

  int size = FileHelper::getSize<Note>(f);

  for (int i = 0; i < size; i++)
    if (FileHelper::fRead<Note>(f, i).tel == tel)
      return i;

  return -1;
}

#endif