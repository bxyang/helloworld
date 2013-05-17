#include<cstdlib>
#include<iostream>
using namespace std;

template <class T> class CMaxHeap {
    public:
        CMaxHeap(const T data[], const int length);
        ~CMaxHeap();
        void BuildMaxHeap();
        void MaxHeapify(const int pos);
        void PrintHeap();
        void HeapSort();
    void HeapIncreaseKey(int pos, T key);
    void MaxHeapInsert(T key);
    void Remove(int pos);
    private:
        T* elem_;
        int length_;
};
template <class T>
CMaxHeap<T>::CMaxHeap(const T data[], const int length) {
    length_ = length;
    elem_ = new T[length];
    for (int i = 0; i < length; i++) {
        elem_[i] = data[i];
    }
}
template <class T>
CMaxHeap<T>::~CMaxHeap() {
    delete [] elem_;
}
template <class T>
void CMaxHeap<T>::BuildMaxHeap() {
    for (int i = length_ / 2; i > -1; i--) {
        MaxHeapify(i);
    }
}
template <class T>
void CMaxHeap<T>::HeapSort() {
    BuildMaxHeap();
    int length = length_;
    while (length_ > 0){
        int last = length_ - 1;
        T temp = elem_[0];
        elem_[0] = elem_[last];
        elem_[last] = temp;
        length_--;
        MaxHeapify(0);
    }
    length_ = length;
}
template <class T>
void CMaxHeap<T>::HeapIncreaseKey(int pos, T key) {
    if(pos < 0 || pos >= length_) {
    return;
    }
    elem_[pos] = key;
    int parent = (pos - 1 ) / 2;
    while(parent > 0) {
    if(elem_[pos] > elem_[parent]) {
        T temp = elem_[pos];
        elem_[pos] = elem_[parent];
        elem_[parent] = temp;
        pos = parent;
        parent = (parent - 1) / 2;
    }
    else {
        break;
    }
    }
    return;
}
template <class T>
void CMaxHeap<T>::MaxHeapInsert(T key) {
    T* temp = new T[length_];
    for (int i = 0; i < length_; i++) {
    temp[i] = elem_[i]; 
    }
    delete [] elem_;
    elem_ = new T[length_ + 1];
    for (int i = 0; i < length_; i++) {
    elem_[i] = temp[i]; 
    }
    delete [] temp;
    elem_[length_] = key - 1;
    length_++;
    HeapIncreaseKey(length_ - 1, key);
}
template <class T>
void CMaxHeap<T>::PrintHeap() {
    for (int i = 0; i < length_; i++) {
        cout << elem_[i] << " ";
    }
    cout << endl;
}
template <class T>
void CMaxHeap<T>::MaxHeapify(const int pos) {
    int left = 2 * pos + 1;
    int right = left + 1;
    int max = elem_[pos];
    int max_pos = pos;
    if (left < length_ && elem_[left] > max) {
        max_pos = left;
        max = elem_[left];
    }
    if (right < length_ && elem_[right] > max) {
        max_pos = right;
        max = elem_[right];
    }
    if (max_pos != pos) {
        T temp = elem_[pos];
        elem_[pos] = max;
        elem_[max_pos] = temp;
        MaxHeapify(max_pos);
    }
}
template <class T>
void CMaxHeap<T>::Remove(int pos) {
    if(pos < length_) {
        length_--;
        elem_[pos] = elem_[length_];
        MaxHeapify(pos);
    }
}

int main() {
    int a[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    CMaxHeap<int> max_heap_obj(a, 10);
    max_heap_obj.BuildMaxHeap();
    //max_heap_obj.HeapSort();
    max_heap_obj.PrintHeap();
    /*
    max_heap_obj.HeapIncreaseKey(9, 11);
    max_heap_obj.PrintHeap();
    max_heap_obj.MaxHeapInsert(15);
    max_heap_obj.PrintHeap();
    max_heap_obj.HeapSort();
    */
    max_heap_obj.Remove(3);
    max_heap_obj.PrintHeap();
}
