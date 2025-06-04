#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper function to heapify up (used during insertion)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2; //Find the parent index IMP 2 as its A Heap is a complete binary tree.
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to heapify down (used during deletion)
    void heapifyDown(int index) {
        int size = heap.size();
        // this is heapify Algorithm
        while (index < size) {
            int left = 2 * index + 1; // Finds the index of the left child of the current node.
            int right = 2 * index + 2; //Finds the index of the right child of the current node.
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    // Insert element into heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1); //passing index of new element
    }

    // Delete root element (max element)
    void deleteRoot() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Deleted element: " << heap[0] << endl;
        heap[0] = heap.back(); //Replace root with last element: heap[0] = 3 → Heap becomes: [3, 7, 5, 3]
        heap.pop_back(); // Heap becomes: [3, 7, 5]
        heapifyDown(0);
        /*
            Heapify down from root:
            3 < 7 → swap → [7, 3, 5]
            3 < 5 → swap → [7, 5, 3]
        */
    }

    // Display current heap
    void printHeap() {
        cout << "Heap elements: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    // Insertion example
    h.insert(5);
    h.insert(10);
    h.insert(3);
    h.insert(2);
    h.insert(7);
    h.printHeap(); // Should maintain max-heap structure

    // Deletion example
    h.deleteRoot();
    h.printHeap();

    h.deleteRoot();
    h.printHeap();

    return 0;
}
