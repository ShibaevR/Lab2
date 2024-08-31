#include <assert.h>

#include "test-immutable-array-sequence.h"

#include "../dynamic-array.h"
#include "../immutable-array-sequence.h"


void TestDefaultConstructorsIAS(){

    ImmutableArraySequence<int> ias_1;
    assert(ias_1.CheckInitialization() && "Error: Failed default construction of an int Immutable Array Sequence");
    ias_1.~ImmutableArraySequence();

    ImmutableArraySequence<double> ias_2;
    assert(ias_2.CheckInitialization() && "Error: Failed default construction of a double Immutable Array Sequence");
    ias_2.~ImmutableArraySequence();

    ImmutableArraySequence<char> ias_3;
    assert(ias_3.CheckInitialization() && "Error: Failed default construction of a char Immutable Array Sequence");
    ias_3.~ImmutableArraySequence();

    ImmutableArraySequence<int*> ias_4;
    assert(ias_4.CheckInitialization() && "Error: Failed default construction of an int* Immutable Array Sequence");
    ias_4.~ImmutableArraySequence();

    ImmutableArraySequence<double*> ias_5;
    assert(ias_5.CheckInitialization() && "Error: Failed default construction of a double* Immutable Array Sequence");
    ias_5.~ImmutableArraySequence();

    ImmutableArraySequence<char*> ias_6;
    assert(ias_6.CheckInitialization() && "Error: Failed default construction of a char* Immutable Array Sequence");
    ias_6.~ImmutableArraySequence();

    ImmutableArraySequence<int**> ias_7;
    assert(ias_7.CheckInitialization() && "Error: Failed default construction of an int** Immutable Array Sequence");
    ias_7.~ImmutableArraySequence();

    ImmutableArraySequence<double**> ias_8;
    assert(ias_8.CheckInitialization() && "Error: Failed default construction of a double** Immutable Array Sequence");
    ias_8.~ImmutableArraySequence();

    ImmutableArraySequence<char**> ias_9;
    assert(ias_9.CheckInitialization() && "Error: Failed default construction of a char** Immutable Array Sequence");
    ias_9.~ImmutableArraySequence();

}


