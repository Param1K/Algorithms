#include<iostream>
using namespace std;
void equalSum(int arr[], int sz)
{
    int maxLen = 0;
    for(int i = 0; i < sz; i++)
    {
        for(int j = i + 1; j < sz; j += 2)
        {
            int len = j - i + 1;
            if(maxLen >= len)
                continue;
            int leftSum = 0;
            int rightSum = 0;
            for(int k = i; k < len/2; k++)
            {
                leftSum += arr[k];
                rightSum += arr[k + len/2];
            }
            if(leftSum == rightSum)
            {
                maxLen = len;
                cout<<maxLen<<endl;
                for(int k = i; k < len/2; k++)
                    cout<<arr[k]<<" "<<arr[k + len/2]<<endl;
            }
        }
    }
}

int main()
{
    int arr[10] = {1, 4, 2, 1, 2, 4, 5, 6};

    equalSum(arr, 10);

}
