#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> positions , int n ,  int c, int minDist)
{
    int cntP = 1;
      int lastPlacedP = positions[0];
      for (int i = 1; i < n; i++) {
        if (positions[i] - lastPlacedP >= minDist) {
          cntP++;
          lastPlacedP = positions[i];
        }
      }
      if (cntP >= c) return true;
      return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	  sort(positions.begin(), positions.end());

      int low = 1, high = positions[n - 1] - positions[0];

      while (low <= high) {
        int mid = (low + high) >> 1;

        if (isPossible(positions, n, c, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    return high;
}
