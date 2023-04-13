#include <gtest/gtest.h>
#include <lib.h>

int id(int) { return 0; }

TEST(tests, one) {
  ASSERT_NE(myfun(true, &id), 0);
}
