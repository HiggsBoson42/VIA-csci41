#include <stuff>
#include <unordered_map>
#include "huff_tree"
#include "coding_types.h"
#include "bitqueue.h"
using namespace std;



int main() {
	bitqueue chronos;
    ifstream my_file;
    unordered_map<unsigned char, int> map;
    array<int, 128> chars = {0};
    char letter;
    string filename;
    vector<Node*> elements;
    vector<sym> char_levels; // stores each letter and its levels (in sym)
    //deque<string> just_strings; // stores just letters; order of letters matches that of char_levels
    //vector<code_size> codes;

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
	for(char k = 0; k>=0&&k<128; k++)
		if(array[size_t(k)]>0) char_levels.push_back(sym(k,array[size_t(k)]);
	huff_tree Maxwell(char_levels);
	
}
