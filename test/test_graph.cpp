#include "gtest.h"
#include "Graph.h"

TEST(GRAPH, can_create_graph)
{
	Graph *graph;
	ASSERT_NO_THROW(graph = new Graph(10));
}

TEST(GRAPH, can_create_graph_with_edg)
{
	Graph *graph;
	ASSERT_NO_THROW(graph = new Graph(2, 1));
}

TEST(GRAPH, cant_create_graph_with_negativ_ver)
{
	Graph *graph;
	ASSERT_ANY_THROW(graph = new Graph(-10));
}

TEST(GRAPH, cant_create_graph_with_to_many_ver)
{
	Graph *graph;
	ASSERT_ANY_THROW(graph = new Graph(maxVer + 1));
}

TEST(GRAPH, cant_create_graph_with_negativ_edg)
{
	Graph *graph;
	ASSERT_ANY_THROW(graph = new Graph(2, -1));
}

TEST(GRAPH, cant_create_graph_with_to_high_edg)
{
	Graph *graph;
	ASSERT_ANY_THROW(graph = new Graph(2, 2));
}

TEST(GRAPH, can_CreateGraph)
{
	Graph *graph = new Graph(2);
	ASSERT_NO_THROW(graph->CreateGraph(0, 10));
}

TEST(GRAPH, cant_CreateGraph_when_wrong_weight)
{
	Graph *graph = new Graph(2);
	ASSERT_ANY_THROW(graph->CreateGraph(1, 0));
}

TEST(GRAPH, can_inputEdge)
{
	Graph *graph = new Graph(2);
	ASSERT_NO_THROW(graph->inputEdge(0, 1, 1));
}

TEST(GRAPH, cant_add_loop)
{
	Graph *graph = new Graph(2);
	ASSERT_ANY_THROW(graph->inputEdge(1, 1, 1));
}

TEST(GRAPH, cant_add_available_edg)
{
	Graph *graph = new Graph(2);
	graph->inputEdge(0, 1, 1);
	ASSERT_ANY_THROW(graph->inputEdge(0, 1, 1));
}

TEST(GRAPH, can_deleteEdge)
{
	Graph *graph = new Graph(2);
	graph->inputEdge(0, 1, 1);
	ASSERT_NO_THROW(graph->deleteEdge(0, 1));
}

TEST(GRAPH, cant_deleteEdge_nonavailable)
{
	Graph *graph = new Graph(2);
	ASSERT_ANY_THROW(graph->deleteEdge(0, 1));
}

TEST(GRAPH, getVer_correct)
{
	Graph *graph = new Graph(2);
	EXPECT_EQ(2, graph->getVer());
}

TEST(GRAPH, getEdgNum_correct)
{
	Graph *graph = new Graph(2);
	EXPECT_EQ(1, graph->getEdgNum());
}

TEST(GRAPH, getSize_correct)
{
	Graph *graph = new Graph(2);
	graph->inputEdge(0, 1, 1);
	EXPECT_EQ(1, graph->getSize());
}

TEST(GRAPH, getW_correct)
{
	Graph *graph = new Graph(2);
	graph->inputEdge(0, 1, 2);
	EXPECT_EQ(2, graph->getW(0, 1));
}
