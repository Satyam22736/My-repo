#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * @brief Finds two indices in the array that sum up to the target value.
 *
 * This function uses a hash map (unordered_map) to achieve O(n) time complexity.
 * It iterates through the array, and for each element, it checks if the
 * required complement (target - current_element) already exists in the map.
 *
 * @param nums The input vector of integers.
 * @param target The target sum.
 * @return A vector containing the indices of the two numbers that add up to the target.
 * If no such pair is found, it returns an empty vector.
 */
std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    // Hash map to store the required complement and its index.
    // Key: The number needed (target - nums[i])
    // Value: The index (i) of the current number.
    std::unordered_map<int, int> complementMap;

    // Iterate through the array
    for (int i = 0; i < nums.size(); ++i) {
        int currentNum = nums[i];
        int complement = target - currentNum;

        // Check if the current number is the complement of a number
        // already processed and stored in the map.
        if (complementMap.count(currentNum)) {
            // Found a pair! The indices are the one stored in the map
            // and the current index 'i'.
            return {complementMap.at(currentNum), i};
        }

        // Store the complement needed for the current number, along with the
        // current number's index 'i', so we can quickly look it up later.
        complementMap[complement] = i;
    }

    // If no solution is found after iterating through the entire array.
    return {};
}

int main() {
    // Sample Input 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);

    std::cout << "Input Array 1: {2, 7, 11, 15}, Target: 9" << std::endl;
    if (!result1.empty()) {
        std::cout << "Output: [" << result1[0] << ", " << result1[1] << "]" << std::endl;
        std::cout << "Explanation: nums1[" << result1[0] << "] (" << nums1[result1[0]]
                  << ") + nums1[" << result1[1] << "] (" << nums1[result1[1]]
                  << ") = " << target1 << std::endl;
    } else {
        std::cout << "Output: No two sum solution found." << std::endl;
    }

    std::cout << "\n----------------------------\n" << std::endl;

    // Sample Input 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);

    std::cout << "Input Array 2: {3, 2, 4}, Target: 6" << std::endl;
    if (!result2.empty()) {
        std::cout << "Output: [" << result2[0] << ", " << result2[1] << "]" << std::endl;
        std::cout << "Explanation: nums2[" << result2[0] << "] (" << nums2[result2[0]]
                  << ") + nums2[" << result2[1] << "] (" << nums2[result2[1]]
                  << ") = " << target2 << std::endl;
    } else {
        std::cout << "Output: No two sum solution found." << std::endl;
    }

    return 0;
}
