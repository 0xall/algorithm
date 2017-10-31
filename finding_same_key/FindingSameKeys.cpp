// 2013011769_Kang_SeungWon_508

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, i, count = 0, value;
    vector<int> A;

    scanf("%d%d", &N, &M);

    A.resize(N);
    
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    sort(A.begin(), A.end());

    for(i = 0; i < M; ++i) {
        scanf("%d", &value);
        if(binary_search(A.begin(), A.end(), value)) {
            ++count;
        }
    }

    printf("%d\n", count);
    return 0;
}
