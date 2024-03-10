#include <iostream>
#include <vector>
#include <fstream>

// coi video youtube thuyet trinh link: https://www.youtube.com/watch?v=RrqbYqeRIsM&t=4s
using namespace std;

struct Maze {
	int cells[6][5];
};

struct RobotBD {
	int x;
	int y;
};

void In_Maze(const Maze& maze) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 5; j++) {
			cout << maze.cells[i][j] << " ";
		}
		cout << endl;
	}
}

vector<int> findRobotPath(const Maze& maze, const RobotBD& startPos, const vector<int>& otherRobotPath) {
	int x = startPos.x;
	int y = startPos.y;

	vector<int> path;
	path.push_back(maze.cells[x][y]);

	int visited[6][5] = {0};

	// ��nh dau cac o duoc tham boi cac robot khac
	for (int i = 0; i < otherRobotPath.size(); i++) {
		int value = otherRobotPath[i];
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 5; k++) {
				if (maze.cells[j][k] == value) {
					visited[j][k] = 1;
					break;
				}
			}
		}
	}

	while (true) {
		int max_value = -1;
		int next_x = x, next_y = y;

		if (x > 0 && maze.cells[x - 1][y] > max_value && visited[x - 1][y] == 0) {
			max_value = maze.cells[x - 1][y];
			next_x = x - 1;
			next_y = y;
		}

		if (x < 5 && maze.cells[x + 1][y] > max_value && visited[x + 1][y] == 0) {
			max_value = maze.cells[x + 1][y];
			next_x = x + 1;
			next_y = y;
		}

		if (y > 0 && maze.cells[x][y - 1] > max_value && visited[x][y - 1] == 0) {
			max_value = maze.cells[x][y - 1];
			next_x = x;
			next_y = y - 1;
		}

		if (y < 4 && maze.cells[x][y + 1] > max_value && visited[x][y + 1] == 0) {
			max_value = maze.cells[x][y + 1];
			next_x = x;
			next_y = y + 1;
		}

		if (max_value == -1) {
			break;
		}

		visited[x][y] = 1;

		x = next_x;
		y = next_y;
		path.push_back(maze.cells[x][y]);
	}

	return path;
}

int calculatePathSum(const vector<int>& path) {
	int sum = 0;
	for (int i = 0; i < path.size(); i++) {
		sum += path[i];
	}
	return sum;
}

