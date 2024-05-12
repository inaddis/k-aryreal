#include "kary_heap.cpp"

void iterativeHeapSort(int arr[], int size) {
    KaryHeap heap(2); 
    for (int i = 0; i < size; ++i)
        heap.insert(arr[i]);

    for (int i = 0; i < size; ++i)
        arr[i] = heap.deleteMin();
}

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    int arr1[] = {12, 7, 9, 15, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {23, 56, 32, 11, 8, 2, 17};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    iterativeHeapSort(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

}
