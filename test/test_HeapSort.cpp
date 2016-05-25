#include <gtest.h>
#include "HeapSort.h"

TEST(HEAPSORT, cant_work_without_arr) {
	int *Elems = 0;
	ASSERT_ANY_THROW(HeapSort::heapSort(Elems, 5, 2));
}

TEST(HEAPSORT, cant_work_with_wrong_size) {
	int *Elems;
	Elems[0] = 1;
	ASSERT_ANY_THROW(HeapSort::heapSort(Elems, -1, 2));
}

TEST(HEAPSORT, cant_work_with_wrong_d) {
	int *Elems;
	Elems[0] = 1;
	ASSERT_ANY_THROW(HeapSort::heapSort(Elems, 1, -1));
}

TEST(HEAPSORT, heapSort_work_correct) {
	int *Elems = new int[6];
	for (int i = 0; i < 6; i++)
		Elems[i] = i;
	
	HeapSort::heapSort(Elems, 6, 4);
	EXPECT_EQ(5, Elems[0]);
	EXPECT_EQ(4, Elems[1]);
	EXPECT_EQ(3, Elems[2]);
	EXPECT_EQ(2, Elems[3]);
	EXPECT_EQ(1, Elems[4]);
	EXPECT_EQ(0, Elems[5]);
}