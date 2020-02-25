//
// Created by Admin on 25.02.2020.
//

#include "modes.h"
#include "source.h"


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

void demonstration(){

}

void benchmark(){

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
            stack.peekOfArr();
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
            stack.peekOfVec();
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
            stack.peekOfList();
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

Circle inputCircle(){
    double x, y, radius;
    std::cout << "Enter x and y of the center of circle and radius\n";
    std::cin >> x >> y >> radius;
    Circle tempCircle(x,y,radius);
    return tempCircle;
}