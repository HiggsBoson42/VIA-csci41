#pragma once
#include <iostream>
#include <fstream>
#include "coding_types"
#include <sstream>
#include <array>
#include <cereal/cereal.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/base_class.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/deque.hpp>
#include <cereal/types/string.hpp>
#include <cereal/archives/binary.hpp>
using namespace std;


/*class bit_buffer_storage{
  string header;
  deque<uint64_t> data;
  template<class Archive>
  void serialize(Archive & ar){
  ar(header, data);
  }
  public:

  };*/
class bit_buffer{
	deque<uint64_t> buff;

	public:
	void encode(const array<cipher::encoding,256> &dict, stringstream &text);
	//stringstream decode(
};

