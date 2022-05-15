#pragma once

#ifndef _APPENDTOFILE_
#define _APPENDTOFILE_

#include <fstream>
#include "Note.hpp"
#include "./FileHelper.cpp"
#include "./createNote.cpp"

void appendToFile(char* fname) {
  fstream toFile(fname, ios::binary | ios::app);

  FileHelper::fWrite(toFile, createNote());

  toFile.close();
}

#endif // !_APPENDTOFILE_
