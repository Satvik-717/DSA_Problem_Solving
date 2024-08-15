//QUESTION

//ROTATE ARRAY BY "K" STEPS TO THE RIGHT

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(vector<int>&nums, int s, int e){

          while(s<=e){

            swap(nums[s],nums[e]);
            s++;
            e--;
        }

    }

void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k%n;          //To keep k in bounds of array

        if(k==0)
        return;
        
        reverse(nums,0,n-1);   //entire array

        reverse(nums,0,k-1);   // first k elements

        reverse(nums,k,n-1);   //remaining elements

    }
    
};
 