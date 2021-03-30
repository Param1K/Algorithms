/*  Dynamic Programming Problem - 
    There are n stations in a route starting 0 to N-1.
    Train moves only in forward direction.
    Calculate minimum cost of travel between 0 to N-1 station
*/
/*
        Design(By taking N = 4)
    --------------------------------
    1       2       3       4

    Min(
        Cost(0,3) //direct,
        Cost(0,1) + Cost(1,3),
        Cost(0,2) + Cost(2,3)
    
    )
    // Generalised Version  //
    Min(
        Cost(0,N-1) //direct,
        Cost(0,1) + Cost(1,N-1),
        Cost(0,2) + Cost(2,N-1)
        Cost(0,3) + Cost(3,N-1)


        Cost(0,N-3) + Cost(N-3,N-1)
        Cost(0,N-2) + Cost(N-2,N-1)
    )
*/
#include<iostream>

using namespace std;

    int cost[5][5] = {
                    {0, 10, 75, 94, 200},
                    {-1, 0, 35, 50, 180},
                    {-1, -1, 0, 80, 100},
                    {-1, -1, -1, 0, 50},
                    {-1, -1, -1, -1, 0},
                    };
int MIN(int x,int y)    
{
    return ((x < y) ? x : y);
}

int MINCost(int s, int d){
    cout<<"Computing MINCost(" <<s<<", "<<d << ")"<<endl;
    if((s == d) || (s == d-1))
        return cost[s][d];
    int minc = cost[s][d];
    for(int i = s + 1; i < d; i++)
        minc = MIN(minc, MINCost(s,i) + MINCost(i, d));
    return minc;
}

int MemoisedMINCost(int mTab[][5], int s, int d){
    if((s == d) || (s == d-1))
        return cost[s][d];
    if(mTab[s][d] > 0)
        return mTab[s][d];
    cout<<"Computing MINCost(" <<s<<", "<<d << ")"<<endl;
    int minc = cost[s][d];
    for(int i = s + 1; i < d; i++)
        minc = MIN(minc, MemoisedMINCost(mTab, s,i) + MemoisedMINCost(mTab, i, d));
    mTab[s][d] = minc;
    return minc;
}

int minCostBottomUp(int n)
{
    int val[6] = {0};
    val[1] = cost[0][1];
    for(int i = 2; i <= n; i++)
    {
        val[i] = cost[0][i];
        for(int j=1; j<=i; j++)
            val[i] = MIN(val[i], val[j] + cost[j][i]);
    }
    return val[n];
}

int main()
{
    int mtable[5][5] = {0};
    mtable[0][0] = 0;
    mtable[4][4] = 0;
    int mcost = MINCost(0, 4);
    cout<<"Recursive Min Cost = " <<mcost<<endl;
    cout<<"Memoised Min Cost Processing " <<endl;
    mcost = MemoisedMINCost(mtable, 0, 4);
    cout<<"Memoised Min Cost = " <<mcost<<endl;
    cout<<"BottomUp : "<<minCostBottomUp(4)<<endl;
}
