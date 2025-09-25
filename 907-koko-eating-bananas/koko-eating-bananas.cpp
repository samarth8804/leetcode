class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        auto it = max_element(piles.begin(),piles.end());
        int maxi = *it;

        int left = 1,right = maxi;

        int ans;

        while(left<=right) {
            int mid = left + ((right-left)/2);

            long long int time = 0;

            for(auto pile : piles) {
                time = time + ((pile + mid - 1)/mid);
            }

            if(time <= h) {
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid+1;
            }
        }

        return ans;
    }
};