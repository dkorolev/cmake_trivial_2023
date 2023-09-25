#include "3rdparty/gtest/gtest-main-with-dflags.h"

TEST(HW, Smoke) {
  std::string s = "Hello";
  s += ", ";
  s += "world";
  s += '!';
  EXPECT_EQ("Hello, world!", s);
}
