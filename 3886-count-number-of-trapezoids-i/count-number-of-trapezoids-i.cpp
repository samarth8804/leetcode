class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {

        int m = points.size();
        int n = points[0].size();

        unordered_map<int, int> groups;

        for (int i = 0; i < m; i++) {
            groups[points[i][1]]++;
        }

        long long sum = 0;

        for(auto &p : groups) {

            long long combinations =  ((1LL * p.second * (p.second-1))/2);
            p.second = combinations;
            sum += 1LL * combinations;
        }

        long long result = 0;

        for(auto it1=groups.begin();it1!=groups.end();it1++) {

            result += 1LL * (it1->second * (sum - it1->second));
            sum -= it1->second;
        }

        const long long MOD = 1000000007;
        

        return result % MOD;
    }
};