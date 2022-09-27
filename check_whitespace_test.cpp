#include <gtest/gtest.h>

#include "check_whitespace.h"

TEST(strip, EmptyString) {

    char *stripResult = strip("");
    ASSERT_STREQ("", stripResult);
}

TEST(strip, NoWhitespace) {

    char *stripResult = strip("frog");
    ASSERT_STREQ("frog", stripResult);
    free((char*)stripResult);
}

TEST(strip, WhitespaceOnFront) {
    char *stripResult = strip("   frog");
    ASSERT_STREQ("frog", stripResult);
    free((char*)stripResult);
}

TEST(strip, WhitespaceOnBack) {
    char *stripResult = strip("frog  ");
    ASSERT_STREQ("frog", stripResult);
    free((char*)stripResult);
}

TEST(strip, WhitespaceOnBothEnds) {
    char *stripResult = strip("  frog     ");
    ASSERT_STREQ("frog", stripResult);
    free((char*)stripResult);
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
