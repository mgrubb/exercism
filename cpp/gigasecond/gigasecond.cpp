#include <cmath>
#include "gigasecond.h"

using namespace boost::gregorian;
namespace gigasecond
{
  const static float days =  std::pow(10,9) / 86400;
  const static date_duration ddays (days);
};

const date & gigasecond::advance(const date& birth_date)
{
  return *(new date (birth_date + gigasecond::ddays));
}
