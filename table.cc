#include <iostream>
#include <unoredered_map>
using namespace std;

int main(){
  unordered map<unsigned char, int> map;
  for (int k=0; k<256; k++){
  map.insert({(unsigned char) k,0 });
  }
  cout << "a : " << map.at('a') << endl;
  cout << "b : " << map.at('b') << endl;
  cout << "c : " << map.at('c') << endl;
  cout << "d : " << map.at('d') << endl;
  cout << "e : " << map.at('e') << endl;
  cout << "f : " << map.at('f') << endl;
  cout << "g : " << map.at('g') << endl;
  cout << "h : " << map.at('h') << endl;
  cout << "i : " << map.at('i') << endl;
  cout << "j : " << map.at('j') << endl;
  cout << "k : " << map.at('k') << endl;
  cout << "l : " << map.at('l') << endl;
  cout << "m : " << map.at('m') << endl;
  cout << "n : " << map.at('n') << endl;
  cout << "o : " << map.at('o') << endl;
  cout << "p : " << map.at('p') << endl;
  cout << "q : " << map.at('q') << endl;
  cout << "r : " << map.at('r') << endl;
  cout << "s : " << map.at('s') << endl;
  cout << "t : " << map.at('t') << endl;
  cout << "u : " << map.at('u') << endl;
  cout << "v : " << map.at('v') << endl;
  cout << "w : " << map.at('w') << endl;
  cout << "x : " << map.at('x') << endl;
  cout << "y : " << map.at('y') << endl;
  cout << "z : " << map.at('z') << endl;
  cout << "A : " << map.at('A') << endl;
  cout << "B : " << map.at('B') << endl;
  cout << "C : " << map.at('C') << endl;
  cout << "D : " << map.at('D') << endl;
  cout << "E : " << map.at('E') << endl;
  cout << "F : " << map.at('F') << endl;
  cout << "G : " << map.at('G') << endl;
  cout << "H : " << map.at('H') << endl;
  cout << "I : " << map.at('I') << endl;
  cout << "J : " << map.at('J') << endl;
  cout << "K : " << map.at('K') << endl;
  cout << "L : " << map.at('L') << endl;
  cout << "M : " << map.at('M') << endl;
  cout << "N : " << map.at('N') << endl;
  cout << "O : " << map.at('O') << endl;
  cout << "P : " << map.at('P') << endl;
  cout << "Q : " << map.at('Q') << endl;
  cout << "R : " << map.at('R') << endl;
  cout << "S : " << map.at('S') << endl;
  cout << "T : " << map.at('T') << endl;
  cout << "U : " << map.at('U') << endl;
  cout << "V : " << map.at('V') << endl;
  cout << "W : " << map.at('W') << endl;
  cout << "X : " << map.at('X') << endl;
  cout << "Y : " << map.at('Y') << endl;
  cout << "Z : " << map.at('Z') << endl;
  cout << "0 : " << map.at('0') << endl;
  cout << "1 : " << map.at('1') << endl;
  cout << "2 : " << map.at('2') << endl;
  cout << "3 : " << map.at('3') << endl;
  cout << "4 : " << map.at('4') << endl;
  cout << "5 : " << map.at('5') << endl;
  cout << "6 : " << map.at('6') << endl;
  cout << "7 : " << map.at('7') << endl;
  cout << "8 : " << map.at('8') << endl;
  cout << "9 : " << map.at('9') << endl;
  cout << ". : " << map.at('.') << endl;
  cout << ", : " << map.at(',') << endl;
  cout << "? : " << map.at('?') << endl;
  cout << "! : " << map.at('!') << endl;
  cout << ": : " << map.at(':') << endl;
}
