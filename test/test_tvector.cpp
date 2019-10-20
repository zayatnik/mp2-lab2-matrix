#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TVector<int> v(5));
	TVector<int> v(5);
	for (int i = 0; i < 5; i++) {
		EXPECT_EQ(v[i], 0);
	}
}

TEST(TVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, can_create_vector_with_max_size)
{
	ASSERT_NO_THROW(TVector<int> v(MAX_VECTOR_SIZE));
}

TEST(TVector, can_create_vector_with_zero_size)
{
	ASSERT_NO_THROW(TVector<int> v(0));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TVector<int> v(-5, 1));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
	ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
	TVector<int> v(10);
	ASSERT_NO_THROW(TVector<int> v1(v));
	TVector<int> v1(v);
	for (int i = 0; i < 10; i++) {
		EXPECT_EQ(v1[i], 0);
	}
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> t1(10);
	t1[0] = 1;
	t1[9] = 1;
	TVector<int> t2(t1);
	EXPECT_EQ(t1, t2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> t1(10);
	t1[0] = 1;
	t1[9] = 1;
	TVector<int> t2(t1);
	t2[0] = 3;
	t2[4] = 5;
	EXPECT_EQ(t1[0], 1);
	EXPECT_EQ(t1[9], 1);
	EXPECT_EQ(t1[4], 0);
	EXPECT_EQ(t2[4], 5);
	EXPECT_EQ(t2[0], 3);

}

TEST(TVector, can_get_size)
{
	TVector<int> v(4);

	EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
	TVector<int> v(4, 2);

	EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
	TVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
	EXPECT_EQ(0, v[1]);
	EXPECT_EQ(0, v[2]);
	EXPECT_EQ(0, v[3]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	EXPECT_ANY_THROW(v[-1] = 5);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	EXPECT_ANY_THROW(v[10] = 5);

}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);
	v[0] = 5;
	EXPECT_NO_THROW(v = v);
	EXPECT_EQ(v[0], 5);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(14), y(14);
	v[0] = 5;
	v[1] = 8;
	EXPECT_NO_THROW(y = v);
	EXPECT_EQ(y[0], 5);
	EXPECT_EQ(y[1], 8);
	for (int i = 2; i < 14; i++) {
		EXPECT_EQ(y[i], 0);
	}
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(44), y(10);
	y = v;
	EXPECT_EQ(y.GetSize(), 44);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(14), y(24);
	v[0] = 5;
	v[1] = 8;
	EXPECT_NO_THROW(y = v);
	EXPECT_EQ(y[0], 5);
	EXPECT_EQ(y[1], 8);
	for (int i = 2; i < 14; i++) {
		EXPECT_EQ(y[i], 0);
	}
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<double> t1(13), t2(20);
	t1[1] = 1;
	t1[4] = 1;
	t2 = t1;
	EXPECT_TRUE(t2 == t1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<double> t1(13);
	t1[9] = 1;
	EXPECT_TRUE(t1 == t1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<double> t1(13), t2(45);
	EXPECT_FALSE(t1 == t2);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<double> t1(13);
	EXPECT_NO_THROW(t1 = t1 + 5);
	for (int i = 0; i < 13; i++) {
		EXPECT_EQ(t1[i], 5);
	}
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<double> t1(13);
	EXPECT_NO_THROW(t1 = t1 - 5);
	for (int i = 0; i < 13; i++) {
		EXPECT_EQ(t1[i], -5);
	}
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<double> t1(13);
	t1[0] = 6;
	EXPECT_NO_THROW(t1 = t1 * 3);
	EXPECT_EQ(t1[0], 18);
	for (int i = 1; i < 13; i++) {
		EXPECT_EQ(t1[i], 0);
	}
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<double> t1(13), t2(13);
	t1[0] = 1;
	t2[1] = 3;
	t2[0] = 2;
	EXPECT_NO_THROW(t1 + t2);
	TVector<double> t3(t1 + t2);
	EXPECT_EQ(t3[0], 3);
	EXPECT_EQ(t3[1], 3);
	for (int i = 2; i < 13; i++) {
		EXPECT_EQ(t3[i], 0);
	}
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<double> t1(13), t2(43);
	t1[0] = 1;
	t2[0] = 3;
	EXPECT_ANY_THROW(t1 + t2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<double> t1(13), t2(13);
	t1[0] = 1;
	t2[0] = 3;
	EXPECT_NO_THROW(t1 - t2);
	TVector<double> t3(t1 - t2);
	EXPECT_EQ(t3[0], -2);
	for (int i = 1; i < 13; i++) {
		EXPECT_EQ(t3[i], 0);
	}
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<double> t1(13), t2(43);
	t1[0] = 1;
	t2[0] = 3;
	EXPECT_ANY_THROW(t1 - t2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<double> t1(13), t2(13);
	t1[0] = 6;
	t2[0] = 8;
	EXPECT_NO_THROW(t1 * t2);
	EXPECT_EQ(t1 * t2, 48);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<double> t1(13), t2(17);
	t1[0] = 6;
	t2[0] = 8;
	EXPECT_ANY_THROW(t1 * t2);
}

