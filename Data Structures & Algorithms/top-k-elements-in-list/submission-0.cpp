class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> a;
        for(int i: nums)
            a[i]++;
        vector<pair<int,int>> cntnum;
        for(auto& i : a)
            cntnum.push_back({i.second,i.first});

        sort(cntnum.begin(),cntnum.end(), greater<pair<int, int>>());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(cntnum[i].second);
        }
        return res;
    }
};