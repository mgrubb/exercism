#ifndef _GRADE_SCHOOL_H_
#define _GRADE_SCHOOL_H_
#include <set>
#include <map>
#include <string>
namespace grade_school
{
  
  typedef std::map<int, std::set<std::string>> roster_type;
  class school
  {
  private:
    roster_type roll;
  public:
    school();
    roster_type roster();
    void add(std::string, int);
    std::set<std::string> grade(int);
  };
};
#endif /* _GRADE_SCHOOL_H_ */
