#include "gtest.h"
#include "separatedSet.h"

TEST(SepSet, can_create_SepSet)
{
	separatedSet *arr;
	ASSERT_NO_THROW(arr = new separatedSet(5));
}

TEST(SepSet, cant_create_SepSet_when_size_negative)
{
	separatedSet *arr;
	ASSERT_ANY_THROW(arr = new separatedSet(-1));
}

TEST(SepSet, can_make_singelton)
{
	separatedSet *arr = new separatedSet(5);
	ASSERT_NO_THROW(arr->singelton(1));
}

TEST(SepSet, cant_make_singelton_with_negative_idx)
{
	separatedSet *arr = new separatedSet(5);
	ASSERT_ANY_THROW(arr->singelton(-1));
}

TEST(SepSet, cant_make_singelton_with_to_high_idx)
{
	separatedSet *arr = new separatedSet(5);
	ASSERT_ANY_THROW(arr->singelton(6));
}

TEST(SepSet, can_make_union)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	ASSERT_NO_THROW(arr->unionS(1,2));
}

TEST(SepSet, cant_make_union_with_negative_idx)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	ASSERT_ANY_THROW(arr->unionS(-1, 2));
}

TEST(SepSet, cant_make_union_with_to_high_idx)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	ASSERT_ANY_THROW(arr->unionS(1, 6));
}

TEST(SepSet, can_subDef)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	arr->unionS(1, 2);
	ASSERT_NO_THROW(arr->subDef(2));
}

TEST(SepSet, subDef_works_correct)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	arr->unionS(1, 2);
	EXPECT_EQ(1, arr->subDef(2));
}

TEST(SepSet, cant_subDef_when_negativ_idx)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	arr->unionS(1, 2);
	ASSERT_ANY_THROW(arr->subDef(-1));
}

TEST(SepSet, cant_subDef_when_to_high_idx)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	arr->unionS(1, 2);
	ASSERT_ANY_THROW(arr->subDef(6));
}

TEST(SepSet, can_getSize)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	arr->unionS(1, 2);
	ASSERT_NO_THROW(arr->getSize(2));
}

TEST(SepSet, can_getSize_correct)
{
	separatedSet *arr = new separatedSet(8);
	arr->singelton(1);
	arr->singelton(2);
	arr->singelton(3);
	arr->singelton(4);
	arr->unionS(1, 2);
	arr->unionS(3, 4);
	arr->unionS(2, 3);
	EXPECT_EQ(4, arr->getSize(1));
}

TEST(SepSet, cant_getSize_when_negativ_idx)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	arr->unionS(1, 2);
	ASSERT_ANY_THROW(arr->getSize(-1));
}

TEST(SepSet, cant_getSize_when_to_high_idx)
{
	separatedSet *arr = new separatedSet(5);
	arr->singelton(1);
	arr->singelton(2);
	arr->unionS(1, 2);
	ASSERT_ANY_THROW(arr->getSize(6));
}

