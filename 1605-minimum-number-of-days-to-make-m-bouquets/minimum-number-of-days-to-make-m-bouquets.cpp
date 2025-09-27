class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();

        int ans = -1;

        if((1LL*m*k) > n) {
            return -1;
        }

        int left = INT_MAX,right = INT_MIN;

        for(auto x : bloomDay) {
            left = min(left,x);
            right = max(right,x);
        }

        while(left<=right) {

            int mid = left + ((right-left)/2);

            int bouquet = 0;

            int count = 0;

            for(int i=0;i<n && bouquet<m;i++) {
                if(bloomDay[i] <= mid) {
                    count++;
                    if(count == k) {
                        bouquet++;
                        count = 0;
                    }
                }
                else {
                    count = 0;
                }
            }

            if(bouquet == m) {
                ans = mid;
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }

        return ans;
    }
};