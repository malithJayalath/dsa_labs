#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMinKey(vector<int>& key, vector<bool>& mstSet, int numNodes) {
    int minKey = INT_MAX, minIndex = -1;
    for (int i = 0; i < numNodes; ++i) {
        if (!mstSet[i] && key[i] < minKey) {
            minKey = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int numNodes) {
    cout << "Edge\tWeight\n";
    for (int i = 1; i < numNodes; ++i) {
        cout << parent[i] << " - " << i << "\t" << graph[parent[i]][i] << endl;
    }
}

void primMST(const vector<vector<int>>& graph, int numNodes) {
    vector<int> parent(numNodes);
    vector<int> key(numNodes, INT_MAX);
    vector<bool> mstSet(numNodes, false);

    // Start with node 0
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numNodes - 1; ++count) {
        int u = findMinKey(key, mstSet, numNodes);
        mstSet[u] = true;

        for (int v = 0; v < numNodes; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, numNodes);
}

int main() {
    // Given adjacency matrix
    vector<vector<int>> adjacencyMatrix = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int numNodes = adjacencyMatrix.size();

    primMST(adjacencyMatrix, numNodes);

    return 0;
}
