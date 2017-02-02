#ifndef _NUCLEOTIDE_COUNT_H_
#define _NUCLEOTIDE_COUNT_H_
#include <string>
#include <map>

namespace dna
{
  typedef std::map<char, int> ncounts;

  class counter
  {
  private:
    std::string sequence;
    ncounts counts;
    void calculate();

  public:
    counter(const std::string);
    int count(const char) const;
    ncounts nucleotide_counts() const;
  };
};
#endif /* _NUCLEOTIDE_COUNT_H_ */
