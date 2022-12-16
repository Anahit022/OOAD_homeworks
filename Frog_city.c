#include <stdio.h>
#include <time.h>

const int time_in = 7;
const int time_out = 19;

struct Sun {
	int X;
	int Y;
} sun;

int is_shine(struct Sun* this);
int isnt_shine(struct Sun* this);
int hungry();
int full();
int air();
void eat();
void sleep();
void move();
void breathe();

int is_shine(struct Sun* this) {
	return this->X;
}
int isnt_shine(struct Sun* this) {
	return this->Y;
}
int hungry() {
	return is_shine(&sun);
}
int full() {
	return !hungry();
}
int air() {
	return is_shine(&sun);
}

void eat() {
	if (hungry()) { printf("I can eat!\n"); }
	if (full()) { printf("I'm full\n"); }
}
void sleep() {
	if (is_shine(&sun)) { printf("I want to sleep\n"); }
	if (isnt_shine(&sun)) { printf("I'm sleeping...\n"); }
}
void move() {
	if (is_shine(&sun)) { printf("I'm moving:\n"); }
}
void breathe() {
	if (air()) printf("I'm breathing:\n");
}
int main()
{
	clock_t time;
	time = clock();
	sun.X = (time / 3600) >= time_in && (time / 3600) <= time_out;
	sun.Y = !sun.X;;
	sleep();
	eat();
	move();
	breathe();

	return 0;
}