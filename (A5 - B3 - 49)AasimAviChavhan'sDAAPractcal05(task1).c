#include <stdio.h>
#include <string.h>
#define MAX 100

int main() 
{
    char X[] = "AGCCCTAAGGGCTACCTAGCTT";
    char Y[] = "GACAGCCTACAAGCGTTAGCTTG";
    int m = strlen(X);
    int n = strlen(Y);

    int dp[MAX][MAX];
    int i, j;

    for (i = 0; i <= m; i++) 
    {
        for (j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0) 
            {
                dp[i][j] = 0;
            } 
            else if (X[i - 1] == Y[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else 
            {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ?
                            dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    printf("Cost Matrix:\n");
    for (i = 0; i <= m; i++) 
    {
        for (j = 0; j <= n; j++) 
        {
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }

    i = m; 
    j = n;
    char lcs[MAX];
    int index = dp[m][n];
    lcs[index] = '\0';

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) 
        {
            lcs[index - 1] = X[i - 1];
            i--; j--; index--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) 
        {
            i--;
        } 
        else 
        {
            j--;
        }
    }

    printf("\nLength of LCS: %d\n", dp[m][n]);
    printf("LCS: %s\n", lcs);

    return 0;
}
