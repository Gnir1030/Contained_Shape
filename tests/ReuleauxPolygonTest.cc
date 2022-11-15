#include "Polygon.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

Point tri3[3] = {Point(2.0,0.0), Point(-2.0, 0.0), Point(0.0, 2.0 * sqrt(3.0))};

TEST(ReuleauxConvex, Contained)
{
  std::vector<Point> convex = {Point(-3.0, -1.0), Point(3.0, -1.0), Point(3.0,4.0), Point(-3.0, 4.0)};
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Polygon outer = Polygon(convex);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(ReuleauxConvex2, Case1NotContained)
{
  std::vector<Point> convex = {Point(-1.0,0.0), Point(1.0, 0.0), Point(1.0, 1.0), Point(-1.0, 1.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri3);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxConvex3, Case2NotContained)
{
  std::vector<Point> convex = {Point(-3.0, -1.0), Point(3.0, -1.0), Point(3.0,2.0), Point(-3.0, 2.0)};
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Polygon outer = Polygon(convex);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxConvex4, Case3NotContained)
{
  std::vector<Point> convex = {Point(8.0/sqrt(3.0) - 2.0,0.0), Point(4.0/sqrt(3.0) - 2, 4.0), Point(-3.0,4.0), Point(-3.0, -2.0)};
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Polygon outer = Polygon(convex);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxConvex5, Case4NotContained)
{
  std::vector<Point> convex = {Point(-3,-0.25), Point(3, -0.25), Point(3.0,4.0), Point(-3.0, 4.0)};
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Polygon outer = Polygon(convex);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
/* 
    1. All inner Polygon vertices outside outer Reuleaux (Inner surrounds Outer)
    2. One or more Polygon vertices outside outer Reuleaux (Inner and Outer intersect) 
    3. One or more Polygon vertices touch Outer perimeter
    All inner Reuleux Vertices inside
    4. A curve of Reuleaux intersect with Outer Circle
*/
