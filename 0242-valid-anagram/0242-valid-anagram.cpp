class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length())
            return false;

        unordered_map<char, int> mp;

        for(char ch : s) {
            mp[ch]++;
        }

        for(char ch : t) {

            if(mp.find(ch) == mp.end()) {
                return false;
            }

            mp[ch]--;
        }

        for(auto it : mp) {
            if(it.second != 0) {
                return false;
            }
        }

        return true;
    }
};