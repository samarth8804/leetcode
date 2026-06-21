class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        map<int,int> mp;

        int len = costs.size();

        int max_bars = 0;

        for(int i=0;i<len;i++) {
            mp[costs[i]]++;
        }

        auto it = mp.begin();

        while(it != mp.end()) {

            if(it->second == 0) {
                it++;
                continue;
            }

            int val = coins - it->first;

            if(val>0) {
                max_bars++;
                it->second--;
                coins=val;
            }
            else if(val == 0) {
                max_bars++;
                return max_bars;
            }
            else{
                return max_bars;
            }
        }

        return max_bars;
    }
};