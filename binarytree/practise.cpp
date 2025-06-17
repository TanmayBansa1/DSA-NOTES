#include<iostream>
#include<string>
using namespace std;

class Animal{
	private:
	string name = " ";
	int legCount;
	string speaks = " ";
	public:
	Animal(string name, int legCount, string speaks){
		this->name = name;
		this->legCount = legCount;
		this->speaks = speaks;
	}
	void print(){
		cout<<this->name<<" has "<<this->legCount<<" number of legs and speaks as "<<this->speaks<<endl;
	}

};
int main()
{
	Animal* dog = new Animal("Doggie", 4, "bhow");
    dog->print();
	return 0;
}