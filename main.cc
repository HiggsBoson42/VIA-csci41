#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ifstream my_file;
    unordered_map<unsigned char, int> map;
    array<int, 128> chars = {0};
    char letter;
    string filename;

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
        if (it -> second != 0)
            cout << it -> first << ": " << it -> second << endl;
    }

    return 0;
}
