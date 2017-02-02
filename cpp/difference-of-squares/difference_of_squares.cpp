#include "difference_of_squares.h"

int squares::sum_of_squares(int n)
{
  int sum = 0;
  for (; n > 0; --n)
    sum += n*n;
      
  return sum;
}

int squares::square_of_sums(int n)
{
  int sum = 0;

  for (; n > 0; --n)
    sum += n;
  return sum*sum;
}

int squares::difference(int n)
{
  return square_of_sums(n) - sum_of_squares(n);
}
