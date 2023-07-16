class Solution {
public:
    unordered_map<string , int> mp;
    vector<int> smp;
    int n , m;
    long long help(int skillMask , int i , vector<vector<long long>> & dp){
        if(skillMask == 0) return 0;
        if(i < 0) return (1LL << n) - 1;
        if(dp[i][skillMask] != -1) return dp[i][skillMask];
        long long ans = ((1LL << n) - 1);
        int reqSkills = skillMask & (~smp[i]);
        long long take = (1LL << n) - 1;
        if(reqSkills != skillMask){
            take = help(reqSkills , i-1 , dp) | (1LL << i);
        }
        long long nottake = help(skillMask , i-1 , dp);
        if(__builtin_popcountll(take) <= __builtin_popcountll(nottake)) return dp[i][skillMask] = take;
        return dp[i][skillMask] = nottake;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        n = people.size();
        m = req_skills.size();
        for(int i = 0 ; i < m ; i++){
            mp[req_skills[i]] = i;
        }
        smp.resize(n);
        for(int i = 0 ; i < n ; i++){
            int mask = 0;
            for(auto & skills : people[i]){
                mask |= (1 << mp[skills]);
            }
            smp[i] = mask;
        }
        vector<vector<long long>> dp(n , vector<long long>(1<<m , -1));
        long long ans = help((1 << m) - 1 , n-1 , dp);
        vector<int> a;
        for(int i = 0 ; i < n ; i++){
            //pushing all those index which brings the minimum value
            if(ans & (1LL << i)) a.push_back(i);
        }
        return a;
    }
};
