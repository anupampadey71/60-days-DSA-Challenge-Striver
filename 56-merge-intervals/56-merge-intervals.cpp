class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mInterval;
        if(intervals.size()== 0) return mInterval;
        sort(intervals.begin(), intervals.end());
        vector <int> tempI = intervals[0];
        for(auto it: intervals ){
            if(it[0] <= tempI[1])
                tempI[1]=max(it[1], tempI[1]);
            else{
                mInterval.push_back(tempI);
                tempI=it;
            }
        }
        mInterval.push_back(tempI);
        return mInterval;
    }
};