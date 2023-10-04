#include <iostream>

using namespace std;

int main()
{
    int n; 
    
    cin >> n; 
    
    long long *dp = new long long[n+1];
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2; 
    
    int divide = 10007; 

    
    for (int i=3; i<=n; i++) {
        dp[i] = (dp[i-1] % divide)  + (dp[i-2] % divide) ;
    }
    
    cout << (dp[n]) % 10007 << endl;
    delete[] dp; 

    return 0;
}
