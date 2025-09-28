class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();

        int left = INT_MIN;
        int right = 0;

        int ans;

        for(auto x : weights) {
            left = max(left,x);
            right = right + x;
        }

        while(left<=right) {
            int mid = left + ((right-left)/2);

            int load = 0;
            int ship_days = 0;

            for(int i=0;i<n && ship_days<=days;i++) {

                load = load + weights[i];

                if(load > mid) {
                    ship_days++;
                    load = weights[i];
                }
            }

            if(load<=mid) {
                ship_days++;
            }

            if(ship_days<=days) {
                ans = mid;
                right = mid-1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};