#include <gtest/gtest.h>

#include "lib.h"

TEST(Add, Smoke) {
  EXPECT_EQ(5, add(2, 3));
}
