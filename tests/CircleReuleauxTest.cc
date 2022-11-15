#include "Circle.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

Point tri[3] = {Point(2.0,0.0), Point(-2.0, 0.0), Point(0.0, 2.0 * sqrt(3.0))};

TEST(CircleReuleaux, Contained)
{
  Circle inner = Circle(Point(0.0,1.0), 1.0);
  ReuleauxTriangle outer = ReuleauxTriangle(tri);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(CircleReuleaux2, Case1NotContained)
{
  Circle inner2 = Circle(Point(2.0,2.0), 2.0);
  ReuleauxTriangle outer2 = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleReuleaux3, Case2NotContained)
{
  Circle inner2 = Circle(Point(0.0,1.0), 2.0);
  ReuleauxTriangle outer2 = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleReuleaux4, Case3NotContained)
{
  Circle inner2 = Circle(Point(0.0,1.0), 4.0);
  Polygon outer2 = Polygon(convex);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleReuleaux5, Case4NotContained)
{
  Circle inner2 = Circle(Point(0.0,0.0), 1.0);
  Polygon outer2 = Polygon(convex);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}
/* 
    1. Circle center outside Reuleaux
    -Circle center inside Reuleaux
    2. Inner and Outer intersect (not contained)
    3. Inner surrounds Outer (not contained)
    4. Inner perimeter touches Outer perimeter, Inner is inside Outer (not contained)
*/
