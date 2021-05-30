#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING  1
#define G_UNITTEST

#include <vector>
#include <Casino_plus.h>
#include <gtest/gtest.h>

TEST(GeneratorTests, CanAddSingleItem) {
	CasinoRandomGenerator<int> rand;
	rand.add_item(10, 1);

	ASSERT_EQ(rand.m_rand_items[0].first, 10);
}

// Todo @critical : create test suits for sequential inseration
//TEST(GeneratorTests, CanAddSequentialItems) {
//	CasinoRandomGenerator<int> rand;
//	rand.add_items(
//		10, 1,
//		20, 2,
//		30, 3
//	);
//
//	EXPECT_EQ(rand.m_rand_items[0].first, 10);
//	EXPECT_EQ(rand.m_rand_items[1].first, 20);
//	EXPECT_EQ(rand.m_rand_items[2].first, 30);
//}

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