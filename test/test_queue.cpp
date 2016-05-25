#include "gtest.h"
#include "queue.h"

TEST(pQueue, can_create_queue)
{
	ASSERT_NO_THROW(QueueHeap *q = new QueueHeap(2));
}

TEST(pQueue, can_create_queue_from_arr)
{
	Data **data = new Data*[2];
	for (int i = 0; i < 2; i++) {
		data[i] = new Data;
		data[i]->priority = 1;
	}
	ASSERT_NO_THROW(QueueHeap *q = new QueueHeap(data, 2, 2));
}

TEST(pQueue, can_add_elem)
{
	QueueHeap *q = new QueueHeap(2);
	Data *tmp = new Data;
	tmp->priority = 1;
	ASSERT_NO_THROW(q->add(tmp));
}
TEST(pQueue,add_works_correct)
{
	QueueHeap *q = new QueueHeap(2);
	Data *tmp = new Data;
	tmp->priority = 1;
	q->add(tmp);
	EXPECT_EQ(1, q->popidx(0)->priority);
}

TEST(pQueue, cant_add_elem_into_full_q)
{
	Data **data = new Data*[MaxSize];
	for (int i = 0; i < MaxSize; i++) 
	{
		data[i] = new Data;
		data[i]->priority = i;
	}
	QueueHeap *q = new QueueHeap(data, MaxSize, 2);
	Data* tmp = new Data();
	tmp->priority = 1;
	ASSERT_ANY_THROW(q->add(tmp));
}

TEST(pQueue, can_popidx_elem)
{
	QueueHeap *q = new QueueHeap(2);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	q->add(i0);
	q->add(i1);
	ASSERT_NO_THROW(q->popidx(1));
}

TEST(pQueue, popidx_works_correct)
{
	QueueHeap *q = new QueueHeap(2);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	q->add(i0);
	q->add(i1);
	EXPECT_EQ(1, q->popidx(0)->priority);
}

/*TEST(pQueue, can_popMin_elem)
{
	QueueHeap *q = new QueueHeap(2);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	q->add(i0);
	q->add(i1);
	ASSERT_NO_THROW(q->popMin());
}

TEST(pQueue, popMin_works_correct)
{
	QueueHeap *q = new QueueHeap(2);
	Data* i0 = new Data();
	Data* i1 = new Data();
	i0->priority = 1;
	i1->priority = 2;
	q->add(i0);
	q->add(i1);
	EXPECT_EQ(2, q->popMin()->priority);
}

TEST(pQueue, cant_popmin_popidx_from_empty_q)
{
	QueueHeap *q = new QueueHeap(2);
	ASSERT_ANY_THROW(q->popMin());
}*/

TEST(pQueue, isFull_work_correct)
{
	Data **data = new Data*[MaxSize];
	for (int i = 0; i < MaxSize; i++) 
	{
		data[i] = new Data;
		data[i]->priority = MaxSize - i;
	}
	QueueHeap *q = new QueueHeap(data, MaxSize, 2);
	ASSERT_TRUE(q->isFull());
}

TEST(pQueue, isFull_work_correct_if_is_not_full)
{
	QueueHeap *q = new QueueHeap(2);
	ASSERT_FALSE(q->isFull());
}

TEST(pQueue, isEmpty_work_true)
{
	QueueHeap *q = new QueueHeap(2);
	Data* i0 = new Data();
	i0->priority = 1;
	q->add(i0);
	q->popidx(0);
	ASSERT_TRUE(q->isEmpty());
}

TEST(pQueue, isEmpty_work_true_if_is_not_empty)
{
	QueueHeap *q = new QueueHeap(2);
	Data* i0 = new Data();
	i0->priority = 1;
	q->add(i0);
	ASSERT_FALSE(q->isEmpty());
}


