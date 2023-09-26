#include <gtest/gtest.h>

#include <string>

TEST(HW, Smoke) {
  std::string s = "Hello";
  s += ", ";
  s += "world";
  s += '!';
  EXPECT_EQ("Hello, world!", s);
}
