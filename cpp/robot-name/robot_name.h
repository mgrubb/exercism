#ifndef _ROBOT_NAME_H_
#define _ROBOT_NAME_H_
#include <string>
#include <random>
namespace robot_name
{
  class robot
  {
  private:
    static std::default_random_engine generator;
    static std::uniform_int_distribution<char> cdist;
    static std::uniform_int_distribution<int> idist;
    std::string _name;
    void gen_name();
  public:
    robot();
    std::string name() const;
    void reset();
  };
}
#endif /* _ROBOT_NAME_H_ */
