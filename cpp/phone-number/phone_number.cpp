#include <algorithm>
#include <sstream>
#include "phone_number.h"
using namespace std;

phone_number::phone_number(string num)
{
  string::iterator s = num.begin();
  string::iterator e = num.end();

  if ((num.size() == 11 && *s != '1') || num.size() < 10)
  {
    digits = string (10, '0');
    return;
  }
  else if ( num.size() == 11 )
    ++s;

  copy_if(s, e, back_inserter(digits), ::isdigit);
  
  stringstream os;
  os << "(" << this->area_code() << ") " << this->co_code() << "-" << this->station_code(); 
  formatted.assign(os.str());
}

string phone_number::number() const
{
  return digits;
}

string phone_number::area_code() const
{
  return digits.substr(0,3);
}

string phone_number::co_code() const
{
  return digits.substr(3,3);
}

string phone_number::station_code() const
{
  return digits.substr(6, 4);
}

phone_number::operator string() const
{
  return formatted;
}