void TestMethodsIAS(){

    int array[10];
    for(int i=0; i < 10; i++)
        array[i] = i;

    ImmutableArraySequence<int>ias_1(array,10);
    assert(ias_1.GetLength() == 10 && "Error: Failed construction of an Immutable Array Sequence");


    for(int i=0; i < 10; i++)
        assert(ias_1.Get(i) == i && "Error: Failed to assign values to the elements of an Immutable Array Sequence");

    assert(ias_1.GetFirst() == 0 && "Error: Failed to get the first element of an Immutable Array Sequence");
    assert(ias_1.GetLast() == 9 && "Error: Failed to get the last element of an Immutable Array Sequence");

    try{
        ias_1.Get(11);
        assert(false && "Error: Acquired an out of range element with Get of an Immutable Array Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        ias_1.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of an Immutable Array Sequence");
    }
    catch(...){
        assert(true);
    }


    ImmutableArraySequence<int> ias_2;


    try{
        ias_2.Get(0);
        assert(false && "Error: Acquired an out of range element with Get of an Immutable Array Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        ias_2.GetFirst();
        assert(false && "Error: Acquired the first element of an Immutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        ias_2.GetLast();
        assert(false && "Error: Acquired the last element of an Immutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }


    ImmutableArraySequence<int>* ias_3 = ias_1.GetSubSequence(1,8);

    assert(ias_3->GetLength() == 8 && "Error: Failed construction of an Immutable Array Sequence");

    for(int i=0; i < 8; i++)
        assert(ias_3->Get(i) == i + 1 && "Error: Failed to assign values to the elements of an Immutable Array Sequence");

    assert(ias_3->GetFirst() == 1 && "Error: Failed to get the first element of an Immutable Array Sequence");
    assert(ias_3->GetLast() == 8 && "Error: Failed to get the last element of an Immutable Array Sequence");

    try{
        ias_1.GetSubSequence(-1,8);
        assert(false && "Error: Created a Sub Immutable Array Sequence with a negative start index");
    }
    catch(...){
        assert(true);
    }

    try{
        ias_1.GetSubSequence(1,-1);
        assert(false && "Error: Created a Sub Immutable Array Sequence with a negative end index");
    }
    catch(...){
        assert(true);
    }

    try{
        ias_1.GetSubSequence(8,1);
        assert(false && "Error: Created a Sub Immutable Array Sequence with a start index greater than end index");
    }
    catch(...){
        assert(true);
    }

    try{
        ias_2.GetSubSequence(1,8);
        assert(false && "Error: Created a Sub Mutable Array Sequence with an Immutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    ias_1.~ImmutableArraySequence();
    ias_2.~ImmutableArraySequence();
    delete ias_3;

};


void TestOperationsIAS(){

    ImmutableArraySequence<int> ias_1;

    ImmutableArraySequence<int>* ias_3 = ias_1.Append(2);

    assert(ias_3->GetLength() == 1 && "Error: Failed to Append an element to an Immutable Array Sequence");
    assert(ias_3->Get(0) == 2 && "Error: Failed to Append an element to an Immutable Array Sequence");

    ImmutableArraySequence<int>* ias_4 = ias_1.Prepend(0);

    assert(ias_4->GetLength() == 1 && "Error: Failed to Prepend an element to an Immutable Array Sequence");
    assert(ias_4->Get(0) == 0 && "Error: Failed to Prepend an element to an Immutable Array Sequence");


    ImmutableArraySequence<int> ias_5(2);
    ImmutableArraySequence<int>* ias_6 = ias_5.InsertAt(1, 1);

    assert(ias_6->GetLength() == 3 && "Error: Failed to Insert an element to an Immutable Array Sequence");
    assert(ias_6->Get(1) == 1 && "Error: Failed to Insert an element to an Immutable Array Sequence");

    try{
        ias_1.InsertAt(1, -1);
        assert(false && "Error: Inserted an element with a negative index to an Immutable Array Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        ias_1.InsertAt(1, 5);
        assert(false && "Error: Inserted an element with an out of range index to an Immutable Array Sequence");
    }
    catch(...){
        assert(true);
    }


    int array[10];
    for(int i=0; i < 10; i++)
        array[i] = i;

    ImmutableArraySequence<int>ias_7(array,10);
    ImmutableArraySequence<int>* ias_2 = ias_7.Concat(ias_7);

    assert(ias_2->GetLength() == 20 && "Error: Failed to Concat an Immutable Array Sequence");

    for(int i=0; i < ias_7.GetLength(); i++){
        assert(ias_7.Get(i) == ias_2->Get(i) && "Error: Failed to Concat an Immutable Array Sequence");
    }
    for(int i=0; i < ias_7.GetLength(); i++){
        assert(ias_7.Get(i) == ias_2->Get(i + ias_1.GetLength()) && "Error: Failed to Concat an Immutable Array Sequence");
    }

    try{
        ImmutableArraySequence<int> ias_8;
        ImmutableArraySequence<int> ias_9(10);
        ias_8.Concat(ias_9);
        assert(false && "Error: Created Concat with an Immutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        ImmutableArraySequence<int> ias_8;
        ImmutableArraySequence<int> ias_9(10);
        ias_9.Concat(ias_8);
        assert(false && "Error: Created Concat with an Immutable Array Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    ias_1.~ImmutableArraySequence();
    delete ias_2;
    delete ias_3;
    delete ias_4;
    ias_5.~ImmutableArraySequence();
    delete ias_6;
    ias_7.~ImmutableArraySequence();

}


void TestConstructorsIAS(){

    ImmutableArraySequence<int> ias_1(10);
    assert(ias_1.GetLength() == 10 && "Error: Failed construction of an Immutable Array Sequence");

    DynamicArray<int> da_1(10);

    for(int i=0; i < 10; i++)
        da_1.Set(i, i);

    ImmutableArraySequence<int> ias_2(da_1);
    assert(ias_2.GetLength() == 10 && "Error: Failed construction of an Immutable Array Sequence");

    for(int i=0; i < 10; i++){
        assert(ias_2.Get(i) == i && "Error: Failed construction of an Immutable Array Sequence");
    }

    ias_1.~ImmutableArraySequence();
    ias_2.~ImmutableArraySequence();
    da_1.~DynamicArray();

}




void TestImmutableArraySequence(){
    TestDefaultConstructorsIAS();
    TestMethodsIAS();
    TestOperationsIAS();
    TestConstructorsIAS();
}