#include <assert.h>

#include "test-mutable-array-sequence.h"

#include "../dynamic-array.h"
#include "../mutable-array-sequence.h"


void TestDefaultConstructorsMAS(){

    MutableArraySequence<int> mas_1;
    assert(mas_1.CheckInitialization() && "Error: Failed default construction of an int Mutable Array Sequence");
    mas_1.~MutableArraySequence();

    MutableArraySequence<double> mas_2;
    assert(mas_2.CheckInitialization() && "Error: Failed default construction of a double Mutable Array Sequence");
    mas_2.~MutableArraySequence();

    MutableArraySequence<char> mas_3;
    assert(mas_3.CheckInitialization() && "Error: Failed default construction of a char Mutable Array Sequence");
    mas_3.~MutableArraySequence();

    MutableArraySequence<int*> mas_4;
    assert(mas_4.CheckInitialization() && "Error: Failed default construction of an int* Mutable Array Sequence");
    mas_4.~MutableArraySequence();

    MutableArraySequence<double*> mas_5;
    assert(mas_5.CheckInitialization() && "Error: Failed default construction of a double* Mutable Array Sequence");
    mas_5.~MutableArraySequence();

    MutableArraySequence<char*> mas_6;
    assert(mas_6.CheckInitialization() && "Error: Failed default construction of a char* Mutable Array Sequence");
    mas_6.~MutableArraySequence();

    MutableArraySequence<int**> mas_7;
    assert(mas_7.CheckInitialization() && "Error: Failed default construction of an int** Mutable Array Sequence");
    mas_7.~MutableArraySequence();

    MutableArraySequence<double**> mas_8;
    assert(mas_8.CheckInitialization() && "Error: Failed default construction of a double** Mutable Array Sequence");
    mas_8.~MutableArraySequence();

    MutableArraySequence<char**> mas_9;
    assert(mas_9.CheckInitialization() && "Error: Failed default construction of a char** Mutable Array Sequence");
    mas_9.~MutableArraySequence();

}


