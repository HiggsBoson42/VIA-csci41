#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <unordered_map>
#include "heap.h"
#include "node.h"

using namespace std;

int main() {
    ifstream my_file;
    unordered_map<unsigned char, int> map;
    array<int, 128> chars = {0};
    char letter;
    string filename;
    Heap<Node*> elements;

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
             // cout << it -> first << ": " << it -> second << endl;
             // Node push_node(it -> first, it -> second);
             elements.push(new Node(it -> first, it -> second));
         }
    }

    elements.print();

    while (elements.get_size() > 1) {
         Node *uno = elements.pop();
         Node *dos = elements.pop();
         int sum = uno -> get_count() + dos -> get_count();
         // ~ represents the node that holds the sum of the two popped nodes
         unsigned char holder = '~';

         elements.push(new Node(holder, sum, uno, dos));
    }

    return 0;
}
