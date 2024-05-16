export module Solution;

import <vector>;
import <map>;
import <hash_map>;


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;

        for (int i {}; i < nums.size(); ++i){
            int x = nums[i];
            if (map.contains(target - x)){
                return std::vector<int>{i, map[target - x]};
            }
            map.emplace(x, i);
        }
        return {};
    }
    std::vector<int> twoSumSorted(std::vector<int>& numbers, int target) {
        std::unordered_map<int, int> map;
        size_t size = numbers.size();
        for (int i {}; i < size; ++i){
            int x = numbers[i];
            if (map.contains(target - x)){
                return std::vector<int>{i, map[target - x]};
            }
            map.emplace(x, i);
            map.emplace(numbers[size - i], size - i);
        }
        return {};
    }
};


