#ifndef LAB2_LINKED_LIST_H
#define LAB2_LINKED_LIST_H

#include <iostream>

template <class T>
class LinkedList{
private:
    struct Node{
        T ll_item;
        Node* ll_next = nullptr;
    };
    int ll_size;
    Node* ll_first = nullptr;

public:
    LinkedList() : ll_size(0) {};

    explicit LinkedList(int size) : LinkedList(){
        if(size <= 0)
            throw std::out_of_range("Error: Size can't be equal to or less than 0");

        ll_size = size;
        Node** ptr = &(ll_first);
        for(int i=0; i < ll_size; i++){
            *ptr = new Node;
            (*ptr)->ll_item = 0;
            ptr = &((*ptr)->ll_next);
        }
    }

    LinkedList(T* items, int size) : LinkedList(){
        if(size <= 0)
            throw std::out_of_range("Error: Size can't be equal to or less than 0");

        ll_size = size;
        Node** ptr = &(ll_first);
        for(int i=0; i < ll_size; i++){
            *ptr = new Node;
            (*ptr)->ll_item = items[i];
            ptr = &((*ptr)->ll_next);
        }
    }

    LinkedList(const LinkedList<T>& list) : LinkedList(){
        if(list.ll_size == 0)
            throw std::out_of_range("Error: Size can't be equal to 0");

        Node* ptr = list.ll_first;
        Node** new_ptr = &(ll_first);
        ll_size = list.ll_size;

        for(int i=0; i < ll_size; i++){
            *new_ptr = new Node;
            (*new_ptr)->ll_item = ptr->ll_item;
            new_ptr = &((*new_ptr)->ll_next);
            ptr = ptr->ll_next;
        }
    }

    ~LinkedList(){
        if(ll_size == 0)
            return;

        Node* ptr;
        int size = ll_size;

        for(int i=0; i < size; i++){
            ptr = ll_first;
            ll_first = ll_first->ll_next;
            delete ptr;
            ll_size--;
        }
    }


    T GetFirst() const{
        if(ll_size == 0)
            throw std::out_of_range("Error: Can't get the first element of a Linked List with a size equal to 0");

        return ll_first->ll_item;
    }

    T GetLast() const{
        if(ll_size == 0)
            throw std::out_of_range("Error: Can't get the first element of a Linked List with a size equal to 0");

        Node* ptr = ll_first;
        while(ptr->ll_next != nullptr)
            ptr = ptr->ll_next;

        return ptr->ll_item;
    }

    T Get(int index) const{
        if(index < 0 || index >= ll_size)
            throw std::out_of_range("Error: Index is out of range");

        Node* ptr = ll_first;

        for(int i=0; i < index; i++)
            ptr = ptr->ll_next;

        return ptr->ll_item;
    }

    LinkedList<T>* GetSubList(int start_index, int end_index) const{
        if(start_index < 0 || start_index >= ll_size)
            throw std::out_of_range("Error: Start index is out of range");

        if(end_index < 0 || end_index >= ll_size)
            throw std::out_of_range("Error: End index is out of range");

        if(start_index > end_index)
            throw std::out_of_range("Error: Start index is greater than the end index");

        LinkedList<T>* new_list;
        new_list = new LinkedList<T>();

        Node* ptr = ll_first;
        Node** new_ptr = &new_list->ll_first;

        for(int i=0; i <= end_index; i++){
            if(i >= start_index){
                *new_ptr = new Node;
                (*new_ptr)->ll_item = ptr->ll_item;
                new_ptr = &((*new_ptr)->ll_next);

                ptr = ptr->ll_next;
            }
        }

        new_list->ll_size = end_index - start_index + 1;

        return new_list;
    }

    int GetLength() const{
        return ll_size;
    }


    void Set(int index, T item){
        if(index < 0 || index >= ll_size)
            throw std::out_of_range("Error: Index is out of range");

        Node* ptr = ll_first;

        for(int i=0; i < index; i++)
            ptr = ptr->ll_next;

        ptr->ll_item = item;
    }

    void Append(T item){
        Node** ptr = &(ll_first);

        while(*ptr != nullptr)
            ptr = &((*ptr)->ll_next);

        (*ptr) = new Node;
        (*ptr)->ll_item = item;

        ll_size++;
    }

    void Prepend(T item){
        Node* ptr = new Node{item, ll_first};
        ll_first = ptr;
        ll_size++;
    }

    void InsertAt(T item, int index){
        if(index < 0 || index >= ll_size)
            throw std::out_of_range("Error: Index is out of range");

        Node old_first = {ll_first->ll_item, ll_first};

        Node* ptr;
        ptr = &old_first;

        for(int i=0; i < index; i++)
            ptr = ptr->ll_next;

        ptr->ll_next = new Node{item, ptr->ll_next};
        ll_first = old_first.ll_next;
        ll_size++;
    }

    LinkedList<T>* Concat(const LinkedList<T>& list){
        if(ll_size == 0)
            throw std::out_of_range("Error: Can't concat a Linked List with a size equal to 0");

        if(list.ll_size == 0)
            throw std::out_of_range("Error: Can't concat a Linked List with a size equal to 0");

        Node* ptr_1 = ll_first;
        Node* ptr_2 = list.ll_first;

        LinkedList<T>* new_list;
        new_list = new LinkedList<T>();
        Node** ptr = &(new_list->ll_first);

        while(ptr_1 != nullptr){
            *ptr = new Node{ptr_1->ll_item, ptr_1->ll_next};

            ptr_1 = ptr_1->ll_next;
            ptr = &((*ptr)->ll_next);
        }

        while(ptr_2 != nullptr){
            *ptr = new Node{ptr_2->ll_item, ptr_2->ll_next};

            ptr_2 = ptr_2->ll_next;
            ptr = &((*ptr)->ll_next);
        }

        new_list->ll_size = ll_size + list.ll_size;

        return new_list;
    }


    bool operator==(const LinkedList<T>& list) const{
        if(ll_size != list.ll_size)
            return false;

        for(int i=0; i < ll_size; i++){
            if(this->Get(i) != list.Get(i))
                return false;
        }

        return true;
    }

    bool operator!=(const LinkedList<T>& list) const{
        if(ll_size != list.ll_size)
            return true;

        for(int i=0; i < ll_size; i++){
            if(this->Get(i) != list.Get(i))
                return true;
        }

        return false;
    }

    LinkedList<T>& operator=(const LinkedList<T>& list){
        return *this;
    }

    bool CheckInitialization() const{
        if(ll_size == 0)
            return true;
        return false;
    }
};


#endif //LAB2_LINKED_LIST_H
