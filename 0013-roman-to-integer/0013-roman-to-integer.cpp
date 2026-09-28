class Solution {
public:
    int romanToInt(string s) {
    
    unordered_map<char,int> roman;

    roman['I']=1;
    roman['V']=5;
    roman['X']=10;
    roman['L']=50;
    roman['C']=100;
    roman['D']=500;
    roman['M']=1000;

    int curr=0;
    int prev=0;
    int ans=0;


    for(int i=s.length()-1; i>=0; i--){
        curr=roman[s[i]];

        if(curr<prev){
          ans=ans-curr;
        }
        else{
            ans=ans+curr;
        }
        prev=curr;
    }

    return ans;
    
        
    }
};