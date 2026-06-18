// Problem: 0
// Difficulty: Easy
// Tags: None
// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};