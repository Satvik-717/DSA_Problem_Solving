#include<bits/stdc++.h>
using namespace std;
// Example 1:  WITH DUPLICATES

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// nums is guaranteed to be rotated at some pivot.
// -104 <= target <= 104

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int s = 0;
        int e = n-1;

        while(s<=e){

            int mid = s+((e-s)/2);

            if(nums[mid] == target)
            return true;

            //Handle duplicates
            if((nums[s]==nums[mid]) && (nums[mid]==nums[e])){
            s++;
            e--;
            continue;
            }
            
            if(nums[s]<=nums[mid]){

                if(nums[s]<= target && target<= nums[mid]){

                    e = mid-1;
                }

                else {

                    s=mid+1;
                }
            }

            else {

                if(nums[mid]<= target && target<= nums[e]){

                    s = mid+1;
                }

                else {

                    e = mid-1;
                }  
            }
        }

        return false;
    }
};