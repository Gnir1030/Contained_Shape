#include "Circle.h"
#include "Polygon.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

std::vector<Point> convex3 = {Point(0.0,0.0), Point(2.0, 0.0), Point(3.0, 2.0), Point(1.0, 4.0), Point(-1.0, 2.0)};

TEST(PolygonCircle, Contained)
{
  Polygon inner = Polygon(convex3);
  Circle outer = Circle(Point(1.0,2.0), 4.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(PolygonCircle2, Case1NotContained)
{
  Polygon inner = Polygon(convex3);
  Circle outer = Circle(Point(2.0,2.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonCircle3, Case2NotContained)
{
  Polygon inner = Polygon(convex3);
  Circle outer = Circle(Point(4.0,4.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonCircle4, Case3NotContained)
{
  Polygon inner = Polygon(convex3);
  Circle outer = Circle(Point(1.0,-1.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonCircle5, Case4NotContained)
{
  Polygon inner = Polygon(convex3);
  Circle outer = Circle(Point(1.0,2.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonCircle6, Case5NotContained)
{
  Polygon inner = Polygon(convex3);
  Circle outer = Circle(Point(1.0,1.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
/* 
    1. Inner and Outer intersect (not contained)
    2. Inner outside Outer
    3. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
    4. Inner surrounds Outer (not contained)
    5. Inner perimeter touches Outer perimeter, Inner is inside Outer (not contained)
*/
