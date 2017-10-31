// 2013011769_KangSeungWon_508

#include <stdio.h>
#include <vector>
using namespace std;

int main(){

	vector<int> s1, s2, t1, t2, p1, p2, path, from[2];
	int i, N, e1, e2, x1, x2;

	scanf("%d", &N);
	scanf("%d %d", &e1, &e2);
	scanf("%d %d", &x1, &x2);

	s1.resize(N+1);
	s2.resize(N+1);
	t1.resize(N);
	t2.resize(N);
	p1.resize(N+1);
	p2.resize(N+1);
	from[0].resize(N+1);
	from[1].resize(N+1);
	path.resize(N+1);

	for (i = 1; i <= N; ++i){
		scanf("%d", &s1[i]);
	}

	for (i = 1; i <= N; ++i){
		scanf("%d", &s2[i]);
	}

	for (i = 1; i < N; ++i){
		scanf("%d", &t1[i]);
	}

	for (i = 1; i < N; ++i){
		scanf("%d", &t2[i]);
	}

	from[0][1] = 1;
	from[1][1] = 2;

	p1[1] = e1 + s1[1];
	p2[1] = e2 + s2[1];

	for (i=2; i<=N; ++i) {

		if (p1[i - 1] <= p2[i - 1] + t2[i - 1]) {
			from[0][i] = 1;
			p1[i] = s1[i] + p1[i - 1];
		}


		else {
			from[0][i] = 2;
			p1[i] = s1[i] + p2[i - 1] + t2[i - 1];
		}


		if (p2[i - 1] <= p1[i - 1] + t1[i - 1]) {
			from[1][i] = 2;
			p2[i] = s2[i] + p2[i - 1];
		}


		else {
			from[1][i] = 1;
			p2[i] = s2[i] + p1[i - 1] + t1[i - 1];
		}


	}

	if (p1[N] + x1 <= p2[N] + x2){
		printf("%d\n", p1[N] + x1);
		path[N] = 1;
	}

	else {
		printf("%d\n", p2[N] + x2);
		path[N] = 2;
	}

	for (i = N; i > 1; --i) {
		path[i - 1] = from[path[i] - 1][i];
	}

	for (i = 1; i <= N; ++i) {
		printf("%d %d\n", path[i], i);
	}

	return 0;
}

