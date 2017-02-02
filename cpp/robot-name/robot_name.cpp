#include <random>
#include <sstream>
#include "robot_name.h"

using namespace std;


namespace robot_name
{

  default_random_engine robot::generator;
  uniform_int_distribution<char> robot::cdist ('A', 'Z');
  uniform_int_distribution<int> robot::idist (100, 999);
  
  void robot::gen_name()
  {
    stringstream ostr;
    ostr << cdist(generator) << cdist(generator); 
    ostr << idist(generator);
    _name = ostr.str();
  }

  robot::robot()
  {
    gen_name();
  }

  void robot::reset()
  {
    gen_name();
  }
  
  string robot::name() const
  {
    return _name;
  }

}
