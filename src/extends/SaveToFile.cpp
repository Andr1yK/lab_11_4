#pragma once

#ifndef _SAVE_TO_FILE_
#define _SAVE_TO_FILE_

#include <fstream>
#include <string>
#include "Note.hpp"
#include "./FileHelper.cpp"

using namespace std;

void SaveToFile(const char* filename, Note* notes, const int N)
{
  ofstream toFile(filename, ios::binary);

  for (int index = 0; index < N; index++) {
    FileHelper::fWrite(toFile, index, notes[index]);
  };

  toFile.close();
}

#endif