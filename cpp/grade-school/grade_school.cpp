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
    roll[grade].push_back(name);
  }

  vector<string> school::grade(int grade)
  {
    vector<string> &v = roll[grade];
    if (is_sorted(v.begin(), v.end()))
      return v;
    
    sort(v.begin(), v.end());
    return v;
  }
  
};
