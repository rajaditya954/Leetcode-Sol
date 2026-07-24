class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());
        queue<string> q;
        unordered_set<string> visited;
        int moves = 0;

        
        if (dead.count("0000"))
            return -1;

        q.push("0000");
        visited.insert("0000");

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                if (curr == target)
                    return moves;

                for (int i = 0; i < 4; i++) {

                    char ch = curr[i];

                    if(ch=='9') curr[i]='0';
                    else curr[i]=ch+1;

                    if (!dead.count(curr) && !visited.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }

                    if(ch=='0') curr[i]='9';
                    else curr[i]=ch-1;

                    if (!dead.count(curr) && !visited.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }

                    curr[i] = ch;
                }
            }

            moves++;
        }

        return -1;
    }
};