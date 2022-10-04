// Question :-
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=nums[0];
        int currsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i]+currsum)
                currsum=nums[i];
            else
                currsum=nums[i]+currsum;
            maxi=max(maxi,currsum);
        }
        return maxi;
    }
};