#include "gtest.h"
#include "Kruskl.h"

TEST(KRUSKL, cant_work_without_ver)
{
	Graph *graph = new Graph(0);
	ASSERT_ANY_THROW(Kruskl::KrusklAlg(graph, 1));
}


TEST(KRUSKL, KrusklAlg_works)
{
	Graph *graph = new Graph(4,6);
	graph->inputEdge(0, 1, 1);
	graph->inputEdge(0, 2, 2);
	graph->inputEdge(1, 2, 4);
	graph->inputEdge(1, 3, 6);
	graph->inputEdge(2, 3, 5);
	graph->inputEdge(3, 0, 3);
		
	Graph *tree = Kruskl::KrusklAlg(graph, 1);
	Edges** edges = tree->getEdgArr();
	
	EXPECT_EQ(3, tree->getSize());
	EXPECT_EQ(0, edges[0]->n);
	EXPECT_EQ(1, edges[0]->k);
	EXPECT_EQ(0, edges[1]->n);
	EXPECT_EQ(2, edges[1]->k);
	EXPECT_EQ(3, edges[2]->n);
	EXPECT_EQ(0, edges[2]->k);
	
}


