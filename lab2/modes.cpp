//
// Created by Admin on 25.02.2020.
//

#include "modes.h"
#include "source.h"

///---------------------Interactive----------------------///
void interactive(){
    bool isContinuedInteractive = true;
    while (isContinuedInteractive) {
        std::cout << "\nSelect data structure:\n"
                  << "1 - stack with new array\n"
                  << "2 - stack with new vector\n"
                  << "3 - stack with new list\n"
                  << "4 - exit interactive mode\n\n";

        int action;
        std::cin >> action;
        isContinuedInteractive = chooseStructure(action);
    }
}

bool chooseStructure(int action){
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
        case 4:
            return false;
        default:
            std::cout << "Wrong number\n";
    }
    return true;
}

void workWithArray(){
    Stack<Circle> stack;
    bool isContinuedArray = true;
    while (isContinuedArray) {
        std::cout << "\nSelect action\n"
                  << "1 - create_empty\n"
                  << "2 - push\n"
                  << "3 - pop\n"
                  << "4 - peek\n"
                  << "5 - is_empty\n"
                  << "6 - cout array\n"
                  << "7 - generate N elements and push\n"
                  << "8 - exit array structure stack\n\n";

        int action;
        std::cin >> action;
        isContinuedArray = chooseArrayAction(action, stack);
    }
}

bool chooseArrayAction(int action, Stack<Circle>& stack){

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
            if (stack.isEmptyArr() == 0)
                std::cout << "Array isn't empty\n" << std::endl;
            else
                std::cout << "Array is empty\n" << std::endl;
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
        case 8:
            return false;
        default:
            std::cout << "Wrong number\n";
            break;

    }
    return true;
}

void workWithVector(){
    Stack<Circle> stack;
    bool isContinuedVector = true;
    while (isContinuedVector) {
        std::cout << "\nSelect action\n"
                  << "1 - create_empty\n"
                  << "2 - push\n"
                  << "3 - pop\n"
                  << "4 - peek\n"
                  << "5 - is_empty\n"
                  << "6 - cout vector\n"
                  << "7 - generate N elements and push\n"
                  << "8 - exit vector structure stack\n\n";

        int action;
        std::cin >> action;
        isContinuedVector = chooseVectorAction(action, stack);
    }
}

bool chooseVectorAction(int action, Stack<Circle>& stack){
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
            if (stack.isEmptyVec() == 0)
                std::cout << "Vector isn't empty\n" << std::endl;
            else
                std::cout << "Vector is empty\n" << std::endl;
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
        case 8:
            return false;
        default:
            std::cout << "Wrong number\n";
            break;
    }
    return true;
}

void workWithList(){
    Stack<Circle> stack;
    bool isContinuedList = true;
    while (isContinuedList) {
        std::cout << "\nSelect action\n"
                  << "1 - create_empty\n"
                  << "2 - push\n"
                  << "3 - pop\n"
                  << "4 - peek\n"
                  << "5 - is_empty\n"
                  << "6 - cout list\n"
                  << "7 - generate N elements and push\n"
                  << "8 - exit linked list structure stack\n\n";

        int action;
        std::cin >> action;
        isContinuedList = chooseListAction(action, stack);
    }
}

bool chooseListAction(int action, Stack<Circle>& stack){

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
            if (stack.isEmptyList() == 0)
                std::cout << "List isn't empty\n" << std::endl;
            else
                std::cout << "List is empty\n" << std::endl;
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
        case 8:
            return false;
        default:
            std::cout << "Wrong number\n";
            break;
    }
    return true;
}

///---------------------DEMO-------------------///

void demonstration(){
    Stack<Circle> stack;
    std::cout << "We have created Stack with type Circle(x,y,radius)\n";
    std::cout << "----------------------------ARRAY DEMO----------------------------\n" << std::endl;
    demoArr(stack);
    std::cout << "----------------------------VECTOR DEMO---------------------------\n"<< std::endl;
    demoVec(stack);
    std::cout << "----------------------------LINKEDLIST DEMO-----------------------\n"<< std::endl;
    demoList(stack);
    std::cout << std::endl;
}

void demoArr(Stack<Circle> stack){
    std::cout << "We have created Stack with type Circle(x,y,radius)\n"
              << "Let's push an element to stack\n";
    Circle tempCircle(1,2,3);
    stack.pushToArr(tempCircle);
    std::cout << "Now we have in stack:\n";
    stack.coutArr();
    std::cout << "-----------------------------------------\n";
    std::cout << "generate 10 elements to stack\n";
    stack.generateToArr(10);
    stack.coutArr();
    std::cout << "-----------------------------------------\n";
    std::cout << "pop from stack\n";
    stack.popFromArr();
    stack.coutArr();
    std::cout << "-----------------------------------------\n";
    std::cout << "peek of stack\n";
    std::cout << stack.peekOfArr() << std::endl;
    std::cout << "-----------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyArr() << std::endl;
    std::cout << "-----------------------------------------\n";
    std::cout << "create_empty stack\n";
    stack.createEmptyArr();
    stack.coutArr();
    std::cout << "-----------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyArr() << std::endl;
}

