#include "gtest.h"
#include "tree_lib.h"

TEST(BINSEARCH, can_create_heap)
{
	ASSERT_NO_THROW(Tree *heap = new Tree(2));
}

TEST(BINSEARCH, cant_create_heap_with_negative)
{
	ASSERT_ANY_THROW(Tree *heap = new Tree(-5));
}

TEST(BINSEARCH, can_add_new_key)
{
	Tree *heap = new Tree(4);
	Data* i = new Data();
	i->priority = 4;
	ASSERT_NO_THROW(heap->input(i));
}

TEST(BINSEARCH, cant_add_key_into_full_heap)
{
	Tree *heap = new Tree(4);
	for (int i = 0; i<MaxSize; i++)
	{
		Data* key = new Data();
		key->priority = 3;
		heap->input(key);
	}
	Data *key = new Data();
	key->priority = 3;
	ASSERT_ANY_THROW(heap->input(key));
}

TEST(BINSEARCH, can_add_group_into_heap)
{
	Data **key = new Data*[4];
	for (int i = 0; i<4; i++)
	{
		key[i] = new Data;
		key[i]->priority = 1;
	}
	Tree *heap = new Tree(4);
	ASSERT_NO_THROW(heap->inputGroup(key, 4));
}
TEST(BINSEARCH, cant_add_group_into_full_heap)
{
	Tree *heap = new Tree(4);
	for (int i = 0; i<MaxSize; i++)
	{
		Data *key = new Data();
		key->priority = 3;
		heap->input(key);
	}
	Data **gkey = new Data*[4];
	for (int i = 0; i<4; i++)
	{
		gkey[i] = new Data;
		gkey[i]->priority = 1;
	}
	ASSERT_ANY_THROW(heap->inputGroup(gkey, 4));
}

TEST(BINSEARCH, can_erase_elem)
{
	Tree *heap = new Tree(2);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_NO_THROW(heap->erase());
}

TEST(BINSEARCH, cant_erase_elem_from_empty_heap)
{
	Tree *heap = new Tree(4);
	ASSERT_ANY_THROW(heap->erase());
}

TEST(BINSEARCH, erase_works_correctly)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	Data *i2 = heap->erase(1);
	EXPECT_EQ(2, i2->priority);
}

TEST(BINSEARCH, cant_erase_missing_elem_negativ)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_ANY_THROW(heap->erase(-1));
}

TEST(BINSEARCH, cant_erase_missing_elem_to_high)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_ANY_THROW(heap->erase(3));
}

TEST(BINSEARCH, can_swap_elem)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_NO_THROW(heap->transposing(0, 1));
}

TEST(BINSEARCH, swap_works_true)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	heap->transposing(0, 1);
	Data* i2 = heap->erase(1);
	Data* i3 = heap->erase(0);
	EXPECT_EQ(i2->priority, 1);
	EXPECT_EQ(i3->priority, 2);
}

TEST(BINSEARCH, cant_swap_elem_with_negativ_idx)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_ANY_THROW(heap->transposing(-1, 1));
}
TEST(BINSEARCH, cant_swap_elem_with_to_high_idx)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_ANY_THROW(heap->transposing(0, 2));
}

TEST(BINSEARCH, can_surfacing)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_NO_THROW(heap->surfacing(0));
}

TEST(BINSEARCH, cant_surfacing_with_negativ_idx)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_ANY_THROW(heap->surfacing(-1));
}

TEST(BINSEARCH, cant_surfacing_with_to_high_idx)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_ANY_THROW(heap->surfacing(3));
}

TEST(BINSEARCH, can_immersion)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_NO_THROW(heap->immersion(1));
}

TEST(BINSEARCH, immersion_works_true)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	Data* i2 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	i2->priority = 3;
	heap->input(i0);
	heap->input(i1);
	heap->input(i2);
	heap->immersion(1);
	EXPECT_EQ(3, heap->erase(2)->priority);
}

TEST(BINSEARCH, cant_immersion_with_to_high_idx)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_ANY_THROW(heap->immersion(3));
}

TEST(BINSEARCH, cant_immersion_with_negativ_idx)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	heap->input(i0);
	heap->input(i1);
	ASSERT_ANY_THROW(heap->immersion(-1));
}

TEST(BINSEARCH, isFull_work_true)
{
	Tree *heap = new Tree(4);
	for (int i = 0; i<MaxSize; i++)
	{
		Data* ni = new Data();
		ni->priority = 1;
		heap->input(ni);
	}
	ASSERT_TRUE(heap->isFull());
}

TEST(BINSEARCH, isFull_works_true_when_heap_not_full)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	i0->priority = 1; 
	heap->input(i0);
	ASSERT_FALSE(heap->isFull());
}

TEST(BINSEARCH, isEmpty_work_true)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	i0->priority = 1;
	heap->input(i0);
	heap->erase(0);
	ASSERT_TRUE(heap->isEmpty());
}

TEST(BINSEARCH, isEmpty_works_true_when_heap_not_empty)
{
	Tree *heap = new Tree(4);
	Data* i0 = new Data();
	i0->priority = 1;
	heap->input(i0);
	
	ASSERT_FALSE(heap->isEmpty());
}
