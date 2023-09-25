#include "3rdparty/gtest/gtest-main-with-dflags.h"
#include "lib.h"

TEST(Add, Smoke) {
  EXPECT_EQ(5, add_from_library(2, 3));
}
