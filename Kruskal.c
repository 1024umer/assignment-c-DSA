#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));
    return graph;
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);
    parent[xRoot] = yRoot;
}

int kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;
    int totalWeight = 0; // Initialize a variable to keep track of the total weight

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compareEdges);

    int parent[V];
    for (i = 0; i < V; i++)
        parent[i] = -1;

    i = 0;
    while (e < V - 1) {
        struct Edge next_edge = graph->edge[i++];
        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unionSets(parent, x, y);
            totalWeight += next_edge.weight; // Add the weight of the current edge to the total
        }
    }

    printf("Edges in Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d, Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    return totalWeight;
}

int main() {
    int V = 4; 
    int E = 5;
    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    int totalWeight = kruskalMST(graph);
    printf("Total Weight of Minimum Spanning Tree: %d\n", totalWeight);

    return 0;
}

