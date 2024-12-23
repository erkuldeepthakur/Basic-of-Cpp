#include <vector>
#include <algorithm>
#include <iostream>

int maxProduct(std::vector<int>& nums) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] < 0) {
            std::swap(maxProd, minProd);
        }
        maxProd = std::max(nums[i], maxProd * nums[i]);
        minProd = std::min(nums[i], minProd * nums[i]);
        result = std::max(result, maxProd);
    }
    return result;
}

int main() {
    std::vector<int> nums = {2, 3, -2, 4};
    std::cout << "Maximum product of contiguous subarray: " << maxProduct(nums) << std::endl;
    return 0;
}