int main() {
	cout << "xin chao !" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "chao mung den voi tro choi maze robot. " << endl;
	cout << "TEN : NGUYEN GIA HUY" << endl;
	cout << "LOP : DL22 " << endl;
	cout << "MA SINH VIEN : 2251320012 " << endl;
	string answer;
	do {
		Maze maze = {
			{
				{2, 1, 14, 12, 17},
				{3, 16, 22, 91, 23},
				{4, 56, 87, 31, 65},
				{27, 43, 90, 100, 101},
				{76, 54, 32, 99, 66},
				{178, 154, 150, 200, 542}
			}
		};

		cout << "Maze robot: " << endl;
		In_Maze(maze);
		cout << endl;

		int option;
		cout << "- 1 -> duong di 1 robot." << endl;
		cout << "- 2 -> duong di 2 robot." << endl;
		cout << "- 3 -> duong di 2 robot khong trung nhau." << endl;
		cout << "- 4 -> su dung file san." << endl;
		cout << "nhap lua chon, bam tu 1 den 4 - > :  ";
		cin >> option;

		switch (option) {
			case 1: {
				RobotBD startPos;
				cout << "nhap vi tri robot: ";
				cin >> startPos.x >> startPos.y;

				vector<int> robotPath = findRobotPath(maze, startPos, {});

				cout << "duong di cua robot: ";
				for (int i = 0; i < robotPath.size(); i++) {
					cout << robotPath[i] << " ";
				}
				cout << endl;

				int pathSum = calculatePathSum(robotPath);
				cout << "tong duong di cua robot: " << pathSum << endl;

				break;
			}
			case 2: {
				RobotBD startPos1, startPos2;
				cout << "nhap vi tri robot 1: ";
				cin >> startPos1.x >> startPos1.y;
				cout << "nhap vi tri robot 2: ";
				cin >> startPos2.x >> startPos2.y;

				vector<int> robotPath1 = findRobotPath(maze, startPos1, {});
				vector<int> robotPath2 = findRobotPath(maze, startPos2, {});

				cout << "duong di cua robot 1: ";
				for (int i = 0; i < robotPath1.size(); i++) {
					cout << robotPath1[i] << " ";
				}
				cout << endl;

				cout << "duong di cua robot 2: ";
				for (int i = 0; i < robotPath2.size(); i++) {
					cout << robotPath2[i] << " ";
				}
				cout << endl;

				cout << "cac o ma 2 robot di trung: ";
				for (int i = 0; i < robotPath1.size(); i++) {
					for (int j = 0; j < robotPath2.size(); j++) {
						if (robotPath1[i] == robotPath2[j]) {
							cout << robotPath1[i] << " ";
							break;
						}
					}
				}
				cout << endl;

				int pathSum1 = calculatePathSum(robotPath1);
				int pathSum2 = calculatePathSum(robotPath2);

				cout << "tong duong di cua robot 1 : " << pathSum1 << endl;
				cout << "tong duong di cua robot 2 : " << pathSum2 << endl;

				if (pathSum1 > pathSum2) {
					cout << "robot 1 chien thang" << endl;
				} else {
					cout << "robot 2 chien thang" << endl;
				}
				break;
			}
			case 3: {
				RobotBD startPos1, startPos2;
				cout << "nhap vi tri robot 1: ";
				cin >> startPos1.x >> startPos1.y;
				cout << "nhap vi tri robot 2: ";
				cin >> startPos2.x >> startPos2.y;

				vector<int> robotPath1 = findRobotPath(maze, startPos1, {});
				vector<int> robotPath2 = findRobotPath(maze, startPos2, robotPath1);

				cout << "duong di cua robot 1: ";
				for (int i = 0; i < robotPath1.size(); i++) {
					cout << robotPath1[i] << " ";
				}
				cout << endl;

				cout << "duong di cua robot 2: ";
				for (int i = 0; i < robotPath2.size(); i++) {
					cout << robotPath2[i] << " ";
				}
				cout << endl;

				int pathSum1 = calculatePathSum(robotPath1);
				int pathSum2 = calculatePathSum(robotPath2);

				cout << "tong duong di cua robot 1 : " << pathSum1 << endl;
				cout << "tong duong di cua robot 2 : " << pathSum2 << endl;

				if (pathSum1 > pathSum2) {
					cout << "robot 1 chien thang" << endl;
				} else {
					cout << "robot 2 chien thang" << endl;
				}
				break;
			}
			case 4: {
				ifstream file("C:\\Users\\nguyen\\c++\\myfile.txt"); //luu y!, phai chinh sua file ten lai khong thi khong hoat dong 
				if (!file.is_open()) {
					cout << "khong the mo tep tin." << endl;
					return 1;
				}

				int fileOption;
				cout << "1 -> duong di 1 robot." << endl;
				cout << "2 -> duong di 2 robot." << endl;
				cout << "3 -> duong di 2 robot khong trung nhau." << endl;
				cout << "nhap lua chon, bam tu 1 den 4 - > :  " ;
				cin >> fileOption;

				switch (fileOption) {
					case 1: {
						RobotBD startPos;
						cout << "nhap vi tri robot: ";
						cin >> startPos.x >> startPos.y;

						vector<int> robotPath = findRobotPath(maze, startPos, {});

						cout << "duong di cua robot: ";
						for (int i = 0; i < robotPath.size(); i++) {
							cout << robotPath[i] << " ";
						}
						cout << endl;

						int pathSum = calculatePathSum(robotPath);
						cout << "tong duong di cua robot: " << pathSum << endl;
						break;
					}
					case 2: {
						RobotBD startPos1, startPos2;
						cout << "nhap vi tri robot 1: ";
						cin >> startPos1.x >> startPos1.y;
						cout << "nhap vi tri robot 2: ";
						cin >> startPos2.x >> startPos2.y;

						vector<int> robotPath1 = findRobotPath(maze, startPos1, {});
						vector<int> robotPath2 = findRobotPath(maze, startPos2, {});

						cout << "duong di cua robot 1: ";
						for (int i = 0; i < robotPath1.size(); i++) {
							cout << robotPath1[i] << " ";
						}
						cout << endl;

						cout << "duong di cua robot 2: ";
						for (int i = 0; i < robotPath2.size(); i++) {
							cout << robotPath2[i] << " ";
						}
						cout << endl;

						cout << "cac o ma 2 robot di trung: ";
						for (int i = 0; i < robotPath1.size(); i++) {
							for (int j = 0; j < robotPath2.size(); j++) {
								if (robotPath1[i] == robotPath2[j]) {
									cout << robotPath1[i] << " ";
									break;
								}
							}
						}
						cout << endl;

						int pathSum1 = calculatePathSum(robotPath1);
						int pathSum2 = calculatePathSum(robotPath2);

						cout << "tong duong di cua robot 1 : " << pathSum1 << endl;
						cout << "tong duong di cua robot 2 : " << pathSum2 << endl;

						if (pathSum1 > pathSum2) {
							cout << "robot 1 chien thang" << endl;
						} else {
							cout << "robot 2 chien thang" << endl;
						}
						break;
					}
					case 3: {
						RobotBD startPos1, startPos2;
						cout << "nhap vi tri robot 1: ";
						cin >> startPos1.x >> startPos1.y;
						cout << "nhap vi tri robot 2: ";
						cin >> startPos2.x >> startPos2.y;

						vector<int> robotPath1 = findRobotPath(maze, startPos1, {});
						vector<int> robotPath2 = findRobotPath(maze, startPos2, {});

						cout << "duong di cua robot 1: ";
						for (int i = 0; i < robotPath1.size(); i++) {
							cout << robotPath1[i] << " ";
						}
						cout << endl;

						cout << "duong di cua robot 2: ";
						for (int i = 0; i < robotPath2.size(); i++) {
							cout << robotPath2[i] << " ";
						}
						cout << endl;

						int pathSum1 = calculatePathSum(robotPath1);
						int pathSum2 = calculatePathSum(robotPath2);

						cout << "tong duong di cua robot 1 : " << pathSum1 << endl;
						cout << "tong duong di cua robot 2 : " << pathSum2 << endl;

						if (pathSum1 > pathSum2) {
							cout << "robot 1 chien thang" << endl;
						} else {
							cout << "robot 2 chien thang" << endl;
						}
						break;
					}
					default:
						cout << "lua chon khong hop le." << endl;
						break;
				}

				file.close();

				break;
			}
			default:
				cout << "lua chon khong hop le" << endl;
				break;
		}

		cout << "ban co muon tiep tuc khong ? (Y/N)" << endl;
		cin >> answer;
	} while (answer == "Y" || answer == "y");

	return 0;
}

