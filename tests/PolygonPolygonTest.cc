#include "Polygon.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

std::vector<Point> convex3 = {Point(-2.0,-1.0), Point(4.0, -1.0), Point(3.0, 5.0), Point(-1.0, 5.0)};

TEST(ConvexConvex, Contained)
{
  std::vector<Point> convex = {Point(0.0,0.0), Point(2.0, 0.0), Point(3.0, 2.0), Point(1.0, 4.0), Point(-1.0, 2.0)};
  Polygon inner = Polygon(convex);
  Polygon outer = Polygon(convex3);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(ConvexConvex2, Case1NotContained)
{
  std::vector<Point> convex = {Point(-3.0,-2.0), Point(5.0, -2.0), Point(5.0, 6.0), Point(-3.0, 6.0)};
  Polygon inner = Polygon(convex);
  Polygon outer = Polygon(convex3);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ConvexConvex3, Case2NotContained)
{
  std::vector<Point> convex = {Point(0.0,0.0), Point(2.0, 0.0), Point(3.0, 2.0), Point(1.0, 4.0), Point(-2.0, 2.0)};
  Polygon inner = Polygon(convex);
  Polygon outer = Polygon(convex3);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ConvexConvex4, Case3NotContained)
{
  std::vector<Point> convex = {Point(0.0,-1.0), Point(2.0, -1.0), Point(3.0, 2.0), Point(1.0, 4.0), Point(-1.0, 2.0)};
  Polygon inner = Polygon(convex);
  Polygon outer = Polygon(convex3);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ConvexConvex5, Case4NotContained)
{
  //std::vector<Point> convex = {Point(0.0,-1.0), Point(2.0, -1.0), Point(3.0, 2.0), Point(1.0, 4.0), Point(-1.0, 2.0)};
  Polygon inner = Polygon(convex3);
  Polygon outer = Polygon(convex3);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
/* 
    1. All inner Polygon vertices outside outer Polygon (Inner surrounds Outer)
    2. One or more Polygon vertices outside outer Polygon (Inner and Outer intersect) 
    3. One or more Polygon vertices touch Outer perimeter
    4. Coincidence
*/
