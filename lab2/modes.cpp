//
// Created by Admin on 25.02.2020.
//

#include "modes.h"
#include "source.h"

///---------------------Interactive----------------------///
void interactive(){
    bool isContinuedInteractive = true;
    while (isContinuedInteractive) {
        std::cout << "Select data structure:\n"
                  << "1 - stack with new array\n"
                  << "2 - stack with new vector\n"
                  << "3 - stack with new list\n";

        int action;
        std::cin >> action;
        chooseStructure(action);

        std::cout << "Do you want to continue works in interactive mode? y/n\n";
        std::string userAnswer;
        std::cin >> userAnswer;
        isContinuedInteractive = userAnswer == "y";
    }
}

void chooseStructure(int action){
    switch(action){
        case 1:
            workWithArray();
            break;
        case 2:
            workWithVector();
            break;
        case 3:
            workWithList();
            break;
        default:
            std::cout << "Wrong number\n";
    }
}

void workWithArray(){
    Stack<Circle> stack;
    bool isContinuedArray = true;
    while (isContinuedArray) {
        std::cout << "Select action\n"
                  << "1 - create_empty\n"
                  << "2 - push\n"
                  << "3 - pop\n"
                  << "4 - peek\n"
                  << "5 - is_empty\n"
                  << "6 - cout array\n"
                  << "7 - generate N elements and push\n";

        int action;
        std::cin >> action;
        chooseArrayAction(action, stack);

        std::cout << "Do you want to continue works with array? y/n\n";
        std::string userAnswer;
        std::cin >> userAnswer;
        isContinuedArray = userAnswer == "y";
    }
}

void chooseArrayAction(int action, Stack<Circle>& stack){

    switch (action){
        case 1:
            stack.createEmptyArr();
            break;
        case 2:
            stack.pushToArr(inputCircle());
            break;
        case 3:
            stack.popFromArr();
            break;
        case 4:
            std::cout << stack.peekOfArr() << std::endl;
            break;
        case 5:
            std::cout << stack.isEmptyArr() << std::endl;
            break;
        case 6:
            stack.coutArr();
            break;
        case 7:
            int countOfElements;
            std::cout << "Enter the count of circle: ";
            std::cin >> countOfElements;
            stack.generateToArr(countOfElements);
            break;
        default:
            std::cout << "Wrong number\n";
            break;
    }
}

void workWithVector(){
    Stack<Circle> stack;
    bool isContinuedVector = true;
    while (isContinuedVector) {
        std::cout << "Select action\n"
                  << "1 - create_empty\n"
                  << "2 - push\n"
                  << "3 - pop\n"
                  << "4 - peek\n"
                  << "5 - is_empty\n"
                  << "6 - cout vector\n"
                  << "7 - generate N elements and push\n";

        int action;
        std::cin >> action;
        chooseVectorAction(action, stack);

        std::cout << "Do you want to continue works with vector? y/n\n";
        std::string userAnswer;
        std::cin >> userAnswer;
        isContinuedVector = userAnswer == "y";
    }
}

void chooseVectorAction(int action, Stack<Circle>& stack){

    switch (action){
        case 1:
            stack.createEmptyVec();
            break;
        case 2:
            stack.pushToVec(inputCircle());
            break;
        case 3:
            stack.popFromVec();
            break;
        case 4:
            std::cout << stack.peekOfVec() << std::endl;
            break;
        case 5:
            std::cout << stack.isEmptyVec() << std::endl;
            break;
        case 6:
            stack.coutVec();
            break;
        case 7:
            int countOfElements;
            std::cout << "Enter the count of circle: ";
            std::cin >> countOfElements;
            stack.generateToVec(countOfElements);
            break;
        default:
            std::cout << "Wrong number\n";
            break;
    }
}

