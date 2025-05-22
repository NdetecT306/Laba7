#include <iostream>
#include <vector>
using namespace std;
void placeKnightsInWhite() {
    vector<vector<char>> board(8, vector<char>(8, '.')); 
    int knightCount = 0;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if ((row + col) % 2 == 0) { 
                board[row][col] = 'K';  
                knightCount++;
            }
        }
    }
    cout << "Шахматная доска с конями:" << endl;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout << "Количество размещенных коней: " << knightCount << endl;
}
void placeKnightsInBlack() {
    vector<vector<char>> board(8, vector<char>(8, '.'));
    int knightCount = 0;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if ((row + col) % 2 == 1) {
                board[row][col] = 'K';
                knightCount++;
            }
        }
    }
    cout << "Шахматная доска с конями:" << endl;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
    cout << "Количество размещенных коней: " << knightCount << endl;
}
int main() {
    setlocale(LC_ALL, "rus");
    placeKnightsInWhite();
    placeKnightsInBlack();
    return 0;
}
