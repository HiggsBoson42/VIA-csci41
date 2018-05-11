#pragma once
#include <memory>
#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <assert.h>
using namespace std;
class trie{
	struct node{
		uint32_t count = 0;
		//bool pass = true;
		vector<shared_ptr<node>> vec;
		node(double c) : vec(0){}
		node(uint32_t level, bool first  = true) {//it_num SHOULD NEVER BE USE EXTERNALLYi
			if(level&&first){
				vec.resize(128);
				vec.shrink_to_fit();
				for(size_t k = 0; k<128; k++){//65='A', 90='Z', 97='a', 122='z'
					if((k>=65&&k<=90)||(k>=97&&k<=122))
						vec[k] = make_shared<node>(level-1, false);
					else vec[k] = make_shared<node>(0.0);
				}
			}
			else if(level){
				vec.resize(128);
				vec.shrink_to_fit();
				for(size_t k = 0; k<128; k++){//65='A', 90='Z', 97='a', 122='z'
					if((k>=65&&k<=90))
						vec[k] = make_shared<node>(level-1, false);
					else vec[k] = make_shared<node>(0.0);
				}
			}
		}
	};
	typedef shared_ptr<node> hub;
	class stak : public stack<hub>{
		public:
		hub loot(){
			hub temp = this->top();
			this->pop();
			return temp;
		}
	};
	hub root;
	hub cur;
	inline void entropy(double &in, const hub &hum){
		uint32_t temp = hum->count;
		if(!temp) return;
		in += double(temp)*log2(double(temp));
	}
	public:
	trie(uint32_t level = 0) : root(new node(level)) {cur = root;}
	void insert(size_t c){
		assert(cur->vec.size());
		cur = cur->vec.at(c);
		if(!cur->vec.size()){
			cur->count++;
			cur = root;
		}
	}
	void stop(){
		if(cur!=root) cur->count++;
		cur = nullptr;
	}
	double get_shannon_entropy(uint32_t &tot){
		//preorder travesal, should use slightly less memory
		double daemon = 0.0;
		//uint32_t tot = 0;
		stak stack;
		stack.push(root);
		hub temp;
		while(stack.size()){
			temp = stack.loot();
			tot += temp->count;
			if(temp->count) entropy(daemon,temp);
			for(hub &ob:temp->vec)
				stack.push(ob);
		}
		double lemma = 1/double(tot);
		return (log2(double(tot))-lemma*daemon);
	}
};

