#include <iostream>
#include <unordered_map>
#include <vector>
#include <ranges>
#include <bits/ranges_algo.h>

class Solution {
public:
    bool isPossibleToSplit(std::vector<int>& nums) {
        if (std::ranges::all_of(nums.begin(), nums.end(),
                                [this](const int number) { return addToMapWithCheck(number); })) {
            return true;
        }
        return false;
    }

private:
    std::unordered_map<int, int> m_count_map_ {};

    auto addToMapWithCheck (const int number) {
        if (m_count_map_.contains(number)) {
            if (m_count_map_[number] < 2) {
                ++m_count_map_[number];
                return true;
            }
            return false;
        }
        m_count_map_[number] = 1;
        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
