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
    vector<string> &v = roll[grade];
    v.push_back(name);
    sort(v.begin(), v.end());
  }

  vector<string> school::grade(int grade)
  {
    return roll[grade];
  }
  
};
