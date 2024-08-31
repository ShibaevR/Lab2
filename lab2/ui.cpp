#include "ui.h"

#include <iostream>
#include <string.h>

#include "mutable-sequence.h"
#include "mutable-list-sequence.h"
#include "mutable-array-sequence.h"


void SequenceMenu() {
    std::cout<<"\n\n\n---------------------------Menu---------------------------\n";
    std::cout<<"Enter <1> to get the first element\n";
    std::cout<<"Enter <2> to get the last element\n";
    std::cout<<"Enter <3> to to show a certain element\n";
    std::cout<<"Enter <4> to get length of the sequence\n";
    std::cout<<"Enter <5> to create the sub sequence\n";

    std::cout<<"Enter <6> to assign a value to an element\n";
    std::cout<<"Enter <7> to add an element at the end of the sequence\n";
    std::cout<<"Enter <8> to add an element at the start of the sequence\n";
    std::cout<<"Enter <9> to insert an element\n";
    std::cout<<"Enter <10> to self concat a sequence\n";

    std::cout<<"Enter <11> to show your sequence\n";

    std::cout<<"---------------------------------------------------------\n\n";
    std::cout<<"Enter 'STOP' to finish\n";
    std::cout<<"----------Or----------\n";
    std::cout<<"Choose action: ";
}


