class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        
        set<pair<int, int>, greater<pair<int,int>> > maxset; 
        
        set<pair<int, int>> minset;

        for(int i = 0; i < k; i++) {
            minset.insert({nums[i], i});
        }

        for(int i = 0; i < k/2; i++) {
            auto it = minset.begin(); 
            maxset.insert(*it);
            minset.erase(it);
        }
        double median = 1.0;
        if(k % 2)
            median = minset.begin()->first;
        else
            median = (1.0 * maxset.begin()->first + 1.0 * minset.begin()->first) / 2.0;
        
        res.push_back(median);
        int r = k, l = 0;

        while(r < nums.size()) {
            
            pair<int,int> add = {nums[r], r};
            pair<int,int> remove = {nums[l], l};
            int f = 1;
            if(maxset.find(remove) != maxset.end()) {
                maxset.erase(remove);
                f--;
            } else {
                minset.erase(remove);
            }

            if(f) {
                maxset.insert(add);
                auto it = maxset.begin();
                minset.insert(*it);
                maxset.erase(it);
            } else {
                minset.insert(add);
                auto it = minset.begin();
                maxset.insert(*it);
                minset.erase(it);
            }


            if(k % 2)
                median = minset.begin()->first;
            else
                median = (1.0 * maxset.begin()->first + 1.0 * minset.begin()->first) / 2.0;
            
            res.push_back(median);
            r++; l++;
        }

        return res;
    }
};