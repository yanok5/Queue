#include "queue.h"

#include <gtest.h>

TEST(Queue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(Queue, cant_create_too_large_queue)
{
	ASSERT_ANY_THROW(Queue<int> q(MAX_VECTOR_SIZE + 1));
}

TEST(Queue, throws_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(Queue<int> q(-1));
}

TEST(Queue, can_push) 
{
	Queue<int> q(2);
	ASSERT_NO_THROW(q.push(1));
}

TEST(Queue, can_pop)
{
	Queue<int> q(5);
	q.push(1);
	ASSERT_NO_THROW(q.pop());
}

TEST(Queue, return_true_when_queue_is_empty)
{
	Queue<int> q;
	EXPECT_EQ(true, q.empty());
}

TEST(Queue, return_false_when_queue_isnt_empty) 
{
	Queue<int> q(1);
	EXPECT_EQ(false, q.empty());
}

TEST(Queue, return_true_when_queue_is_full) 
{
	Queue<int> q;
	EXPECT_EQ(true, q.full());
}

TEST(Queue, return_false_when_queue_isnt_full) 
{
	Queue<int> q(10);
	q.push(1);
	EXPECT_EQ(false, q.full());
}
