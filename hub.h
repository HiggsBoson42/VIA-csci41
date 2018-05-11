#pragma once
#include <memory>
#include <string>
using namespace std;
struct hub{
	//unsigned char letter = '\0';
	uint32_t count = 0;
	shared_ptr<hub> left;
	shared_ptr<hub> right;
	string enc;
	//bool ::operator<(const shared_ptr<hub> &lhs, const shared_ptr<hub> &rhs);
	hub() : left(), right(/*make_shared<hub>(nullptr)*/) {}
};
extern bool operator<(const shared_ptr<hub> lhs, const shared_ptr<hub> rhs){
	return (lhs->count<rhs->count);
}
