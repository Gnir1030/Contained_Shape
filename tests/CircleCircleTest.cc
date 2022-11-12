#include "Circle.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

TEST(CircleCircle, Contained)
{
  Circle inner = Circle(Point(0.0,0.0), 2.0);
  Circle outer = Circle(Point(0.0,0.0), 4.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(CircleCircle2, Contained)
{
  Circle inner2 = Circle(Point(2.0,0.0), 2.0);
  Circle outer2 = Circle(Point(0.0,0.0), 4.0);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

/* 
   You'll need to extend this by adding additional tests for:
    1. Inner and Outer intersect (not contained)
    2. Inner is entirely outside Outer (not contained)
    3. Inner surrounds Outer (not contained)
    3. Inner coincident with Outer (not contained)
    4. Inner perimeter touches Outer perimeter, Inner is inside Outer (not contained)
    5. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)

    Note that 4. and 5. should be taken care of by 1. but you need the tests to make sure
*/
