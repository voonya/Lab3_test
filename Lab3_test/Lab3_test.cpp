#include "func.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <ctime>


#define fs filesystem
#define SIZE_OF_TABLE 2500 


using namespace std;





string standard_str(string str) {
	string str_cpy = str;
	for (int i = 0; i < str_cpy.length();i++) {
		if (islower(str[i])) {
			str_cpy[i] = toupper(str[i]);
		}
	}
	return str_cpy;
}

string input_word() {
	string word;
	cout << "Input word to get definition: ";
	cin >> word;
	return standard_str(word);
}

unsigned long int hash_func(string str)
{
	unsigned long int hash_val = 0;
	for (int i = 0; i < str.length(); i++) {
		hash_val += str[i];
	}
	return hash_val % SIZE_OF_TABLE;
}

item_table parse_line(string line) {
	item_table w;
	string word = line.substr(0, line.find(";"));
	string def = line.substr(line.find(";") + 1, string::npos);
	w.key = word;
	w.value = def;
	return w;
}

void parse_dict(string path, Hash_table dict) {
	ifstream in_file(path);
	if (in_file.is_open()) {
		while (!in_file.eof()) {
			string word_line;
			getline(in_file, word_line);
			item_table curr = parse_line(word_line);
			unsigned long int hash = hash_func(curr.key);
			dict.add_element(hash, curr);
		}
	}
	else {
		cout << "Can`t open the file";
	}
}

string search(Hash_table dict, string word) {
	linked_list list = dict.table[hash_func(word)];
	string def = list.find_el(word);
	if (def != "0") {
		return def;
	}
	return "Dicitonary doesn`t have this element";
}

/*void analyze_table(Hash_table dict) {
	int index_max;
	int max = 0;
	for (int i = 0; i < dict.size(); i++) {
		if (!dict.table[i].is_empty() && dict.table[i].size() > max) {
			index_max = i;
			max = dict.table[i].size();
		}
	}
	cout << index_max << "has " << max << "elements " << "Last word is: " << dict.table[index_max].get_last().key;
}*/


int main()
{
	
	string file_name = "dict.txt";
	string path = fs::current_path().string() + "/" + file_name;
	
	Hash_table dictionary(SIZE_OF_TABLE);

	cout << " Preparing dictionary...\n\n";
	cout << "======================================\n\n";

	//parse_dict(path, dictionary);

	cout << " Done\n\n======================================\n\n";

	string word = input_word();

	int start = clock();
	cout << search(dictionary, standard_str(word));
	int end = clock();

	cout << (end - start)<< " ms" << endl;

	
}



