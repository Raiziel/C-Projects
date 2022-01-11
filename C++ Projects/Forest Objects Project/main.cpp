#include <iostream>
#include "forest.h"
#include "object.h"

using namespace std;

int main()
{

	position posTiger,posDeer,posGrass;//position for tiger, deer and grass.
	tiger *t;//pointer to point tiger object
	deer *d;//pointer to point deer object
	grass *g;//pointer to point grass object

	/*Creating first forest of tiger and deer*/
	posTiger.x=3;//starting position x for tiger
	posTiger.y=3;//starting position y for tiger
	t=new tiger("tiger1",'T',"UULLLDD",posTiger);//declaring a new tiger object


	posDeer.x=1;//starting position x for deer
	posDeer.y=5;//starting position y for deer
	d=new deer("deer1",'D',"LLUUUU",posDeer);//declaring a new deer object

	forest <tiger, deer> *f1 = new forest<tiger,deer>(7,7,t,d);//createing a new forest of size 7,7 with tiger and  deer object 

	f1->simulate();//simulating the forest operation
	
	delete f1;//deallocating the forest.

	/********************************************/
	
	/*Creating second forest of deer and grass*/
	posDeer.x=1;
	posDeer.y=0;
	d = new deer("deer2",'D',"RRRDRD",posDeer);

	posGrass.x=0;
	posGrass.y=4;
	g = new grass("grass1",'G',"LDDLDR",posGrass);

	forest <deer, grass> *f2=new forest<deer,grass>(5,5,d,g);

	f2->simulate();

	delete f2;
	/********************************************/


	/*Creating third forest of tiger and grass*/
	posTiger.x=1;
	posTiger.y=2;

	t=new tiger("tiger2",'T',"LDRRRR",posTiger);

	posGrass.x=0;
	posGrass.y=1;

	g=new grass("grass2",'G',"RRDD",posGrass);

	forest <tiger,grass> *f3=new forest<tiger,grass>(3,5,t,g);

	f3->simulate();

	delete f3;
	/*******************************************/


	/*Creating fourth forest of tiger and deer*/
	posTiger.x=4;
	posTiger.y=1;
	t=new tiger("tiger3",'T',"DDLDRRRUUUUR",posTiger);

	posDeer.x=0;
	posDeer.y=6;
	d=new deer("deer3",'D',"RRDDDDDLLLD",posDeer);

	forest <tiger,deer> *f4=new forest<tiger,deer>(8,10,t,d);
	f4->simulate();

	delete f4;

	/*******************************************/



	return 0;
}