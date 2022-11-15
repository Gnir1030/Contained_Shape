#include "Polygon.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

Point tri2[3] = {Point(2.0,0.0), Point(-2.0, 0.0), Point(0.0, 2.0 * sqrt(3.0))};

TEST(PolygonReuleaux, Contained)
{
  std::vector<Point> convex = {Point(-1.0,0.0), Point(1.0, 0.0), Point(0.0, 2.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri2);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(PolygonReuleaux2, Case1NotContained)
{
  std::vector<Point> convex = {Point(3.0,0.0), Point(4.0, 0.0), Point(0.0, 2.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonReuleaux3, Case2NotContained)
{
  std::vector<Point> convex = {Point(0.0,0.0), Point(2.0, 0.0), Point(5.0, 3.0), Point(1.0, 4.0), Point(-1.0, 2.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonReuleaux4, Case3NotContained)
{
  std::vector<Point> convex = {Point(-2.0,2.0 * sqrt(3.0) - 4), Point(2.0,2.0 * sqrt(3.0) - 4), Point(0.0,-2.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonReuleaux5, Case4NotContained)
{
  std::vector<Point> convex = {Point(3.0,-1.0), Point(-3.0, -1.0), Point(0.0,5.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(PolygonReuleaux6, Case5NotContained)
{
  std::vector<Point> convex = {Point(1.0,sqrt(7.0)), Point(1.5, sqrt(3.75)), Point(0.0,0.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

/* 
    1. Inner and Outer intersect (not contained)
    2. Inner outside Outer
    3. Inner perimeter touches Outer perimeter, Inner is outside Outer (not contained)
    4. Inner surrounds Outer (not contained)
    5. Inner perimeter touches Outer perimeter, Inner is inside Outer (not contained)
*/
