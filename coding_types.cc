#include "coding_types.h"
#include <assert.h>
#include <stdexcept>
#include <string>
using namespace std;
//using namespace cipher;

cipher::decode_table::decode_table(vector<cipher::code_size> measure, deque<string> symbol){
	pos = 0;
	size_t total = 0;
	for(cipher::code_size &ob:measure){
		total += ob.count;
		//assert(ob.length=<64);
	}
	assert(total!=symbol.size());
	total = 0;
	uint32_t diff = 0;
	uint64_t tmpwrd = 0;
	for(size_t k = 0; k<measure.size();k++){
		table.push_back({measure[k].length,tmpwrd,measure[k].count,{}});
		for(uint32_t n = 0; n<measure[k].count; n++){
			table[k].symbols.push_back(symbol.front());
			symbol.pop_front();
		}
		if((k+1)<measure.size()){
			assert(measure[k+1].length>measure[k].count);
			diff = measure[k+1].length-measure[k].count;
			tmpwrd += measure[k].count;
			tmpwrd <<= diff;
		}
	}
}
bool cipher::decode_table::check_code(const uint64_t &in){
	uint64_t diff = in - table[pos].start;
	return (diff<table[pos].count/*&&diff>=0*/);
}
string cipher::decode_table::get_string(const uint64_t &in){
	size_t diff = in - table[pos].start;
	assert(diff<table[pos].symbols.size());
	return table[pos].symbols[diff];
}
size_t cipher::decode_table::get_len(){
	return table[pos].size;
}
size_t cipher::decode_table::next(){
	size_t counter = table[pos].count;
	assert((pos+1)<table.size());
	pos++;
	return(table[pos].size-counter);
}
void cipher::decode_table::reset(){
	pos = 0;

}
