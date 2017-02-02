#ifndef _PHONE_NUMBER_H_
#define _PHONE_NUMBER_H_
#include <string>
class phone_number
{
 private:
  std::string digits;
  std::string formatted;

 public:
  phone_number(std::string);
  std::string number() const;
  std::string area_code() const;
  std::string co_code() const;
  std::string station_code() const;
  operator std::string() const;
};
#endif /* _PHONE_NUMBER_H_ */
