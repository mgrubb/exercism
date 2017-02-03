#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_
namespace triangle
{
  enum triangle_type {equilateral, isosceles, scalene};
  triangle_type kind(float, float, float);
  
}
#endif /* _TRIANGLE_H_ */
