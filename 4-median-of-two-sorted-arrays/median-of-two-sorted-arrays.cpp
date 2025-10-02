class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int m = nums1.size();
        int n = nums2.size();

        if(m<=n) {

            int left = 0,right = m;

            while(left<=right) {

                int cut1 = (left+right)/2;
                int cut2 = ((m+n+1)/2)-cut1;

                double l1 = (cut1==0 ? INT_MIN : nums1[cut1-1]);
                double r1 = (cut1==m ? INT_MAX : nums1[cut1]);
                double l2 = (cut2==0 ? INT_MIN : nums2[cut2-1]);
                double r2 = (cut2==n ? INT_MAX : nums2[cut2]);

                if(l1<=r2 && l2<=r1) {
                    if((m+n) % 2 == 0) {
                        return ((max(l1,l2) + min(r1,r2)) / 2.0);
                    }
                    else {
                        return max(l1,l2);
                    }
                }
                else if(l1>r2) {
                    right = cut1-1;
                }
                else {
                    left = cut1+1;
                }
            }
        }
        else {
            int left = 0,right = n;

            while(left<=right) {

                int cut1 = (left+right)/2;
                int cut2 = ((m+n+1)/2)-cut1;

                double l1 = (cut1==0 ? INT_MIN : nums2[cut1-1]);
                double r1 = (cut1==n ? INT_MAX : nums2[cut1]);
                double l2 = (cut2==0 ? INT_MIN : nums1[cut2-1]);
                double r2 = (cut2==m ? INT_MAX : nums1[cut2]);

                if(l1<=r2 && l2<=r1) {
                    if((m+n) % 2 == 0) {
                        return ((max(l1,l2) + min(r1,r2)) / 2.0);
                    }
                    else {
                        return max(l1,l2);
                    }
                }
                else if(l1>r2) {
                    right = cut1-1;
                }
                else {
                    left = cut1+1;
                }
            }
        }
        

        

        return 0;
    }
};