#include <stdio.h>
#include <math.h>
// From: https://www.cnblogs.com/onepixel/p/7674659.html
void swap(int& a, int& b) {
    int tmp = b;
    b = a;
    a = tmp;
}
//stable
//complexity: o(n2)
int bubbleSort(int* array, int length) {
    //the first loop: need find max numbers num
    for (int i = 0; i < length - 1; i++) {
        //the second loop: compare each other
        for (int j = 0; j < length - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
    return 0;
}
//not stable
//complexity: o(n2)
int selectSort(int* array, int length) {
    int min = 0;
    int min_pos = 0;
    for (int i = 0; i < length - 1; i++) {
        min = array[i];
        min_pos = i;
        for (int j = i+1; j < length; j++) {
            if (array[j] < min) {
                min_pos = j;
                min = array[j];
            }
        }
        if (min != array[i]) {
            swap(array[i], array[min_pos]);
        }
    }
}
// stable
//complexity: o(n2)
int insertionSort(int* array, int length) {
    for(int i = 1; i < length; i++) {
        int preIndex = i - 1;
        int current = array[i];
        while (preIndex >= 0 && array[preIndex] > current) {
            array[preIndex+1] = array[preIndex];
            preIndex--;
        }
        array[preIndex+1] = current;
    }
    return 0;
}
//not statble
//complexity: o(nlogn)
int shellSort(int* array, int length) {
    for (int gap = floor(length / 2); gap > 0; gap = floor(gap / 2)) {
        for (int i = gap; i < length; i++) {
            int preIndex = i - gap;
            int current = array[i];
            while (preIndex >= 0 && array[preIndex] > current) {
                array[preIndex + gap] = array[preIndex];
                preIndex -= gap;
            }
            array[preIndex + gap] = current;
        }
    }
    return 0;
}
void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
}
//stable
//complexity:o(nlogn)
void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        //Divide and Conquer
        mergeSort(array, left, mid);
        mergeSort(array, mid+1, right);
        //Combine
        merge(array, left, mid, right);
    }
}
int partition(int* array, int left, int right) {
    //select left as pivot
    int pivot = left;
    int index = pivot + 1;
    for (int i = index; i <= right; i++) {
        if (array[i] < array[pivot]) {
            swap(array[i], array[index]);
            index++;
        }
    }
    swap(array[pivot], array[index-1]);
    //select right as pivot
    /*int pivot = right;
    int index = pivot - 1;
    for (int i = index; i >= 0; i--) {
        if (array[i] > array[pivot]) {
            swap(array[i], array[index]);
            index--;
        }
    }
    swap(array[pivot], array[index+1]);*/
    return index-1;
}
void quickSort(int* array, int left, int right) {
    if (left < right) {
        int pi = partition(array, left, right);
        quickSort(array, left, pi - 1);
        quickSort(array, pi + 1, right);
    }
}
void printArray(int* array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main(){
    int array[] = {3,-1,9,8,10,100,20,30,-13,15,16};
    int length = sizeof(array) / sizeof(int);
    printf("before sort: ");
    printArray(array, length);
    // bubbleSort(array, length);
    // selectSort(array, length);
    // insertionSort(array, length);
    // shellSort(array, length);
    // mergeSort(array, 0, length);
    quickSort(array, 0, length - 1);
    printf("after sort: ");
    printArray(array, length);
    return 0;
}
