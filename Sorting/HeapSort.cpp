#include<iostream>
#define LEFT(i)	((i+1)*2 -1)
#define RIGHT(i)	((i+1)*2)
void Heapify(int * arr, int i, int n){

	int l = LEFT(i);
	int r =RIGHT(i);
	int largest = i;

	if((l < n) && (arr[i] < arr[l]))
		largest = l;
	if((r< n) && (arr[i] < arr[r]))
		largest = r;
	if(largest != i){
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		Heapify(arr, largest ,  n);
	}



}
void MAXHeap(int * arr, int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
	{
		Heapify(arr, i, n);
	}
	
}

int main()
{
	//int arr[10] = {3,2,1,5,4,6,9,8,7,10}; 
	//int arr[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1}; 
	int arr[11] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7,11}; 
	MAXHeap(arr, 11);
	for(int i = 0; i< 11; i++)
		std::cout<<arr[i]<<"    ";

}