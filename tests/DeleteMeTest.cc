#include <gtest/gtest.h>

// only here to generate a compiler warning - delete this file

extern void branch(bool flag);

TEST(DeleteMe, Branch)
{
  branch(true);
  ASSERT_TRUE(false);
}