void workWithList(){
    Stack<Circle> stack;
    bool isContinuedList = true;
    while (isContinuedList) {
        std::cout << "Select action\n"
                  << "1 - create_empty\n"
                  << "2 - push\n"
                  << "3 - pop\n"
                  << "4 - peek\n"
                  << "5 - is_empty\n"
                  << "6 - cout list\n"
                  << "7 - generate N elements and push\n";

        int action;
        std::cin >> action;
        chooseListAction(action, stack);

        std::cout << "Do you want to continue works with list? y/n\n";
        std::string userAnswer;
        std::cin >> userAnswer;
        isContinuedList = userAnswer == "y";
    }
}

void chooseListAction(int action, Stack<Circle>& stack){

    switch (action){
        case 1:
            stack.createEmptyList();
            break;
        case 2:
            stack.pushToList(inputCircle());
            break;
        case 3:
            stack.popFromList();
            break;
        case 4:
            std::cout << stack.peekOfList() << std::endl;
            break;
        case 5:
            std::cout << stack.isEmptyList() << std::endl;
            break;
        case 6:
            stack.coutList();
            break;
        case 7:
            int countOfElements;
            std::cout << "Enter the count of circle: ";
            std::cin >> countOfElements;
            stack.generateToList(countOfElements);
            break;
        default:
            std::cout << "Wrong number\n";
            break;
    }
}

///---------------------DEMO-------------------///

void demonstration(){
    std::cout << "------------------ARRAY DEMO--------------------\n" << std::endl;
    demoArr();
    std::cout << "------------------VECTOR DEMO--------------------\n"<< std::endl;
    demoVec();
    std::cout << "------------------LINKEDLIST DEMO--------------------\n"<< std::endl;
    demoList();
    std::cout << std::endl;
}

void demoArr(){
    Stack<Circle> stack;
    std::cout << "We have created Stack with type Circle(x,y,radius)\n"
              << "Let's push an element to stack\n";
    Circle tempCircle(1,2,3);
    stack.pushToArr(tempCircle);
    std::cout << "Now we have in stack:\n";
    stack.coutArr();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "generate 10 elements to stack\n";
    stack.generateToArr(10);
    stack.coutArr();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "pop from stack\n";
    stack.popFromArr();
    stack.coutArr();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "peek of stack\n";
    std::cout << stack.peekOfArr() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyArr() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "create_empty stack\n";
    stack.createEmptyArr();
    stack.coutArr();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyArr() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
}

void demoVec(){
    Stack<Circle> stack;
    std::cout << "We have created Stack with type Circle(x,y,radius)\n"
              << "Let's push an element to stack\n";
    Circle tempCircle(1,2,3);
    stack.pushToVec(tempCircle);
    std::cout << "Now we have in stack:\n";
    stack.coutVec();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "generate 10 elements to stack\n";
    stack.generateToVec(10);
    stack.coutVec();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "pop from stack\n";
    stack.popFromVec();
    stack.coutVec();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "peek of stack\n";
    std::cout << stack.peekOfVec() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyVec() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "create_empty stack\n";
    stack.createEmptyVec();
    stack.coutVec();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyVec() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
}

void demoList(){
    Stack<Circle> stack;
    std::cout << "We have created Stack with type Circle(x,y,radius)\n"
              << "Let's push an element to stack\n";
    Circle tempCircle(1,2,3);
    stack.pushToList(tempCircle);
    std::cout << "Now we have in stack:\n";
    stack.coutList();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "generate 10 elements to stack\n";
    stack.generateToList(10);
    stack.coutList();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "pop from stack\n";
    stack.popFromList();
    stack.coutList();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "peek of stack\n";
    std::cout << stack.peekOfList() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyList() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "create_empty stack\n";
    stack.createEmptyList();
    stack.coutList();
    std::cout << "-----------------------------------------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyList() << std::endl;
    std::cout << "-----------------------------------------------------------------------\n";
}

///-----------------------BENCHMARK--------------------///
void benchmark(){

}

Circle inputCircle(){
    double x, y, radius;
    std::cout << "Enter x and y of the center of circle and radius\n";
    std::cin >> x >> y >> radius;
    Circle tempCircle(x,y,radius);
    return tempCircle;
}