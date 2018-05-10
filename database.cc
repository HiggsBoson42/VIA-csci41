#include <iostream>
using namespace std;

class Book{
protected:
string title;
string author;
int release;
};

Book Dorian: protected Book{
protected:
string title = "The Picture of Dorian Gray";
string author = "Oscar Wilde";
int release = 1890;
};

Book Jane: protected Book{
protected:
string title = "Jane Eyre";
string author = "Charlotte Bronte";
int release = 1847;
};

Book Pride: protected Book{
protected:
string title = "Pride and Predjudice";
string author = "Jane Austen";
int release = 1813;
};

Book Frankenstein: protected Book{
protected:
string title = "Frankenstein";
string author = "Mary Wollstonecraft Shelley";
int release = 1818;
};

Book Dracula: protected Book{
protected:
string title = "Dracula";
string author = "Bram Stoker";
int release = 1897;
};

Book Heights: protected Book{
protected:
string title = "Wuthering Heights";
string author = "Emily Bronte";
int release = 1847;
};

Book Finn: protected Book{
protected:
string title = "The Adventures of Huckleberry Finn";
string author = "Mark Twain";
int release = 1884;
};

Book Carol: protected Book{
protected:
string title = "A Christmas Carol";
string author = "Charles Dickens";
int release = 1843;
};
