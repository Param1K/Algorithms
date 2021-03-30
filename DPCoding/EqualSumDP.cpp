#include<iostream>
/*
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
}*/

int mTab[6][21];
int subsetSum(int wt[], int sum, int n)
{
    for(int j=0; j<=sum; j++)
        mTab[0][j] = 0; //FALSE
    for(int i=0; i<=n; i++)
        mTab[i][0] = 1; //TRUE
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; j++)
        {
            //if((i==0)||(j==0))
              //  mTab[i][j] = 0;
            if((wt[i-1]) <= j)
                mTab[i][j] = mTab[i-1][j - wt[i-1]] || mTab[i-1][j];
            else
                mTab[i][j] = mTab[i-1][j];
        }
    }
    return mTab[n][sum];
}

int isSubsetSumRec(int wt[], int sum, int n)
{
    if(n==0)
        return 0;
    if(sum==0)
        return 1;

    if(wt[n-1] > sum)
        return isSubsetSumRec(wt, sum, n-1);
    return isSubsetSumRec(wt, sum, n-1) || isSubsetSumRec(wt, sum-wt[n-1], n-1);
}

int main(){
    int wt[] = {2,3,7,12,10};
    int sum = 10;
    std::cout<<subsetSum(wt, 2*sum, 5)<<std::endl;
    std::cout<<isSubsetSumRec(wt, 2*sum, 5)<<std::endl;
    int wt2[] = {2,3,7,9,10};
    std::cout<<isSubsetSumRec(wt2, 2*sum, 5);
}
