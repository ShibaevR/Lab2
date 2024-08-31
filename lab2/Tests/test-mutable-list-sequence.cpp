#include <assert.h>

#include "test-mutable-list-sequence.h"

#include "../mutable-list-sequence.h"
#include "../linked-list.h"


void TestDefaultConstructor(){

    MutableListSequence<int> mls_1;
    assert(mls_1.CheckInitialization() && "Error: Failed default construction of an int Mutable List Sequence");
    mls_1.~MutableListSequence();

    MutableListSequence<double> mls_2;
    assert(mls_2.CheckInitialization() && "Error: Failed default construction of a double Mutable List Sequence");
    mls_2.~MutableListSequence();

    MutableListSequence<char> mls_3;
    assert(mls_3.CheckInitialization() && "Error: Failed default construction of a char Mutable List Sequence");
    mls_3.~MutableListSequence();


    MutableListSequence<int*> mls_4;
    assert(mls_4.CheckInitialization() && "Error: Failed default construction of an int* Mutable List Sequence");
    mls_4.~MutableListSequence();

    MutableListSequence<double*> mls_5;
    assert(mls_5.CheckInitialization() && "Error: Failed default construction of a double* Mutable List Sequence");
    mls_5.~MutableListSequence();

    MutableListSequence<char*> mls_6;
    assert(mls_6.CheckInitialization() && "Error: Failed default construction of a char* Mutable List Sequence");
    mls_6.~MutableListSequence();


    MutableListSequence<int**> mls_7;
    assert(mls_7.CheckInitialization() && "Error: Failed default construction of an int** Mutable List Sequence");
    mls_7.~MutableListSequence();

    MutableListSequence<double**> mls_8;
    assert(mls_8.CheckInitialization() && "Error: Failed default construction of a double** Mutable List Sequence");
    mls_8.~MutableListSequence();

    MutableListSequence<char**> mls_9;
    assert(mls_9.CheckInitialization() && "Error: Failed default construction of a char** Mutable List Sequence");
    mls_9.~MutableListSequence();

}


