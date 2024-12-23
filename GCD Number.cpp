#include <iostream>
#include <vector>
#include <algorithm>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findGCD(std::vector<int>& nums) {
    int minNum = *std::min_element(nums.begin(), nums.end());
    int maxNum = *std::max_element(nums.begin(), nums.end());
    return gcd(minNum, maxNum);
}

int main() {
    std::vector<int> nums = {2, 5, 6, 9, 10};
    std::cout << findGCD(nums) << std::endl; // Output: 2
    return 0;
}
