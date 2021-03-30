/*  DP Problem - N*N order matrix, No. of ways to move from Top Left cell to Bottom Right cell.
 *               Movement allowed only down I and right
 *
 *                                       (00)
 *                                     /       \
 *                                   (1,0)     (0,1)
 *                                  /    \     /   \
 *                               (2,0)  (1,1) (1,1) (0,2)
 */

#include<iostream>

using namespace std;
int R = 0;
int C = 0;
int pathCount(int rows, int cols)
{
    cout<<"calculate cost of "<< rows << ", "<<cols<<endl;
    if((rows == R - 1) && (cols == C - 1))
        return 1;
    if((rows == R - 1) || (cols == C - 1))
        return 1;
    return pathCount(rows + 1, cols) + pathCount(rows, cols + 1);
}

int pathCountMM(int *mem, int rows, int cols)
{
    int *cost = (mem + (rows - 1) *  C +   cols);
    if(*cost >= 0)
        return *cost;
    cout<<"calculate cost of "<< rows << ", "<<cols<<endl;
    if((rows == R - 1) && (cols == C - 1))
        return 1;
    if((rows == R - 1) || (cols == C - 1))
        return 1;
    *cost = pathCountMM(mem, rows + 1, cols) + pathCountMM(mem, rows, cols + 1);
    return *cost;
}
int pathCountRL(int rows, int cols)
{
    if((rows == 0) && (cols == 0))
        return 0;
    if((rows == 0) || (cols == 0))
        return 1;
    return pathCountRL(rows - 1, cols) + pathCountRL(rows, cols - 1);
}
int main(int argc, char *argv[])
{
    /*if(argc < 2){
        cout<<"usage : ./path <Matrix Rows> <Matrix Columns>"<<endl;
        return -1;
    }*/
    
    R = *argv[1] - '0';
    C = *argv[2] - '0';

    int *mem = (int *)malloc(sizeof(int) * R * C);
    memset(mem, -1, sizeof(int) * R * C);

    cout<<"LR Total Paths for "<<R<<" X "<<C<<" Matrix are : "<<pathCount(0, 0)<<endl;
    cout<<"RL Total Paths for "<<R<<" X "<<C<<" Matrix are : "<<pathCountRL(R - 1, C - 1)<<endl;
    cout<<"MM Total Paths for "<<R<<" X "<<C<<" Matrix are : "<<pathCountMM(mem, 0, 0)<<endl;
    free(mem);
}
