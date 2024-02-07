class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int totSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            totSum += arr[i];
        }
        
        if(totSum % 2 == 1)
                return false;
        
        int k = totSum/2;
        
        vector<bool> prev(k+1, false);
        
        prev[0] = true;
        
        if(arr[0] <= k)
            prev[arr[0]] = true;
    
        for(int i = 1; i < n; i++){
            vector<bool> curr(k+1,false);
            curr[0] = true;
            
            for(int t = 1; t <= k; t++)
            {
                bool notTaken = prev[t];
                
                bool taken = false;
                
                if(arr[i] <= t)
                    taken = prev[t - arr[i]];
                
                curr[t] = notTaken || taken;
            }
            
            prev = curr;
        }
        
        return prev[k];
        
    }
};