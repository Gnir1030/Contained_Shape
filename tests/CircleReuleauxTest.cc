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
  Circle inner = Circle(Point(2.0,2.0), 2.0);
  ReuleauxTriangle outer = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(CircleReuleaux3, Case2NotContained)
{
  Circle inner = Circle(Point(3.0,2.0), 1.0);
  ReuleauxTriangle outer = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(CircleReuleaux4, Case3NotContained)
{
  Circle inner2 = Circle(Point(0.0,-1.0), 1.0+2.0 * sqrt(3.0) - 4.0);
 ReuleauxTriangle outer2 = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleReuleaux5, Case4NotContained)
{
  Circle inner2 = Circle(Point(0.0,0.0), 1);
 ReuleauxTriangle outer2 = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleReuleaux6, Case5NotContained)
{
  Circle inner2 = Circle(Point(0.0,1.0), 3);
  ReuleauxTriangle outer2 = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleReuleaux7, Case6NotContained)
{
  Circle inner2 = Circle(Point(0.0,0.0), 4.0 - 2.0 * sqrt(3.0));
 ReuleauxTriangle outer2 = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}
/* 
    -Circle center outside Reuleaux
    1. Inner and Outer intersect (not contained)
    2. Inner outside Outer
    3. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
    -Circle center inside Reuleaux
    4. Inner and Outer intersect (not contained)
    5. Inner surrounds Outer (not contained)
    6. Inner perimeter touches Outer perimeter, Inner is inside Outer (not contained)
*/
