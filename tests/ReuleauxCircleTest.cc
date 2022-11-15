#include "Circle.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

Point tri3[3] = {Point(2.0,0.0), Point(-2.0, 0.0), Point(0.0, 2.0 * sqrt(3.0))};

TEST(ReuleauxCircle, Contained)
{
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Circle outer = Circle(Point(0.0,0.0), 10.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle2, Case1NotContained)
{
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Circle outer = Circle(Point(0.0,1.0), 1.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle3, Case2NotContained)
{
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Circle outer = Circle(Point(0.0,2.0), 2.0);
  ASSERT_FALSE(inner.ContainedBy(outer));
}


TEST(ReuleauxCircle4, Case3NotContained)
{
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Circle outer = Circle(Point(0.0,5.0), 9.0 - 2.0 * sqrt(3.0));
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle5, Case4NotContained)
{
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Circle outer = Circle(Point(0.0,5.0), 5.5);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxCircle6, Case5Contained)
{
  ReuleauxTriangle inner = ReuleauxTriangle(tri3);
  Circle outer = Circle(Point(2.0,2.0), 5.0);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

/* 
    1. All inner Reuleaux vertices outside outer Circle (Inner surrounds Outer)
    2. One or more Reuleaux vertices outside outer Circle (Inner and Outer intersect) 
    3. One or more Reuleaux vertices touch Outer perimeter
    All inner Reuleux Vertices inside
    4. A curve of Reuleaux intersect with Outer Circle
    5. Circle not intersect when reaching on vertex, not curve (Contained)
*/
