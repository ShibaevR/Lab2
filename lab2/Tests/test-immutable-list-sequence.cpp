#include <assert.h>

#include "test-immutable-list-sequence.h"

#include "../immutable-list-sequence.h"
#include "../linked-list.h"


void TestDefaultConstructorILS(){

    ImmutableListSequence<int> ils_1;
    assert(ils_1.CheckInitialization() && "Error: Failed default construction of an int Immutable List Sequence");
    ils_1.~ImmutableListSequence();

    ImmutableListSequence<double> ils_2;
    assert(ils_2.CheckInitialization() && "Error: Failed default construction of a double Immutable List Sequence");
    ils_2.~ImmutableListSequence();

    ImmutableListSequence<char> ils_3;
    assert(ils_3.CheckInitialization() && "Error: Failed default construction of a char Immutable List Sequence");
    ils_3.~ImmutableListSequence();


    ImmutableListSequence<int*> ils_4;
    assert(ils_4.CheckInitialization() && "Error: Failed default construction of an int* Immutable List Sequence");
    ils_4.~ImmutableListSequence();

    ImmutableListSequence<double*> ils_5;
    assert(ils_5.CheckInitialization() && "Error: Failed default construction of a double* Immutable List Sequence");
    ils_5.~ImmutableListSequence();

    ImmutableListSequence<char*> ils_6;
    assert(ils_6.CheckInitialization() && "Error: Failed default construction of a char* Immutable List Sequence");
    ils_6.~ImmutableListSequence();


    ImmutableListSequence<int**> ils_7;
    assert(ils_7.CheckInitialization() && "Error: Failed default construction of an int** Immutable List Sequence");
    ils_7.~ImmutableListSequence();

    ImmutableListSequence<double**> ils_8;
    assert(ils_8.CheckInitialization() && "Error: Failed default construction of a double** Immutable List Sequence");
    ils_8.~ImmutableListSequence();

    ImmutableListSequence<char**> ils_9;
    assert(ils_9.CheckInitialization() && "Error: Failed default construction of a char** Immutable List Sequence");
    ils_9.~ImmutableListSequence();

}


