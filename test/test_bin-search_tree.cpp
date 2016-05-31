#include "gtest.h"
#include "bin-search-tree.h"


TEST(BINSEARCH, can_create_tree)
{
	ASSERT_NO_THROW(BinSearchTree *tree = new BinSearchTree());
}

TEST(BINSEARCH, can_add_new_key)
{
	BinSearchTree *tree = new BinSearchTree();
	Node* i = new Node();
	i->key = 1;
	ASSERT_NO_THROW(tree->add(i));
}

TEST(BINSEARCH, can_del_node)
{
	BinSearchTree *tree = new BinSearchTree();
	Node* i = new Node();
	i->key = 1;
	tree->add(i);
	ASSERT_NO_THROW(tree->DelNode(i));
}

TEST(BINSEARCH, pull_works_correctly)
{
	BinSearchTree *tree = new BinSearchTree();
	Node* i = new Node();
	Node* j = new Node();
	i->key = 1;
	j->key = 2;
	tree->add(i);
	
	EXPECT_EQ(2, tree->pull(2)->key);
}



TEST(BINSEARCH, isEmpty_work_true)
{
	BinSearchTree *tree = new BinSearchTree();
	Node* i = new Node();
	i->key = 1;
	tree->add(i);
	tree->del(1);
	ASSERT_TRUE(tree->isEmpty());
}

TEST(BINSEARCH, isEmpty_works_true_when_heap_not_empty)
{
	BinSearchTree *tree = new BinSearchTree();
	Node* i = new Node();
	i->key = 1;
	tree->add(i);
	
	ASSERT_FALSE(tree->isEmpty());
}
