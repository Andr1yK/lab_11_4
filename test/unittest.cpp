#include <gtest/gtest.h>

#include <fstream>
#include <string>

#include "../src/extends/Note.hpp"
#include "../src/extends/search.cpp"
#include "../src/extends/appendToFile.cpp"
#include "../src/extends/Sort.cpp"

struct WorkWithFile : public testing::Test
{
  char input_fname[30] = "unittests.temp";
  char input_fname_indexes[30] = "unittests_indexes.temp";

  ofstream fout;
  const int N = 10;

  Note excepted[10] = {
    {"Atlanta Gall",      "380925229621", {4, 12,  2020} },
    {"Sheikh Barnard",    "380634161835", {14, 9,  2014} },
    {"Eathan Roach",      "380683038390", {7,  7,  2010} },
    {"Santino Read",      "380683046862", {23, 3,  2010} },
    {"Anita Dominguez",   "380665919172", {1,  7,  2003} },
    {"Jaxon Leal",        "380506986742", {12, 8,  2000} },
    {"Uma Noble",         "380633648116", {21, 5,  1998} },
    {"Shana Flores",      "380631996430", {17, 5,  1998} },
    {"Louisa Irwin",      "380503792270", {5,  9,  1974} },
    {"Siddharth Ferry",   "380507585956", {7,  4,  1974} },
  };

  Note notes[10] = {
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

  void SetUp() override {
    fout.open(input_fname);

    for (size_t i = 0; i < N; i++)
      fout.write((char*)&notes[i], sizeof(notes[i]));

    fout.close();

    fout.open(input_fname_indexes);

    for (size_t i = 0; i < N; i++)
      fout.write((char*)&notes[i], sizeof(notes[i]));

    fout.close();
  }

  void TearDown() override {
    remove(input_fname);
    remove(input_fname_indexes);
  }
};

TEST_F(WorkWithFile, Sort) {
  Sort(input_fname);

  ifstream f(input_fname);

  for(int i = 0; i < N; i++)
    EXPECT_EQ(FileHelper::fRead<Note>(f, i).fullName, excepted[i].fullName);
  
  f.close();
};

TEST_F(WorkWithFile, Search) {
  string tel = "380665919172";

  int finded_index = Search(input_fname, tel);
  
  ifstream f(input_fname);

  EXPECT_EQ(finded_index, 8);
  EXPECT_EQ(FileHelper::fRead<Note>(f, finded_index).fullName, notes[8].fullName);
  
  f.close();
};

TEST_F(WorkWithFile, SearchNotFound) {
  string tel = "not a number";

  int finded_index = Search(input_fname, tel);

  EXPECT_EQ(finded_index, -1);
};