int func(vector<vector<int>> &points,int n,int last,vector<vector<int>>& dp){
    int max_val = 0;
    int current_branch = 0;
    if(dp[n][last] != -1){
        return dp[n][last];
    }
    if(n==0){
        for(int i=0;i<3;i++){
            if(i!=last){
                max_val = max_val > points[0][i] ? max_val : points[0][i];
            }
        }
    }
    else{
        for(int i=0;i<3;i++){
            if(i!=last){
                current_branch = points[n][i] + func(points,n-1,i,dp);
            }
            max_val = max_val > current_branch ? max_val : current_branch;
        }
    }
    dp[n][last] = max_val;
    return dp[n][last];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1)); 
    int answer = func(points,n-1,3,dp);
    return answer;
}