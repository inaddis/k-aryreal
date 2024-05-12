#include <vector>
#include <iostream>

class KaryHeap {
  private: 

    std::vector<int> heap;
    int k;

    int parent(int i) { return (i - 1) / k; }
    int kthChild(int i, int j) { return k * i + j + 1; }

    void heapifyUp(int i) {
        int temp = heap[i];
        while (i > 0 && temp < heap[parent(i)]) {
            heap[i] = heap[parent(i)];
            i = parent(i);
        }
        heap[i] = temp;
    }

    void heapifyDown(int i) {
        int child;
        int temp = heap[i];
        while (kthChild(i, 0) < heap.size()) {
            child = minChild(i);
            if (heap[child] < temp)
                heap[i] = heap[child];
            else
                break;
            i = child;
        }
        heap[i] = temp;
    }

    int minChild(int i) {
        int bestChild = kthChild(i, 0);
        int kChild = kthChild(i, k - 1);
        if (kChild < heap.size()) {
            for (int j = 1; j < k; j++) {
                if (kthChild(i, j) < heap.size() && heap[kthChild(i, j)] < heap[bestChild])
                    bestChild = kthChild(i, j);
            }
        }
        return bestChild;
    }

  public: 

    KaryHeap(int k_val) : k(k_val) {}

    void insert(int element) {
        heap.push_back(element);
        heapifyUp(heap.size() - 1);
    }

    int deleteMin() {
        if (heap.size() == 0)
            throw std::out_of_range("Heap is empty");
        int minElement = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);
        return minElement;
    }

    void heapify() {
        for (int i = (heap.size() - 2) / k; i >= 0; --i)
            heapifyDown(i);
    }

    void printHeap() {
        for (int i : heap)
            std::cout << i << " ";
        std::cout << std::endl;
    }

};
