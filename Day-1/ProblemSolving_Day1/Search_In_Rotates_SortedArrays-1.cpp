#include<bits/stdc++.h>
using namespace std;

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int s=0;
        int e=n-1;

        while(s<=e){

            int mid = s+((e-s)/2);

            if(nums[mid] == target)
            return mid;

           //Checking left sorted part
            
            if(nums[s]<=nums[mid]){

                if((nums[s]<=target) && (target<=nums[mid]))
                e = mid-1;
                else
                s = mid+1;
            }

            //Checking right sorted part

            else {

                if((nums[mid]<=target) && (target<=nums[e]))
                s = mid+1;
                else
                e = mid-1;
            }
        } 

        return -1;
    }
};