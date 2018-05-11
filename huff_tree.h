#pragma once
#include "hub.h"
#include <memory>
#include <string>
#include <vector>
#include <deque>
#include <assert.h>
#include "coding_types.h"
//#define Node shared_ptr<hub>
using namespace std;
struct sym {
    string letter; // actual letter
    uint32_t size = 0; // how many levels down the tree
	sym(string s, uint32_t in) : letter(s), size(in) {}
    bool operator< (const sym &sy) const {
        if(size != sy.size) return size < sy.size;
        else return letter < sy.letter;
    }
};
/*struct hub{
	//unsigned char letter = '\0';
	uint32_t count = 0;
	shared_ptr<hub> left;
	shared_ptr<hub> right;
	string enc;
	//bool ::operator<(const shared_ptr<hub> &lhs, const shared_ptr<hub> &rhs);
	hub() : left(make_shared<hub>(nullptr)), right(make_shared<hub>(nullptr)) {}
};*/
class huff_tree{
	typedef shared_ptr<hub> Node;
	void info_helper(Node&,vector<sym>&,uint32_t);
	Node make_node(const uint32_t tally = 0,const string s = "");
	Node make_node(const sym&);
	Node merge(const Node&, const Node&);
	Node root;
	//void levels(Node t, uint32_t l, vector<sym> &symbols);
	//void walk(Node t, int spaces);
	//friend bool ::operator<(const Node &lhs, const Node &rhs);
	public:
	huff_tree() : root(make_node()) {}
	void insert(vector<sym>&);
	void get_coding_info(deque<string>&,vector<cipher::code_size>&);
	//void gen_code_sizes();
	//void reset();
};
/*bool operator<(const shared_ptr<hub> &lhs, const shared_ptr<hub> &rhs){
	return lhs->count<rhs->count;
}*/