void TestMethodsMLS(){

    MutableListSequence<int> mls_1(10);
    assert(mls_1.GetLength() == 10 && "Error: Failed construction of a Mutable List Sequence");

    for(int i=0; i < 10; i++)
        mls_1.Set(i, i);
    for(int i=0; i < 10; i++)
        assert(mls_1.Get(i) == i && "Error: Failed to assign values to th elements of a Mutable List Sequence");

    assert(mls_1.GetFirst() == 0 && "Error: Failed to get the first element of a Mutable List Sequence");
    assert(mls_1.GetLast() == 9 && "Error: Failed to get the last element of a Mutable List Sequence");

    try{
        mls_1.Get(11);
        assert(false && "Error: Acquired an out of range element with Get of a Mutable List Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_1.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of a Mutable List Sequence");
    }
    catch(...){
        assert(true);
    }


    try{
        mls_1.Set(11,11);
        assert(false && "Error: Set an out of range element for a Mutable List Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_1.Set(-1,-1);
        assert(false && "Error: Set an out of range element for a Mutable List Sequence");
    }
    catch(...){
        assert(true);
    }


    MutableListSequence<int> mls_2;

    try{
        mls_2.Set(0,0);
        assert(false && "Error: Set an out of range element for a Mutable List Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_2.Get(0);
        assert(false && "Error: Acquired an out of range element with Get of a Mutable List Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_2.GetFirst();
        assert(false && "Error: Acquired the first element of a Mutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_2.GetLast();
        assert(false && "Error: Acquired the last element of a Mutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    MutableListSequence<int>* mls_3 = mls_1.GetSubSequence(1,8);
    assert(mls_3->GetLength() == 8 && "Error: Failed construction of a Mutable List Sequence");

    for(int i=0; i < 8; i++)
        assert(mls_3->Get(i) == i + 1 && "Error: Failed to assign values to th elements of a Mutable List Sequence");

    assert(mls_3->GetFirst() == 1 && "Error: Failed to get the first element of a Mutable List Sequence");
    assert(mls_3->GetLast() == 8 && "Error: Failed to get the last element of a Mutable List Sequence");

    try{
        mls_1.GetSubSequence(-1,8);
        assert(false && "Error: Created a Sub Mutable List Sequence with a negative start index");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_1.GetSubSequence(1,-1);
        assert(false && "Error: Created a Sub Mutable List Sequence with a negative end index");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_1.GetSubSequence(8,1);
        assert(false && "Error: Created a Sub Mutable List Sequence with a start index greater than end index");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_2.GetSubSequence(1,8);
        assert(false && "Error: Created a Sub Mutable List Sequence with Mutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    mls_1.~MutableListSequence();
    mls_2.~MutableListSequence();
    delete mls_3;

}


void TestOperationsMLS(){

    MutableListSequence<int> mls_1;

    mls_1.Append(2);

    assert(mls_1.GetLength() == 1 && "Error: Failed to Append an element to a Mutable List Sequence");
    assert(mls_1.Get(0) == 2 && "Error: Failed to Append an element to a Mutable List Sequence");

    mls_1.Prepend(0);

    assert(mls_1.GetLength() == 2 && "Error: Failed to Prepend an element to a Mutable List Sequence");
    assert(mls_1.Get(0) == 0 && "Error: Failed to Prepend an element to a Mutable List Sequence");

    mls_1.InsertAt(1, 1);

    assert(mls_1.GetLength() == 3 && "Error: Failed to Insert an element to a Mutable List Sequence");
    assert(mls_1.Get(1) == 1 && "Error: Failed to Insert an element to a Mutable List Sequence");

    try{
        mls_1.InsertAt(1, -1);
        assert(false && "Error: Inserted an element with a negative index to a Mutable List Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        mls_1.InsertAt(1, 5);
        assert(false && "Error: Inserted an element with an out of range index to a Mutable List Sequence");
    }
    catch(...){
        assert(true);
    }


    MutableListSequence<int>* mls_2 = mls_1.Concat(mls_1);

    assert(mls_2->GetLength() == 6 && "Error: Failed to Concat a Mutable List Sequence");

    for(int i=0; i < mls_1.GetLength(); i++)
        assert(mls_1.Get(i) == mls_2->Get(i) && "Error: Failed to Concat a Mutable List Sequence");

    for(int i=0; i < mls_1.GetLength(); i++)
        assert(mls_1.Get(i) == mls_2->Get(i + mls_1.GetLength()) && "Error: Failed to Concat a Mutable List Sequence");

    try{
        MutableListSequence<int> mls_3;
        MutableListSequence<int> mls_4(10);
        mls_3.Concat(mls_4);
        assert(false && "Error: Created Concat with a Mutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        MutableListSequence<int> mls_3;
        MutableListSequence<int> mls_4(10);
        mls_4.Concat(mls_3);
        assert(false && "Error: Created Concat with a Mutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    mls_1.~MutableListSequence();
    delete mls_2;

}


void TestConstructorsMLS(){

    int array[10];
    for(int i=0; i < 10; i++)
        array[i] = i;

    MutableListSequence<int> mls_1(array, 10);
    assert(mls_1.GetLength() == 10 && "Error: Failed construction of a Mutable Array Sequence");

    for(int i=0; i < 10; i++){
        assert(mls_1.Get(i) == i && "Error: Failed construction of a Mutable Array Sequence");
    }


    LinkedList<int> ll_1(10);

    for(int i=0; i < 10; i++)
        ll_1.Set(i, i);

    MutableListSequence<int> mls_2(ll_1);
    assert(mls_2.GetLength() == 10 && "Error: Failed construction of a Mutable Array Sequence");

    for(int i=0; i < 10; i++){
        assert(mls_2.Get(i) == i && "Error: Failed construction of a Mutable Array Sequence");
    }

    mls_1.~MutableListSequence();
    mls_2.~MutableListSequence();
    ll_1.~LinkedList();

}


void TestMutableListSequence(){
    TestDefaultConstructor();
    TestMethodsMLS();
    TestOperationsMLS();
    TestConstructorsMLS();
}