// 2013011769_Kang_SeungWon_508

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX_SEQ_LEN 500
#define SWAP(T, a, b) { T tmp = a; a = b; b = tmp; }
#define SEQ_VALUE(SEQ, INDEX) ( SEQ[ INDEX - 1 ] )

string seqA, seqB;
int dy[501][501];

void InitData();
void InputData();
int GetLCSLen();
string GetLCSString(int i, int j);

int main(int argc, char* argv[]) {

    InputData();

    GetLCSLen();
    cout << GetLCSString(seqA.length(), seqB.length()) << endl;
}

void InputData() {

    cin >> seqA >> seqB;

    if(seqA.length() < seqB.length()) {
        SWAP(string, seqA, seqB);
    }
}

int GetLCSLen() {
    size_t i, j;
    const size_t seqALen = seqA.length();
    const size_t seqBLen = seqB.length();

    for(i = 1; i <= seqALen; ++i) {
        for(j = 1; j <= seqBLen; ++j) {
            char a = SEQ_VALUE(seqA, i);
            char b = SEQ_VALUE(seqB, j);

            if(a == b) {
                dy[i][j] = dy[i-1][j-1] + 1;
            }

            else {
                dy[i][j] = max(dy[i-1][j], dy[i][j-1]);
            }
        }
    }

    return dy[seqALen][seqBLen];
}

string GetLCSString(int i, int j) {
    if(i == 0 || j == 0) return string("");
    
    char a = SEQ_VALUE(seqA, i);
    char b = SEQ_VALUE(seqB, j);

    if(a == b) {
        return GetLCSString(i-1, j-1) + a;
    }

    else {
        if(dy[i-1][j] > dy[i][j-1]) return GetLCSString(i-1, j);
        else return GetLCSString(i, j-1);
    }
}