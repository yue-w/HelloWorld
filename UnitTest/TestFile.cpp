#include <gtest\gtest.h>

TEST(MyArbitraryCategoryName, FirstTestTestName)
{
	int i = 7;
	int j = 10;
	int result = i*j;
	EXPECT_EQ(60, result);
	//EXPECT_TRUE(result == 70);

}