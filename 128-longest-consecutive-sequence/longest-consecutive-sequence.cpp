class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        
        unordered_set<int> cons;
        int longestSeq = 0;
        int n = nums.size();

        

        for(int i=0;i<n;i++) {
            if(!cons.count(nums[i])) {
                cons.insert(nums[i]);
            }
        }


        for(unordered_set<int>::iterator it = cons.begin();it!=cons.end();++it) {
            
        int currentSeq = 0;

            if(cons.count(*it-1)) {
                continue;
            }
            else {
                int i = 0;
                while(cons.count(*it+i)) {
                    currentSeq++;
                    i++;
                }
                longestSeq = max(currentSeq,longestSeq);
            }
        }

        return longestSeq;
    }
};