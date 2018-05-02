#pragma once
#include <iostream>

using namespace std;

class Node {
  
  private:
    unsigned char letter = '\0';
    int count = 0;
    Node *left = nullptr;
    Node *right = nullptr;
    string enc = "";
  
  public:
    Node() {}
    Node (unsigned char new_letter, int new_count, Node *new_left, Node *new_right, string new_enc) :
        letter(new_letter), count(new_count), left(new_left), right(new_right), enc(new_enc) {}
    Node (unsigned char new_letter, int new_count) : letter(new_letter), count(new_count) {}
    Node (unsigned char new_letter, int new_count, Node *new_left, Node *new_right) :
        letter(new_letter), count(new_count), left(new_left), right(new_right) {}
    
    char get_letter() {
        return letter;
    }

    int get_count() {
        return count;
    }

    Node *get_left() {
        return left;
    }

    Node *get_right() {
        return right;
    }

    string get_enc() {
        return enc;
    }

    void set_letter(char l) {
        letter = l;
    }

    void set_count(int c) {
        count = c;
    }

    void set_left(Node *l) {
        left = l;
    }

    void set_right(Node *r) {
        right = r;
    }

    void set_enc(string e) {
        enc = e;
    }

    bool operator< (Node *in_node) const {
        return count > in_node -> get_count();
    }

};
