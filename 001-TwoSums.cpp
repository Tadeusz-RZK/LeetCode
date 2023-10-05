#include <iostream>
#include <vector>
#include <map>

// Good memory usage but bad runtime

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, const int target) {
        const int n = nums.size();

        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                if (i == j) break;
                if (nums[i] + nums[j] == target) return {i, j};
            }
        }

        return {};
    }
};

// Good runtime but bad memory usage

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, const int target) {
        std::unordered_map<int, int> m;
        int n = nums.size();

        for (auto i = 0; i < n; i++) {
            int tmp = target - nums[i];
            if (m.count(tmp))
                return {i, m.find(tmp)->second};
            m[nums[i]] = i;
        }

        return {};
    }
};