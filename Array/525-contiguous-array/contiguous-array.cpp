class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, max_len = 0;
        mp[0] = -1;

        for(int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 0 ? -1 : 1);

            if(mp.find(sum) != mp.end()) {
                max_len = max(max_len, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return max_len;
    }
};