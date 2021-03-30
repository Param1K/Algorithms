/*
 *  Cutting Rod to bring maximum profit while selling
 *  This is a 0-1 Knapsack problem
 *  Price array -> int p[] = {0, 1, 5, 8, 10, 13, 17, 18, 22, 25,30};
 *  N = 10 // 10 meter rod
 *  Max { P[N-1],
 *        P[1] + P[N-1-1]
 *        P[2] + P[N-1-2]
 *          ...
 *          ... 
 *        P[N-1] + P[N-1-(N-1)]}
 */

#include<iostream>
using namespace std;

#define MAX(a,b) ((a)>(b))?(a):(b)


int cutRodMemoised(int p[], int n, int m[])
{
    if(m[n] >= 0)
        return m[n];
    if(n==0)
        return n;
    int q = -1;
    for (int i = 1; i <= n; i++)
        q = MAX(q, p[i] + cutRodMemoised(p, n-i, m));
    m[n] = q;
    return q;
}

int cutRod(int p[], int n)
{
    if(n==0)
        return n;
    int q = -1;
    for (int i = 1; i <= n; i++)
        q = MAX(q, p[i] + cutRod(p, n-i));
    return q;
}
/*
 *  Bottom up approach.
 *  1       2       3       4       5       6
 *  -------->i
 *  -------->j
 *  ---------------->i
 *  -------->j------>j
 *  ------------------------>i
 *  -------->j------->j----->j
 *
 *
 */
int cutRodBottomUp(int p[], int n)
{
    int val[12] = {0};
    for(int i = 1; i <= n; i++){
        int q = -1;
        for(int j = 0; j <= i; j++)
            q = MAX(q, p[j] + val[i - j]);
        val[i] = q;
    }
    return val[n];
}

int main()
{
    //int p[] = {0, 1, 5, 8, 10, 13, 17, 18, 22, 25,30};
    int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20};
    int m[11];
    for(int i = 0; i < 11; i++)
        m[i] = -1;
    cout<<cutRod(p, sizeof(p)/sizeof(int) - 1)<<endl;
    cout<<cutRodMemoised(p, sizeof(p)/sizeof(int) - 1, m)<<endl;
    cout<<cutRodBottomUp(p, sizeof(p)/sizeof(int) - 1)<<endl;
}
