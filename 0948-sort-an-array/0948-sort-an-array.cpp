class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.empty()) {
            return nums; // Return empty vector for empty input
        }

        int min_val = INT_MAX;
        int max_val = INT_MIN;
        
        for (int num : nums) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }
        
        int range = max_val - min_val + 1;
        vector<int> counting_array(range, 0);

        for (int num : nums) {
            counting_array[num - min_val]++;
        }

        int i = 0;
        for (int j = 0; j < range; j++) {
            while (counting_array[j] > 0) {
                nums[i++] = j + min_val;
                counting_array[j]--;
            }
        }

        return nums;
    }
};
