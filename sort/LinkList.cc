/*
 * =====================================================================================
 *
 *       Filename:  LinkList.cc
 *
 *    Description:  LinkList practice
 *
 *        Version:  1.0
 *        Created:  05/25/2013 08:55:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  yang_bao_xing@163.com
 *   Organization:  ict
 *
 * =====================================================================================
 */

#include<cstdlib>
#include<cstdio>

template<class T>
struct Node {
    T data;
    Node* next;
};


template<class T>
class LinkList {
 public:
    LinkList();
    LinkList(T data[], const int length);
    void InsertionSort(bool is_ascend = true);
    void BubbleSort(bool is_ascend = true);
    void SelectionSort(bool is_ascend = true);
    void QuickSort(bool is_ascend = true);
    void print();
 private:
    void QuickSortInterval(bool is_ascend,
        Node<T>* start_prev, Node<T>* end_post);
    bool compare(bool is_ascend, T left, T right);
    Node<T>* Partion(bool is_ascend, Node<T>* start_prev, Node<T>* end_post);
    Node<T>* head;
};

template<class T>
LinkList<T>::LinkList() {
    head = new Node<T>();
    head.next = NULL;
}
template<class T>
LinkList<T>::LinkList(T data[], const int length) {
    head = new Node<T>();
    head -> next = NULL;
    Node<T>* p = head;
    for (int i = 0; i < length; i++) {
        Node<T>* node = new Node<T>();
        node -> data = data[i];
        node -> next = NULL;
        p -> next = node;
        p = p -> next;
    }
}
template<class T>
void LinkList<T>::print() {
    Node<T>* p = head -> next;
    while (p != NULL) {
        printf("%0.3f ", (double)p -> data);
        p = p -> next;
    }
    printf("\n");
}

template<class T>
bool LinkList<T>::compare(bool is_ascend, T left, T right) {
    if (is_ascend)
        return left <= right ? true:false;
    else
        return left >= right ? true:false;
}
template<class T>
void LinkList<T>::InsertionSort(bool is_ascend) {
    if (head -> next == NULL)
        return;
    Node<T>* key_pre = head -> next;
    Node<T>* q;
    while (key_pre -> next != NULL) {
        q = head;
        while (q -> next != key_pre -> next) {
            if (compare(is_ascend, q -> next -> data,
                    key_pre -> next -> data)) {
                q = q -> next;
            } else {
                break;
            }
        }
        if (q -> next != key_pre -> next) {
            Node<T>* key = key_pre -> next;
            key_pre -> next = key -> next;
            key -> next = q -> next;
            q -> next = key;
        } else {
            key_pre = key_pre -> next;
        }
    }
}

/*
template<class T>
void LinkList<T>::BubbleSort(bool is_ascend) {
    if(head -> next == NULL)
        return;
    bool exchange = true;
    Node<T>* bound = NULL;
    while(exchange) {
        Node<T>* p = head;
        exchange = false;
        while((p -> next -> next != NULL) && (p != bound)) {
            if(compare(is_ascend, p -> next -> data, p -> next -> next ->data))
                p = p -> next;
            else {
                // exchange p->next and p->next->next
                Node<T>* t1 = p -> next;
                Node<T>* t2 = p -> next -> next -> next;
                p -> next = p -> next -> next;
                p -> next -> next = t1;
                t1 -> next = t2;
                bound = p;
                p = p -> next;
                exchange = true;
            }
        }
        if(bound != NULL){
            printf("bound %d\n", bound -> data);
        }
        else{
            printf("bound null\n");
        }
    }
}
*/
template<class T>
void LinkList<T>::BubbleSort(bool is_ascend) {
    if (head -> next == NULL)
        return;
    bool exchange = true;
    Node<T>* bound = NULL;
    while (exchange) {
        Node<T>* p = head -> next;
        exchange = false;
        while ((p -> next != NULL) && (p != bound)) {
            if (compare(is_ascend, p -> data, p -> next -> data))
                p = p -> next;
            else {
                // exchange
                T t = p -> data;
                p -> data = p -> next -> data;
                p -> next -> data = t;
                bound = p;
                p = p -> next;
                exchange = true;
            }
        }
    }
}

template<class T>
void LinkList<T>::SelectionSort(bool is_ascend) {
    if (head -> next == NULL)
        return;
    Node<T>* p = head -> next;
    Node<T>* q = head -> next;
    while (q -> next != NULL) {
        Node<T>* key = q;
        while (p != NULL) {
            if (compare(is_ascend, key -> data, p -> data))
                p = p -> next;
            else {
                key = p;
            }
        }
        // exchange
        T t = key -> data;
        key -> data = q -> data;
        q -> data = t;
        q = q -> next;
    }
}

template<class T>
Node<T>* LinkList<T>::Partion(bool is_ascend,
    Node<T>* start_prev, Node<T>* end_post) {
    printf("partion \n");
    Node<T>* p = start_prev;
    Node<T>* q = start_prev -> next;
    while (q -> next != end_post) {
        if (compare(is_ascend, p -> next -> data, q -> data))
            q = q -> next;
        else {
            // exchange
            T t = p -> next -> next -> data;
            p -> next -> next -> data = q -> data;
            q -> data = t;
            p = p -> next;
            q = q -> next;
        }
    }
    // exchange
    T t = start_prev -> next -> data;
    start_prev -> next -> data = p -> next -> data;
    p -> next -> data = t;
    return p -> next;
}

template<class T>
void LinkList<T>::QuickSortInterval(bool is_ascend,
    Node<T>* start_prev, Node<T>* end_post) {
    if ((start_prev -> next == end_post) ||
            (start_prev -> next -> next == end_post))
        return;
    Node<T>* p = Partion(is_ascend, start_prev, end_post);
    QuickSortInterval(is_ascend, start_prev, p);
    QuickSortInterval(is_ascend, p, end_post);
}
template<class T>
void LinkList<T>::QuickSort(bool is_ascend) {
    if (head -> next == NULL )
        return;
    QuickSortInterval(is_ascend, head, NULL);
}

int main() {
    const int len = 2;
    // int data[len] = {3, 4, 5, 2, 1};
    int data[len] = {1, 2};
    LinkList<int> listObj(data, len);
    listObj.print();
    // listObj.InsertionSort(false);
    // listObj.print();
    // listObj.BubbleSort(false);
    // listObj.print();
    // listObj.SelectionSort(false);
    listObj.QuickSort(false);
    listObj.print();
    return 0;
}
