#pragma once
#include "Point.h"
#include <math.h>

class Node
{


public:
	enum Orientation
	{
		Horisontal,
		Vertical
	};


	Node();
	Node(Point pt, Orientation orient);
	~Node();
	Point getPoint();
	Node* getLeft();
	Node* getRight();
	Orientation getOrient();
	Orientation otherOrint(Orientation o);

	void setLeft(Point pt);
	void setLeft(Node* n);
	void setRight(Point pt);
	void setRight(Node* n);

	int compareTo(Point pt);
	double perpendicularDistance(Point pt);


private:
	Node* left;
	Node* right;
	Point m_point;
	Orientation orient;



};

