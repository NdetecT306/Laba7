#include <iostream>
#include <vector>
using namespace std;
void solve(int ind, int remainingArrows, int currentSc, vector<int>& alice, vector<int>& currentBob, vector<int>& bestBob, int& maxSc) {
    if (ind == 12) {
        if (remainingArrows > 0) {
            currentBob[0] += remainingArrows;
        }
        if (currentSc > maxSc) {
            maxSc = currentSc;
            bestBob = currentBob;
        }
        if(remainingArrows > 0) {
            currentBob[0] -= remainingArrows;
        }
        return;
    }
    solve(ind+ 1, remainingArrows, currentSc, alice, currentBob, bestBob, maxSc);
    int arrowsNeed = alice[ind] + 1;
    if (remainingArrows >= arrowsNeed) {
        currentBob[ind] = arrowsNeed;
        solve(ind + 1, remainingArrows - arrowsNeed, currentSc + ind, alice, currentBob, bestBob, maxSc);
        currentBob[ind] = 0;  
    }
}
vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    vector<int> bobArrows(12, 0);
    vector<int> bestBobArrows(12, 0);
    int maxScore = 0;
    solve(0, numArrows, 0, aliceArrows, bobArrows, bestBobArrows, maxScore);
    return bestBobArrows;
}
int main() {
    int numArrows;
    cout << "Введите общее количество стрел: ";
    cin >> numArrows;
    vector<int> aliceArrows(12);
    cout << "Введите количество стрел, выпущенных Алисой в каждой секции (0-11):" << endl;
    for (int i = 0; i < 12; ++i) {
        cout << "Секция " << i << ": ";
        cin >> aliceArrows[i];
    }
    vector<int> bobArrows = maximumBobPoints(numArrows, aliceArrows);
    cout << "Боб должен выпустить следующее количество стрел в каждом раунде:" << endl;
    for (int i = 0; i < bobArrows.size(); ++i) {
        cout << bobArrows[i] << " ";
    }
    int totaBobArrows = 0;
    for(int e : bobArrows){
        totaBobArrows += e;
    }
    cout << endl;
    if (totaBobArrows != numArrows) {
      cout << "Ошибка: общее количество стрел Боба не соответствует введенному числу." << endl;
    }
    return 0;
}
