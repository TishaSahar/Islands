#include <iostream>

void IslandWalk(int** arr, int m, int n, int i, int j, int NFI) {
	arr[i][j] = NFI;
	
	if (i + 1 < m) {
		if (arr[i + 1][j] == 0) {
			IslandWalk(arr, m, n, i + 1, j, NFI);
		}
		if(j + 1 < n)
			if (arr[i + 1][j + 1] == 0) {
				IslandWalk(arr, m, n, i + 1, j + 1, NFI);
			}
	}

	if (j + 1 < n) {
		if (arr[i][j + 1] == 0) {
			IslandWalk(arr, m, n, i, j + 1, NFI);
		}
		if(i > 0)
			if (arr[i - 1][j + 1] == 0) {
				IslandWalk(arr, m, n, i - 1, j + 1, NFI);
			}
	}
	
	if (j > 0) {
		if (arr[i][j - 1] == 0)
			IslandWalk(arr, m, n, i, j - 1, NFI);
		if (i > 0)
			if (arr[i - 1][j - 1] == 0)
				IslandWalk(arr, m, n, i - 1, j - 1, NFI);
	}

}

int foundIslands(int** arr, int m, int n) {
	int Count = 0; int NumForIsl = 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				Count++;
				IslandWalk(arr, m, n, i, j, NumForIsl);
				NumForIsl += 2;
			}
		}
	}
	return Count;
}

void out(int** arr, int m, int n) {
	for (int i = 0; i < m; i++) {
		std::cout << '\n' << "     ";
		for (int j = 0; j < n; j++) {
			std::cout << arr[i][j] << ' ';
		}
	}
}