#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	int row, col;
	string line;

	getline(cin, line);

	row = floor(sqrt(line.length()));
	col = ceil(sqrt(line.length()));

	while((row * col) < line.length())
		if(row < col)
			row++;
		else
			col++;

	vector<vector<char>> encryptionTable;

	int stringLengthCounter = 0;

	for(int i = 0; i < col; i++)
		encryptionTable.push_back(vector<char>());

	while(stringLengthCounter < line.length()) {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				encryptionTable.at(i).push_back(line[stringLengthCounter]);
				stringLengthCounter++;
			}
		}
	}

	for(const vector<char>& chunk : encryptionTable) {
		for(const char& c : chunk)
			cout << c;

		cout << " ";
	}

	cout << endl;

	return 0;
}