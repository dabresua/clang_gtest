#include <gtest/gtest.h>
#include <lib.h>

int ff(int x) {
  return 2 / x;
}

TEST(tests, two) {
  ASSERT_NE(myfun(false, ff), ff(10));
}
