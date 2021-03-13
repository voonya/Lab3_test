#include "func.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <ctime>


#define fs filesystem
#define SIZE_OF_TABLE 100000
const auto n = 100000;
using namespace std;




/*void init_dict(item_Dict dictionary[n]) {
	for (int i = 0; i < SIZE_OF_TABLE; i++) {
		dictionary[i] = nullptr;
	}
}*/

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

item_Dict parse_line(string line) {
	item_Dict w;
	string word = line.substr(0, line.find(";"));
	string def = line.substr(line.find(";") + 1, string::npos);
	w.key = word;
	w.value = def;
	return w;
}

int parse_dict(string path, item_Dict dict[n]) {
	ifstream in_file(path);
	if (in_file.is_open()) {
		int counter = 0;
		while (!in_file.eof()) {
			string word_line;
			getline(in_file, word_line);
			item_Dict curr = parse_line(word_line);
			unsigned long int hash = hash_func(curr.key);
			if(dictionary[hash] != )

			counter++;
		}
		return counter;
	}
	else {
		cout << "Can`t open the file";
	}
}









string find_def(string word, item_Dict dict[n],int count_words) {
	for (int i = 0; i < count_words; i++) {
		if (word == dict[i].key) {
			return dict[i].value;
		}
	}
	return "Can`t find this word\n";
}



int main()
{
	/*
	string file_name = "dict.txt";
	string path = fs::current_path().string() + "/" + file_name;
	int count_words = parse_dict(path, dictionary);
	string word = input_word();
	int start = clock();
	cout << find_def(word,dictionary,count_words);
	int end = clock();
	cout << (end - start) / 1000. << "s" << " " << count_words ;*/
	Hash_table dictionary(SIZE_OF_TABLE);

}
//176 back; 219


/*void loadingBar(){
	cout << "\n\n" << "    Parsing dictionary..." << "\n\n  ";
	for (int i = 0; i < 26; i++) {
		cout << char(176);
	}
	cout << "\r ";
	for (int i = 0; i < 26; i++) {
		cout << char(219);
		//Sleep(500);
	}
	cout << "\n\n\    Done\n";
}*/