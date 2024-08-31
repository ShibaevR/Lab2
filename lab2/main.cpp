#include <iostream>

#include "Tests/test-dynamic-array.h"
#include "Tests/test-linked-list.h"
#include "Tests/test-mutable-array-sequence.h"
#include "Tests/test-immutable-array-sequence.h"
#include "Tests/test-mutable-list-sequence.h"
#include "Tests/test-immutable-list-sequence.h"

#include "ui.h"


int main() {

    TestDynamicArray();
    TestLinkedList();
    TestMutableArraySequence();
    TestImmutableArraySequence();
    TestMutableListSequence();
    TestImmutableListSequence();

    std::cout<<"\nAll tests completed successfully\n";

    UserInterface();

    return 0;
}