void TestMethodsMAS(){

    MutableArraySequence<int> mas_1(10);
    assert(mas_1.GetLength() == 10 && "Error: Failed construction of a Mutable Array Sequence");

    for(int i=0; i < 10; i++)
        mas_1.Set(i, i);
    for(int i=0; i < 10; i++)
        assert(mas_1.Get(i) == i && "Error: Failed to assign values to th elements of a Mutable Array Sequence");

    assert(mas_1.GetFirst() == 0 && "Error: Failed to get the first element of a Mutable Array Sequence");
    assert(mas_1.GetLast() == 9 && "Error: Failed to get the last element of a Mutable Array Sequence");

    try{
        mas_1.Get(11);
        assert(false && "Error: Acquired an out of range element with Get of a Mutable Array Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_1.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of a Mutable Array Sequence");
    }
    catch(...){
        assert(true);
    }


    try{
        mas_1.Set(11,11);
        assert(false && "Error: Set an out of range element for a Mutable Array Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_1.Set(-1,-1);
        assert(false && "Error: Set an out of range element for a Mutable Array Sequence");
    }
    catch(...){
        assert(true);
    }


    MutableArraySequence<int> mas_2;

    try{
        mas_2.Set(0,0);
        assert(false && "Error: Set an out of range element for a Mutable Array Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_2.Get(0);
        assert(false && "Error: Acquired an out of range element with Get of a Mutable Array Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_2.GetFirst();
        assert(false && "Error: Acquired the first element of a Mutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_2.GetLast();
        assert(false && "Error: Acquired the last element of a Mutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    MutableArraySequence<int>* mas_3 = mas_1.GetSubSequence(1,8);
    assert(mas_3->GetLength() == 8 && "Error: Failed construction of a Mutable Array Sequence");

    for(int i=0; i < 8; i++)
        assert(mas_3->Get(i) == i + 1 && "Error: Failed to assign values to th elements of a Mutable Array Sequence");

    assert(mas_3->GetFirst() == 1 && "Error: Failed to get the first element of a Mutable Array Sequence");
    assert(mas_3->GetLast() == 8 && "Error: Failed to get the last element of a Mutable Array Sequence");

    try{
        mas_1.GetSubSequence(-1,8);
        assert(false && "Error: Created a Sub Mutable Array Sequence with a negative start index");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_1.GetSubSequence(1,-1);
        assert(false && "Error: Created a Sub Mutable Array Sequence with a negative end index");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_1.GetSubSequence(8,1);
        assert(false && "Error: Created a Sub Mutable Array Sequence with a start index greater than end index");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_2.GetSubSequence(1,8);
        assert(false && "Error: Created a Sub Mutable Array Sequence with Mutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    mas_1.~MutableArraySequence();
    mas_2.~MutableArraySequence();
    delete mas_3;

}


void TestOperationsMAS(){

    MutableArraySequence<int> mas_1;

    mas_1.Append(2);

    assert(mas_1.GetLength() == 1 && "Error: Failed to Append an element to a Mutable Array Sequence");
    assert(mas_1.Get(0) == 2 && "Error: Failed to Append an element to a Mutable Array Sequence");

    mas_1.Prepend(0);

    assert(mas_1.GetLength() == 2 && "Error: Failed to Prepend an element to a Mutable Array Sequence");
    assert(mas_1.Get(0) == 0 && "Error: Failed to Prepend an element to a Mutable Array Sequence");

    mas_1.InsertAt(1, 1);

    assert(mas_1.GetLength() == 3 && "Error: Failed to Insert an element to a Mutable Array Sequence");
    assert(mas_1.Get(1) == 1 && "Error: Failed to Insert an element to a Mutable Array Sequence");

    try{
        mas_1.InsertAt(1, -1);
        assert(false && "Error: Inserted an element with a negative index to a Mutable Array Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mas_1.InsertAt(1, 5);
        assert(false && "Error: Inserted an element with an out of range index to a Mutable Array Sequence");
    }
    catch(...){
        assert(true);
    }


    MutableArraySequence<int>* mas_2 = mas_1.Concat(mas_1);

    assert(mas_2->GetLength() == 6 && "Error: Failed to Concat a Mutable Array Sequence");

    for(int i=0; i < mas_1.GetLength(); i++)
        assert(mas_1.Get(i) == mas_2->Get(i) && "Error: Failed to Concat a Mutable Array Sequence");

    for(int i=0; i < mas_1.GetLength(); i++)
        assert(mas_1.Get(i) == mas_2->Get(i + mas_1.GetLength()) && "Error: Failed to Concat a Mutable Array Sequence");

    try{
        MutableArraySequence<int> mas_3;
        MutableArraySequence<int> mas_4(10);
        mas_3.Concat(mas_4);
        assert(false && "Error: Created Concat with a Mutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        MutableArraySequence<int> mas_3;
        MutableArraySequence<int> mas_4(10);
        mas_4.Concat(mas_3);
        assert(false && "Error: Created Concat with a Mutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    mas_1.~MutableArraySequence();
    delete mas_2;

}


void TestConstructorsMAS(){

    int array[10];
    for(int i=0; i < 10; i++)
        array[i] = i;

    MutableArraySequence<int> mas_1(array, 10);
    assert(mas_1.GetLength() == 10 && "Error: Failed construction of a Mutable Array Sequence");

    for(int i=0; i < 10; i++){
        assert(mas_1.Get(i) == i && "Error: Failed construction of a Mutable Array Sequence");
    }


    DynamicArray<int> da_1(10);

    for(int i=0; i < 10; i++)
       da_1.Set(i, i);

    MutableArraySequence<int> mas_2(da_1);
    assert(mas_2.GetLength() == 10 && "Error: Failed construction of a Mutable Array Sequence");

    for(int i=0; i < 10; i++){
        assert(mas_2.Get(i) == i && "Error: Failed construction of a Mutable Array Sequence");
    }

    mas_1.~MutableArraySequence();
    mas_2.~MutableArraySequence();
    da_1.~DynamicArray();

}



void TestMutableArraySequence(){
    TestDefaultConstructorsMAS();
    TestMethodsMAS();
    TestOperationsMAS();
    TestConstructorsMAS();
}
