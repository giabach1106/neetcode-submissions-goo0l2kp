class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> p;
        vector <int> ans;
        for(int i = 0; i < nums.size(); i++) {
            if(p[nums[i]] == 0)
                p[nums[i]] = i;
            
        }
        for(int i = 0; i < nums.size(); i++) {
            if(p.find(target - nums[i]) != p.end() &&  i!= p[target - nums[i]]) {
                ans.push_back(i);
                ans.push_back(p[target - nums[i]]);
                sort(ans.begin(), ans.end());
                break;
            }
        }
        return ans;
    }
};
