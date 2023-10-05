#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        size_t len = nums.size();
        int max = len / 3;

        std::unordered_map<int, unsigned int> counter;
        std::vector<int> res = {};

        for (auto i = 0; i < len; i++) {
            if ( counter.count(nums[i]) ) counter[ nums[i] ] += 1;
            else counter[ nums[i] ] = 1;
        }

        std::unordered_map<int, unsigned int>::iterator it = counter.begin();
        std::unordered_map<int, unsigned int>::iterator it_end = counter.end();

        while ( it != it_end ) {
            if (it->second > max) res.push_back(it->first);
            it++;
        }

        return res;
    }
};