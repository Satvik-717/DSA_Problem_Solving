#include<bits/stdc++.h>
using namespace std;

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
 

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

//BRUTE FORCE APPROACH

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
        // int n = nums.size();

        // vector<int>ans;

        // for(int i=0; i<n-1; i++){

        //     for(int j=i+1; j<n; j++){

        //         if((nums[i]+nums[j]) == target){

        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        
//         // return ans;
//     }
// };

//OPTIMIZED APPROACH

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
             
             int n = nums.size();
             unordered_map<int,int>mp;

             for(int i=0; i<n; i++){

                int remaining = target - nums[i];

                if(mp.find(remaining) != mp.end()){

                    return{mp[remaining],i};
                }

                mp[nums[i]] = i;
             }

             return {};
             
    }

};