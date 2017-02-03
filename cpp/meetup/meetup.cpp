#include <iostream>
#include "meetup.h"

using namespace std;
using namespace boost::gregorian;

namespace meetup
{
  scheduler::scheduler(months_of_year month, int year)
  {
    _base = date(year, month, 1);
    this->find_teenths();
  }

  void scheduler::find_teenths()
  {
    date teenth = _base + date_duration(12);
    day_iterator it (teenth);
    for (; it->day() < 20; ++it)
    {
      greg_weekday d = it->day_of_week();
      if (_teenths[d].is_not_a_date())
        _teenths[d] = *it;
    }
  }

  typedef nth_day_of_the_week_in_month nth_dow;

#define FDM(dow) (first_day_of_the_week_in_month(dow, _base.month()).get_date(_base.year()))
#define LDM(dow) (last_day_of_the_week_in_month(dow, _base.month()).get_date(_base.year()))
#define NDM(c,dow) (nth_dow(nth_dow::c, dow, _base.month()).get_date(_base.year()))
  
  date scheduler::first_monday() const { return FDM(Monday); }
  date scheduler::first_tuesday() const { return FDM(Tuesday); }
  date scheduler::first_wednesday() const { return FDM(Wednesday); }
  date scheduler::first_thursday() const { return FDM(Thursday); }
  date scheduler::first_friday() const { return FDM(Friday); }
  date scheduler::first_saturday() const { return FDM(Saturday); }
  date scheduler::first_sunday() const { return FDM(Sunday); }

  date scheduler::second_monday() const { return NDM(second, Monday); }
  date scheduler::second_tuesday() const { return NDM(second, Tuesday); }
  date scheduler::second_wednesday() const { return NDM(second, Wednesday); }
  date scheduler::second_thursday() const { return NDM(second, Thursday); }
  date scheduler::second_friday() const { return NDM(second, Friday); }
  date scheduler::second_saturday() const { return NDM(second, Saturday); }
  date scheduler::second_sunday() const { return NDM(second, Sunday); }

  date scheduler::third_monday() const { return NDM(third, Monday); }
  date scheduler::third_tuesday() const { return NDM(third, Tuesday); }
  date scheduler::third_wednesday() const { return NDM(third, Wednesday); }
  date scheduler::third_thursday() const { return NDM(third, Thursday); }
  date scheduler::third_friday() const { return NDM(third, Friday); }
  date scheduler::third_saturday() const { return NDM(third, Saturday); }
  date scheduler::third_sunday() const { return NDM(third, Sunday); }

  date scheduler::fourth_monday() const { return NDM(fourth, Monday); }
  date scheduler::fourth_tuesday() const { return NDM(fourth, Tuesday); }
  date scheduler::fourth_wednesday() const { return NDM(fourth, Wednesday); }
  date scheduler::fourth_thursday() const { return NDM(fourth, Thursday); }
  date scheduler::fourth_friday() const { return NDM(fourth, Friday); }
  date scheduler::fourth_saturday() const { return NDM(fourth, Saturday); }
  date scheduler::fourth_sunday() const { return NDM(fourth, Sunday); }

  date scheduler::last_monday() const { return LDM(Monday); }
  date scheduler::last_tuesday() const { return LDM(Tuesday); }
  date scheduler::last_wednesday() const { return LDM(Wednesday); }
  date scheduler::last_thursday() const { return LDM(Thursday); }
  date scheduler::last_friday() const { return LDM(Friday); }
  date scheduler::last_saturday() const { return LDM(Saturday); }
  date scheduler::last_sunday() const { return LDM(Sunday); }

  date scheduler::monteenth() const { return _teenths[Monday]; }
  date scheduler::tuesteenth() const { return _teenths[Tuesday]; }
  date scheduler::wednesteenth() const { return _teenths[Wednesday]; }
  date scheduler::thursteenth() const { return _teenths[Thursday]; }
  date scheduler::friteenth() const { return _teenths[Friday]; }
  date scheduler::saturteenth() const { return _teenths[Saturday]; }
  date scheduler::sunteenth() const { return _teenths[Sunday]; }

}
