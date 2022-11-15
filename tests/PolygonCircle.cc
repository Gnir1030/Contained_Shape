#include "Circle.h"
#include "Polygon.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

std::vector<Point> convex2 = {Point(0.0,0.0), Point(2.0, 0.0), Point(3.0, 2.0), Point(1.0, 4.0), Point(-1.0, 2.0)};

TEST(PolygonCircle, Contained)
{
  Polygon inner = Polygon(convex2);
  Circle outer = Circle(Point(1.0,2.0), 4.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(PolygonCircle2, Case1NotContained)
{
  Polygon inner = Polygon(convex2);
  Circle outer = Circle(Point(1.0,2.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonCircle3, Case2NotContained)
{
  Polygon inner = Polygon(convex2);
  Circle outer = Circle(Point(2.0,2.0), 1.5);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonCircle4, Case3NotContained)
{
  Polygon inner = Polygon(convex2);
  Circle outer = Circle(Point(1.0,2.0), sqrt(3.0));
  ASSERT_FALSE(inner.ContainedBy(outer));
}
/* 
    1. All Polygon vertices outside Circle (Inner surrounds Outer)
    2. One or more Polygon vertices outside Circle (Inner and Outer intersect) 
    4. One or more Polygon vertices touch Outer perimeter
*/
