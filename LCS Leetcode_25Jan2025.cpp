 int solve(int i , int j,string &text1, string &text2, vector<vector<int>> &dp){
        //base case
        if( i<0 || j<0){
            return 0;
        }
        // code
        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(i-1,j-1,text1,text2,dp);
        }
        
           return dp[i][j]= max(solve(i-1,j,text1,text2,dp),// only i+1
                                  solve(i,j-1,text1,text2,dp));// only j+1
        
        
    }

    int longestCommonSubsequence(string text1, string text2) {
        // if(text1==text2) return text1.size();
        // int n = text1.size() , m = text2.size();

        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return solve(n-1,m-1,text1,text2,dp);
      int n = text1.size() , m = text2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // tabulation 
        // base cases
            for(int i =0 ; i<=n ; i++) dp[i][0] = 0;
            for(int i =0 ; i<=m ; i++) dp[0][i] = 0;

          for( int i =1 ; i <=n ;i++){
              for( int j =1 ; j<=m ; j++){
                if(text1[i-1] == text2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                }
                else 
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);     
              }
          }
        return dp[n][m];
    }
