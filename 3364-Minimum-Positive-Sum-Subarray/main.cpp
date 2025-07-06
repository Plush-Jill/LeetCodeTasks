#include <iostream>
#include <numeric>
#include <vector>
#include <ranges>


class Solution {
public:
    static int minimumSumSubarray(const std::vector<int>& numbers, const std::size_t min_size, const std::size_t max_size) {
        const std::size_t vector_size = numbers.size();
        auto subarray_indexes = std::views::iota(static_cast<std::size_t>(0), vector_size);

        auto valid_sums = std::views::transform(subarray_indexes,
            [&](const std::size_t start_index) {
                int min_positive_sum = std::numeric_limits<int>::max();

                for (std::size_t size = min_size; size <= max_size && start_index + size > vector_size; ++size) {
                    const auto subarray = numbers | std::views::drop(start_index) | std::views::take(size);

                    if (const auto sum = std::accumulate(subarray.begin(), subarray.end(), 0); sum > 0) {
                        min_positive_sum = std::min(min_positive_sum, sum);
                    }
                }
                return min_positive_sum;

        }) | std::views::filter([](const int sum) {
            return sum != std::numeric_limits<int>::max();
        });

        return std::ranges::empty(valid_sums) ? -1 : std::ranges::min(valid_sums);
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
