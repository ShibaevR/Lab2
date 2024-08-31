#ifndef LAB2_IMMUTABLE_LIST_SEQUENCE_H
#define LAB2_IMMUTABLE_LIST_SEQUENCE_H

#include <iostream>

#include "immutable-sequence.h"
#include "linked-list.h"


template <class T>
class ImmutableListSequence : public ImmutableSequence<T>{
private:
    LinkedList<T>* ils_list;
public:
    ImmutableListSequence(){
        ils_list = new LinkedList<T>();
    }

    ImmutableListSequence(T* items, int size){
        ils_list = new LinkedList<T>(items, size);
    }

    explicit ImmutableListSequence(int size){
        ils_list = new LinkedList<T>(size);
    }

    explicit ImmutableListSequence(const LinkedList<T>& list){
        ils_list = new LinkedList<T>(list);
    }

    ~ImmutableListSequence(){
        delete ils_list;
        ils_list = nullptr;
    }


    T GetFirst() const override{
        if(ils_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't get the last element of a Mutable List Sequence with a size equal to 0");

        return ils_list->GetFirst();
    }

    T GetLast() const override{
        if(ils_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't get the last element of a Mutable List Sequence with a size equal to 0");

        return ils_list->GetLast();
    }

    T Get(int index) const override{
        if(index < 0 || index >= ils_list->GetLength())
            throw std::out_of_range("Error: Index out of range");

        return ils_list->Get(index);
    }

    ImmutableListSequence<T>* GetSubSequence(int start_index, int end_index) const override{
        if(start_index < 0 || start_index >= ils_list->GetLength())
            throw std::out_of_range("Error: Start index is out of range");

        if(end_index < 0 || end_index >= ils_list->GetLength())
            throw std::out_of_range("Error: End index is out of range");

        if(start_index > end_index)
            throw std::out_of_range("Error: Start index is greater than the end index");

        T array[end_index - start_index + 1];

        for(int i=0; i < end_index; i++)
            array[i] = ils_list->Get(i + start_index);

        ImmutableListSequence<T>* new_sequence;
        new_sequence = new ImmutableListSequence<T>(array, end_index - start_index + 1);

        return new_sequence;
    }

    int GetLength() const override{
        return ils_list->GetLength();
    }


    ImmutableListSequence<T>* Append(T item) const override{
        LinkedList<T> new_list;
        new_list = *ils_list;

        new_list.Append(item);

        ImmutableListSequence<T>* new_sequence;
        new_sequence = new ImmutableListSequence<T>(new_list);

        return new_sequence;
    }

    ImmutableListSequence<T>* Prepend(T item) const override{
        LinkedList<T> new_list;
        new_list = *ils_list;

        new_list.Prepend(item);

        ImmutableListSequence<T>* new_sequence;
        new_sequence = new ImmutableListSequence<T>(new_list);

        return new_sequence;
    }

    ImmutableListSequence<T>* InsertAt(T item, int index) const override{
        if(index < 0 || index >= ils_list->GetLength())
            throw std::out_of_range("Error: Index out of range");

        LinkedList<T> new_list(*ils_list);

        new_list.InsertAt(item, index);

        ImmutableListSequence<T>* new_sequence;
        new_sequence = new ImmutableListSequence<T>(new_list);

        return new_sequence;
    }

    ImmutableListSequence<T>* Concat(const ImmutableSequence<T>& sequence) const override{
        if(ils_list->GetLength() == 0)
            throw std::out_of_range("Error: Can't concat a Mutable Array Sequence with a size equal to 0");

        if(sequence.GetLength() == 0)
            throw std::out_of_range("Error: Can't concat a Mutable Array Sequence with a size equal to 0");

        T new_array[ils_list->GetLength() + sequence.GetLength()];

        for(int i=0; i < ils_list->GetLength(); i++)
            new_array[i] = ils_list->Get(i);

        for(int i=0; i < sequence.GetLength(); i++){
            new_array[i + ils_list->GetLength()] = sequence.Get(i);
        }

        ImmutableListSequence<T>* new_sequence;
        new_sequence = new ImmutableListSequence<T>(new_array, ils_list->GetLength() + sequence.GetLength());

        return new_sequence;
    }

    bool CheckInitialization() const override{
        return ils_list->CheckInitialization();
    }

};

#endif //LAB2_IMMUTABLE_LIST_SEQUENCE_H
