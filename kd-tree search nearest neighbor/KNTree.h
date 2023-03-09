#pragma once
#include "Node.h"
#include "Point.h"
#include <list>



class KNTree
{
public:
	KNTree();
	KNTree(Node* n);
	~KNTree();

	bool insert(Point pt); //Insert a new point into the tree
	bool insert(Point pt, Node* n);

	//bool contains(Point pt); //Determines if a point is in this instance of KDTree
	//bool contains(Point pt, Node n);

	Node* getNode(Point pt); //Return the node associated with point pt
	Node* getNode(Point pt, Node* n); 

	Node* nearest(Point pt); //Return the node that represents the closest point in the tree
	Node* nearest(Point pt, Node* n); 

	Node* closerNode(Point pt, Node* n1, Node* n2);

	//std::list<Point>  inOrder();
	//std::list<Point>  inOrder(Node* n);

	void PrintInOrder();
	void PrintInOrder(Node* n);


private:

	Node* root;

};

