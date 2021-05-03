#include <stdio.h>

#define ARRY_SIZE 10
#define LEFT(i) (2*(i+1) -1)
#define RIGHT(i) (2*(i+1))
#define Parent(i) ((i+1)/2 -1)

int heapSize = ARRY_SIZE;

void maxHeapify (int *heap, int index)
{
    int largest = index;
    int tmp = 0;
    int left = LEFT(index);
    int right = RIGHT(index);

    printf(" maxHepify index %d, element %d\n", index, heap[index]);
    if ((left < heapSize) && (heap[left] > heap[index])){
        largest = LEFT(index);    
    }
    if ((right < heapSize) && (heap[right] > heap[largest])) {
        largest = RIGHT(index);    
    }
    
    if(index != largest) {
        printf("------------>exchange %d [%d]<-> %d[%d]------------\n", 
                index, heap[index], largest, heap[largest]);
        tmp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = tmp;
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(int *heap)
{
    int index = 0;
    for (index = (heapSize / 2) - 1; index >= 0; index--) {
        maxHeapify(heap, index);
    }
}

void print_heap (int *heap)
{   
    int index = 0;
    while(index < ARRY_SIZE) {
        printf("%d  ", heap[index++]);
    }
    printf("\n");
}

int main(void) 
{
    int index, tmp;
    //int heap[ARRY_SIZE] = {10,9,8,7,1,2,6,3,4,5};	
    int heap[ARRY_SIZE] = {4,1,3,2,16,9,10,14,8,7};
    print_heap(heap);
    buildMaxHeap(heap);
    print_heap(heap);
    printf(" Heap sorting Begins\n");
    for (index = ARRY_SIZE -1; index > 0; index--) {
        tmp = heap[0];
        heap[0] = heap[index];
        heap[index] = tmp;
        heapSize--;
        maxHeapify(heap, 0);
        print_heap(heap);
    }
    printf(" Heap sorting done\n");
    print_heap(heap);
}
