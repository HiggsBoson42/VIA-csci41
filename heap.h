#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <assert.h>
#include <stdexcept>

/*NOTES:
 *Either requries less than operator or a comparsion function to be give to constructor
 *For set_comp either write a function above that returns a boolean and takes two different type T varibles as arguments 
 *Or use a lambda expression, I suggest the lambda expression
 */

template <class T>
class Heap {
	std::vector<T> data;
	//std::function<bool(T,T)> comp;
	inline bool bounds(const size_t &dex){return ((dex<data.size())&&(dex>=0));}
	inline void swapper(size_t a, size_t b){ //Algorimths swap swap seems to buged for this
		//assert(bounds(a)&&bounds(b));
		if(!(bounds(a)&&bounds(b))){
			std::cerr << "Error in swapper\nSize: " << data.size() << " A: " << a << " B: " << b << std::endl;
			exit(1);
		}
		T temp = data[a];
		data[a] = data[b];
		data[b] = temp;
	}
    bool comp(T a, T b) {
        return a -> get_count() < b -> get_count();
    }
	void sift_up(const size_t &dex){
		if(dex==0) return;
		assert(bounds(dex));
		size_t parent = (dex-1)/2;
		if(data[dex] -> get_count() < data[parent] -> get_count()){
			swapper(dex,parent);
			assert(data[parent] -> get_count() < data[dex] -> get_count());
			sift_up(parent);
		}
		return;
	}

	void sift_down(const size_t &dex){
		size_t spawn = 2*dex+1;
		if(!bounds(spawn)) return;
		if((!bounds(spawn+1))||comp(data[spawn],data[spawn+1])){
			if(!comp(data[dex], data[spawn])){
				swapper(dex, spawn);
				sift_down(spawn);
			}
		}
		else if(!comp(data[dex], data[spawn+1])){
			swapper(dex, spawn+1);
			sift_down(spawn+1);
		}
		return;
	}
public:
	Heap() : data(std::vector<T>())  {}
	bool empty(){return data.empty();}
	void push(const T &in){
		data.push_back(in);
		sift_up(data.size()-1);
	}
	void print(){
		for(T n:data){
			std::cout << n -> get_count() << std::endl;
		}
	}
	T& top(){return data.front();}
	T pop(){
		T temp = data.front();
		if(data.size()<1){
			data.pop_back();
			return temp;
		}
		swapper(0, data.size()-1);
		//assert(comp(data.back(),data.front()));
		data.pop_back();
		sift_down(0);
		return temp;
	}
    int get_size() {
        return data.size();
    }
};
