#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING  1

#include <Casino_plus.h>
#include <gtest/gtest.h>

TEST(GeneratorTests, ReturnsJustOneElementWhenThereIsJustOne) {
	CasinoRandomGenerator<int> rand;
	rand.add_item(10, 1);

	EXPECT_EQ(rand.get_random_item(), 10);
	EXPECT_EQ(rand.get_random_item(), 10);
}

TEST(GeneratorTests, ReturnsZeroWhenEmpty) {
	CasinoRandomGenerator<int> rand;
	EXPECT_EQ(rand.get_random_item(), 0);
}