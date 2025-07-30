class Solution {
public:
    void binarySearch(const vector<int>& nums, int target, int &first, int &last, int l, int r, int flag) {
        if (l > r) return;

        int mid = (l + r) / 2;

        if (nums[mid] == target) {
            if (flag == 0) {
                first = mid;
                binarySearch(nums, target, first, last, l, mid - 1, 0); 
            } else {
                last = mid;
                binarySearch(nums, target, first, last, mid + 1, r, 1); 
            }
        } 
        else if (target < nums[mid]) {
            binarySearch(nums, target, first, last, l, mid - 1, flag);
        } 
        else {
            binarySearch(nums, target, first, last, mid + 1, r, flag);
        }
    }
    // this is little complicated you can do it simple calling two diffrent functions.
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        int n = nums.size();
        binarySearch(nums, target, first, last, 0, n - 1, 0);
        binarySearch(nums, target, first, last, 0, n - 1, 1);
        return {first, last};
    }
};
