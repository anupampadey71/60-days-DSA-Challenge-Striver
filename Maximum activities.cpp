#include<bits/stdc++.h>
using namespace std;
struct meeting {
   int start;
   int end;
   int pos;
};

bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    struct meeting meet[n];
      for (int i = 0; i < n; i++) {
         meet[i].start = start[i], meet[i].end = finish[i], meet[i].pos = i + 1;
      }

      sort(meet, meet + n, comparator);
      vector < int > answer;
      int count=0;
      int limit = meet[0].end;
      answer.push_back(meet[0].pos);
      count++;
      for (int i = 1; i < n; i++) {
         if (meet[i].start > limit || meet[i].start == limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
            count++;
         }
      }
      return count;
}