/**
 * LabSD 6
 * MatrixGraph.h
 * Purpose: Skeleton code for the matrix graph.
 *
 * @author Gabriel Bercaru
 */

#ifndef __MATRIXGRAPH_H__
#define __MATRIXGRAPH_H__

#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

/**
 * Matrix implementation.
 */
class MatrixGraph {
private:
    std::vector<std::vector<int>> adjacency_matrix;
    int size;

public:
    // Constructor
    MatrixGraph(int size): size(size) {
        for(int i=0; i<size; i++) {
            std::vector<int> row;
            for(int j=0; j<size; j++) {
                row.push_back(0);
            }
            adjacency_matrix.push_back(row);
        }
    }

    // Destructor
    ~MatrixGraph() {}

    /**
     * Adds an edge between two existing nodes.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     */
    void addEdge(int src, int dst) {
        adjacency_matrix[src][dst] = 1;
        adjacency_matrix[dst][src] = 1;
    }

    /**
     * Adds an edge between two existing nodes, with given cost.
     *
     * @param src Source node of the edge to be added.
     * @param dst Destination node of the edge to be added.
     * @param cost The cost associated with the new edge.
     */
    void addEdgeWithCost(int src, int dst, int cost) {
        adjacency_matrix[src][dst] = cost;
        adjacency_matrix[dst][src] = cost;
    }

    /**
     * Removes an existing edge from the graph.
     *
     * @param src Source node of the edge to be removed.
     * @param dst Destination node of the edge to be removed.
     */
    void removeEdge(int src, int dst) {
        adjacency_matrix[src][dst] = 0;
        adjacency_matrix[dst][src] = 0;
    }

    /**
     * Checks if there is an edge between two existing nodes.
     *
     * @param src Source node of the edge.
     * @param dst Destination node of the edge.
     * @return True if there is and edge between src and dst, False otherwise.
     */
    bool hasEdge(int src, int dst) {
        if(src==dst) {
            return true;
        }

        if(adjacency_matrix[src][dst]!=0) {
            return true;
        }
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
        if(src == dst) {
            return 1;
        }

        return adjacency_matrix[src][dst];
    }

    /**
     * Gets the vector of neighbors associated with the given node.
     *
     * @param node Node whose neighbors will get returned.
     * @return A vector containing the neighbors of the given node.
     */
    std::vector<int> getNeighbors(int node) {
        std::vector<int> nodes;
        for(int i=0; i<size; i++) {
            if(adjacency_matrix[node][i]!=0) {
                nodes.push_back(i);
            }
        }

        return nodes;
    }

    /**
     * Gets the graph size.
     *
     * @return Number of nodes in the graph.
     */
    int getSize() {
        return size;
    }

    void BFS() {
        // Every element will have an index and if it was erased from the queue
        std::deque<std::pair<int, bool>> queue;
        std::pair<int, bool> curr(0,false);

        int qSize = 1;
        int it = 0;
        queue.push_back(curr);
        while(qSize!=0) {
            std::vector<int> neighbours = getNeighbors(curr.first);

            // Add all unvisited neighbours in the queue
            for(auto &i : neighbours) {
                if(std::find(queue.begin(), queue.end(), std::make_pair(i, false)) == queue.end()) {
                    if(std::find(queue.begin(), queue.end(), std::make_pair(i, true)) == queue.end()){
                        queue.push_back(std::make_pair(i, false));
                        qSize++;
                    }
                }
            }
            
            queue[it] = std::make_pair(curr.first, true);
            it++;
            qSize--;
            curr = queue[it];
        }
        for(int i=0; i<int(queue.size()); i++) {
            std::cout << queue[i].first << " ";
        }
        std::cout << std::endl;

    }

    void printMatrix() {
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                std::cout << adjacency_matrix[i][j] << " ";
            }
            std::cout<<std::endl;
        }
    }
};

#endif // __MATRIXGRAPH_H__
