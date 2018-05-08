#pragma once
#include <vector>
#include <deque>
#include <string>
namespace cipher{
	unsigned char STOP = 7;
	struct encoding{
		//THE CODE MUST BE BACKWARDS FOR ENCODING(LEAST Significant Digit is most left)!!!!!!!!!!
		uint64_t key;//The actual code
		uint32_t size;
	};
	struct decode{
		size_t size;
		uint64_t start;
		size_t count;
		std::vector<string> symbols;
	}
	struct code_size{
		uint32_t length;
		uint32_t count;
	}
	class decode_table{
		//THE CODE MUST BE FORWARDS FOR DECODING(MOST Significant Digit is most left)!!!!!!!!!!
		size_t pos;
		std::vector<decode> table;
		public:
		decode_table() = delete;
		//The vector of strings is sorted by greater than, first by code length then by, alphabetical
		decode_table(std::vector<code_size>, std::vector<string>);
		bool check_code(const uint64_t&);
		std::string get_string(const uint64_t&);
		size_t next();
		void reset();
	};
}
