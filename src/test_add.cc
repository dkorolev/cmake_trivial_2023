#include "3rdparty/gtest/gtest-main-with-dflags.h"
#include "lib.h"

TEST(Add, Smoke) {
  EXPECT_EQ(5, add(2, 3));
}
