#include<bits/stdc++.h>
using namespace std;

//FIND MINIMUM IN ROTATED SORTED ARRAY

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Example 2:

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
// Example 3:

// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

// Constraints:

// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// All the integers of nums are unique.
// nums is sorted and rotated between 1 and n times.

class Solution {
public:
    int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}
};
