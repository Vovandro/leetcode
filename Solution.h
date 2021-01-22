#include <iostream>
#include <vector>
#include <set>
#include <map>

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * Given a binary array, find the maximum number of consecutive 1s in this array.
     * @param nums
     * @return
     */
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        bool last_1 = false;
        int count = 0;

        for (int i: nums) {
            if (i == 1) {
                count++;
            } else {
                if (count > max_count) {
                    max_count = count;
                }

                count = 0;
            }
        }

        if (count > max_count) {
            max_count = count;
        }

        return max_count;
    }

    /**
     * Given an array nums of integers, return how many of them contain an even number of digits.
     * @param nums
     * @return
     */
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i: nums) {
            if (to_string(i).size() % 2 == 0) {
                count++;
            }
        }

        return count;
    }

    /**
     * Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
     * @param nums
     * @return
     */
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] *= nums[i];
        }

        sort(nums.begin(), nums.end());

        return nums;
    }

    /**
     * Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.
     * Note that elements beyond the length of the original array are not written.
     * Do the above modifications to the input array in place, do not return anything from your function.
     * @param arr
     */
    void duplicateZeros(vector<int>& arr) {
        int i = 0;

        while (i < arr.size()) {
            if (arr[i] == 0) {
                arr.insert(arr.begin()+i, 0);
                arr.pop_back();
                ++i;
            }

            ++i;
        }
    }

    /**
     * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
     * The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has a
     * size equal to m + n such that it has enough space to hold additional elements from nums2.
     * @param nums1
     * @param m
     * @param nums2
     * @param n
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }

    /**
     * Given an array nums and a value val, remove all instances of that value in-place and return the new length.
     * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
     * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
     * @param nums
     * @param val
     * @return
     */
    int removeElement(vector<int>& nums, int val) {
        int i = 0;

        while (i < nums.size()) {
            if (nums[i] == val) {
                nums.erase(nums.begin()+i);
                --i;
            }

            ++i;
        }

        return nums.size();
    }

    /**
     * Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.
     * Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
     * @param nums
     * @return
     */
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        while (i < int(nums.size()) - 1) {
            if (nums[i] == nums[i + 1]) {
                nums.erase(nums.begin()+i);
                continue;
            }

            ++i;
        }

        return nums.size();
    }

    /**
     * Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
     * @param arr
     * @return
     */
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            int search_num = int(arr[i] * 2);
            for (int j = 0; j < arr.size(); ++j) {
                if ((arr[j] == search_num) && (i != j))
                    return true;
            }
        }

        return false;
    }

    /**
     * Given an array of integers arr, return true if and only if it is a valid mountain array.
     * Recall that arr is a mountain array if and only if:
     *
     * arr.length >= 3
     * There exists some i with 0 < i < arr.length - 1 such that:
     * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
     * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
     * @param arr
     * @return
     */
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;

        if (arr[0] >= arr[1])
            return false;

        bool upper = true;

        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] == arr[i+1])
                return false;

            if (upper) {
                if (arr[i] > arr[i+1])
                    upper = false;
            } else {
                if (arr[i] < arr[i+1])
                    return false;
            }
        }

        return !upper;
    }

    /**
     * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
     * You may assume that each input would have exactly one solution, and you may not use the same element twice.
     * You can return the answer in any order.
     * @param nums
     * @param target
     * @return
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target)
                    return vector<int>({i, j});
            }
        }

        return vector<int>();
    }

    /**
     * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
     * and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
     * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
     * @param l1
     * @param l2
     * @return
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool is_next = false;
        ListNode* buf1 = l1;
        ListNode* buf2 = l2;
        ListNode* result = nullptr;
        ListNode* last = nullptr;

        while ((buf1 != nullptr) && (buf2 != nullptr)) {
            int num = buf1->val + buf2->val;

            if (is_next) {
                num += 1;
                is_next = false;
            }

            if (num >= 10) {
                num -= 10;
                is_next = true;
            }

            if (result == nullptr) {
                result = new ListNode(num);
                last = result;
            } else {
                last->next = new ListNode(num);
                last = last->next;
            }

            buf1 = buf1->next;
            buf2 = buf2->next;
        }

        while (buf1 != nullptr) {
            int num = buf1->val;

            if (is_next) {
                num += 1;
                is_next = false;
            }

            if (num >= 10) {
                num -= 10;
                is_next = true;
            }

            if (result == nullptr) {
                result = new ListNode(num);
                last = result;
            } else {
                last->next = new ListNode(num);
                last = last->next;
            }

            buf1 = buf1->next;
        }

        while (buf2 != nullptr) {
            int num = buf2->val;

            if (is_next) {
                num += 1;
                is_next = false;
            }

            if (num >= 10) {
                num -= 10;
                is_next = true;
            }

            if (result == nullptr) {
                result = new ListNode(num);
                last = result;
            } else {
                last->next = new ListNode(num);
                last = last->next;
            }

            buf2 = buf2->next;
        }

        if (is_next) {
            last->next = new ListNode(1);
            last = last->next;
        }


        return result;
    }

    /**
     * Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.
     * After doing so, return the array.
     * @param arr
     * @return
     */
    vector<int> replaceElements(vector<int>& arr) {
        int max_num = 0;
        if (arr.size() > 1)
            max_num = arr[1];
        for (int i = 0; i < arr.size(); ++i) {
            if (i == arr.size() - 1) {
                arr[i] = -1;
            } else {
                if (arr[i] == max_num) {
                    max_num = -999999999;
                    for (int j = i + 1; j < arr.size(); ++j) {
                        if (arr[j] > max_num)
                            max_num = arr[j];
                    }
                }
                arr[i] = max_num;
            }
        }

        return arr;
    }

    /**
     * Given a string s, find the length of the longest substring without repeating characters.
     * @param s
     * @return
     */
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        string str = "";
        int i = 0;

        while (i < s.size()) {
            if (str.find(s[i]) == string::npos) {
                str += s[i];
            } else {
                if (str.size() > max_len)
                    max_len = str.size();

                i -= str.size() - str.find(s[i]);
                str = "";
            }
            ++i;
        }

        if (str.size() > max_len)
            max_len = str.size();

        return max_len;
    }

    /**
     * Given a string s, return the longest palindromic substring in s.
     * @param s
     * @return
     */
    string longestPalindrome(string s) {
        string max_size = "";

        if (s.size() > 0)
            max_size += s[0];

        int i = 0;

        while (i < s.size() - max_size.size()) {
            size_t next_char = i;
            while (next_char != string::npos) {
                next_char = s.find(s[i], next_char + 1);

                if (next_char == string::npos)
                    break;

                if (max_size.size() > next_char - i)
                    continue;

                string b = s.substr(i, next_char - i + 1);

                string b1 = b.substr(0, int(b.size() / 2));
                string b2 = b.substr(int(b.size() / 2) + b.size() % 2);
                std::reverse(b2.begin(), b2.end());
                if (b1 == b2)
                    max_size = b;
            }

            ++i;
        }

        return max_size;
    }

    /**
     * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
     * @param nums
     */
    void moveZeroes(vector<int>& nums) {
        auto i = nums.begin();
        int j = nums.size();

        while ((i != nums.end()) && (i != nums.begin() + j)) {
            if (*i == 0) {
                nums.erase(i);
                nums.push_back(0);
                --j;
            }
            else {
                ++i;
            }
        }
    }

    /**
     * Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
     * You may return any answer array that satisfies this condition.
     * @param A
     * @return
     */
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int lastFound = 0, cur = 0; cur < A.size(); cur++) {
            if (A[cur] % 2 == 0) {
                swap(A[lastFound++], A[cur]);
            }
        }

        return A;
    }

    /**
     * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
     *
     * An input string is valid if:
     * Open brackets must be closed by the same type of brackets.
     * Open brackets must be closed in the correct order.
     * @param s
     * @return
     */
    bool isValid(string s) {
        if (s.empty())
            return true;

        if (s.size() == 1)
            return false;

        if ((s[0] == ']') || (s[0] == '}') || (s[0] == ')'))
            return false;

        char symbol = s[0];
        int num = 1;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == symbol) {
                ++num;
                continue;
            }

            switch (symbol) {
                case '(': {
                    if (s[i] == ')')
                        --num;
                    break;
                }

                case '[': {
                    if (s[i] == ']')
                        --num;
                    break;
                }

                case '{': {
                    if (s[i] == '}')
                        --num;
                    break;
                }

                default:
                    return false;
            }

            if (num == 0) {
                return isValid(s.substr(1, i - 1)) && isValid(s.substr(i + 1));
            }
        }

        return false;
    }

    /**
     * Students are asked to stand in non-decreasing order of heights for an annual photo.
     * Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.
     * Notice that when a group of students is selected they can reorder in any possible way between themselves and the non selected students remain on their seats.
     * @param heights
     * @return
     */
    int heightChecker(vector<int>& heights) {
        vector<int> heights_sort = heights;
        sort(heights_sort.begin(), heights_sort.end());
        int count = 0;

        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != heights_sort[i])
                count++;
        }

        return count;
    }

    /**
     * Given integer array nums, return the third maximum number in this array. If the third maximum does not exist, return the maximum number.
     * @param nums
     * @return
     */
    int thirdMax(vector<int>& nums) {

        set<int> val{nums.begin(), nums.end()};

        nums = {val.begin(), val.end()};

        if (nums.size() >= 3)
            return nums[nums.size() - 3];

        return nums[nums.size() - 1];
    }

    /**
     * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
     * Find all the elements of [1, n] inclusive that do not appear in this array.
     * Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
     * @param nums
     * @return
     */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        sort(nums.begin(), nums.end());
        int numbers = 1;
        int min_find = 0;
        bool find = false;

        while (numbers <= nums.size()) {
            find = false;
            for (int i = min_find; i < nums.size(); ++i) {
                if (nums[i] == numbers) {
                    ++numbers;
                    min_find = i + 1;
                    find = true;
                    break;
                }

                if (nums[i] > numbers) {
                    find = true;
                    for (int j = numbers; j < nums[i]; ++j)
                        result.push_back(j);
                    numbers = nums[i];
                    break;
                }
            }

            if (!find) {
                result.push_back(numbers);
                ++numbers;
            }
        }

        return result;
    }

    /**
     * Say you have an array prices for which the ith element is the price of a given stock on day i.
     * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
     * Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
     * @param prices
     * @return
     */
    int maxProfit(vector<int>& prices) {
        int cost = 0;
        bool bye = false;
        int result = 0;

        for (int i = 0; i < prices.size() - 1; ++i) {
            if (bye) {
                if (prices[i] > prices[i + 1]) {
                    result += prices[i] - cost;
                    bye = false;
                }
            } else {
                if (prices[i] < prices[i + 1]) {
                    cost = prices[i];
                    bye = true;
                }
            }
        }

        if (bye) {
            result += prices[prices.size() - 1] - cost;
        }

        return result;
    }

    /**
     * Given an array, rotate the array to the right by k steps, where k is non-negative.
     *
     * Follow up:
     * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
     * Could you do it in-place with O(1) extra space?
     * @param nums
     * @param k
     */
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end());
    }

    /**
     * Given an array of integers, find if the array contains any duplicates.
     * Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
     * @param nums
     * @return
     */
    bool containsDuplicate(vector<int>& nums) {
        set<int> nums2{nums.begin(), nums.end()};
        return nums.size() != nums2.size();
    }

    /**
     * Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
     * Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?
     * @param nums
     * @return
     */
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] != nums[i+1])
                return nums[i];
        }

        return 0;
    }

    /**
     * Given two arrays, write a function to compute their intersection.
     *
     * Note:
     * Each element in the result should appear as many times as it shows in both arrays.
     * The result can be in any order.
     *
     * Follow up:
     * What if the given array is already sorted? How would you optimize your algorithm?
     * What if nums1's size is small compared to nums2's size? Which algorithm is better?
     * What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
     *
     * @param nums1
     * @param nums2
     * @return
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        auto pos2 = nums2.begin();
        vector<int> result;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int num: nums1) {
            while (pos2 != nums2.end()) {
                if (*pos2 == num) {
                    result.push_back(num);
                    pos2++;
                    break;
                }

                if (*pos2 > num)
                    break;

                pos2++;
            }

            if (pos2 == nums2.end())
                break;
        }

        return result;
    }

    /**
     * Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
     * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
     * You may assume the integer does not contain any leading zero, except the number 0 itself.
     * @param digits
     * @return
     */
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            digits[i] += 1;
            if (digits[i] < 10)
                break;
            digits[i] -= 10;

            if (i == 0) {
                digits.insert(digits.begin(), 1);
                break;
            }
        }

        return digits;
    }

    /**
     * Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
     * An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
     * 
     * We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position
     * where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more
     * competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.
     * @param nums
     * @param k
     * @return
     */
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        if (k == nums.size())
            return nums;

        vector<int> result;
        int start_pos = 0;
        while (result.size() < k) {
            auto min_num = min_element(nums.begin() + start_pos, nums.end() - k + 1 + result.size());
            start_pos = distance(nums.begin(), min_num) + 1;
            result.push_back(*min_num);
        }

        return result;
    }

    /**
     * Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go
     * outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
     * @param x
     * @return
     */
    int reverse(int x) {
        int rem, result = 0;
        while(x!=0)
        {
            rem=x%10;
            if (result > INT_MAX/10 || (result == INT_MAX / 10 && rem > 7)) return 0;
            if (result < INT_MIN/10 || (result == INT_MIN / 10 && rem < -8)) return 0;

            result = result * 10 + rem;
            x/=10;
        }

        return result;
    }
};


#endif //LEETCODE_SOLUTION_H