void OptionArraySequence(){

    while(true){
        std::cout<<"\nWhat type of elements do you want?\n";
        std::cout<<"\nEnter <1> for int";
        std::cout<<"\nEnter <2> for double";
        std::cout<<"\nEnter <3> to char\n";
        std::cout<<"\nEnter <4> to go back\n";
        std::cout<<"\nChoose action: ";

        char user_input_1[20];

        std::cin>>user_input_1;
        int action = atoi(user_input_1);

        switch(action){
            case 1:{

                std::cout<<"\nEnter the size of the sequence: ";
                int size;
                std::cin>>size;

                if(size <= 0){
                    std::cout<<"\nError: Size can't less than or equal to 0\n";
                    break;
                }

                int array[size];

                for(int i=0; i < size; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>array[i];
                }

                MutableArraySequence<int> mas(array, size);

                std::cout<<"\nYour sequence: ";
                for(int i=0; i < size; i++)
                    std::cout<<mas.Get(i)<<" ";


                while(true){
                    SequenceMenu();

                    char user_input_2[20];
                    std::cin>>user_input_2;

                    if(strcmp(user_input_2, "STOP") == 0){
                        break;
                    }

                    int option = atoi(user_input_2);

                    switch(option){
                        case 1:{
                            std::cout<<"\nFirst element: "<<mas.GetFirst();
                            break;
                        }


                        case 2:{
                            std::cout<<"\nLast element: "<<mas.GetLast();
                            break;
                        }


                        case 3:{
                            int index;

                            std::cout<<"\nEnter number of the element: ";

                            std::cin>>index;
                            index--;

                            if(index < 0 || index >= size){
                                std::cout<<"\nError: This element doesn't exist\n";
                            }

                            index++;
                            std::cout<<"Element number "<<index<<": "<<mas.Get(index);

                            break;
                        }


                        case 4:{
                            std::cout<<"\nLength of the sequence: "<<mas.GetLength();
                            break;
                        }


                        case 5:{
                            int start_index;
                            std::cout<<"\nEnter the number of the first element of the sub sequence: ";
                            std::cin>>start_index;
                            start_index--;

                            if(start_index < 0 || start_index >= size)
                                std::cout<<"\nError: The number of the first element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            int end_index;
                            std::cout<<"\nEnter the number of the last element of the sub sequence: ";
                            std::cin>>end_index;
                            end_index--;

                            if(end_index < 0 || end_index >= size)
                                std::cout<<"\nError: The number of the last element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            if(start_index > end_index)
                                std::cout<<"\nError: The number of the first element can't be greater than the number of the last element\n";

                            MutableArraySequence<int>* sub = mas.GetSubSequence(start_index,end_index);

                            std::cout<<"\nYour sub sequence: ";
                            for(int i=0; i < end_index; i++)
                                std::cout<<sub->Get(i)<<" ";

                            delete sub;
                            break;
                        }


                        case 6:{
                            int index;
                            std::cout<<"\nEnter the number of the element you want to change: ";
                            std::cin>>index;
                            index--;

                            int value;
                            std::cout<<"\nEnter the value that you want to assign: ";
                            std::cin>>value;

                            mas.Set(index,value);

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 7:{
                            int value;
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Append(value);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 8:{
                            int value;
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Prepend(value);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 9:{
                            int index;
                            std::cout<<"\nEnter the number of the place where you want to insert the element: ";
                            std::cin>>index;
                            index--;

                            int value;
                            std::cout<<"\nEnter the element you want to insert: ";
                            std::cin>>value;

                            mas.InsertAt(value, index);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 10:{
                            MutableArraySequence<int>* concat = mas.Concat(mas);

                            std::cout<<"\nYour concat sequence: ";
                            for(int i=0; i < size*2; i++)
                                std::cout<<concat->Get(i)<<" ";

                            delete concat;
                            break;
                        }


                        case 11:{
                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        default:{
                            std::cout<<"\nError: This action doesn't exist. Please try again";
                            break;
                        }
                    }
                }
                mas.~MutableArraySequence();

                break;
            }




            case 2:{
                std::cout<<"\nEnter the size of the sequence: ";
                int size;
                std::cin>>size;

                if(size <= 0){
                    std::cout<<"\nError: Size can't less than or equal to 0\n";
                    break;
                }

                double array[size];

                for(int i=0; i < size; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>array[i];
                }

                MutableArraySequence<double> mas(array, size);

                std::cout<<"\nYour sequence: ";
                for(int i=0; i < size; i++)
                    std::cout<<mas.Get(i)<<" ";


                while(true){
                    SequenceMenu();

                    char user_input_2[20];
                    std::cin>>user_input_2;

                    if(strcmp(user_input_2, "STOP") == 0){
                        break;
                    }

                    int option = atoi(user_input_2);

                    switch(option){
                        case 1:{
                            std::cout<<"\nFirst element: "<<mas.GetFirst();
                            break;
                        }


                        case 2:{
                            std::cout<<"\nLast element: "<<mas.GetLast();
                            break;
                        }


                        case 3:{
                            int index;

                            std::cout<<"\nEnter number of the element: ";

                            std::cin>>index;
                            index--;

                            if(index < 0 || index >= size){
                                std::cout<<"\nError: This element doesn't exist\n";
                            }

                            index++;
                            std::cout<<"Element number "<<index<<": "<<mas.Get(index);

                            break;
                        }


                        case 4:{
                            std::cout<<"\nLength of the sequence: "<<mas.GetLength();
                            break;
                        }


                        case 5:{
                            int start_index;
                            std::cout<<"\nEnter the number of the first element of the sub sequence: ";
                            std::cin>>start_index;
                            start_index--;

                            if(start_index < 0 || start_index >= size)
                                std::cout<<"\nError: The number of the first element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            int end_index;
                            std::cout<<"\nEnter the number of the last element of the sub sequence: ";
                            std::cin>>end_index;
                            end_index--;

                            if(end_index < 0 || end_index >= size)
                                std::cout<<"\nError: The number of the last element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            if(start_index > end_index)
                                std::cout<<"\nError: The number of the first element can't be greater than the number of the last element\n";

                            MutableArraySequence<double>* sub = mas.GetSubSequence(start_index,end_index);

                            std::cout<<"\nYour sub sequence: ";
                            for(int i=0; i < end_index; i++)
                                std::cout<<sub->Get(i)<<" ";

                            delete sub;
                            break;
                        }


                        case 6:{
                            int index;
                            std::cout<<"\nEnter the number of the element you want to change: ";
                            std::cin>>index;
                            index--;

                            double value;
                            std::cout<<"\nEnter the value that you want to assign: ";
                            std::cin>>value;

                            mas.Set(index,value);

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 7:{
                            double value;
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Append(value);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 8:{
                            double value;
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Prepend(value);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 9:{
                            int index;
                            std::cout<<"\nEnter the number of the place where you want to insert the element: ";
                            std::cin>>index;
                            index--;

                            double value;
                            std::cout<<"\nEnter the element you want to insert: ";
                            std::cin>>value;

                            mas.InsertAt(value, index);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 10:{
                            MutableArraySequence<double>* concat = mas.Concat(mas);

                            std::cout<<"\nYour concat sequence: ";
                            for(int i=0; i < size*2; i++)
                                std::cout<<concat->Get(i)<<" ";

                            delete concat;
                            break;
                        }


                        case 11:{
                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        default:{
                            std::cout<<"\nError: This action doesn't exist. Please try again";
                            break;
                        }
                    }
                }
                mas.~MutableArraySequence();

                break;
            }




            case 3:{
                std::cout<<"\nEnter the size of the sequence: ";
                int size;
                std::cin>>size;

                if(size <= 0){
                    std::cout<<"\nError: Size can't less than or equal to 0\n";
                    break;
                }

                char* array[size];

                for(int i=0; i < size; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>array[i];
                }

                MutableArraySequence<char*> mas(array, size);

                std::cout<<"\nYour sequence: ";
                for(int i=0; i < size; i++)
                    std::cout<<mas.Get(i)<<" ";


                while(true){
                    SequenceMenu();

                    char user_input_2[20];
                    std::cin>>user_input_2;

                    if(strcmp(user_input_2, "STOP") == 0){
                        break;
                    }

                    int option = atoi(user_input_2);

                    switch(option){
                        case 1:{
                            std::cout<<"\nFirst element: "<<mas.GetFirst();
                            break;
                        }


                        case 2:{
                            std::cout<<"\nLast element: "<<mas.GetLast();
                            break;
                        }


                        case 3:{
                            int index;

                            std::cout<<"\nEnter number of the element: ";

                            std::cin>>index;
                            index--;

                            if(index < 0 || index >= size){
                                std::cout<<"\nError: This element doesn't exist\n";
                            }

                            std::cout<<"Element number"<<index<<": "<<mas.Get(index);

                            break;
                        }


                        case 4:{
                            std::cout<<"\nLength of the sequence: "<<mas.GetLength();
                            break;
                        }


                        case 5:{
                            int start_index;
                            std::cout<<"\nEnter the number of the first element of the sub sequence: ";
                            std::cin>>start_index;
                            start_index--;

                            if(start_index < 0 || start_index >= size)
                                std::cout<<"\nError: The number of the first element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            int end_index;
                            std::cout<<"\nEnter the number of the last element of the sub sequence: ";
                            std::cin>>end_index;
                            end_index--;

                            if(end_index < 0 || end_index >= size)
                                std::cout<<"\nError: The number of the last element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            if(start_index > end_index)
                                std::cout<<"\nError: The number of the first element can't be greater than the number of the last element\n";

                            MutableArraySequence<char*>* sub = mas.GetSubSequence(start_index,end_index);

                            std::cout<<"\nYour sub sequence: ";
                            for(int i=0; i < end_index; i++)
                                std::cout<<sub->Get(i)<<" ";

                            delete sub;
                            break;
                        }


                        case 6:{
                            int index;
                            std::cout<<"\nEnter the number of the element you want to change: ";
                            std::cin>>index;
                            index--;

                            char value[20];
                            std::cout<<"\nEnter the value that you want to assign: ";
                            std::cin>>value;

                            mas.Set(index,value);

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 7:{
                            char value[20];
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Append(value);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 8:{
                            char value[20];
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Prepend(value);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 9:{
                            int index;
                            std::cout<<"\nEnter the number of the place where you want to insert the element: ";
                            std::cin>>index;
                            index--;

                            char value[20];
                            std::cout<<"\nEnter the element you want to insert: ";
                            std::cin>>value;

                            mas.InsertAt(value, index);
                            size++;

                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        case 10:{
                            MutableArraySequence<char*>* concat = mas.Concat(mas);

                            std::cout<<"\nYour concat sequence: ";
                            for(int i=0; i < size*2; i++)
                                std::cout<<concat->Get(i)<<" ";

                            delete concat;
                            break;
                        }


                        case 11:{
                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        default:{
                            std::cout<<"\nError: This action doesn't exist. Please try again";
                            break;
                        }
                    }
                }
                mas.~MutableArraySequence();
                break;
            }




            case 4:{
                return;
            }




            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                return;
            }
        }
    }



}


void OptionListSequence(){

    while(true){
        std::cout<<"\nWhat type of elements do you want?\n";
        std::cout<<"\nEnter <1> for int";
        std::cout<<"\nEnter <2> for double";
        std::cout<<"\nEnter <3> to char\n";
        std::cout<<"\nEnter <4> to go back\n";
        std::cout<<"\nChoose action: ";

        char user_input_1[20];

        std::cin>>user_input_1;
        int action = atoi(user_input_1);

        switch(action){
            case 1:{

                std::cout<<"\nEnter the size of the sequence: ";
                int size;
                std::cin>>size;

                if(size <= 0){
                    std::cout<<"\nError: Size can't less than or equal to 0\n";
                    break;
                }

                int array[size];

                for(int i=0; i < size; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>array[i];
                }

                MutableListSequence<int> mas(array, size);

                std::cout<<"\nYour sequence: ";
                for(int i=0; i < size; i++)
                    std::cout<<mas.Get(i)<<" ";


                while(true){
                    SequenceMenu();

                    char user_input_2[20];
                    std::cin>>user_input_2;

                    if(strcmp(user_input_2, "STOP") == 0){
                        break;
                    }

                    int option = atoi(user_input_2);

                    switch(option){
                        case 1:{
                            std::cout<<"\nFirst element: "<<mas.GetFirst();
                            break;
                        }


                        case 2:{
                            std::cout<<"\nLast element: "<<mas.GetLast();
                            break;
                        }


                        case 3:{
                            int index;

                            std::cout<<"\nEnter number of the element: ";

                            std::cin>>index;
                            index--;

                            if(index < 0 || index >= size){
                                std::cout<<"\nError: This element doesn't exist\n";
                            }

                            std::cout<<mas.Get(index);

                            break;
                        }


                        case 4:{
                            std::cout<<"\nLength of the sequence: "<<mas.GetLength();
                            break;
                        }


                        case 5:{
                            int start_index;
                            std::cout<<"\nEnter the number of the first element of the sub sequence: ";
                            std::cin>>start_index;
                            start_index--;

                            if(start_index < 0 || start_index >= size)
                                std::cout<<"\nError: The number of the first element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            int end_index;
                            std::cout<<"\nEnter the number of the last element of the sub sequence: ";
                            std::cin>>end_index;
                            end_index--;

                            if(end_index < 0 || end_index >= size)
                                std::cout<<"\nError: The number of the last element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            if(start_index > end_index)
                                std::cout<<"\nError: The number of the first element can't be greater than the number of the last element\n";

                            MutableListSequence<int>* sub = mas.GetSubSequence(start_index,end_index);

                            std::cout<<"\nYour sub sequence: ";
                            for(int i=0; i < end_index; i++)
                                std::cout<<sub->Get(i)<<" ";

                            delete sub;
                            break;
                        }


                        case 6:{
                            int index;
                            std::cout<<"\nEnter the number of the element you want to change: ";
                            std::cin>>index;
                            index--;

                            int value;
                            std::cout<<"\nEnter the value that you want to assign: ";
                            std::cin>>value;

                            mas.Set(index,value);

                            break;
                        }


                        case 7:{
                            int value;
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Append(value);

                            break;
                        }


                        case 8:{
                            int value;
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Prepend(value);

                            break;
                        }


                        case 9:{
                            int index;
                            std::cout<<"\nEnter the number of the place where you want to insert the element: ";
                            std::cin>>index;
                            index--;

                            int value;
                            std::cout<<"\nEnter the element you want to insert: ";
                            std::cin>>value;

                            mas.InsertAt(value, index);

                            break;
                        }


                        case 10:{
                            MutableListSequence<int>* concat = mas.Concat(mas);

                            std::cout<<"\nYour concat sequence: ";
                            for(int i=0; i < size*2; i++)
                                std::cout<<concat->Get(i)<<" ";

                            delete concat;
                            break;
                        }


                        case 11:{
                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        default:{
                            std::cout<<"\nError: This action doesn't exist. Please try again";
                            break;
                        }
                    }
                }
                mas.~MutableListSequence();

                break;
            }




            case 2:{
                std::cout<<"\nEnter the size of the sequence: ";
                int size;
                std::cin>>size;

                if(size <= 0){
                    std::cout<<"\nError: Size can't less than or equal to 0\n";
                    break;
                }

                double array[size];

                for(int i=0; i < size; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>array[i];
                }

                MutableListSequence<double> mas(array, size);

                std::cout<<"\nYour sequence: ";
                for(int i=0; i < size; i++)
                    std::cout<<mas.Get(i)<<" ";


                while(true){
                    SequenceMenu();

                    char user_input_2[20];
                    std::cin>>user_input_2;

                    if(strcmp(user_input_2, "STOP") == 0){
                        break;
                    }

                    int option = atoi(user_input_2);

                    switch(option){
                        case 1:{
                            std::cout<<"\nFirst element: "<<mas.GetFirst();
                            break;
                        }


                        case 2:{
                            std::cout<<"\nLast element: "<<mas.GetLast();
                            break;
                        }


                        case 3:{
                            int index;

                            std::cout<<"\nEnter number of the element: ";

                            std::cin>>index;
                            index--;

                            if(index < 0 || index >= size){
                                std::cout<<"\nError: This element doesn't exist\n";
                            }

                            std::cout<<mas.Get(index);

                            break;
                        }


                        case 4:{
                            std::cout<<"\nLength of the sequence: "<<mas.GetLength();
                            break;
                        }


                        case 5:{
                            int start_index;
                            std::cout<<"\nEnter the number of the first element of the sub sequence: ";
                            std::cin>>start_index;
                            start_index--;

                            if(start_index < 0 || start_index >= size)
                                std::cout<<"\nError: The number of the first element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            int end_index;
                            std::cout<<"\nEnter the number of the last element of the sub sequence: ";
                            std::cin>>end_index;
                            end_index--;

                            if(end_index < 0 || end_index >= size)
                                std::cout<<"\nError: The number of the last element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            if(start_index > end_index)
                                std::cout<<"\nError: The number of the first element can't be greater than the number of the last element\n";

                            MutableListSequence<double>* sub = mas.GetSubSequence(start_index,end_index);

                            std::cout<<"\nYour sub sequence: ";
                            for(int i=0; i < end_index; i++)
                                std::cout<<sub->Get(i)<<" ";

                            delete sub;
                            break;
                        }


                        case 6:{
                            int index;
                            std::cout<<"\nEnter the number of the element you want to change: ";
                            std::cin>>index;
                            index--;

                            double value;
                            std::cout<<"\nEnter the value that you want to assign: ";
                            std::cin>>value;

                            mas.Set(index,value);

                            break;
                        }


                        case 7:{
                            double value;
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Append(value);

                            break;
                        }


                        case 8:{
                            double value;
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Prepend(value);

                            break;
                        }


                        case 9:{
                            int index;
                            std::cout<<"\nEnter the number of the place where you want to insert the element: ";
                            std::cin>>index;
                            index--;

                            double value;
                            std::cout<<"\nEnter the element you want to insert: ";
                            std::cin>>value;

                            mas.InsertAt(value, index);

                            break;
                        }


                        case 10:{
                            MutableListSequence<double>* concat = mas.Concat(mas);

                            std::cout<<"\nYour concat sequence: ";
                            for(int i=0; i < size*2; i++)
                                std::cout<<concat->Get(i)<<" ";

                            delete concat;
                            break;
                        }


                        case 11:{
                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        default:{
                            std::cout<<"\nError: This action doesn't exist. Please try again";
                            break;
                        }
                    }
                }
                mas.~MutableListSequence();

                break;
            }




            case 3:{
                std::cout<<"\nEnter the size of the sequence: ";
                int size;
                std::cin>>size;

                if(size <= 0){
                    std::cout<<"\nError: Size can't less than or equal to 0\n";
                    break;
                }

                char* array[size];

                for(int i=0; i < size; i++){
                    std::cout<<"\nEnter element "<<i + 1<<": ";
                    std::cin>>array[i];
                }

                MutableListSequence<char*> mas(array, size);

                std::cout<<"\nYour sequence: ";
                for(int i=0; i < size; i++)
                    std::cout<<mas.Get(i)<<" ";


                while(true){
                    SequenceMenu();

                    char user_input_2[20];
                    std::cin>>user_input_2;

                    if(strcmp(user_input_2, "STOP") == 0){
                        break;
                    }

                    int option = atoi(user_input_2);

                    switch(option){
                        case 1:{
                            std::cout<<"\nFirst element: "<<mas.GetFirst();
                            break;
                        }


                        case 2:{
                            std::cout<<"\nLast element: "<<mas.GetLast();
                            break;
                        }


                        case 3:{
                            int index;

                            std::cout<<"\nEnter number of the element: ";

                            std::cin>>index;
                            index--;

                            if(index < 0 || index >= size){
                                std::cout<<"\nError: This element doesn't exist\n";
                            }

                            std::cout<<mas.Get(index);

                            break;
                        }


                        case 4:{
                            std::cout<<"\nLength of the sequence: "<<mas.GetLength();
                            break;
                        }


                        case 5:{
                            int start_index;
                            std::cout<<"\nEnter the number of the first element of the sub sequence: ";
                            std::cin>>start_index;
                            start_index--;

                            if(start_index < 0 || start_index >= size)
                                std::cout<<"\nError: The number of the first element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            int end_index;
                            std::cout<<"\nEnter the number of the last element of the sub sequence: ";
                            std::cin>>end_index;
                            end_index--;

                            if(end_index < 0 || end_index >= size)
                                std::cout<<"\nError: The number of the last element can't be less than 0, equal to 0 or greater than size of the sequence\n";

                            if(start_index > end_index)
                                std::cout<<"\nError: The number of the first element can't be greater than the number of the last element\n";

                            MutableListSequence<char*>* sub = mas.GetSubSequence(start_index,end_index);

                            std::cout<<"\nYour sub sequence: ";
                            for(int i=0; i < end_index; i++)
                                std::cout<<sub->Get(i)<<" ";

                            delete sub;
                            break;
                        }


                        case 6:{
                            int index;
                            std::cout<<"\nEnter the number of the element you want to change: ";
                            std::cin>>index;
                            index--;

                            char value[20];
                            std::cout<<"\nEnter the value that you want to assign: ";
                            std::cin>>value;

                            mas.Set(index,value);

                            break;
                        }


                        case 7:{
                            char value[20];
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Append(value);

                            break;
                        }


                        case 8:{
                            char value[20];
                            std::cout<<"\nEnter the element you want to add: ";
                            std::cin>>value;

                            mas.Prepend(value);

                            break;
                        }


                        case 9:{
                            int index;
                            std::cout<<"\nEnter the number of the place where you want to insert the element: ";
                            std::cin>>index;
                            index--;

                            char value[20];
                            std::cout<<"\nEnter the element you want to insert: ";
                            std::cin>>value;

                            mas.InsertAt(value, index);

                            break;
                        }


                        case 10:{
                            MutableListSequence<char*>* concat = mas.Concat(mas);

                            std::cout<<"\nYour concat sequence: ";
                            for(int i=0; i < size*2; i++)
                                std::cout<<concat->Get(i)<<" ";

                            delete concat;
                            break;
                        }


                        case 11:{
                            std::cout<<"\nYour sequence: ";
                            for(int i=0; i < size; i++)
                                std::cout<<mas.Get(i)<<" ";

                            break;
                        }


                        default:{
                            std::cout<<"\nError: This action doesn't exist. Please try again";
                            break;
                        }
                    }
                }
                mas.~MutableListSequence();
                break;
            }




            case 4:{
                return;
            }




            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                return;
            }
        }
    }
}



void MainMenu() {
    std::cout<<"\n--------------------------Menu--------------------------\n";
    std::cout<<"Enter <1> to create a sequence\n";
    std::cout<<"Enter <2> to finish\n";
    std::cout<<"Choose action: ";
}


void UserInterface(){

    while(true){

        MainMenu();

        char user_input_1[20];

        std::cin>>user_input_1;

        int action = atoi(user_input_1);

        switch(action){
            case 1:{
                while(true){
                    std::cout<<"\nWhat type of sequence do you want to create?\n";
                    std::cout<<"\nEnter <1> for Array Sequence";
                    std::cout<<"\nEnter <2> for List Sequence";
                    std::cout<<"\nEnter <3> to finish\n";
                    std::cout<<"\nChoose action: ";

                    char user_input_2[20];

                    std::cin>>user_input_2;
                    action = atoi(user_input_2);

                    switch(action){
                        case 1:{
                            OptionArraySequence();
                            break;
                        }

                        case 2:{
                            OptionListSequence();
                            break;
                        }

                        case 3:{
                            exit(0);
                        }

                        default:{
                            std::cout<<"\nError: This action doesn't exist. Please try again";
                            break;
                        }
                    }
                }
            }
            case 2:{
                exit(0);
            }
            default:{
                std::cout<<"\nError: This action doesn't exist. Please try again";
                break;
            }
        }
    }
}