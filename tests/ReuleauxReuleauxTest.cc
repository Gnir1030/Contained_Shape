#include "Polygon.h"
#include "Reuleaux.h"
#include <gtest/gtest.h>
// Uncomment when you're ready

Point tri5[3] = {Point(2.0,0.0), Point(-2.0, 0.0), Point(0.0, 2.0 * sqrt(3.0))};

TEST(ReuleauxReuleaux, Contained)
{
  Point tri[3] = {Point(-3.0,-1.0), Point(3.0, -1.0), Point(0.0, 3.0 * sqrt(3.0) - 1)};
  ReuleauxTriangle inner = ReuleauxTriangle(tri5);
  ReuleauxTriangle outer = ReuleauxTriangle(tri);
  ASSERT_TRUE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux2, Case1NotContained)
{
  Point tri[3] = {Point(-1.0,0.0), Point(1.0, 0.0), Point(0.0, sqrt(3.0))};
  ReuleauxTriangle inner = ReuleauxTriangle(tri5);
  ReuleauxTriangle outer = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux3, Case2NotContained)
{
  Point tri[3] = {Point(0.0,1.0), Point(- 2.0, 1.0), Point(-1.0, 1 + sqrt(3.0))};
  ReuleauxTriangle inner = ReuleauxTriangle(tri5);
  ReuleauxTriangle outer = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux4, Case3NotContained)
{
  Point tri[3] = {Point(1.0,0.4), Point(1.0, -0.4), Point(0.0, sqrt(3.0) -0.4)};
  ReuleauxTriangle inner = ReuleauxTriangle(tri5);
  ReuleauxTriangle outer = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux5, Case4NotContained)
{
  Point tri[3] = {Point(0.0,2.0 * sqrt(3.0) - 4), Point(2.0, 4.0 *sqrt(3.0)), Point(-2.0, 4.0 *sqrt(3.0) - 4)};
  ReuleauxTriangle inner = ReuleauxTriangle(tri5);
  ReuleauxTriangle outer = ReuleauxTriangle(tri);
  ASSERT_FALSE(inner.ContainedBy(outer));
}

TEST(ReuleauxReuleaux6, Case5NotContained)
{
  ReuleauxTriangle inner = ReuleauxTriangle(tri5);
  ReuleauxTriangle outer = ReuleauxTriangle(tri5);
  ASSERT_FALSE(inner.ContainedBy(outer));
}
/* 
    1. All inner Reuleaux vertices outside outer Reuleaux (Inner surrounds Outer)
    2. One or more Reuleaux vertices outside outer Reuleaux (Inner and Outer intersect) 
    3. Inner Reuleaux curve touches Outer perimeter (inside)
    4. Inner Reuleaux curve touches Outer perimeter (outside)
    5. Coincidence
*/
