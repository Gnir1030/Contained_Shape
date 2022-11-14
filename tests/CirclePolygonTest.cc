#include "Circle.h"
#include "Polygon.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

std::vector<Point> convex = {Point(0.0,0.0), Point(2.0, 0.0), Point(3.0, 2.0), Point(1.0, 4.0), Point(-1.0, 2.0)};
std::vector<Point> concave = {Point(-3.0,0.0), Point(2.0, 0.0), Point(4.0, 5.0), Point(2.0, 5.0), Point(-4.0, 8.0)};

TEST(CircleConvexPolygon, Contained)
{
  Circle inner = Circle(Point(1.0,2.0), 1.0);
  Polygon outer = Polygon(convex);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(CircleConvexPolygon2, Case1NotContained)
{
  Circle inner2 = Circle(Point(4.0,2.0), 2.0);
  Polygon outer2 = Polygon(convex);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleConvexPolygon3, Case2NotContained)
{
  Circle inner2 = Circle(Point(2.0,2.0), 2.0);
  Polygon outer2 = Polygon(convex);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleConvexPolygon4, Case3NotContained)
{
  Circle inner2 = Circle(Point(2.0,2.0), 4.0);
  Polygon outer2 = Polygon(convex);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleConvexPolygon5, Case4NotContained)
{
  Circle inner2 = Circle(Point(1.0,1.0), 1.0);
  Polygon outer2 = Polygon(convex);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleConcavePolygon, Contained)
{
  Circle inner = Circle(Point(-1.0,4.0), 2.0);
  Polygon outer = Polygon(concave);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(CircleConcavePolygon2, Case1NotContained)
{
  Circle inner2 = Circle(Point(0.0,7.0), 2.0);
  Polygon outer2 = Polygon(concave);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleConcavePolygon3, Case2NotContained)
{
  Circle inner2 = Circle(Point(0.0,3.0), 4.0);
  Polygon outer2 = Polygon(concave);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleConcavePolygon4, Case3NotContained)
{
  Circle inner2 = Circle(Point(0.0,3.0), 7.0);
  Polygon outer2 = Polygon(concave);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}

TEST(CircleConcavePolygon5, Case4NotContained)
{
  Circle inner2 = Circle(Point(0.0,2.0), 2.0);
  Polygon outer2 = Polygon(concave);
  ASSERT_FALSE(inner2.ContainedBy(outer2));
}
/* 
    1. Circle center outside Polygon
    -Circle center inside Polygon
    2. Inner and Outer intersect (not contained)
    3. Inner surrounds Outer (not contained)
    4. Inner perimeter touches Outer perimeter, Inner is inside Outer (not contained)
*/
