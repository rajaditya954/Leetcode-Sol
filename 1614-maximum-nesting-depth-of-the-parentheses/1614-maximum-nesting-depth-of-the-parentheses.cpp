class Solution {
public:
    int maxDepth(string s) {
        int count =0;
        int maxcount=0;

        for(char t:s){
            if(t=='('){
                count++;
                maxcount=max(count,maxcount);
            }
            else if(t==')'){
                count--;
            }
        }
        return maxcount;
    }
};