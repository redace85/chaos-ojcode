#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int numTrees(int n) {
    int dp[n+1];
    dp[0]=dp[1]=1;

    for (int i=2; i<=n; i++) {
        dp[i] = 0;
        for (int j=1;j<=i;j++) {
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}

int main(){
	printf("num %d\n", numTrees(3));
}

