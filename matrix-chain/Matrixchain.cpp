// 2013011769_Kang SeungWon_508

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int GetMatrixHeight(size_t index);
int GetMatrixWidth(size_t index);

void InputData();
void InitDy();
pair<int, int> GetMinMult(int i, int j);
void printMult(int i, int j);

int N;
vector<int> p;
vector<vector<pair<int, int> > > dy;

int main(int argc, char* argv[]) {

    InputData();
    InitDy();

    printf("%d\n", GetMinMult(1, N).first);
    printf("( ");
    printMult(1, N);
    printf(")\n");
    
    return 0;
}

void InputData() {
    int i;
    scanf("%d", &N);
    p.resize(N+1);

    const size_t inputSize = p.size();
    for(i=0; i<inputSize; ++i) {
        scanf("%d", &p[i]);
    }
}

void InitDy() {
    dy.resize(N+1, vector<pair<int, int> >(N+1, make_pair(-1, -1)));
}

int GetMatrixHeight(size_t index) {
    return p[index-1];
}

int GetMatrixWidth(size_t index) {
    return p[index];
}

pair<int, int> GetMinMult(int i, int j) {
    int k;

    if(dy[i][j].first != -1) return dy[i][j];

    // if i is equal to j, no multiplication
    if(i == j) {
        dy[i][j].first = 0;
        dy[i][j].second = i;
    }

    else {
        int minValue = 0x7fffffff;
        int minIndex = -1, tmp;

        for(k = i; k < j; ++k) {
            tmp = GetMinMult(i, k).first + GetMinMult(k+1, j).first + 
            GetMatrixHeight(i) * GetMatrixWidth(k) * GetMatrixWidth(j);
            if(minValue > tmp) {
                minValue = tmp;
                minIndex = k;
            }
        }

        dy[i][j].first = minValue;
        dy[i][j].second = minIndex;
        
    }

    return dy[i][j];
}

void printMult(int i, int j) {

    if(i > j) return;

    pair<int, int> p = GetMinMult(i, j);
    int divIndex = p.second, k;

    if(j == i) {
        
        printf("%d ", divIndex);
        printMult(divIndex + 1, j);

    }

    else {
        if(i != divIndex) printf("( ");
        printMult(i, divIndex);
        if(i != divIndex) printf(") ");
        if(divIndex + 1 != j) printf("( ");
        printMult(divIndex + 1, j);
        if(divIndex + 1 != j) printf(") ");
    }
}