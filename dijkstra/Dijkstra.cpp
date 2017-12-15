// 2013011769_Kang_SeungWon_508

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef struct _GRAPH_EDGE {
    int to, weight;
} GRAPH_EDGE;

typedef struct _VERTEX {
    int index;
    int selected;
    int weight;
} VERTEX;

int
main()
{
    int N, i, numOfEdges, fromEdge, toEdge;
    vector<VERTEX> vertices;
    vector< vector<GRAPH_EDGE> > edges;
    VERTEX inputVertex = {0, -1};
    queue<VERTEX> q;

    scanf("%d", &N);
    vertices.resize(N + 1);
    edges.resize(N + 1);

    for (i = 1; i <= N; ++i) {
        vertices[i].index = i;
        vertices[i].selected = 0;
        vertices[i].weight = -1;
    }

    while (scanf("%d%d", &fromEdge, &numOfEdges) != EOF) {

        edges[fromEdge].resize(numOfEdges);        
        for (i = 0; i < numOfEdges; ++i) {
            scanf("%d%d", &edges[fromEdge][i].to, &edges[fromEdge][i].weight);
        }
    }

    vertices[1].selected = 1;
    vertices[1].weight = 0;
    q.push(vertices[1]);

    while (!q.empty()) {
        VERTEX currentVertex = q.front();
        const int currentIndex = currentVertex.index;
        q.pop();

        // if the value is changed
        //if (currentVertex.weight != vertices[currentIndex].weight) continue;
        vertices[currentIndex].selected = 1;

        const int edgesSize = edges[currentIndex].size();
        for (i = 0; i < edgesSize; ++i) {
            int to = edges[currentIndex][i].to;
            int toWeight = edges[currentIndex][i].weight;
            if (currentVertex.weight + toWeight < vertices[to].weight || vertices[to].weight == -1) {
                const VERTEX prevVertex = vertices[to];
                vertices[to].weight = currentVertex.weight + toWeight;
            }
        }

        int minValue = 1234567890;
        int minIndex = -1;

        for (i = 1; i <= N; ++i) {
            
            if (!vertices[i].selected && minValue > vertices[i].weight && vertices[i].weight != -1) {
                minValue = vertices[i].weight;
                minIndex = i;
            }
        }

        if (minIndex != -1) q.push(vertices[minIndex]);
    }

    int maxValue = -1;
    for (i = 1; i <= N; ++i) {
        //printf("%d ", vertices[i].weight);
        maxValue = max(maxValue, vertices[i].weight);
    }

    printf("%d\n", maxValue);
}