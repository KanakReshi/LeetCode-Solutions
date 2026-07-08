class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<long long> suffix(n);
        suffix[n - 1] = shifts[n - 1] % 26;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] + shifts[i]) % 26;
        }
        for (int i = 0; i < n; i++) {
            s[i] = 'a' + (s[i] - 'a' + suffix[i]) % 26;
        }
        return s;
    }
};