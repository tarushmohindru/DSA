#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
using std::vector, std::queue;

struct Edge
{
    int u;
    int v;
    int weight;
};

struct Graph
{
    int V;
    vector<Edge> edges;
    vector<vector<std::pair<int, int>>> adjacency;

    explicit Graph(int vertices) : V(vertices), adjacency(vertices) {}

    void addEdge(int u, int v, int weight)
    {
        adjacency[u].push_back({v, weight});
        adjacency[v].push_back({u, weight});
        edges.push_back({u, v, weight});
    }
};

struct DisjointSet
{
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) : parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
        {
            return false;
        }
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

void breadthFirstSearch(const Graph &graph, int start)
{
    vector<bool> visited(graph.V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    std::cout << "BFS order starting from " << start << ": ";
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        std::cout << current << " ";
        for (const auto &neighbor : graph.adjacency[current])
        {
            if (!visited[neighbor.first])
            {
                visited[neighbor.first] = true;
                q.push(neighbor.first);
            }
        }
    }
    std::cout << '\n';
}

void depthFirstSearchUtil(const Graph &graph, int vertex, std::vector<bool> &visited)
{
    visited[vertex] = true;
    std::cout << vertex << " ";
    for (const auto &neighbor : graph.adjacency[vertex])
    {
        if (!visited[neighbor.first])
        {
            depthFirstSearchUtil(graph, neighbor.first, visited);
        }
    }
}

void depthFirstSearch(const Graph &graph, int start)
{
    vector<bool> visited(graph.V, false);
    std::cout << "DFS order starting from " << start << ": ";
    depthFirstSearchUtil(graph, start, visited);
    std::cout << '\n';
}

void kruskalMST(const Graph &graph)
{
    vector<Edge> sortedEdges = graph.edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(),
              [](const Edge &a, const Edge &b)
              { return a.weight < b.weight; });

    DisjointSet sets(graph.V);
    int totalWeight = 0;
    std::cout << "Kruskal MST edges:\n";
    for (const auto &edge : sortedEdges)
    {
        if (sets.unite(edge.u, edge.v))
        {
            std::cout << edge.u << " -- " << edge.v << " (weight " << edge.weight << ")\n";
            totalWeight += edge.weight;
        }
    }
    std::cout << "Total weight: " << totalWeight << '\n';
}

void primMST(const Graph &graph)
{
    vector<int> key(graph.V, std::numeric_limits<int>::max());
    vector<int> parent(graph.V, -1);
    vector<bool> inMST(graph.V, false);
    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int vertex = pq.top().second;
        pq.pop();
        if (inMST[vertex])
        {
            continue;
        }
        inMST[vertex] = true;
        for (const auto &neighbor : graph.adjacency[vertex])
        {
            int adjacent = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[adjacent] && weight < key[adjacent])
            {
                key[adjacent] = weight;
                parent[adjacent] = vertex;
                pq.push({key[adjacent], adjacent});
            }
        }
    }

    std::cout << "Prim MST edges:\n";
    int totalWeight = 0;
    for (int i = 1; i < graph.V; ++i)
    {
        if (parent[i] != -1)
        {
            std::cout << parent[i] << " -- " << i << " (weight " << key[i] << ")\n";
            totalWeight += key[i];
        }
    }
    std::cout << "Total weight: " << totalWeight << '\n';
}

void dijkstraShortestPath(const Graph &graph, int start)
{
    vector<int> distances(graph.V, std::numeric_limits<int>::max());
    using Pair = std::pair<int, int>;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int current = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        if (currentDistance > distances[current])
        {
            continue;
        }

        for (const auto &neighbor : graph.adjacency[current])
        {
            int next = neighbor.first;
            int weight = neighbor.second;
            if (distances[next] > currentDistance + weight)
            {
                distances[next] = currentDistance + weight;
                pq.push({distances[next], next});
            }
        }
    }

    std::cout << "Dijkstra shortest paths from " << start << ":\n";
    for (int i = 0; i < graph.V; ++i)
    {
        std::cout << "Vertex " << i << ": ";
        if (distances[i] == std::numeric_limits<int>::max())
        {
            std::cout << "unreachable\n";
        }
        else
        {
            std::cout << distances[i] << '\n';
        }
    }
}

int main()
{
    Graph graph(6);
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 6);
    graph.addEdge(2, 3, 8);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 3);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 5, 7);

    breadthFirstSearch(graph, 0);
    depthFirstSearch(graph, 0);
    kruskalMST(graph);
    primMST(graph);
    dijkstraShortestPath(graph, 0);

    return 0;
}
