// 2013011769_Kang_SeungWon_508

#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

#define MAX_NUM_OF_VERTICE      1000

int N;
int visited[MAX_NUM_OF_VERTICE + 1];
int graph[MAX_NUM_OF_VERTICE + 1][MAX_NUM_OF_VERTICE + 1];
stack<int> result;

int dfs(int currentVertex) {
    int i;

    visited[currentVertex] = 1;

    for (i = 1; i <= N; ++i) {
        if (graph[currentVertex][i]) {
            graph[currentVertex][i] = 0;

            // if the circulation exists
            if (visited[i] == 1) return -1;

            // dfs
            if (visited[i] == 0 && dfs(i) == -1) return -1;
        }
    }

    // it is visited and no need to check
    visited[currentVertex] = -1;

    // push the result
    result.push(currentVertex);

    return 0;
}

int main() {
    int x, y, i, res;
    
    scanf("%d", &N);

    while(scanf("%d%d", &x, &y) != EOF) {
        graph[x][y] = 1;
    }

    for (i = 1; i <= N; ++i) {
        if (!visited[i]) res = dfs(i);
        if (res == -1) break;
    }

    if (i == N + 1) {
        printf("1\n");

        while (!result.empty()) {
            printf("%d ", result.top());
            result.pop();
        }
    } else {
        printf("0\n");

        while (!result.empty()) {
            printf("%d ", result.top());
            result.pop();
        }
    }
}

