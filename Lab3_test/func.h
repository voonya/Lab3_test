#include <string>
#include <iostream>

using namespace std;

struct item_Dict {
	string key;
	string value;
};

struct list_item {
	item_Dict value;
	list_item* next;
};

class linked_list {
	list_item* start;
	list_item* end;
	int count_el;
public:
	linked_list() {
		start = NULL;
		end = NULL;
		count_el = 0;
	}
	void push_back(item_Dict item) {
		list_item* curr = new list_item;
		curr->value = item;
		curr->next = NULL;
		if (start == NULL && end == NULL) {
			start = curr;
			end = curr;
		}
		else {
			end->next = curr;
			end = curr;
		}
		count_el++;
	}
	int size() {
		return count_el;
	}
	void show_list() {
		list_item* ptr = start;
		for (int i = 0; i < count_el; i++) {
			cout << ptr->value.key << " " << ptr->value.value << endl;
			ptr = ptr->next;
		}
	}
};


class Hash_table {
	int size;
	int count_el;
	item_Dict* table;
public:
	Hash_table(int size_t) {
		size = size_t;
		table = new item_Dict[size];
	}

};