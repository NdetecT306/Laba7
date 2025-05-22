#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
vector<int> solution(int numArrows, vector<int>& aliceArrows) {
    int n = 12;
    vector<int> bobArrows(n);
    int max = -1;
    vector<int> bestBobArrows(n);
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> peremBobArrows(n);
        int peremArrows = 0;
        int peremScore = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                peremBobArrows[j] = aliceArrows[j] + 1;
                peremArrows += peremBobArrows[j];
                peremScore += j;
            }
        }
        if (peremArrows <= numArrows) {
            if (peremScore > max) {
                max = peremScore;
                bestBobArrows = peremBobArrows;
                int remainingArrows = numArrows - peremArrows;
                bestBobArrows[0] += remainingArrows;
            }
        }
    }
    return bestBobArrows;
}

int main() {
    int numArrows;
    cin >> numArrows;
    vector<int> aliceArrows(12);
    for (int i = 0; i < 12; ++i) {
        cin >> aliceArrows[i];
    }
    vector<int> bobArrows = solution(numArrows, aliceArrows);
    for (int i = 0; i < 12; ++i) {
        cout << bobArrows[i] << " ";
    }
    cout << endl;

    return 0;
}
