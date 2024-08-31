#ifndef LAB2_MUTABLE_LIST_SEQUENCE_H
#define LAB2_MUTABLE_LIST_SEQUENCE_H

#include <iostream>

#include "mutable-sequence.h"
#include "linked-list.h"


template <class T>
class MutableListSequence : public MutableSequence<T>{
private:
    LinkedList<T>* mls_list;
public:
    MutableListSequence(){
        mls_list = new LinkedList<T>();
    }

    MutableListSequence(T* items, int size){
        mls_list = new LinkedList<T>(items, size);
    }

    explicit MutableListSequence(int size){
        mls_list = new LinkedList<T>(size);
    }

    explicit MutableListSequence(const LinkedList<T>& list){
        mls_list = new LinkedList<T>(list);
    }

    ~MutableListSequence(){
        delete mls_list;
        mls_list = nullptr;
    }


    T GetFirst() const override{
        if(mls_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't get the last element of a Mutable List Sequence with a size equal to 0");

        return mls_list->GetFirst();
    }

    T GetLast() const override{
        if(mls_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't get the last element of a Mutable List Sequence with a size equal to 0");

        return mls_list->GetLast();
    }

    T Get(int index) const override{
        if(index < 0 || index >= mls_list->GetLength())
            throw std::out_of_range("Error: Index out of range");

        return mls_list->Get(index);
    }

    MutableListSequence<T>* GetSubSequence(int start_index, int end_index) const override{
        if(start_index < 0 || start_index >= mls_list->GetLength())
            throw std::out_of_range("Error: Start index is out of range");

        if(end_index < 0 || end_index >= mls_list->GetLength())
            throw std::out_of_range("Error: End index is out of range");

        if(start_index > end_index)
            throw std::out_of_range("Error: Start index is greater than the end index");

        T array[end_index - start_index + 1];

        for(int i=0; i < end_index; i++)
            array[i] = mls_list->Get(i + start_index);

        MutableListSequence<T>* new_sequence;
        new_sequence = new MutableListSequence<T>(array, end_index - start_index + 1);

        return new_sequence;
    }

    int GetLength() const override{
        return mls_list->GetLength();
    }


    void Set(int index, T item) override{
        if(index < 0 || index >= mls_list->GetLength())
            throw std::out_of_range("Error: Index out of range");

        mls_list->Set(index, item);
    }

    MutableListSequence<T>* Append(T item) override{
        mls_list->Append(item);

        return this;
    }

    MutableListSequence<T>* Prepend(T item) override{
        mls_list->Prepend(item);

        return this;
    }

    MutableListSequence<T>* InsertAt(T item, int index) override{
        mls_list->InsertAt(item, index);

        return this;
    }

    MutableListSequence<T>* Concat(const MutableSequence<T>& sequence) const override{
        if(mls_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't concat a Mutable Array Sequence with a size equal to 0");

        if(sequence.GetLength() == 0)
            throw std::out_of_range("Error: Can't concat a Mutable Array Sequence with a size equal to 0");

        T new_array[mls_list->GetLength() + sequence.GetLength()];

        for(int i=0; i < mls_list->GetLength(); i++)
            new_array[i] = mls_list->Get(i);

        for(int i=0; i < sequence.GetLength(); i++){
            new_array[i + mls_list->GetLength()] = sequence.Get(i);
        }

        MutableListSequence<T>* new_sequence;
        new_sequence = new MutableListSequence<T>(new_array, mls_list->GetLength() + sequence.GetLength());

        return new_sequence;
    }

    bool CheckInitialization() const override{
        return mls_list->CheckInitialization();
    }

};




#endif //LAB2_MUTABLE_LIST_SEQUENCE_H
