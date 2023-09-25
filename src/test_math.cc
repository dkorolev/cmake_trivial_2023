#include "3rdparty/gtest/gtest-main-with-dflags.h"
#include "lib.h"

TEST(Math, Add) {
  EXPECT_EQ(5, add_from_library(2, 3));
}

TEST(Math, Sum) {
  EXPECT_EQ(6, mul_from_library(2, 3));
}
