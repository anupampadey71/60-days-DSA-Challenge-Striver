class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> helper;
        helper['I']=1;
        helper['V']=5;
        helper['X']=10;
        helper['L']=50;
        helper['C']=100;
        helper['D']=500;
        helper['M']=1000;
        int ans=helper[s[0]];
        for(int i=1;i<s.size();i++){
            if(helper[s[i]]>helper[s[i-1]]){
                ans-=helper[s[i-1]];
                ans+=helper[s[i]]-helper[s[i-1]];
            }
            else{ans+=helper[s[i]];}
        }
        return ans;
    }
};

