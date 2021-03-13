#include <string>
#include <iostream>

using namespace std;

struct item_table {
	string key;
	string value;
	void show() {
		cout << key << " " << value << endl;
	}
};

struct list_item {
	item_table value;
	list_item* next;
};

class linked_list {
	list_item* start;
	list_item* end;
	int count_el;
	bool empty;
public:
	linked_list() {
		start = NULL;
		end = NULL;
		count_el = 0;
		empty = true;
	}
	void push_back(item_table item) {
		empty = false;
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
	string find_el(string word) {
		list_item* ptr = start;
		if (ptr != NULL) {
			for (int i = 0; i < count_el; i++) {
				if (ptr->value.key == word) {
					return ptr->value.value;
				}
				ptr = ptr->next;
			}
			
		}
		return "0";
	}
	void show_list() {
		list_item* ptr = start;
		for (int i = 0; i < count_el; i++) {
			cout << ptr->value.key << " " << ptr->value.value << endl;
			ptr = ptr->next;
		}
	}
	bool is_empty() {
		return empty;
	}
	item_table get_last() {
		return end->value;
	}
};


class Hash_table {
	int size_t;
	long unsigned int count_el;
public:
	linked_list* table;
	Hash_table(int s) {
		size_t = s;
		table = new linked_list[size_t];
		//for (int i = 0; i < size; i++) table[i] = NULL;
		count_el = 0;
	}
	void add_element(int index, item_table item) {
		if (table[index].is_empty()) count_el++;
		table[index].push_back(item);
	}
	int size() {
		return size_t;
	}
	int count_element() {
		return count_el;
	}
	void show() {
		int counter = 0;
		for (int i = 0; i < size_t; i++) {
			if (!table[i].is_empty()) {
				for (int j = 0; j < table[i].size(); i++) {
					cout << table[i].size() << endl;
					table[i].show_list();
					if (table[i].size() > 1) counter++;
				}
			}
			
		}
		cout << counter << endl;
	}
};