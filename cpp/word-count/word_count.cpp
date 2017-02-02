#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "word_count.h"

using namespace std;

static const string whitespace (" \t\n,");

namespace word_count
{
  static bool keep_char(const char c)
  {
    return isalnum(c) || isspace(c) || c == ',' || c == '\'';

  }

  static bool is_empty(string s)
  {
    return s.empty();
  }

  static vector<string> tokenize(const string phrase, const string delim = whitespace)
  {
    string str;
    vector<string> &res = *(new vector<string>());
    typedef string::const_iterator sci;
    string *rs;
    sci strb, stre, db, de, r;

    copy_if(phrase.begin(), phrase.end(), back_inserter(str), keep_char);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    strb = str.begin();
    stre = str.end();
    db = delim.begin();
    de = delim.end();

    r = find_first_of(strb, stre, db, de);
    while (r != stre)
                {
                  rs = new string(strb, r);
                  res.push_back(*rs);
                  strb = r+1;
                  r = find_first_of(strb, stre, db, de);
                } 

    if (res.empty())
      rs = new string(str);
    else
      rs = new string(strb, stre);

    res.push_back(*rs);
    res.erase(remove_if(res.begin(), res.end(), word_count::is_empty),
              res.end());
    return res;
  }

  map<string, int> words(const char *words)
  {
    map<string, int> &res = *(new map<string,int>);
    vector<string> tokens = tokenize(string(words));

    for (string w : tokens)
      {
        res[w]++;
      }
    //  tokenize(string("abc def ghi"));
    return res;
  }
};
