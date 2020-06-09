/*** https://mindcoding.ro/pb/ggx ***/

#include <iostream>

using namespace std;
int main()
{
	int N, M, X;
	cin >> N >> M >> X;

	int* initialPixels = new int[N * M];
	int* finalPixels = new int[N * M * X * X];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> initialPixels[i * M + j];
			for (int iInner = 0; iInner < X; iInner++) {
				for (int jInner = 0; jInner < X; jInner++) {
					finalPixels[i * M * X * X + j * X + iInner * M * X + jInner] = initialPixels[i * M + j];
				}
			}
		}
	}

	for (int i = 0; i < N * M * X * X; i++) {
		cout << finalPixels[i] << " ";
		if ((i + 1) % (M * X) == 0) {
			cout << endl;
		}
	}

	return 0;
}