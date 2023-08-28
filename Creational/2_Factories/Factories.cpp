#include "Factories.hpp"

/*
* We want to create a point class which will create a cartesian point.
* And for that, we can write a point constructor with two floats.
* and say afterwards the user requests that we need a polar coordinate and to create polar coordinate we need;
* radius R and angle theta.
* So again, the constructor would be with the 2 floats as a input.
* So here there is a problem in C++, we can't create two constructors which accepts same type of and number of arguments.
* So To resolve this issue, we can create two factory methods. which would be a static methods and
* we can say NewCartesian and NewPolar and that will create these points for us.
*/

struct Point
{
public:
  static Point NewCartesian(float x, float y)
  {
    return { x, y };
  }

  static Point NewPolar(float r, float theta)
  {
    return { r * cos(theta), r * sin(theta) };
  }

protected:
  Point(const float x, const float y)
    : x{ x },
    y{ y }
  {}

  float x;
  float y;
};

int main()
{
  auto cartesian = Point::NewCartesian(10, 15);

  auto polar = Point::NewPolar(10, 15);
  return 0;
}
