#include "__preprocessor__.h"
#include <gtest/gtest.h> // must be first

TEST(SampleTest, Sanity) { EXPECT_EQ(1, 1); }

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
