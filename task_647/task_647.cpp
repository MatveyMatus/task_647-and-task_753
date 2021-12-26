#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct num
{
	int val;
	int pos;
};

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");
	int N, M;
	in >> N;
	in >> M;

	num* A = new num[N];
	for (int i = 1; i <= N; i++)
		A[i] = { i, i };

	int X;
	vector<int> V;
	for (int i = 0; i < M; i++) {
		in >> X;
		V.push_back(X);
	}

	int h;
	for (int i = 0; i < M; i++) {

		for (int j = 1; j <= N; j++)
			if (A[j].val == V[i]) {
				h = A[j].pos;
				break;
			}

		for (int j = h - 1; j > 0; j--) {
			A[j + 1].val = A[j].val;
			A[j + 1].pos = A[j].pos + 1;

		}

		A[1] = { V[i], 1 };

		out << h << " ";

	}

}