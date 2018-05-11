#include "bitqueue.h"
#include <fstream>
using namespace std;
void bit_buffer::encode(const array<cipher::encoding,128> &dict, stringstream &text){
	const uint32_t NIN = 63;
	const uint64_t ADDITIVE_IDENITY = 0;
	const uint8_t STOP = 4;//This is the EOT character
	uint64_t temp, ktemp = 0;
	cipher::encoding mode;
	char dolt;
	uint8_t ctemp;
	uint32_t count = 0;
	while(text){
		text.get(dolt);
		ctemp = (unsigned char) dolt;
		mode = dict[ctemp];
		ktemp = mode.key;
		if((count+mode.size)<=NIN){
			ktemp <<= count;
			temp |= ktemp;
			count += mode.size;
		}
		else{
			uint64_t ltemp = mode.key;
			ktemp <<= count;
			temp |= ktemp;
			count = NIN-count;
			ltemp >>= count;
			buff.push_front(temp);
			temp = ADDITIVE_IDENITY;
			temp |= ltemp;
		}
		if(ctemp == STOP) break;//REMEMBER TO BREAK DOWN AT STOP SIGN, I MEAN STOP CHARACTER
	}
}
void bit_buffer::get_bit(uint64_t& out){
	if(!buf_size){
		buf_size = 64;
		store = buff.back();
		buff.pop_back();
	}
	out << 1;
	out |= (store&1);
	buf_size--;
}
void bit_buffer::get_bit(uint64_t& out, const size_t &amount){
	for(size_t k = 0; k<amount; k++){
		if(!buf_size){
			buf_size = 64;
			store = buff.back();
			buff.pop_back();
		}
		out << 1;
		out |= (store&1);
		store >> 1;
		buf_size--;
	}
}
void bit_buffer::decode(string name, cipher::decode_table &decoder){
	ofstream out(name, ofstream::out);
	buf_size = 64;
	uint64_t temp = 0;
	decoder.reset();
	const size_t start = decoder.get_len();
	get_bit(temp, start);
	while(buff.size()||store){
		if(decoder.check_code(temp)){
			out << decoder.get_string(temp);
			decoder.reset();
			temp = 0;
			get_bit(temp, start);
		}
		else get_bit(temp, decoder.next());
	}
	out.close(	);
}






















//fd
