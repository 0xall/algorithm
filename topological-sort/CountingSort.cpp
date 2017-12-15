// 2013011769_KangSeungWon_508

#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void InsertDegree0(vector< vector<int> >& graph, stack<int>& search, vector<int>& degrees);

int main() {
    int N, x, y, i;
    vector< vector<int> > graph;
    vector<int> degrees;
    queue<int> resultQueue;
    stack<int> search;
    
    scanf("%d", &N);
    graph.resize(N + 1, vector<int>(N+1, 0));
    degrees.resize(N + 1, 0);

    while(scanf("%d%d", &x, &y) != EOF) {
        if (!graph[x][y]) {
            graph[x][y] = 1;
            ++degrees[y];
        }
    }
    
    InsertDegree0(graph, search, degrees);
    
    while (!search.empty()) {
        int currentVertex = search.top();
        search.pop();
        
        resultQueue.push(currentVertex);
        //degrees[currentVertex] = -1;
        
        for (i = 1; i <= N; ++i) {
            if (graph[currentVertex][i]) {
                graph[currentVertex][i] = 0;
                --degrees[i];
            }
        }

        InsertDegree0(graph, search, degrees);
    }
    
    for (i = 1; i <= N; ++i) {
        if (degrees[i] >= 0) break;
    }
    
    if (i == N + 1) {
        printf("1\n");
        while (!resultQueue.empty()) {
            printf("%d ", resultQueue.front());
            resultQueue.pop();
        }
        printf("\n");
    }
    
    else {
        printf("0\n");
    }
}

void InsertDegree0(vector< vector<int> >& graph, stack<int>& search, vector<int>& degrees) {
    int i, j;
    
    for (i = 1; i < degrees.size(); ++i) {
        if (degrees[i] == 0) {
            search.push(i);
            degrees[i] = -1;
        }
    }
}
