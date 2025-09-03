class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        
        set<int> cons;
        int longestSeq = 1;
        int currentSeq = 1;
        int n = nums.size();

        if(n==0) {
            return 0;
        }

        for(int i=0;i<n;i++) {
            if(!cons.count(nums[i])) {
                cons.insert(nums[i]);
            }
        }

        set<int>::iterator prev = cons.begin();

        for(set<int>::iterator it = ++cons.begin();it!=cons.end();++it) {

            if(*prev+1 == *it) {
                currentSeq++;
            }
            else {
                if(currentSeq>longestSeq) {
                    longestSeq = currentSeq;
                }
                currentSeq = 1;
            }
            prev = it;
        }

        longestSeq = max(currentSeq,longestSeq);
        return longestSeq;
    }
};