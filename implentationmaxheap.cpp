#include <iostream>
using namespace std;

class Maxheap {
public:
    int arr[50];
    int idx;

    Maxheap() {
        idx = 1;
    }

    int top() {
        return arr[1];
    }

    void push(int x) {
        arr[idx] = x;
        int i = idx;
        idx++;
        while (i != 1) {
            int parent = i / 2;
            if (arr[i] > arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else break;
        }
    }

    int size() {
        return idx - 1;
    }

    void pop() {
        if (idx <= 1) return; 
        arr[1] = arr[idx - 1];
        idx--;

        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int largest = i;

            if (left < idx && arr[left] > arr[largest])
                largest = left;
            if (right < idx && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
        }
    }
};

int main() {
    Maxheap pq;
    pq.push(10);
    pq.push(2);
    cout << pq.top() << endl;  
    pq.push(11);
    pq.push(12);
    cout << pq.top() << endl;  
    pq.push(30);
    cout << pq.top() << endl;  
    pq.pop();
    cout << pq.top() << endl;  
    cout << pq.size() << endl; 
}
