#include "bitqueue.h"

void bit_buffer::encode(const array<coding::code,256> &dict, stringstream &text){
	const uint32_t NIN = 63;
	const uint64_t ADDITIVE_IDENITY = 0;
	const uint8_t STOP = 4;//This is the EOT character
	uint64_t temp, ktemp = 0;
	coding::code mode;
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