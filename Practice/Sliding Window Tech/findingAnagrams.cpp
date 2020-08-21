/*
438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int mp[26] = {0};
        vector<int> smp(27, 0);

        //storing the characters of p in mp
        for (int i = 0; i < p.size(); i++)
            mp[p[i] - 'a']++;

        int start = 0;
        for (int end = 0; end < s.size(); end++) {
            smp[s[end] - 'a']++;
            if (end - start + 1 == p.size()) {
                int check = 1;
                for (int i = 0; i < 26; i++) {
                    if (mp[i] != smp[i])
                        check = 0;
                }
                if (check)
                    ans.push_back(start);
                smp[s[start] - 'a']--;
                start++;
            }
        }
        return ans;
    }
};