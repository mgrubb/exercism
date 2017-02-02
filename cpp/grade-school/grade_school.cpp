#include <algorithm>
#include <iostream>
#include <utility>
#include "grade_school.h"

using namespace std;

namespace grade_school
{

  school::school()
  {
  }

  roster_type school::roster()
  {
    return roll;
  }

  void school::add(string name, int grade)
  {
    roll[grade].insert(name);
  }

  set<string> school::grade(int grade)
  {
    return roll[grade];
  }
  
};
