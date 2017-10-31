// 2013011769_Kang_SeungWon_508


#include <stdio.h>
#include <vector>
using namespace std;

typedef struct RANGE {
    int min, max;
} RANGE;

int GetCount(vector<int>& countings, RANGE& range);

int main() {
    int N, K, M, i, input;
    vector<int> countings;
    vector<RANGE> ranges;

    scanf("%d%d%d", &N, &M, &K);
    countings.resize(M, 0);
    ranges.resize(K);

    for(i = 0; i < K; ++i) {
        scanf("%d%d", &ranges[i].min, &ranges[i].max);
    }

    for(i = 0; i < N; ++i) {
        scanf("%d", &input);
        ++countings[input];
    }

    for(i = 1; i < M; ++i) {
        countings[i] += countings[i - 1];
    }

    for(i = 0; i < K; ++i) {
        printf("%d\n", GetCount(countings, ranges[i]));
    }

    return 0;
}

int GetCount(vector<int>& countings, RANGE& range) {   
    if(range.min == 0) return countings[range.max];
    return countings[range.max] - countings[range.min - 1];
}