void TestMethodsILS(){

    int array[10];
    for(int i=0; i < 10; i++)
        array[i] = i;

    ImmutableListSequence<int>ils_1(array,10);
    assert(ils_1.GetLength() == 10 && "Error: Failed construction of an Immutable List Sequence");

    for(int i=0; i < 10; i++)
        assert(ils_1.Get(i) == i && "Error: Failed to assign values to th elements of an Immutable List Sequence");

    assert(ils_1.GetFirst() == 0 && "Error: Failed to get the first element of an Immutable List Sequence");
    assert(ils_1.GetLast() == 9 && "Error: Failed to get the last element of an Immutable List Sequence");

    try{
        ils_1.Get(11);
        assert(false && "Error: Acquired an out of range element with Get of an Immutable List Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        ils_1.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of an Immutable List Sequence");
    }
    catch(...){
        assert(true);
    }


    ImmutableListSequence<int> ils_2;


    try{
        ils_2.Get(0);
        assert(false && "Error: Acquired an out of range element with Get of an Immutable List Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        ils_2.GetFirst();
        assert(false && "Error: Acquired the first element of an Immutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        ils_2.GetLast();
        assert(false && "Error: Acquired the last element of an Immutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    ImmutableListSequence<int>* ils_3 = ils_1.GetSubSequence(1,8);
    assert(ils_3->GetLength() == 8 && "Error: Failed construction of an Immutable List Sequence");

    for(int i=0; i < 8; i++)
        assert(ils_3->Get(i) == i + 1 && "Error: Failed to assign values to th elements of an Immutable List Sequence");

    assert(ils_3->GetFirst() == 1 && "Error: Failed to get the first element of an Immutable List Sequence");
    assert(ils_3->GetLast() == 8 && "Error: Failed to get the last element of an Immutable List Sequence");

    try{
        ils_1.GetSubSequence(-1,8);
        assert(false && "Error: Created a Sub Immutable List Sequence with a negative start index");
    }
    catch(...){
        assert(true);
    }

    try{
        ils_1.GetSubSequence(1,-1);
        assert(false && "Error: Created a Sub Immutable List Sequence with a negative end index");
    }
    catch(...){
        assert(true);
    }

    try{
        ils_1.GetSubSequence(8,1);
        assert(false && "Error: Created a Sub Immutable List Sequence with a start index greater than end index");
    }
    catch(...){
        assert(true);
    }

    try{
        ils_2.GetSubSequence(1,8);
        assert(false && "Error: Created a Sub Immutable List Sequence with Immutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    ils_1.~ImmutableListSequence();
    ils_2.~ImmutableListSequence();
    delete ils_3;

}


void TestOperationsILS(){

    ImmutableListSequence<int> ils_1;

    ImmutableListSequence<int>* ils_3 = ils_1.Append(2);

    assert(ils_3->GetLength() == 1 && "Error: Failed to Append an element to an Immutable List Sequence");
    assert(ils_3->Get(0) == 2 && "Error: Failed to Append an element to an Immutable List Sequence");

    ImmutableListSequence<int>* ils_4 = ils_1.Prepend(0);

    assert(ils_4->GetLength() == 1 && "Error: Failed to Prepend an element to an Immutable List Sequence");
    assert(ils_4->Get(0) == 0 && "Error: Failed to Prepend an element to an Immutable List Sequence");


    ImmutableListSequence<int> ils_5(2);
    ImmutableListSequence<int>* ils_6 = ils_5.InsertAt(1, 1);

    assert(ils_6->GetLength() == 3 && "Error: Failed to Insert an element to an Immutable List Sequence");
    assert(ils_6->Get(1) == 1 && "Error: Failed to Insert an element to an Immutable List Sequence");

    try{
        ils_1.InsertAt(1, -1);
        assert(false && "Error: Inserted an element with a negative index to an Immutable List Sequence");
    }
    catch(...){
        assert(true);
    }

    try{
        ils_1.InsertAt(1, 5);
        assert(false && "Error: Inserted an element with an out of range index to an Immutable List Sequence");
    }
    catch(...){
        assert(true);
    }


    int array[10];
    for(int i=0; i < 10; i++)
        array[i] = i;

    ImmutableListSequence<int>ils_7(array,10);
    ImmutableListSequence<int>* ils_2 = ils_7.Concat(ils_7);

    assert(ils_2->GetLength() == 20 && "Error: Failed to Concat an Immutable List Sequence");

    for(int i=0; i < ils_7.GetLength(); i++){
        assert(ils_7.Get(i) == ils_2->Get(i) && "Error: Failed to Concat an Immutable List Sequence");
    }
    for(int i=0; i < ils_7.GetLength(); i++){
        assert(ils_7.Get(i) == ils_2->Get(i + ils_1.GetLength()) && "Error: Failed to Concat an Immutable List Sequence");
    }

    try{
        ImmutableListSequence<int> ils_8;
        ImmutableListSequence<int> ils_9(10);
        ils_8.Concat(ils_9);
        assert(false && "Error: Created Concat with an Immutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        ImmutableListSequence<int> ils_8;
        ImmutableListSequence<int> ils_9(10);
        ils_9.Concat(ils_8);
        assert(false && "Error: Created Concat with an Immutable List Sequence with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    ils_1.~ImmutableListSequence();
    delete ils_2;
    delete ils_3;
    delete ils_4;
    ils_5.~ImmutableListSequence();
    delete ils_6;
    ils_7.~ImmutableListSequence();

}


void TestConstructorsILS(){

    ImmutableListSequence<int> ils_1(10);
    assert(ils_1.GetLength() == 10 && "Error: Failed construction of an Immutable List Sequence");

    LinkedList<int> ll_1(10);

    for(int i=0; i < 10; i++)
        ll_1.Set(i, i);

    ImmutableListSequence<int> ils_2(ll_1);
    assert(ils_2.GetLength() == 10 && "Error: Failed construction of an Immutable List Sequence");

    for(int i=0; i < 10; i++){
        assert(ils_2.Get(i) == i && "Error: Failed construction of an Immutable List Sequence");
    }

    ils_1.~ImmutableListSequence();
    ils_2.~ImmutableListSequence();
    ll_1.~LinkedList();

}


void TestImmutableListSequence(){
    TestDefaultConstructorILS();
    TestMethodsILS();
    TestOperationsILS();
    TestConstructorsILS();
}