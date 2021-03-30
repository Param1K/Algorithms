#include<iostream>
using namespace std;
int MAX(int a, int b)
{
    return (a>b)?a:b;
}
int mTab[4][51]; 
int knapsackMem(int wt[], int val[], int W, int n)
{
    if((n==0)||(W==0))
        return 0;
    if(mTab[n][W] >= 0){
       return mTab[n][W];
    }
    if((W -wt[n]) < 0)
        mTab[n][W] = knapsackMem(wt, val, W, n-1);
    mTab[n][W] = MAX(val[n] + knapsackMem(wt, val, W-wt[n], n-1),
                knapsackMem(wt, val, W, n-1));
    return mTab[n][W];
}

int knapsack(int wt[], int val[], int W, int n)
{
    if((n==0)||(W==0))
        return 0;
    if((W -wt[n]) < 0)
        knapsack(wt, val, W, n-1);
    return MAX(val[n] + knapsack(wt, val, W-wt[n], n-1),
                knapsack(wt, val, W, n-1));
}


int knapsackBottomup(int wt[], int val[], int W, int n)
{
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j <= W; j++)
        {
            if((i==0)||(j==0))
                mTab[i][j] = 0;
            //else if((j - wt[i-1]) >= 0)
            else if((wt[i-1]) <= j)
                mTab[i][j] = MAX(val[i-1] + mTab[i-1][j - wt[i-1]], mTab[i-1][j]);
            else
                mTab[i][j] = mTab[i-1][j];
        }
    }
    return mTab[n][W];
}


int main()
{
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int W = 50;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 51; j++)
            mTab[i][j] = -1;
           /* if((!i)||(!j))
                mTab[i][j] = 0;
            else
                mTab[i][j] = -1;*/
    cout<<knapsack(wt, val, W, 2)<<endl;
    cout<<knapsackMem(wt, val, W, 2)<<endl;
    for(int i = 0; i <= 3; i++)
        for(int j = 0; j <= 50; j++)
            mTab[i][j] = -1;
    cout<<knapsackBottomup(wt, val, W, 3)<<endl;
}
