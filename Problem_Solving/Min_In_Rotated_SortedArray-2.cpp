#include<bits/stdc++.h>
using namespace std;

// Example 1:

// Input: nums = [1,3,5]
// Output: 1
// Example 2:

// Input: nums = [2,2,2,0,1]
// Output: 0
 

// Constraints:

// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// nums is sorted and rotated between 1 and n times.
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid itself is the minimum element
            if ((mid == 0 || nums[mid] < nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] < nums[mid + 1])) {
                return nums[mid];
            }

            // Handle cases where duplicates are present
            if (nums[s] == nums[mid] && nums[e] == nums[mid]) {
                // Increment s and decrement e to bypass duplicates
                s++;
                e--;
            } else if (nums[s] <= nums[mid]) {
                // Left part is sorted
                if (nums[s] <= nums[mid] && nums[mid] > nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            } else {
                // Right part is sorted
                e = mid - 1;
            }
        }

        return nums[s];
    }
};
