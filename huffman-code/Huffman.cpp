// 2013011769_Kang_SeungWon_508

#include <stdio.h>
#include <vector>
using namespace std;

int N, S;
vector<int> counts;

typedef struct Node {
    int counts;
    int leafNode;
} Node;

#define SWAP(TYPE, X, Y)   { TYPE tmp = Y; Y = X; X = tmp; }

#define HEAP_LEFT(X)    (X*2+1)
#define HEAP_RIGHT(X)   (X*2+2)
#define HEAP_PARENT(X)  ((X-1)/2)

vector<Node> huffHeap;
int heapCount;
int insertIndex;

void InputData();
int GetMinLength(int N);

Node PopMin();
int GetHeapCount();
void InsertNode(Node value);
void Heapify(int index);
void IncreasePriority(int index);
void InsertHuffNode(Node value);

void MakeHuffNode();

void PrintHuffCode();
int CalculateLength();

int main() {
    
    int totalLength, chLen;
    
    InputData();
    
    chLen = GetMinLength(N);
    totalLength = S * chLen;
    
    //PrintHuffCode();
    
    printf("%d\n%d\n", totalLength, CalculateLength());
}

void InputData() {
    char tmp[10];
    int i;
    
    scanf("%d", &N);
    counts.resize(N);
    
    huffHeap.resize(N*2-1);
    heapCount = 0;
    insertIndex = N*2-2;
    
    for(i=0; i<N; ++i) {
        Node insert;
        
        scanf("%s", tmp);
        scanf("%d", &counts[i]);
        
        insert.counts = counts[i];
        insert.leafNode = 1;
        InsertNode(insert);
    }
    
    scanf("%d", &S);
    
    MakeHuffNode();
}

int GetMinLength(int N) {
    N--;
    int ret = 0;
    
    while(N) {
        N >>= 1;
        ret++;
    }
    
    if(ret) return ret;
    return 1;
}

Node PopMin() {
    Node ret = huffHeap[0];
    huffHeap[0] = huffHeap[--heapCount];
    Heapify(0);
    
    return ret;
}

int GetHeapCount() {
    return heapCount;
}

void Heapify(int index) {
    
    if(index >= heapCount) return;
    
    int minIndex = -1;
    int minValue = huffHeap[index].counts;
    
    int leftIndex = HEAP_LEFT(index);
    int rightIndex = HEAP_RIGHT(index);
    
    if(leftIndex < heapCount && minValue > huffHeap[leftIndex].counts) {
        minIndex = leftIndex;
        minValue = huffHeap[leftIndex].counts;
    }
    
    if(rightIndex < heapCount && minValue > huffHeap[rightIndex].counts) {
        minIndex = rightIndex;
        minValue = huffHeap[rightIndex].counts;
    }
    
    if(minIndex > 0) {
        SWAP(Node, huffHeap[index], huffHeap[minIndex]);
        Heapify(minIndex);
    }
}

void IncreasePriority(int index) {
    
    if(index == 0) return;
    
    int parentIndex = HEAP_PARENT(index);
    int parentValue = huffHeap[parentIndex].counts;
    int currentValue = huffHeap[index].counts;
    
    if(parentValue > currentValue) {
        SWAP(Node, huffHeap[parentIndex], huffHeap[index]);
        IncreasePriority(parentIndex);
    }
}

void InsertNode(Node value) {
    huffHeap[heapCount++] = value;
    IncreasePriority(heapCount-1);
}

void InsertHuffNode(Node value) {
    huffHeap[insertIndex--] = value;
}

void MakeHuffNode() {
    
    int sumValue;
    Node popNode;
    Node pushNode;
    
    while(GetHeapCount() > 1) {
        sumValue = 0;
        
        popNode = PopMin();
        sumValue += popNode.counts;
        InsertHuffNode(popNode);
        
        
        popNode = PopMin();
        sumValue += popNode.counts;
        InsertHuffNode(popNode);
        
        pushNode.leafNode = 0;
        pushNode.counts = sumValue;
        InsertNode(pushNode);
    }
}

void PrintHuffCode() {
    int i;
    
    for(i=0; i<huffHeap.size(); ++i) {
        printf("%d %d\n", huffHeap[i].leafNode, huffHeap[i].counts);
    }
}

int CalculateLength() {
    int length = 0;
    int weight = 0;
    int count = 1;
    int nextCount = 0;
    int index = 0;
    
    while(index < huffHeap.size()) {
        if(huffHeap[index].leafNode) {
            length += huffHeap[index].counts * weight;
        }
        
        else {
            ++nextCount;
        }
        
        ++index;
        --count;
        
        if(!count) {
            weight++;
            count = nextCount * 2;
            nextCount = 0;
        }
    }
    
    return length;
}
