class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> p_max(n),s_max(n);

        p_max[0] = height[0];

        for(int i=1;i<n;i++) {
            p_max[i] = max(p_max[i-1],height[i]);
        }

        s_max[n-1] = height[n-1];

        for(int i=n-2;i>=0;i--) {
            s_max[i] = max(s_max[i+1],height[i]);
        }

        int total = 0;

        for(int i=0;i<n;i++) {
            int left_max = p_max[i];
            int right_max = s_max[i];

            if(height[i]<left_max && height[i]<right_max) {
                total += min(left_max,right_max) - height[i];
            }
        }

        return total;
    }
};