void demoVec(Stack<Circle> stack){
    std::cout << "Let's push an element to stack\n";
    Circle tempCircle(1,2,3);
    stack.pushToVec(tempCircle);
    std::cout << "Now we have in stack:\n";
    stack.coutVec();
    std::cout << "-----------------------------------------\n";
    std::cout << "generate 10 elements to stack\n";
    stack.generateToVec(10);
    stack.coutVec();
    std::cout << "-----------------------------------------\n";
    std::cout << "pop from stack\n";
    stack.popFromVec();
    stack.coutVec();
    std::cout << "-----------------------------------------\n";
    std::cout << "peek of stack\n";
    std::cout << stack.peekOfVec() << std::endl;
    std::cout << "-----------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyVec() << std::endl;
    std::cout << "-----------------------------------------\n";
    std::cout << "create_empty stack\n";
    stack.createEmptyVec();
    stack.coutVec();
    std::cout << "-----------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyVec() << std::endl;
}

void demoList(Stack<Circle> stack){
    std::cout << "Let's push an element to stack\n";
    Circle tempCircle(1,2,3);
    stack.pushToList(tempCircle);
    std::cout << "Now we have in stack:\n";
    stack.coutList();
    std::cout << "-----------------------------------------\n";
    std::cout << "generate 10 elements to stack\n";
    stack.generateToList(10);
    stack.coutList();
    std::cout << "-----------------------------------------\n";
    std::cout << "pop from stack\n";
    stack.popFromList();
    stack.coutList();
    std::cout << "-----------------------------------------\n";
    std::cout << "peek of stack\n";
    std::cout << stack.peekOfList() << std::endl;
    std::cout << "-----------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyList() << std::endl;
    std::cout << "-----------------------------------------\n";
    std::cout << "create_empty stack\n";
    stack.createEmptyList();
    stack.coutList();
    std::cout << "-----------------------------------------\n";
    std::cout << "is_empty stack?\n";
    std::cout << stack.isEmptyList() << std::endl;
    std::cout << "-----------------------------------------\n";
}

///-----------------------BENCHMARK--------------------///

void benchmark(){
    benchmarkArr();
    benchmarkVec();
    benchmarkList();
}

void benchmarkArr(){
    Stack<Circle> stack;
    Circle tempToPush(1,2,3);

    std::cout << "STARTING BENCHMARK FOR ARRAY\nTIME:" << std::endl;

    double timePushStart = clock();
    for(int i = 0; i < 100*MAX_ARR_SIZE; i++) {
        stack.pushToArr(tempToPush);
        stack.popFromArr();
    }
    double timePushEnd = clock();
    double timePush = (timePushEnd - timePushStart) / CLOCKS_PER_SEC;
    std::cout << "push&pop " << 100*MAX_ARR_SIZE << " times = " << timePush << std::endl;

    double timeGeneratingStart = clock();
    for(int i = 0; i < 100; i++) {
        stack.generateToArr(MAX_ARR_SIZE);
        stack.createEmptyArr();
    }
    double timeGeneratingEnd = clock();
    double timeGenerating = (timeGeneratingEnd - timeGeneratingStart) / CLOCKS_PER_SEC;
    std::cout << "Generating " << MAX_ARR_SIZE  << " elements 100 times and create empty each time = " << timeGenerating << std::endl;

    double timePeekStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.peekOfArr();
    double timePeekEnd = clock();
    double timePeek = (timePeekEnd - timePeekStart) / CLOCKS_PER_SEC;
    std::cout << "peek " << 100*MAX_ARR_SIZE << " = " << timePeek << std::endl;

    double timeIsEmptyStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.isEmptyArr();
    double timeIsEmptyEnd = clock();
    double timeIsEmpty = (timeIsEmptyEnd - timeIsEmptyStart) / CLOCKS_PER_SEC;
    std::cout << "is_empty " << 100*MAX_ARR_SIZE << " times = " << timeIsEmpty << std::endl;

    double timeCreatingEmptyStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.createEmptyArr();
    double timeCreatingEmptyEnd = clock();
    double timeCreatingEmpty = (timeCreatingEmptyEnd - timeCreatingEmptyStart) / CLOCKS_PER_SEC;
    std::cout << "create_empty " << 100*MAX_ARR_SIZE << " times = " << timeCreatingEmpty << std::endl;

    stack.generateToArr(MAX_ARR_SIZE);
    std::cout << "size of " << MAX_ARR_SIZE << " elements = " << stack.sizeOfArr() << "KB" << std::endl;

    std::cout << "THE END FOR ARRAY" << std::endl << std::endl;
}

