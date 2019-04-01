/**
 * LabSD 6
 * ListGraph.h
 * Purpose: Skeleton code for the neighbors list graph.
 *
 * @author Gabriel Bercaru
 */

#ifndef __LISTGRAPH_H__
#define __LISTGRAPH_H__

#include <map>
#include <vector>

/**
 * Node structure is useful only for the neighbors list implementation.
 */
struct Node {
    std::vector<int> neighbors;
};

/**
 * Neighbors list implementation.
 */
class ListGraph {
private:
    std::vector<Node> nodes;
    std::map<std::pair<int, int>, int> edgeCosts;
    int size;

public:
    // Constructor
    ListGraph(int size) {
    }

    // Destructor
    ~ListGraph() {}

    /**
     * Adds an edge between two existing nodes.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     */
    void addEdge(int src, int dst) {
        // TODO: TASK 1
    }

    /**
     * Adds an edge between two existing nodes, with given cost.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     * @param cost The cost associated with the new edge.
     */
    void addEdgeWithCost(int src, int dst, int cost) {
        // TODO: TASK 1
    }

    /**
     * Removes an existing edge from the graph.
     *
     * @param src Source node of the edge to be removed.
     * @param dst Destination node of the edge to be removed.
     */
    void removeEdge(int src, int dst) {
        // TODO: TASK 1
    }

    /**
     * Checks if there is an edge between two existing nodes.
     * 
     * @param src Source node of the edge.
     * @param dst Destination node of the edge.
     * @return True if there is an edge between src and dst, False otherwise.
     */
    bool hasEdge(int src, int dst) {
        // TODO: TASK 1
        return false;
    }

    /**
     * Returns the cost of the edge described by src and dst.
     *
     * @param src Source node of the edge.
     * @param dst Destination node of the edge.
     * @return Cost of the edge between src and dst.
     */
    int edgeCost(int src, int dst) {
        // TODO: TASK 1
        return 0;
    }

    /**
     * Gets the vector of neighbors associated with the given node.
     *
     * @param node Node whose neighbors will get returned.
     * @return A vector containing the neighbors of the given node.
     */
    std::vector<int> getNeighbors(int node) {
        // TODO: TASK 1

        return std::vector<int>();
    }

    /**
     * Gets the graph size.
     *
     * @return Number of nodes in the graph.
     */
    int getSize() {
        return size;
    }
};

#endif // __LISTGRAPH_H__
