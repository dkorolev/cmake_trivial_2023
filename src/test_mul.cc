#include <gtest/gtest.h>

#include "lib.h"

TEST(Mul, Smoke) {
  EXPECT_EQ(6, mul(2, 3));
}
