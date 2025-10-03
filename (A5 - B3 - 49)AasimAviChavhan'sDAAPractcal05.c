#include <stdio.h>
#include <string.h>

typedef struct 
{
    int val;
    char dir;
} Cell;

void printLRS(char *s, int n) 
{
    Cell c[n+1][n+1];

    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0) 
            {
                c[i][j].val = 0;
                c[i][j].dir = '0';
            }
            else if (s[i-1] == s[j-1] && i != j) 
            {
                c[i][j].val = 1 + c[i-1][j-1].val;
                c[i][j].dir = 'm';
            }
            else 
            {
                if (c[i-1][j].val >= c[i][j-1].val) 
                {
                    c[i][j].val = c[i-1][j].val;
                    c[i][j].dir = 'u';
                } 
                else 
                {
                    c[i][j].val = c[i][j-1].val;
                    c[i][j].dir = 'l';
                }
            }
        }
    }

    printf("\nCost Matrix (val,dir):\n");
    for (int i = 0; i <= n; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            printf("%2d%c ", c[i][j].val, c[i][j].dir);
        }
        printf("\n");
    }

    int index = c[n][n].val;
    printf("\nLength of LRS = %d\n", index);

    char lrs[index+1];
    lrs[index] = '\0';
    int i = n, j = n;
    while (i > 0 && j > 0) 
    {
        if (c[i][j].dir == 'm') 
        {
            lrs[index-1] = s[i-1];
            i--; j--; index--;
        }
        else if (c[i][j].dir == 'u') 
        {
            i--;
        }
        else 
        {
            j--;
        }
    }

    printf("LRS = %s\n", lrs);
}

int main() 
{
    char s[] = "AABEBCDD";
    int n = strlen(s);

    printf("Given String: %s\n", s);
    printLRS(s, n);

    return 0;
}
