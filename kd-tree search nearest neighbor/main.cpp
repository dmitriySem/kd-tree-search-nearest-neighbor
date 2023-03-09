#pragma once
#include "Point.h"
#include "KNTree.h"

#include <stdlib.h>

#include <iostream>

using namespace std;

int main(){



	KNTree kdTree = KNTree();
	Point points[100];

	srand(time(NULL));
	
	for (int i = 0; i < 100; i++) {
		Point p = Point(i, rand()%100+1, rand() % 100 + 1);
		kdTree.insert(p);
		points[i] = p;
	}
	
	

	//Node n0 = Node(p0, n0.Horisontal);
	
	kdTree.PrintInOrder();

	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;

	cout << "x: " << kdTree.nearest(Point(101, 1, 45))->getPoint().getCoord(0) <<  " y: " << kdTree.nearest(Point(101, 1, 45))->getPoint().getCoord(1) << endl;

	return 0;
}