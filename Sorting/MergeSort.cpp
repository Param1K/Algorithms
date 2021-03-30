
/**.     Prepare a recursion tree
** Each level j has 2 power j sub problems and (n/(2 power j)) size of sub problem 
** recursion tree has Leaf node log2n 
** Number of subproblems doubling at each level
** Each level has half of input size of the previous level
** Work done at level j==> 2J * 6(n/2j) = 6n //Independant of level j
** Work done For all levels collectively = 6n* (log2n +1) //1 is for level 0
**.                Running time complexity = 6n log2n + 6n.    
**         	Insertion sort complexity - 1/2 n square
** 		below data size 90, insertion sort is faster
** 		Above 90, Merge sort is lot faster
**		Highly tunable version of Merge sort switches to insertion sort when problem size drops below 90
**.            Libraries use insertion sort in merge sort when input size becomes less than 90

==============FAST ALGORITHM=======================
==>	Worst cose running time grows slowly with input size
==> Find the sweet spot with large and small input size
==> Retain the predicting power with input growth

==============3 BIASES/ASSUMPTIONS/GUIDING PRINCIPLES =======
1==> Worst case analysis 
   =>(worst-­‐case running time grows slowly with input size)
   => Average case analysis
   => Bench Mark inputs

2==> Won't pay attention to constant factors, lower order terms
  => Much easier
  => Constant depend on Architecture/compiler/Programmer
  => Lose very little predicting power

3==> Asymptotic Analysis
	=> Focus on running time on large input sizes
	=> Merge Sort 6nlog2n.  Insertion sort 1/2n2
	=> Bias is that we are focusing on larg n
	-> Focus Only large input size because those are the only problems which are interesting
		sort 100 numbers happens instantly by all algorithms and no. need to learn divide and conquor
	=> growing computing power and data set together

=========Asymptotic Analysis
------> Suppressing constant factors and lower order terms
	=>  6n log2n + 6n (Lower order term 6n going more slower than nlog2n )
	=> Suppress constant factor 6
	=> After those two suppression, we are left with much simpler suppression nlog2n
	=> Running time is ["Big Oh" of  nlog2n]
**/
#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void LowMemMerge(int *arr, int start, int end)
{
	int mid = (start + end)/2;
	int j = mid+1;
	for(int i=start; i <= mid; i++)
	{
		if(arr[i] > arr[j]) {
			swap(&arr[i], &arr[j]);
			/*{10, 2,3,4,11,15}*/
			int r = j;
			while(r < end){
				if(arr[r] > arr[r+1]){
					swap(&arr[r], &arr[r+1]);
					r++;
				} else{
					break;
				}
			}
		}	
	}
}
void merge(int *arr, int start, int mid, int end)
{
	int left[mid-start+1];
	int right[end-mid];
	int len = end-start+1;
 
	/* Copy left subarray */
	for(int i = start; i<= mid; i++)
		{left[i-start] = arr[i]; cout<<left[i-start]<<" ";}
	cout<<"\t";
	/* Copy right subarray */
	for(int i = mid+1; i<=end; i++)
		{right[i-mid-1] = arr[i]; cout<<right[i-mid-1]<<" ";}
	cout<<endl;
	/* Actual merge routine */
	int i =0;
	int j=0;
	int k=start;
	
	for(; k<=end;k++){
		if((left[i]<=right[j])&& i <=mid) {
			arr[k]=left[i];
			i++;
		} else {
			arr[k]=right[j];
			j++;
		}
	}
}

void mergeSort(int * arr, int start, int end)
{
	int mid = (start + end)/2;
	if(end > start) {
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}
int main()
{
	int arr[10] = {5,10,3,2,8,1,9,7,4,6};
	for(int i=0; i<10; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	mergeSort(arr, 0, 9);
	for(int i=0; i<10; i++)
		cout<<arr[i]<<" ";
}