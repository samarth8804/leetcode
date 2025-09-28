class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();

        int left = k;

        int right = arr[n-1] + k;

        while(left <= right) {

            int mid = left + ((right-left)/2);

            int pos=0;

            int i;

            for(i=0;i<n;i++) {
                if(arr[i] == mid) {
                    break;
                }
                else if(arr[i] > mid) {
                    pos = mid - i;
                    break;
                }
            }

            if(i==n) {
                pos = mid - n;
            }

            if(pos==0) {
                if(arr[i]-i-1 < k) {
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
            else {
                if(pos == k) {
                    return mid;
                }
                else if(pos<k) {
                    left = mid + 1;
                }
                else {
                    right = mid-1;
                }
            }
        }

        return 0;
    }
};