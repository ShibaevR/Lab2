#include <assert.h>

#include "test-dynamic-array.h"
#include "../dynamic-array.h"


void TestDefaultConstructorsDA(){

    DynamicArray<int> da_1;
    assert(da_1.CheckInitialization() && "Error: Failed default construction of an int Dynamic Array");
    da_1.~DynamicArray();

    DynamicArray<double> da_2;
    assert(da_2.CheckInitialization() && "Error: Failed default construction of a double Dynamic Array");
    da_2.~DynamicArray();

    DynamicArray<char> da_3;
    assert(da_3.CheckInitialization() && "Error: Failed default construction of a char Dynamic Array");
    da_3.~DynamicArray();


    DynamicArray<int*> da_4;
    assert(da_4.CheckInitialization() && "Error: Failed default construction of an int* Dynamic Array");
    da_4.~DynamicArray();

    DynamicArray<double*> da_5;
    assert(da_5.CheckInitialization() && "Error: Failed default construction of a double* Dynamic Array");
    da_5.~DynamicArray();

    DynamicArray<char*> da_6;
    assert(da_6.CheckInitialization() && "Error: Failed default construction of a char* Dynamic Array");
    da_6.~DynamicArray();


    DynamicArray<int**> da_7;
    assert(da_7.CheckInitialization() && "Error: Failed default construction of an int* Dynamic Array");
    da_7.~DynamicArray();

    DynamicArray<double**> da_8;
    assert(da_8.CheckInitialization() && "Error: Failed default construction of a double* Dynamic Array");
    da_8.~DynamicArray();

    DynamicArray<char**> da_9;
    assert(da_9.CheckInitialization() && "Error: Failed default construction of a char* Dynamic Array");
    da_9.~DynamicArray();
}


void TestMethodsDA(){

    DynamicArray<int> da_1(10);
    assert(da_1.GetSize() == 10 && "Error: Failed construction of a Dynamic Array");

    for(int i=0; i < 10; i++)
        da_1.Set(i, i);
    for(int i=0; i < 10; i++)
        assert(da_1.Get(i) == i && "Error: Failed to assign values to elements of a Dynamic Array");


    try{
        da_1.Get(11);
        assert(false && "Error: Acquired an out of range element with Get of a Dynamic Array");
    }
    catch(...){
        assert(true);
    }

    try{
        da_1.Get(-1);
        assert(false && "Error: Acquired an out of range element with Get of a Dynamic Array");
    }
    catch(...){
        assert(true);
    }


    try{
        da_1.Set(11,11);
        assert(false && "Error: Set an out of range element for a Dynamic Array");
    }
    catch(...){
        assert(true);
    }

    try{
        da_1.Set(-1,-1);
        assert(false && "Error: Set an out of range element for a Dynamic Array");
    }
    catch(...){
        assert(true);
    }


    da_1.Resize(11);
    assert(da_1.GetSize() == 11 && "Error: Failed to Resize a Dynamic Array");

    try{
        da_1.Resize(-1);
        assert(false && "Error: Changed size of ");
    }
    catch(...){
        assert(true);
    }


    for(int i=0; i < 10; i++)
        assert(da_1.Get(i) == i && "Error: Failed to assign values to elements of a Dynamic Array");

    da_1.Set(10,10);
    assert(da_1.Get(10) == 10 && "Error: Failed to assign values to elements of a resized Dynamic Array");

    da_1.~DynamicArray();

    assert(da_1.GetSize() == 0 && "Error: Failed deconstruction of a Dynamic Array");

    try{
        da_1.Get(1);
        assert(false && "Error: Acquired an element after deconstruction of a Dynamic Array");
    }
    catch(...){
        assert(true);
    }

    try{
        da_1.Set(1,1);
        assert(false && "Error: Set an element after deconstruction of a Dynamic Array");
    }
    catch(...){
        assert(true);
    }
}


void TestOperationsDA(){

    DynamicArray<int> da_1(10);
    for(int i=0; i < 10; i++)
        da_1.Set(i, i);

    DynamicArray<int> da_2(10);
    for(int i=0; i < 10; i++)
        da_2.Set(i, i);

    DynamicArray<int> da_3(10);
    for(int i=0; i < 10; i++)
        da_3.Set(i, 0);

    assert(da_1 == da_2 && "Error: The same Dynamic Arrays are not equal");

    assert(da_1 != da_3 && "Error: Different Dynamic Arrays are equal");

    da_1.~DynamicArray();
    da_2.~DynamicArray();
    da_3.~DynamicArray();

}


void TestConstructorsAndDestructorsDA(){

    DynamicArray<int> da_1(10);
    for(int i=0; i < 10; i++)
        da_1.Set(i, i);
    DynamicArray<int> da_2(da_1);
    assert(da_2.GetSize() == 10 && "Error: Failed construction of a Dynamic Array");
    for(int i=0; i < 10; i++)
        assert(da_2.Get(i) == da_1.Get(i) && "Error: Failed construction of a Dynamic Array");
    da_1.~DynamicArray();

    try{
        DynamicArray<int> da_3(da_1);
        assert(false && "Error: Created a Dynamic Array with an already deconstructed Dynamic Array");
    }
    catch(...){
        assert(true);
    }

    da_2.~DynamicArray();

    try{
        DynamicArray<int> da_3(-10);
        assert(false);
    }
    catch(...){
        assert(true);
    }


    int array[10];
    for(int i=0; i < 10; i++)
        array[i] = i;
    DynamicArray<int> da_4(array,10);

    for(int i=0; i < 10; i++)
        assert(da_4.Get(i) == array[i] && "Error: Failed construction of a Dynamic Array");

    da_4.~DynamicArray();
}


void TestDynamicArray(){
    TestDefaultConstructorsDA();
    TestMethodsDA();
    TestOperationsDA();
    TestConstructorsAndDestructorsDA();
}