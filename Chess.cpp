#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<bool>> attacked;
int maxCount = 0;
bool MoveKnight(int row, int col) {
    return !attacked[row][col];
}
void setKnight(int row, int col, bool place, vector<pair<int, int>>& changed) {
    static const int moves[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };
    if (place) {
        return; 
    }
    changed.push_back({row, col});
    for (int i = 0; i < 8; ++i) {
        int nr = row + moves[i][0];
        int nc = col + moves[i][1];
        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
            if (!attacked[nr][nc]) {
                changed.push_back({nr, nc});
            }
        }
    }
    for(const auto& p : changed){
        attacked[p.first][p.second] = !place;
    }
}
void backtrack(int start, int count, int color) {
    if (start >= n * n) {
        maxCount = max(maxCount, count);
        return;
    }
    int row = start / n;
    int col = start % n;
    if (((row + col) % 2) != color) { 
        backtrack(start + 1, count, color);
        return;
    }
    vector<pair<int, int>> changed;
    if (MoveKnight(row, col)) {
        setKnight(row, col, false, changed);
        backtrack(start + 1, count + 1, color);
        setKnight(row, col, true, changed);  
    }
    backtrack(start + 1, count, color);
}
int main() {
    n = 8;
    attacked.assign(n, vector<bool>(n, false));
    maxCount = 0;
    backtrack(0, 0, 1); 
    cout << "Максимальное количество коней: " << maxCount << endl;
    return 0;
}
