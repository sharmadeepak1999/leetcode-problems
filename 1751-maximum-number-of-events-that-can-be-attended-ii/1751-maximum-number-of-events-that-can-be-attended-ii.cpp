class Solution {
public:
    vector<vector<int>> dp;
    int bs(vector<vector<int>>& arr,int idx)
    {
        int a=arr[idx][1];
        int l=idx+1;
        int h=arr.size()-1;
        int res=arr.size();
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(arr[m][0]>a)
            {
                res=m;
                h=m-1;
            }
            else l=m+1;
        }
        return res;
    }
    int func(vector<vector<int>>& arr,int idx,int k)
    {
        if(idx==arr.size() || k==0)return 0;
        if(dp[idx][k]!=-1)return dp[idx][k];
        int pick,npick;
        npick=func(arr,idx+1,k);
        int i=bs(arr,idx);
        pick=arr[idx][2]+func(arr,i,k-1);
        return dp[idx][k]=max(pick,npick);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        // memset(dp,-1,sizeof(dp));
        dp=vector<vector<int>>(events.size()+1,vector<int>(k+1,-1));
        return func(events,0,k);
    }
};
