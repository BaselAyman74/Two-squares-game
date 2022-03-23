#include<iostream>
using namespace std;
int main()
{
	int  arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	bool cont = true;
	int player = 0;

	int n, m, row1, col1, row2, col2;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			std::cout << arr[i][j] << " ";
		}cout << endl;
	}
	while (cont) {
		std::cout << "Player " << player + 1 << " turn." << endl;
		std::cout << "======================" << endl;
		cin >> n >> m;
		if (!(n <= 16 && n >= 1 && m >= 1 && m <= 16)) {
			std::cout << "Numbers should be between 1 to 16" << endl;
			continue;
		}
		row1 = (n / 4) - 1 * (n % 4 == 0);
		col1 = n % 4 == 0 ? 3 : n % 4 - 1;// condation ? true: false.
		row2 = (m / 4) - 1 * (m % 4 == 0);
		col2 = m % 4 == 0 ? 3 : m % 4 - 1;// condation ? true: false.
		int diff = abs(abs(arr[row1][col1]) - abs(arr[row2][col2]));
		if (diff != 4 && diff != 1) {
			std::cout << "Error, they are not adjacent" << endl;
			continue;
		}
		if (arr[row1][col1] < 0 || arr[row2][col2] < 0) {
			std::cout << "Error, reserved cells." << endl;
			continue;
		}
		arr[row1][col1] *= -1;
		arr[row2][col2] *= -1;
		cont = false;
		for (int i = 0; i < 4 && !cont;i++) {
			for (int j = 0; j < 4 &&!cont;j++) {
				if (arr[i][j] < 0) { continue; }
				for (int k = 0; k < 4 && !cont; k++) {
					int new_i = i + dx[k];
					int new_j = j + dy[k];
					if (new_i > 3 || new_i < 0 || new_j > 3 || new_j < 0 || arr[new_i][new_j] < 0) {
						continue;
					}
					cont = true;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (arr[i][j] < 0) {
					std::cout << "X" << " ";
				}
				else {
					std::cout << arr[i][j] << " ";
				}
				
			}
			std::cout << endl;
		}

		if (!cont) {
			std::cout << "Player " << player + 1 << " won!" << endl;
		}
	
		player ^= 1; // xor with 1 
	}
 
	return 0;
}