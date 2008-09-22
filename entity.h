
#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <SDL/SDL.h>
using std::string;
#include "text.h"
#include "namecache.h"
/*
 * Defined to be a source/sink for the visualization. 
 * knows its position, label and brightness
 * Its position is between 0,0-1,1. it can be scaled to fit to whatever easily
 */
class entity
{
public:
	unsigned int label;
	unsigned int count;
	unsigned char mask;
private:
	float brightness;
	float x;
	float y;
	float ndx, ndy;
	bool valid;
	bool fade;
	bool net;
	int fadeval;
	double lastupdate;
	void init(unsigned int label);
public:
	entity(unsigned int l);
	entity() {init(0);valid=false;net=false;}
	entity(unsigned int l, unsigned int c, unsigned char m):count(c),mask(m),net(true) {init(l);}

	void dofade(double dt);
	void move(float dx, float dy, float damp, double dt);
	//TODO getX and getY are in world coordinates, yet getW and getH are not
	float getX() {return x;}
	float getY() {return y;}
	float getW() {return text.getW() * names[label].length();}
	float getH() {return text.getH();}

	void jump(float nx, float ny);

	bool draw(SDL_Surface*s);
	bool isvalid() {return valid;}

	bool deleteme() {return fade && fadeval>=15;}
	int getfadeval() {return fadeval;}
	void touch() {fade=false;}
	bool isnet() {return net;}
	//two toggles that can publicly modified
	bool moving;
	bool resolve;
};

#endif //ENTITY_H
