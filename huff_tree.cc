#include "huff_tree.h"
#include "heap.h"
#include <algorithm>
#define Node shared_ptr<hub>
Node huff_tree::make_node(const uint32_t tally,const string s){
	Node out = make_shared<hub>();
	out->count = tally;
	out->enc = s;
	return out;
}
Node huff_tree::make_node(const sym &in){
	Node out = make_shared<hub>();
	out->count = in.size;
	out->enc = in.letter;
	return out;
}

Node huff_tree::merge(const Node &a,const Node &b){
	Node out = make_shared<hub>();
	out->count = a->count+b->count;
	out->left = a;
	out->right = b;
	return out;
}

void huff_tree::insert(vector<sym> &in){
	if(in.empty()) return;
	Heap<Node> pile;
	for(sym &ob:in)
		pile.push(make_node(ob));
	if(pile.size()==1){
		root = pile.pop();
		return;
	}
	Node tmpl;
	Node tmpr;
	//if(pile.)
	while(pile.size()>1){
		tmpl = pile.pop();
		tmpr = pile.pop();
		pile.push(merge(tmpl,tmpr));
	}
	root = pile.pop();
}
void huff_tree::info_helper(Node &jnct,vector<sym> &out,uint32_t lvl){
	if(!jnct->enc.empty()) out.push_back(sym(jnct->enc,lvl));
	if(jnct->left) info_helper(jnct->left,out, (lvl+1));
	if(jnct->left) info_helper(jnct->left,out, (lvl+1));
}

void huff_tree::get_coding_info(deque<string> &symbols,vector<cipher::code_size> &msg){
	vector<sym> vim;
	info_helper(root, vim, 0);
	sort(vim.begin(),vim.end());
	//bool start = true;
	uint32_t Nefaria = 0, len = 0; //No Fingers required
	for(sym &ob:vim){
		if(ob.size != len){
			msg.push_back({len,Nefaria});
			len = ob.size;
			Nefaria = 0;
		}
		else Nefaria++;
	}
	if(Nefaria) msg.push_back({len,Nefaria});
	sort(msg.begin(),msg.end());
	symbols.resize(vim.size());
	for(size_t k = 0; k<vim.size(); k++)
		symbols[k] = vim[k].letter;
}
































//dfdasdfk
