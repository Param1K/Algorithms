#include<iostream>
#define MAX(a,b) ((a) > (b)?(a):(b))

using namespace std;
int longestCSQ(int *arr1, int *arr2, int m, int n){
	int count = 0;
	if(!m || !n)
		return 0;
	if(arr1[m-1] == arr2[n-1])
		return 1+longestCSQ(arr1, arr2, m-1, n-1);
	else
		return max(longestCSQ(arr1, arr2, m-1, n), longestCSQ(arr1, arr2, m, n-1));
}
int main()
{
	int arr1[6] = {1,4,7,9, 11,13};
	int arr2[5] = {4,3,7,10, 11};
	cout<<longestCSQ(arr1, arr2, 6, 5);
}