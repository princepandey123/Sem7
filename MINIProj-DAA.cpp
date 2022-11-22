//To Execute :->g++ -pthread filename.cpp and then ./a.out


#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> mat1, mat2, mat3;
int n;

void compute(int r, int c){
	for(int i = 0; i < n; i++){
		mat3[r][c] = mat3[r][c] + mat1[r][i] * mat2[i][c];
	}
}

int main(){


	cin >> n;
	mat1 = mat2 = mat3 = std::vector<vector<int>> (n, vector <int> (n, 0));


	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat1[i][j];
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> mat2[i][j];
		}
	}

	thread threads[n][n];

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			threads[i][j] = thread(compute, i, j);
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			threads[i][j].join();
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << mat3[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}
