int minCost(vector<vector<int> >& costs,
      int N)
{
  // Corner Case
  if (N == 0)
    return 0;
	int dp[3][3] = {0}; 
  	dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
  	dp[0][2] = costs[0][2];
  	for(int i=1; i<costs.size(); i++){
    	dp[i][0] = costs[i][0] + min(dp[i-1][1],dp[i-1][2]);
      	dp[i][1] = costs[i][1] + min(dp[i-1][0],dp[i-1][2]);
      	dp[i][2] = costs[i][2] + min(dp[i-1][0],dp[i-1][1]);
    }
  cout<<min(dp[2][0],min(dp[2][1],dp[2][2]));
}
