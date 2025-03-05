#include <iostream>
#include <vector>

using namespace std;
struct Entry {
string name;
int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
return os << "{\"" << e.name << "\", " << e.number << "}";
}


istream& operator>>(istream& is, Entry& e)
// read { "name" , number } pair. Note: formatted with { " " , and }
{
	char c, c2;
	if (is>>c && c=='{' && is>>c2 && c2=='"') { // start with a { followed by a "
	string name; // the default value of a string is the empty string: ""
	while (is.get(c) && c!='"') // anything before a " is part of the name
	name+=c;
	if (is>>c && c==',') {
		int number = 0;
		if (is>>number>>c && c=='}') { // read the number and a }
			e = {name,number}; // assign to the entry
			return is;
			}
		}
	}
	is.setstate(ios_base::failbit); // register the failure in the stream
	return is;
}

vector<Entry> phone_book = {
{"David Hume",123456},
{"Karl Popper",234567},
{"Bertrand Arthur William Russell",345678}
};


void print_book(const vector<Entry>& book)
{
for (int i = 0; static_cast<long unsigned int>(i)!=book.size(); ++i)
//for (auto i = 0; i!=book.size(); ++i)
cout << book[i] << '\n';
}

void input()
{
	for (Entry e; cin>>e; )
		Entry e; cin>>e;phone_book.push_back(e);
}


int main(){

print_book(phone_book);

}
