#include "gtest.h"
#include "Dijkstra.h"

TEST(DIJKSTRA, cant_work_without_ver)
{
	Graph *graph = new Graph(0);
	ASSERT_ANY_THROW(Dijkstra::DijkstraAlg(graph, 0));
}

TEST(DIJKSTRA, cant_work_with_wrong_startV)
{
	Graph *graph = new Graph(4);
	graph->inputEdge(0, 1, 2);
	ASSERT_ANY_THROW(Dijkstra::DijkstraAlg(graph, 9));
}

/*TEST(DIJKSTRA, algorithm_is_correct1)
{
	Graph *graph = new Graph(4, 6);
	graph->inputEdge(0, 1, 1);
	graph->inputEdge(0, 2, 2);
	graph->inputEdge(1, 2, 4);
	graph->inputEdge(1, 3, 6);
	graph->inputEdge(2, 3, 5);
	graph->inputEdge(3, 0, 3);
	Dijkstra::DijkstraAlg(graph, 0)

	EXPECT_EQ();
	EXPECT_EQ();
	EXPECT_EQ();
}*/
