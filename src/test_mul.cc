#include "3rdparty/gtest/gtest-main-with-dflags.h"
#include "lib.h"

TEST(Mul, Smoke) {
  EXPECT_EQ(6, mul(2, 3));
}
