#ifndef LAB2_IMMUTABLE_ARRAY_SEQUENCE_H
#define LAB2_IMMUTABLE_ARRAY_SEQUENCE_H

#include <iostream>

#include "immutable-sequence.h"
#include "dynamic-array.h"

template <class T>
class ImmutableArraySequence : public ImmutableSequence<T>{
private:
    DynamicArray<T>* ias_array;

public:
    ImmutableArraySequence(){
        ias_array = new DynamicArray<T>();
    }

    ImmutableArraySequence(T* items, int size){
        ias_array = new DynamicArray<T>(items, size);
    }

    explicit ImmutableArraySequence(int size){
        ias_array = new DynamicArray<T>(size);
    }

    explicit ImmutableArraySequence(const DynamicArray<T>& array){
        ias_array = new DynamicArray<T>(array);
    }

    ~ImmutableArraySequence() override{
        delete ias_array;
        ias_array = nullptr;
    }


    T GetFirst() const override{
        if(ias_array->GetSize() == 0)
            throw std::out_of_range("Error: Can't get the first element of an Immutable Array Sequence with a size equal to 0");

        return ias_array->Get(0);
    }

    T GetLast() const override{
        if(ias_array->GetSize() == 0)
            throw std::out_of_range("Error: Can't get the last element of an Immutable Array Sequence with a size equal to 0");

        return ias_array->Get(ias_array->GetSize() - 1);
    }

    T Get(int index) const override{
        if(index < 0 || index >= ias_array->GetSize())
            throw std::out_of_range("Error: Index out of range");

        return ias_array->Get(index);
    }

    ImmutableArraySequence<T>* GetSubSequence(int start_index, int end_index) const override{
        if(start_index < 0 || start_index >= ias_array->GetSize())
            throw std::out_of_range("Error: Start index is out of range");

        if(end_index < 0 || end_index >= ias_array->GetSize())
            throw std::out_of_range("Error: End index is out of range");

        if(start_index > end_index)
            throw std::out_of_range("Error: Start index is greater than the end index");


        T array[end_index - start_index + 1];

        for(int i=0; i < end_index; i++)
            array[i] = ias_array->Get(i + start_index);

        ImmutableArraySequence<T>* new_sequence;
        new_sequence = new ImmutableArraySequence<T>(array, end_index - start_index + 1);

        return new_sequence;
    }

    int GetLength() const override{
        return ias_array->GetSize();
    }


    ImmutableArraySequence<T>* Append(T item) const override{
        DynamicArray<T> new_array;
        new_array = *ias_array;

        new_array.Resize(new_array.GetSize() + 1);
        new_array.Set(new_array.GetSize() - 1, item);

        ImmutableArraySequence<T>* new_sequence;
        new_sequence = new ImmutableArraySequence<T>(new_array);

        return new_sequence;
    }

    ImmutableArraySequence<T>* Prepend(T item) const override{
        DynamicArray<T> new_array;
        new_array = *ias_array;

        new_array.Resize(new_array.GetSize() + 1);
        T element_1 = new_array.Get(0);
        T element_2;

        for(int i=0; i < new_array.GetSize() - 1; i++){
            element_2 = element_1;
            element_1 = new_array.Get(i + 1);
            new_array.Set(i + 1, element_2);
        }

        new_array.Set(0, item);

        ImmutableArraySequence<T>* new_sequence;
        new_sequence = new ImmutableArraySequence<T>(new_array);
        return new_sequence;
    }

    ImmutableArraySequence<T>* InsertAt(T item, int index) const override{
        if(index < 0 || index >= ias_array->GetSize())
            throw std::out_of_range("Error: Index out of range");

        DynamicArray<T> new_array(*ias_array);

        new_array.Resize(new_array.GetSize() + 1);
        T element_1 = new_array.Get(index);
        T element_2;

        for(int i=index; i < new_array.GetSize() - 1; i++){
            element_2 = element_1;
            element_1 = new_array.Get(i + 1);
            new_array.Set(i + 1, element_2);
        }

        new_array.Set(index, item);

        ImmutableArraySequence<T>* new_sequence;
        new_sequence = new ImmutableArraySequence<T>(new_array);

        return new_sequence;
    }

    ImmutableArraySequence<T>* Concat(const ImmutableSequence<T>& sequence) const override{
        if(ias_array->GetSize() == 0)
            throw std::out_of_range("Error: Can't concat an Immutable Array Sequence with a size equal to 0");

        if(sequence.GetLength() == 0)
            throw std::out_of_range("Error: Can't concat an Immutable Array Sequence with a size equal to 0");

        T new_array[ias_array->GetSize() + sequence.GetLength()];

        for(int i=0; i < ias_array->GetSize(); i++)
            new_array[i] = ias_array->Get(i);

        for(int i=0; i < sequence.GetLength(); i++){
            new_array[i + ias_array->GetSize()] = sequence.Get(i);
        }

        ImmutableArraySequence<T>* new_sequence;
        new_sequence = new ImmutableArraySequence<T>(new_array, ias_array->GetSize() + sequence.GetLength());

        return new_sequence;
    }


    bool CheckInitialization() const override{
        return ias_array->CheckInitialization();
    }

};


#endif //LAB2_IMMUTABLE_ARRAY_SEQUENCE_H
