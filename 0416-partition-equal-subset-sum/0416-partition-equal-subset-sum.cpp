class Solution {
public:
    bool helper(vector<int> arr, int k){
        int n = arr.size();
        vector<vector<int>> dp;
        dp.resize(205,vector<int>(20005,false));

        for(int i=0; i<n; i++) dp[i][0] = true;

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=k; j++){
                if(arr[i]<=j){
                    dp[i][j] = dp[i+1][j] || dp[i+1][j-arr[i]];
                }else{
                    dp[i][j] = dp[i+1][j];
                }
                
            }
        }
        return dp[0][k];
    }
    bool canPartition(vector<int>& arr) {

        int n = arr.size();

        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
        }

        if(sum%2!=0) return false;
        else return helper(arr,sum/2);
        
    }
};