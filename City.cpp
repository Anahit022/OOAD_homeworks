#include <iostream>
#include <ctime>

const int time_in = 7;
const int time_out = 18;

class Sun
{
public:
	double time = clock();
	bool X = (time / 3600000) >= time_in && (time / 3600000) <= time_out;
	bool Y = !X;
	bool is_shine() {
		return X;
	}
	bool isnt_shine() {
		return Y;
	}
};

class Grass
{
public:
	Sun sun;
	bool hungry() {
		return sun.is_shine();
	}
	bool full() {
		return !hungry();
	}

};

class Tree
{
public:
	Sun sun;
	bool air() {
		return sun.is_shine();
	}
};

class Frog
{
public:
	Sun sun;
	Grass grass;
	Tree tree;
	void eat() {
		if (grass.hungry()) { std::cout << "I can eat!" << std::endl; }
		if (grass.full()) { std::cout << "I'm full" << std::endl; }  
	}
	void sleep() {
		if (sun.is_shine()) { std::cout << "I want to sleep" << std::endl; } 
		if (sun.isnt_shine()) { std::cout << "I'm sleeping..." << std::endl; } 
	}
	void move() {
		if (sun.is_shine()) { std::cout << "I'm moving:" << std::endl; } 
	}
	void breathe() { if (tree.air()) std::cout << "I'm breathing:" << std::endl; } 
};




int main()
{
	Frog frog;
	frog.sleep();
	frog.eat();
	frog.move();
	frog.breathe();

	return 0;
}