class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();

        int ans = -1;

        if((1LL*m*k) > n) {
            return -1;
        }

        vector<int>::iterator it1 = max_element(bloomDay.begin(),bloomDay.end());
        int right = *it1;

        vector<int>::iterator it2 = min_element(bloomDay.begin(),bloomDay.end());
        int left = *it2;

        while(left<=right) {

            if(ans == left) {
                break;
            }

            int mid = left + ((right-left)/2);

            int bouquet = 0;

            int count = 0;

            for(int i=0;i<n;i++) {
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

            if(bouquet >= m) {
                ans = mid;
                right = mid;
            }
            else {
                left = mid+1;
            }
        }

        return ans;
    }
};