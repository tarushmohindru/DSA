#include <iostream>
#include <vector>
using std::vector;

void depthFirstSearch(int vertex, const vector<vector<int>> &adjacency,
                      vector<bool> &visited)
{
    visited[vertex] = true;
    for (int neighbor : adjacency[vertex])
    {
        if (!visited[neighbor])
        {
            depthFirstSearch(neighbor, adjacency, visited);
        }
    }
}

int countConnectedComponents(int vertices, const vector<vector<int>> &adjacency)
{
    vector<bool> visited(vertices, false);
    int components = 0;
    for (int vertex = 0; vertex < vertices; ++vertex)
    {
        if (!visited[vertex])
        {
            ++components;
            depthFirstSearch(vertex, adjacency, visited);
        }
    }
    return components;
}

int main()
{
    int vertices, edges;
    std::cout << "Enter number of vertices and edges: ";
    std::cin >> vertices >> edges;

    vector<vector<int>> adjacency(vertices);
    std::cout << "Enter each edge as two vertex indices (space separated):\n";
    for (int i = 0; i < edges; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        if (u >= 0 && u < vertices && v >= 0 && v < vertices)
        {
            adjacency[u].push_back(v);
            adjacency[v].push_back(u);
        }
    }

    int componentCount = countConnectedComponents(vertices, adjacency);
    std::cout << "Number of connected components: " << componentCount << '\n';
    return 0;
}
