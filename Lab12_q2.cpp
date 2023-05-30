#include<iostream>
#include<stdio.h>
using namespace std;
#define infinity 9999
#define max 6

void dijkstra(int G[max][max],int n, int startnode);

int main(){
    int G[max][max]={
        {0,10,0,0,15,5},
        {10,0,10,30,0,0},
        {0,10,0,12,5,0},
        {0,30,12,0,0,20},
        {15,0,5,0,0,0},
        {5,0,0,20,0,0}
    };
    int n=6;
    int u=5;
    dijkstra(G,n,u);
    return 0;
}

void dijkstra(int G[max][max],int n, int startnode){
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, mindistance, nextnode, i, j;

    // Initialize the cost and distance arrays
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = infinity;
            else
                cost[i][j] = G[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;

    while (count < n - 1) {
        mindistance = infinity;

        // Nextnode gives the node at minimum distance
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        // Check if a better path exists through nextnode
        visited[nextnode] = 1;
        for (i = 0; i < n; i++) {
            if (!visited[i] && (mindistance + cost[nextnode][i] < distance[i])) {
                distance[i] = mindistance + cost[nextnode][i];
                pred[i] = nextnode;
            }
        }
        count++;
    }

    // Print the distance and path from the startnode to each node
    for (i = 0; i < n; i++) {
        if (i != startnode) {
            cout << "Distance of node" << i << "=" << distance[i] << endl;
            cout << "Path=" << i;
            
            j = i;
            do {
                j = pred[j];
                cout << "<-" << j;
            } while (j != startnode);
            cout << endl;
        }
    }
}
