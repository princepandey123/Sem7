
#include <bits/stdc++.h>
using namespace std;

// binomialCoeff(n - 1,k-1)+ binomialCoeff(n-1,k)

int binomialCoeff(int n, int k)
{
	
	if (k > n)
		return 0;
	if ((n-k)<k)
	     K=n-k;

        int dp[k+1];
        memset(dp,0,sizeof(dp));
         dp[0]=1;

        for (int i=1;i<=n;i++)
        { 
           for( int j= min(k,i);j>0;j--)
            {
               dp[j] = (dp[j] + dp[j-1])%1000000007;
             }
        }

	return dp[k];
        
}

int main()
{
	int n = 5, k = 2;
	cout << "Value of C(" << n << ", " << k << ") is "
		<< binomialCoeff(n, k);
	return 0;
}

