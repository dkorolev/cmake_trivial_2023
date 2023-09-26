#include <gtest/gtest.h>

#include "lib.h"

TEST(Math, Add) {
  EXPECT_EQ(5, add(2, 3));
}

TEST(Math, Sum) {
  EXPECT_EQ(6, mul(2, 3));
}
