class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 枚舉
        int n = nums.size(), out_max = INT_MIN;
        vector<int> st;
        for(int i = n - 1;i >= 0;i--){
            if(nums[i] < out_max) return true;
            while(!st.empty() && nums[i] > st.back()){
                out_max = max(out_max, st.back());
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        return false;
    }
};