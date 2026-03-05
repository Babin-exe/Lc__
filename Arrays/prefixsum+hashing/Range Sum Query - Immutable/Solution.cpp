// Problem Link :https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
    vector<int> nums;
    vector<int> pf;

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        pf = vector<int>(nums.size());

        pf[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            pf[i] = pf[i - 1] + nums[i];
    }

    int sumRange(int left, int right) {
        if (left == 0)
            return pf[right];
        return pf[right] - pf[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
