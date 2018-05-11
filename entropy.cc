#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <array>
#include <algorithm>
#include <chrono>
#include <unordered_map>
#include <map>
#include "trie.h"
using namespace std;

int main(){
	string s = "";
	if(s.empty()) cerr << "Empty string is empty!!!\n";
	/*char har;
	unsigned saint;
	for(size_t k = 0; k<5; k++){
		cin >> har;
		saint = (unsigned char)(har);
		cout << "S: " << +har << " U: " << +saint << endl;
	}*/
	ifstream file("poni", ifstream::in | ifstream::binary);
	//vector<double> histo;
	cout << boolalpha << file.is_open() << endl;
	unsigned char temp;
	char bad;
	//unordered_map<char, uint32_t> topo;
	uint32_t count = 0;
	trie fail(4);
	bool mah = true;
	while(file.good()){
		file.get(bad);
		temp = bad;
		if(bad==0) cout << '.';
		if(size_t(temp)>127&&mah){
			cerr << bad << ": HAAAAAAAAAAXXXXXXXXXXXXXXXXXXX!!!!!!!!!!!!!\n";
			 mah = false;
		}
		fail.insert(size_t(temp));
		//temp = static_cast<unsigned char>(bad);
		//histo.at(temp) += 1.0;
		//topo[bad]++;
		//count++;
	}
	//cout << count << endl;
	file.close();
	double shannon = 0.0, total = 0;
	/*for(auto n:topo)
		total += n.second;
	cout << "Total: " << total << endl;
	for(auto n:topo)
		histo.push_back(n.second);
	//cout << total << endl;
	for(double &n:histo)
		shannon += n*log2(n/total)/total;
	*/
	shannon = fail.get_shannon_entropy(count);
	total = count;
	//shannon *= -1;
	cout << "Entropy is " << shannon << " bits\n";
	cout << "Total Entropy is " << total*shannon/(8*1024) << " kilobytes\n";
}
