#include <stdexcept>
#include "nucleotide_count.h"

using namespace std;

namespace dna
{
  void counter::calculate()
  {
    for (const char c : sequence)
    {
      ++counts[c];
    }
  }
  
  counter::counter(const std::string nucs)
  {
    counts['A'] = 0;
    counts['T'] = 0;
    counts['C'] = 0;
    counts['G'] = 0;
    sequence.assign(nucs);
    this->calculate();
  }

  ncounts counter::nucleotide_counts() const
  {
    return counts;
  }

  int counter::count(const char c) const
  {
    try
    {
      return counts.at(c);
    }
    catch (out_of_range&)
    {
      throw invalid_argument("Bad nucleotide");
    }
  }
}
