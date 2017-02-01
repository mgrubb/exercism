#include "anagram.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace anagram
{
  anagram::anagram(const char *subj)
  {
    subject.assign(subj);
    transform(subject.begin(), subject.end(), subject.begin(), ::tolower);
  }

  const vector<const char*> &anagram::matches(const vector<const char*>& mlist)
  {
    typedef string::iterator si;
    typedef vector<const char*>::const_iterator vi;
    vector<const char *> *res = new vector<const char *>();
    
    for (vi m = mlist.begin(); m != mlist.end(); ++m)
    {
      string ms(*m);
      transform(ms.begin(), ms.end(), ms.begin(), ::tolower);
      if ((ms.length() == subject.length()) &&
          (ms != subject) &&
          is_permutation(subject.begin(), subject.end(), ms.begin()) )
        res->push_back(*m);
    }
      
    return *res;
  }

};
