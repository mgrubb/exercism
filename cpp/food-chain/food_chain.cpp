#include <sstream>
#include <vector>
#include "food_chain.h"

using namespace std;

struct verse_info
{
  const string animal;
  const string action;
  const string repeat_action;
};
  
static const vector<verse_info> verse_data
{
  {"fly", "I don't know why she swallowed the fly. Perhaps she'll die.", ".\nI don't know why she swallowed the fly. Perhaps she'll die"},
  {"spider", "It wriggled and jiggled and tickled inside her.", " that wriggled and jiggled and tickled inside her"},
  {"bird", "How absurd to swallow a bird!", ""},
  {"cat", "Imagine that, to swallow a cat!", ""},
  {"dog", "What a hog, to swallow a dog!", ""},
  {"goat", "Just opened her throat and swallowed a goat!", ""},
  {"cow", "I don't know how she swallowed a cow!", ""},
  {"horse", "", ""}
};

string food_chain::verse(int v)
{
  stringstream os;
  const verse_info *vp = &verse_data[--v];
  const verse_info *vc;
  os << "I know an old lady who swallowed a " << vp->animal << "." << endl;
  if (vp->action.empty() && vp->repeat_action.empty())
  {
    os << "She's dead, of course!" << endl;
    return os.str();
  }
  os << vp->action << endl;
  for (int i = v-1; i > -1; --i, vp = vc)
        {
          vc = &verse_data[i];
          os << "She swallowed the " << vp->animal << " to catch the " << vc->animal << vc->repeat_action << "." << endl;
        }

  return os.str();
}

string food_chain::verses(int s, int e)
{
  stringstream os;
  for (int i = s; i <= e; ++i)
  {
    os << verse(i) << endl;
  }

  return os.str();
}

string food_chain::sing()
{
  int s = verse_data.size();
  return verses(1, s);
}

