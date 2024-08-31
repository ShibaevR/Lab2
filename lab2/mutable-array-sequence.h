#ifndef LAB2_MUTABLE_ARRAY_SEQUENCE_H
#define LAB2_MUTABLE_ARRAY_SEQUENCE_H

#include <iostream>

#include "mutable-sequence.h"
#include "dynamic-array.h"


template <class T>
class MutableArraySequence : public MutableSequence<T>{
private:
    DynamicArray<T>* mas_array;

public:
    MutableArraySequence(){
        mas_array = new DynamicArray<T>();
    }

    MutableArraySequence(T* items, int size){
        mas_array = new DynamicArray<T>(items, size);
    }

    explicit MutableArraySequence(int size){
        mas_array = new DynamicArray<T>(size);
    }

    explicit MutableArraySequence(const DynamicArray<T>& array){
        mas_array = new DynamicArray<T>(array);
    }

    ~MutableArraySequence(){
        delete mas_array;
        mas_array = nullptr;
    }


    T GetFirst() const override{
        if(mas_array->GetSize() == 0)
            throw std::out_of_range("Error: Can't get the first element of an Mutable Array Sequence with a size equal to 0");

        return mas_array->Get(0);
    }

    T GetLast() const override{
        if(mas_array->GetSize() == 0)
            throw std::out_of_range("Error: Can't get the last element of a Mutable Array Sequence with a size equal to 0");

        return mas_array->Get(mas_array->GetSize() - 1);
    }

    T Get(int index) const override{
        if(index < 0 || index >= mas_array->GetSize())
            throw std::out_of_range("Error: Index out of range");

        return mas_array->Get(index);
    }

    MutableArraySequence<T>* GetSubSequence(int start_index, int end_index) const override{
        if(start_index < 0 || start_index >= mas_array->GetSize())
            throw std::out_of_range("Error: Start index is out of range");

        if(end_index < 0 || end_index >= mas_array->GetSize())
            throw std::out_of_range("Error: End index is out of range");

        if(start_index > end_index)
            throw std::out_of_range("Error: Start index is greater than the end index");


        T array[end_index - start_index + 1];

        for(int i=0; i < end_index; i++)
            array[i] = mas_array->Get(i + start_index);

        MutableArraySequence<T>* new_sequence;
        new_sequence = new MutableArraySequence<T>(array, end_index - start_index + 1);

        return new_sequence;
    }

    int GetLength() const override{
        return mas_array->GetSize();
    }


    void Set(int index, T item) override{
        if(index < 0 || index >= mas_array->GetSize())
            throw std::out_of_range("Error: Index out of range");

        mas_array->Set(index, item);
    }

    MutableArraySequence<T>* Append(T item) override{
        mas_array->Resize(mas_array->GetSize() + 1);
        mas_array->Set(mas_array->GetSize() - 1, item);

        return this;
    }

    MutableArraySequence<T>* Prepend(T item) override{
        mas_array->Resize(mas_array->GetSize() + 1);
        T element_1 = mas_array->Get(0);
        T element_2;

        for(int i=0; i < mas_array->GetSize() - 1; i++){
            element_2 = element_1;
            element_1 = mas_array->Get(i + 1);
            mas_array->Set(i + 1, element_2);
        }

        mas_array->Set(0, item);

        return this;
    }

    MutableArraySequence<T>* InsertAt(T item, int index) override{
        if(index < 0 || index >= mas_array->GetSize())
            throw std::out_of_range("Error: Index out of range");

        mas_array->Resize(mas_array->GetSize() + 1);
        T element_1 = mas_array->Get(index);
        T element_2;

        for(int i=index; i < mas_array->GetSize() - 1; i++){
            element_2 = element_1;
            element_1 = mas_array->Get(i + 1);
            mas_array->Set(i + 1, element_2);
        }

        mas_array->Set(index, item);

        return this;
    }

    MutableArraySequence<T>* Concat(const MutableSequence<T>& sequence) const override{
        if(mas_array->GetSize() == 0)
            throw std::out_of_range("Error: Can't concat a Mutable Array Sequence with a size equal to 0");

        if(sequence.GetLength() == 0)
            throw std::out_of_range("Error: Can't concat a Mutable Array Sequence with a size equal to 0");

        T new_array[mas_array->GetSize() + sequence.GetLength()];

        for(int i=0; i < mas_array->GetSize(); i++)
            new_array[i] = mas_array->Get(i);

        for(int i=0; i < sequence.GetLength(); i++){
            new_array[i + mas_array->GetSize()] = sequence.Get(i);
        }

        MutableArraySequence<T>* new_sequence;
        new_sequence = new MutableArraySequence<T>(new_array, mas_array->GetSize() + sequence.GetLength());

        return new_sequence;
    }


    bool CheckInitialization() const override{
        return mas_array->CheckInitialization();
    }

};

#endif //LAB2_MUTABLE_ARRAY_SEQUENCE_H
