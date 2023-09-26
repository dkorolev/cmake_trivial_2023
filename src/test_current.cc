#include <gtest/gtest.h>

// NOTE(dkorolev): Works with regular quotes too, but we're using `current` as a CMake-enabled dependency now!
#include <bricks/strings/split.h>

TEST(Current, StringsSplit) {
  auto const parts = current::strings::Split("foo,bar,baz", ",");
  ASSERT_EQ(parts.size(), 3u);
  EXPECT_EQ("foo", parts[0]);
  EXPECT_EQ("bar", parts[1]);
  EXPECT_EQ("baz", parts[2]);
}
