#include <iostream>


struct ListNode {
	int value;
	ListNode* prev;
	ListNode* next;
	ListNode(int value) {
		this->value = value;
		prev = next = nullptr;
	}
};

struct List {
	ListNode* head;
	ListNode* tail;
	size_t length;

	List() {
		head = nullptr;
		tail = nullptr;
		length = 0;
	}
	void push_back(int value) {
		ListNode * node = new ListNode(value);
		node->prev = tail;
		if (tail) {
			tail->next = node;
		}
		tail = node;
		if ( ! head) {
			head = node;
		}
		length++;
	}

	void insert(int value, int index){
	    ListNode* node = new ListNode(value);

        if (index > length){
            std::cout << "Index is more than length of list \n";
            return;
        }

	    if (index == length){
            ListNode* tempTail = tail;
            tail = node;
            tail->prev = tempTail;
            tempTail->next = tail;
            length++;
            return;
	    }

	    if (index == 0){
            ListNode* tempHead = head;
            head = node;
            head->next = tempHead;
            tempHead->prev = head;
            length++;
            return;
	    }

        ListNode* tempNodePrev = head;
        for (int i = 1; i < index; i++){
            tempNodePrev = tempNodePrev->next;
        }
        ListNode* tempNodeNext = tempNodePrev->next;

        node->prev = tempNodePrev;
        node->next = tempNodeNext;
        tempNodePrev->next = node;
        tempNodeNext->prev = node;

        length++;
	}

	void output(){
	    ListNode* current = head;
        for(int i = 0; i < length; i++){
            std::cout << "Index is " << i << " , value is " << current->value << '\n';
            current = current->next;
        }
	}
};



int main() {
	List my_list;
	my_list.push_back(228);
	my_list.push_back(322);
	my_list.push_back(1024);
	my_list.push_back(2024);
	int val, in;

	std::cout << "Enter value and index\n";
	std::cin >> val >> in;
	my_list.insert(val, in);
    my_list.output();
	return 0;
}
