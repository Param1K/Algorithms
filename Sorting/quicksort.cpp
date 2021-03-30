#include<iostream>
void swap(int *i, int *j){
	std::cout<<"i = " <<*i <<"  j =  "<<*j<<'\n';
	int temp = *j;
	*j = *i;
	*i = temp;
}

int partition(int *arr, int l, int r)
{
	int p = arr[l];
	int i = l+1;
	int j = i+1;
	for(;j <= r; j++){
		if(arr[j] < p){
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[l], &arr[i]);
	return i;
}

void quickSort(int *arr, int l, int r){
	if(l < r) {
		int p = partition(arr, l, r);
		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, r);
	}
}

int main(){
	int arr[10] = {3,2,1,5,4,9,8,7,6,10};
	int i = 0;
	quickSort(arr, 0, 9);
	while(i< 10)
		std::cout<<arr[i++]<<"  ";
}