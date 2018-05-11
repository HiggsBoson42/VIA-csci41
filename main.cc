// TODO: sym: turn char letter to string
#include <iostream>
#include <algorithm>
#include <deque>
#include <array>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include "node.h"

using namespace std;

void walk(Node*, int);

// to convert char to string for sym struct
string get_string(unsigned char x) {
    string s(1, x);
    return s;
}

struct sym {
    string letter = ""; // actual letter
    uint32_t size = 0; // how many levels down the tree

    bool operator< (const sym &sy) const {
        if (this -> size != sy.size) { return this -> size < sy.size; }
        else { return this -> letter < sy.letter; }
    }
};

void levels(Node*, uint32_t, vector<sym>&);

bool sym_comp(const sym &a, const sym &b) { // use to sort vector<sym> by levels
    return a < b;
}

bool comp(Node *a, Node *b) {
    return a -> get_count() < b -> get_count();
}

int main() {
    ifstream my_file;
    unordered_map<unsigned char, int> map;
    array<int, 128> chars = {0};
    char letter;
    string filename;
    vector<Node*> elements;
    vector<sym> char_levels; // stores each letter and its levels (in sym)
    deque<string> just_strings; // stores just letters; order of letters matches that of char_levels

    // cout << "Enter your file path: ";
    // getline(cin, filename);
    my_file.open("./textfiles/lorem.txt");
    
    letter = my_file.get();

    while(!my_file.eof()) { 
        if (letter != ' ')
            chars.at(letter) = chars.at(letter) + 1;
        letter = my_file.get();
    }
    my_file.close();

    for (char let = 'A'; let <= 'z'; let++) { 
        map.insert({let, chars.at(let)});
    }

    for (auto it = map.begin(); it != map.end(); it++) {
         if (it -> second != 0) {
             elements.push_back(new Node(it -> first, it -> second));
         }
    }
    
    while (elements.size() > 1) {
        sort(elements.begin(), elements.end(), comp);
        int sum = elements.at(0) -> get_count() + elements.at(1) -> get_count();
        // '~' represents the node that holds the sum of the two popped nodes
        unsigned char holder = '~';

        elements.push_back(new Node(holder, sum, elements.at(0), elements.at(1)));
        elements.erase(elements.begin(), elements.begin() + 2);
    }
     
    walk(elements.at(0), 0);
    levels(elements.at(0), 0, char_levels);
    sort(char_levels.begin(), char_levels.end(), sym_comp);
    
    for (size_t i = 0; i < char_levels.size(); i++) {
        // cout << char_levels.at(i).letter << ": " << char_levels.at(i).size << endl;
        just_strings.push_back(char_levels.at(i).letter);
    
    }
    for (size_t i = 0; i < just_strings.size(); i++) {
        // cout << just_strings.at(i) << endl;
    }

    return 0;
}

// traverse thru the tree and get characters' position levels
void levels(Node *t, uint32_t l, vector<sym> &symbols) {   
    if (t != nullptr) {
        if (t -> get_letter() != '~') { 
            symbols.push_back({get_string(t -> get_letter()), l});
        }
        levels(t -> get_left(), l + 1, symbols);
        levels(t -> get_right(), l + 1, symbols);
    }
}

// traverse thru the tree and print letters and their counts
void walk(Node *t, int spaces) {
    if (t != nullptr) {
        // for (size_t i = 0; i < spaces; i++) { cout << ' '; }
        // cout << t -> get_letter() << ": " << t -> get_count () << endl;
        walk(t -> get_left(), spaces + 1);
        walk(t -> get_right(), spaces + 1);
    }
}
