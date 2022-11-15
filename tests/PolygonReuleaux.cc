#include "Polygon.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

Point tri2[3] = {Point(4.0,0.0), Point(-4.0, 0.0), Point(0.0, 4.0 * sqrt(3.0))};

TEST(PolygonReuleaux, Contained)
{
  std::vector<Point> convex = {Point(0.0,0.0), Point(2.0, 0.0), Point(2.0, 2.0), Point(1.0, 3.0), Point(-1.0, 2.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri2);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(PolygonReuleaux2, Case1NotContained)
{
  std::vector<Point> convex = {Point(-5.0,5.0), Point(-5.0, -1.0), Point(5.0, -1.0), Point(5.0, 5.0)};
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
  std::vector<Point> convex = {Point(0.0,0.0), Point(4.0, 0.0), Point(3.0, sqrt(15.0)), Point(1.0, 4.0), Point(-1.0, 2.0)};
  Polygon inner = Polygon(convex);
  ReuleauxTriangle outer = ReuleauxTriangle(tri2);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
/* 
    1. All inner Polygon vertices outside outer Reuleaux (Inner surrounds Outer)
    2. One or more Polygon vertices outside outer Reuleaux (Inner and Outer intersect) 
    3. One or more Polygon vertices touch Outer perimeter
*/
