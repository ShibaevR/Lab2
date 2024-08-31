#include <assert.h>

#include "test-linked-list.h"
#include "../linked-list.h"

void TestDefaultConstructorsLL(){

    LinkedList<int> ll_1;
    assert(ll_1.CheckInitialization() && "Error: Failed default construction of an int Linked List");
    ll_1.~LinkedList();

    LinkedList<double> ll_2;
    assert(ll_2.CheckInitialization() && "Error: Failed default construction of a double Linked List");
    ll_2.~LinkedList();

    LinkedList<char> ll_3;
    assert(ll_3.CheckInitialization() && "Error: Failed default construction of a char Linked List");
    ll_3.~LinkedList();


    LinkedList<int*> ll_4;
    assert(ll_4.CheckInitialization() && "Error: Failed default construction of an int* Linked List");
    ll_4.~LinkedList();

    LinkedList<double*> ll_5;
    assert(ll_5.CheckInitialization() && "Error: Failed default construction of a double* Linked List");
    ll_5.~LinkedList();

    LinkedList<char*> ll_6;
    assert(ll_6.CheckInitialization() && "Error: Failed default construction of a char* Linked List");
    ll_6.~LinkedList();


    LinkedList<int**> ll_7;
    assert(ll_7.CheckInitialization() && "Error: Failed default construction of an int** Linked List");
    ll_7.~LinkedList();

    LinkedList<double**> ll_8;
    assert(ll_8.CheckInitialization() && "Error: Failed default construction of a double** Linked List");
    ll_8.~LinkedList();

    LinkedList<char**> ll_9;
    assert(ll_9.CheckInitialization() && "Error: Failed default construction of a char** Linked List");
    ll_9.~LinkedList();

}

void TestMethodsLL(){

    LinkedList<int> ll_1(10);
    assert(ll_1.GetLength() == 10 && "Error: Failed construction of a Linked List");

    assert(ll_1.GetFirst() == 0 && "Error: Failed to get the first element of a Linked List");
    assert(ll_1.GetLast() == 0 && "Error: Failed to get the last element of a Linked List");

    for(int i=0; i < 10; i++)
        assert(ll_1.Get(i) == 0 && "Error: Failed construction of a Linked List");

    try{
        ll_1.Get(11);
        assert(false && "Error: Acquired an out of range element with Get of a Linked List");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_1.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of a Linked List");
    }
    catch(...){
        assert(true);
    }


    LinkedList<int> ll_2;

    try{
        ll_2.GetFirst();
        assert(false && "Error: Acquired an out of range element with Get of a Linked List");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_2.GetLast();
        assert(false && "Error: Acquired an out of range element with Get of a Linked List");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_2.Get(1);
        assert(false && "Error: Acquired an out of range element with Get of a Linked List");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_2.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of a Linked List");
    }
    catch(...){
        assert(true);
    }

    ll_2.~LinkedList();


    LinkedList<int>* ll_3 = ll_1.GetSubList(1,8);
    assert(ll_3->GetLength() == 8 && "Error: Failed creation of a Sub Linked List");

    assert(ll_3->GetFirst() == 0 && "Error: Failed to get the first element of a Sub Linked List");
    assert(ll_3->GetLast() == 0 && "Error: Failed to get the last element of a Sub Linked List");

    for(int i=0; i < 8; i++)
        assert(ll_3->Get(i) == 0 && "Error: Failed to get an element of a Sub Linked List");

    delete ll_3;

    try{
        ll_1.GetSubList(-1,8);
        assert(false && "Error: Made a Sub Linked List with negative start index");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_1.GetSubList(1,11);
        assert(false && "Error: Made a Sub Linked List with out of range end index");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_1.GetSubList(8,1);
        assert(false && "Error: Made a Sub Linked List with start index greater than end index");
    }
    catch(...){
        assert(true);
    }

    ll_1.~LinkedList();
}