void benchmarkVec(){
    Stack<Circle> stack;
    Circle tempToPush(1,2,3);

    std::cout << "STARTING BENCHMARK FOR VECTOR\nTIME:" << std::endl;

    double timePushStart = clock();
    for(int i = 0; i < 100*MAX_ARR_SIZE; i++) {
        stack.pushToVec(tempToPush);
        stack.popFromVec();
    }
    double timePushEnd = clock();
    double timePush = (timePushEnd - timePushStart) / CLOCKS_PER_SEC;
    std::cout << "push&pop " << 100*MAX_ARR_SIZE << " times = " << timePush << std::endl;

    double timeGeneratingStart = clock();
    for(int i = 0; i < 100; i++) {
        stack.generateToVec(MAX_ARR_SIZE);
        stack.createEmptyVec();
    }
    double timeGeneratingEnd = clock();
    double timeGenerating = (timeGeneratingEnd - timeGeneratingStart) / CLOCKS_PER_SEC;
    std::cout << "Generating " << MAX_ARR_SIZE  << " elements 100 times and create empty each time = " << timeGenerating << std::endl;

    double timePeekStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.peekOfVec();
    double timePeekEnd = clock();
    double timePeek = (timePeekEnd - timePeekStart) / CLOCKS_PER_SEC;
    std::cout << "peek " << 100*MAX_ARR_SIZE << " = " << timePeek << std::endl;

    double timeIsEmptyStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.isEmptyVec();
    double timeIsEmptyEnd = clock();
    double timeIsEmpty = (timeIsEmptyEnd - timeIsEmptyStart) / CLOCKS_PER_SEC;
    std::cout << "is_empty " << 100*MAX_ARR_SIZE << " times = " << timeIsEmpty << std::endl;

    double timeCreatingEmptyStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.createEmptyVec();
    double timeCreatingEmptyEnd = clock();
    double timeCreatingEmpty = (timeCreatingEmptyEnd - timeCreatingEmptyStart) / CLOCKS_PER_SEC;
    std::cout << "create_empty " << 100*MAX_ARR_SIZE << " times = " << timeCreatingEmpty << std::endl;

    stack.generateToVec(MAX_ARR_SIZE);
    std::cout << "size of " << MAX_ARR_SIZE << " elements = " << stack.sizeOfVec() << "KB" << std::endl;

    std::cout << "THE END FOR VECTOR" << std::endl << std::endl;
}

void benchmarkList(){
    Stack<Circle> stack;
    Circle tempToPush(1,2,3);

    std::cout << "STARTING BENCHMARK FOR LIST\nTIME:" << std::endl;

    double timePushStart = clock();
    for(int i = 0; i < 100*MAX_ARR_SIZE; i++) {
        stack.pushToList(tempToPush);
        stack.popFromList();
    }
    double timePushEnd = clock();
    double timePush = (timePushEnd - timePushStart) / CLOCKS_PER_SEC;
    std::cout << "push&pop " << 100*MAX_ARR_SIZE << " times = " << timePush << std::endl;

    double timeGeneratingStart = clock();
    for(int i = 0; i < 100; i++) {
        stack.generateToList(MAX_ARR_SIZE);
        stack.createEmptyList();
    }
    double timeGeneratingEnd = clock();
    double timeGenerating = (timeGeneratingEnd - timeGeneratingStart) / CLOCKS_PER_SEC;
    std::cout << "Generating " << MAX_ARR_SIZE  << " elements 100 times and create empty each time = " << timeGenerating << std::endl;

    stack.pushToList(tempToPush);

    double timePeekStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.peekOfList();
    double timePeekEnd = clock();
    double timePeek = (timePeekEnd - timePeekStart) / CLOCKS_PER_SEC;
    std::cout << "peek " << 100*MAX_ARR_SIZE << " = " << timePeek << std::endl;

    double timeIsEmptyStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.isEmptyList();
    double timeIsEmptyEnd = clock();
    double timeIsEmpty = (timeIsEmptyEnd - timeIsEmptyStart) / CLOCKS_PER_SEC;
    std::cout << "is_empty " << 100*MAX_ARR_SIZE << " times = " << timeIsEmpty << std::endl;

    double timeCreatingEmptyStart = clock();
    for (int i = 0; i < 100*MAX_ARR_SIZE; i++)
        stack.createEmptyList();
    double timeCreatingEmptyEnd = clock();
    double timeCreatingEmpty = (timeCreatingEmptyEnd - timeCreatingEmptyStart) / CLOCKS_PER_SEC;
    std::cout << "create_empty " << 100*MAX_ARR_SIZE << " times = " << timeCreatingEmpty << std::endl;

    stack.generateToList(MAX_ARR_SIZE);
    std::cout << "size of " << MAX_ARR_SIZE << " elements = " << stack.sizeOfList() << "KB" << std::endl;

    std::cout << "THE END FOR LIST" << std::endl << std::endl;
}

///----------------------OTHER-------------------------///
Circle inputCircle(){
    double x, y, radius;
    std::cout << "Enter x and y of the center of circle and radius\n";
    std::cin >> x >> y >> radius;
    Circle tempCircle(x,y,radius);
    return tempCircle;
}