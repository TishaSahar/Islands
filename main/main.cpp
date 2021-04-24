#include "islands.h"

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;

	int** arr = new int* [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 1 + 0; //cin >> arr[i][j];
		}
		cout << endl;
	}
	out(arr, m, n);
	cout << foundIslands(arr, m, n);

	return 0;
}