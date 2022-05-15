#pragma once

#ifndef _GETCONDITION_
#define _GETCONDITION_

#include "Note.hpp"

bool getCondition(Note c, Note p) {
  int cYear = c.birthday[2],
    pYear = p.birthday[2],
    cMonth = c.birthday[1],
    pMonth = p.birthday[1],
    cDay = c.birthday[0],
    pDay = p.birthday[0];

  bool byYear = cYear > pYear;
  bool byMonth = cYear == pYear 
    && cMonth > pMonth;

  bool byDay = cYear == pYear 
    && cMonth == pMonth
    && cDay > pDay;

  return byYear || byMonth || byDay;
};

#endif // !_GETCONDITION_
