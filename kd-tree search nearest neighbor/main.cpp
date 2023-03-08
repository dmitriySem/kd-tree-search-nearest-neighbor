#pragma once
#include "Point.h"
#include "Node.h"

#include <iostream>

using namespace std;

int main(){


	Point p0 = Point(0, 1.0, 2.0);
	Point p1 = Point(1, 1, 5);


	//Node n0 = Node(p0, n0.Horisontal);
	

	cout << "x: " << p0.distTo(p1) << endl;

	return 0;
}