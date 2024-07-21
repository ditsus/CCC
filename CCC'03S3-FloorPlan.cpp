#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main() {
	int tiles, rows, columns;
	
	cin >> tiles >> rows >> columns;

	string house[rows][columns];

	string column;
	for (int i = 0; i < rows; i++) {
		cin >> column;
		for (int j = 0; j < columns; j++) {
			house[i][j] = column[j];
		}
	}

	vector<int> rooms;
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (house[i][j] == ".") {
				int numOfTiles = 0;
				vector<vector<int>> queue = {{i, j}};
				house[i][j] = "I";

				while (queue.size() != 0) {
					vector<int> currentTile = queue.front();
					queue.erase(queue.begin());
					numOfTiles++;
	
					if (currentTile[0] > 0 && house[currentTile[0] - 1][currentTile[1]] == ".") {
						queue.push_back({currentTile[0] - 1, currentTile[1]});
						house[currentTile[0] - 1][currentTile[1]] = "I";
					}
					if ((currentTile[0] < rows - 1) && house[currentTile[0] + 1][currentTile[1]] == ".") {
						queue.push_back({currentTile[0] + 1, currentTile[1]});
						house[currentTile[0] + 1][currentTile[1]] = "I";
					}
					if ((currentTile[1] > 0) && house[currentTile[0]][currentTile[1] - 1] == ".") {
						queue.push_back({currentTile[0], currentTile[1] - 1});
						house[currentTile[0]][currentTile[1] - 1] = "I";
					}
					if ((currentTile[1] < columns - 1) && house[currentTile[0]][currentTile[1] + 1] == ".") {
						queue.push_back({currentTile[0], currentTile[1] + 1});
						house[currentTile[0]][currentTile[1] + 1] = "I";
					}
				}	
				rooms.push_back(numOfTiles);
			}
		}
	}

	sort(rooms.begin(), rooms.end(), greater<int>()); 
	// for (int i = 0; i < rooms.size(); i++) {
	// 	cout << rooms[i] << " ";
	// }
	bool resultNotFound = true;
	for (int i = 0; i < rooms.size(); i++) {
		tiles -= rooms[i];
		if (tiles == 0) {
			if (i == 0) {
				cout << i + 1 << " room, 0 square metre(s) left over"; 
			}
			else {
				cout << i + 1 << " rooms, 0 square metre(s) left over"; 
			}
			i = rooms.size();
			resultNotFound = false;
		}
	 	if (tiles < 0) {
			if (i == 1) {
				cout << i << " room, " << (tiles + rooms[i]) << " square metre(s) left over";
			}
			else {
				cout << i << " rooms, " << (tiles + rooms[i]) << " square metre(s) left over";
			}
			i = rooms.size();
			resultNotFound = false;
		}
	}
	if (resultNotFound) {
		if (rooms.size() == 1) {
			cout << rooms.size() << " room, " << tiles << " square metre(s) left over";
		}
		else {
			cout << rooms.size() << " rooms, " << tiles << " square metre(s) left over";
		}
	}

	
	return 0; 
}
