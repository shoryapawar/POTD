int solve(int num1,int num2)
    {   
       //sieve start
        int max_num = 9999;
        vector<int> prime(10001, 1);
        prime[1] = 0;
        for(int i = 2; i*i <= max_num; i++){
            if(prime[i]){
                for(int j = i*i; j <= max_num; j += i){
                    prime[j]=0;
                }
            }
        }
        //sieve end
        
        vector<int> dp(10001,-1),vis(10001);
        
        queue<int> q;
        q.push(num1);
        
        dp[num1]=0 ; vis[num1] =0;
        
        // BFS
        while(!q.empty()){
            int num = q.front();
            q.pop();
            
            if(vis[num]) continue;
            vis[num] = 1;
            
            string s = to_string(num);
            
            for(int i =0 ; i<4 ;i++){   // 4 digit number
                for(char c='0'; c<='9' ; c++){
                    
                    if(c == s[i] or (c == '0' and i == 0)){ // skipping zero or same number
                        continue;
                    }
                    
                    string next = s; 
                    next[i]=c; // changing a single digit
                    int next_num = stoi(next);
                     // checking is prime and also it's value should not be changed again bcz we are using queue and 
                     // BFS the first one is smallest always
                    if(prime[next_num] and dp[next_num] ==-1){
                          dp[next_num] = 1 + dp[num]; // adding 1 to path
                          q.push(next_num);// pushing the new num in queue
                    }
                    
                    // if next-num matches with destanation num2
                    if(next_num==num2) return dp[next_num];
                    
                }
            }
        }
        return dp[num2];
    }
