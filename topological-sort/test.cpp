#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>
#include <stack>
using namespace std;
vector<vector<int> > vt;
int in[1001];
int visited[1001];
int isDAG;
stack<int> st;
void DFS(int here)
{
    if (!isDAG) return ;
    visited[here] = 1;
    for (int k = 0; k < vt[here].size(); k++)
    {
        int there = vt[here][k];
        if (visited[there] == 0)
        {
            //in[there]--;
            DFS(there);
        } else if (visited[there] == 1) {
            isDAG = 0;
            return ;
        }
    }
    visited[here] = 2;
    st.push(here);
}
int main()
{
    int n;
    scanf("%d", &n);
    vt.resize(n + 1);
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        vt[a].push_back(b);
        //in[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(vt[i].begin(), vt[i].end());
    }
    isDAG = 1;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
            DFS(i);
    }
    if (isDAG)
    {
        printf("1\n");
        while (!st.empty())
        {
            printf("%d ", st.top());
            st.pop();
        }
    }
    else
        printf("0\n");
    return 0;
}