void TestOperationsLL(){

    LinkedList<int> ll_1(10);
    LinkedList<int>* ll_3 = ll_1.GetSubList(1,8);

    ll_3->Prepend(1);

    assert(ll_3->GetLength() == 9 && "Error: Failed to add an element at the start of a Linked List");
    assert(ll_3->GetFirst() == 1 && "Error: Failed to get the first element of a Linked List");

    ll_3->Append(1);
    assert(ll_3->GetLength() == 10 && "Error: Failed to add an element at the end of a Linked List");
    assert(ll_3->GetLast() == 1 && "Error: Failed to get the first element of a Linked List");

    ll_3->InsertAt(1,5);
    assert(ll_3->GetLength() == 11 && "Error: Failed to add an element at the end of a Linked List");
    assert(ll_3->Get(5) == 1 && "Error: Failed to get the first element of a Linked List");

    try{
        ll_1.InsertAt(1,-1);
        assert(false && "Error: Inserted an element with out of range index into Linked List ");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_1.InsertAt(1,21);
        assert(false && "Error: Inserted an element with out of range index into Linked List ");
    }
    catch(...){
        assert(true);
    }

    delete ll_3;


    LinkedList<int>* ll_4 = ll_1.Concat(ll_1);
    assert(ll_4->GetLength() == 20 && "Error: Failed construction of a Linked List");

    assert(ll_4->GetFirst() == 0 && "Error: Failed to get the first element of a Linked List");
    assert(ll_4->GetLast() == 0 && "Error: Failed to get the last element of a Linked List");

    for(int i=0; i < 20; i++)
        assert(ll_4->Get(i) == 0 && "Error: Failed construction of a Linked List");

    try{
        LinkedList<int> ll_5;
        LinkedList<int> ll_6(10);
        ll_5.Concat(ll_6);
        assert(false && "Error: Created a Concat Linked List with a Linked List with size equal to 0");
    }
    catch(...){
        assert(true);
    }

    try{
        LinkedList<int> ll_5;
        LinkedList<int> ll_6(10);
        ll_6.Concat(ll_5);
        assert(false && "Error: Created a Concat Linked List with a Linked List with size equal to 0");
    }
    catch(...){
        assert(true);
    }


    LinkedList<int> ll_5(10);
    LinkedList<int> ll_6(20);

    assert(ll_1 == ll_5 && "Error: The same Linked Lists aren't equal");
    assert(ll_6 != ll_5 && "Error: The same Linked Lists aren't equal");

    ll_1.~LinkedList();
    ll_5.~LinkedList();
    ll_6.~LinkedList();

    delete ll_4;
}


void TestConstructorsAndDestructorsLL(){

    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    LinkedList<int> ll_1(array, 10);
    assert(ll_1.GetLength() == 10 && "Error: Failed construction of a Linked List");

    assert(ll_1.GetFirst() == 0 && "Error: Failed to get the first element of a Linked List");
    assert(ll_1.GetLast() == 9 && "Error: Failed to get the last element of a Linked List");

    for(int i=0; i < 10; i++)
        assert(ll_1.Get(i) == i && "Error: Failed construction of a Linked List");

    try{
        LinkedList<int> ll_3(array, -1);
        assert(false && "Error: Constructed a Linked List with negative size");
    }
    catch(...){
        assert(true);
    }


    LinkedList<int> ll_2(ll_1);
    assert(ll_1 == ll_2 && "Error: Failed construction of a Linked List");

    try{
        LinkedList<int> ll_4;
        LinkedList<int> ll_5(ll_4);
        assert(false && "Error: Constructed a Linked List with negative size");
    }
    catch(...){
        assert(true);
    }


    ll_1.Set(0, 11);
    assert(ll_1.Get(0) == 11 && "Error: Failed construction of a Linked List");

    try{
        ll_1.Set(-1, 11);
        assert(false && "Error: Set a value to an element of a Linked List with negative index");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_1.Set(21, 11);
        assert(false && "Error: Set a value to an element of a Linked List with out of range index");
    }
    catch(...){
        assert(true);
    }



    ll_1.~LinkedList();
    ll_2.~LinkedList();

    assert(ll_1.GetLength() == 0 && "Error: Failed deconstruction of a Linked List");

    try{
        ll_1.Get(1);
        assert(false && "Error: Acquired an element of a deconstructed Linked List");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_1.GetFirst();
        assert(false && "Error: Acquired the first element of a deconstructed Linked List");
    }
    catch(...){
        assert(true);
    }

    try{
        ll_1.GetLast();
        assert(false && "Error: Acquired the first element of a deconstructed Linked List");
    }
    catch(...){
        assert(true);
    }
}


void TestLinkedList(){
    TestDefaultConstructorsLL();
    TestMethodsLL();
    TestOperationsLL();
    TestConstructorsAndDestructorsLL();
}
