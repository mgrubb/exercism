#ifndef _ANAGRAM_H_
#define _ANAGRAM_H_
#include <string>
#include <vector>
namespace anagram
{
  class anagram
  {
  private:
    std::string subject;
    
  public:
    anagram(const char*);
    const std::vector<const char*> &matches(const std::vector<const char*>&);
    
  };
};
#endif /* _ANAGRAM_H_S */
