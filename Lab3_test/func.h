using namespace std;

struct item_Dict {
	string key;
	string value;
};

struct list_item {
	item_Dict value;
	item_Dict* next;
};

class linked_list {
	list_item* start;
	list_item* end;

	public:
		linked_list() {
			start = NULL;
			end = NULL;
		}
}
