#include "KNTree.h"
#include <iostream>

KNTree::KNTree()
{
	root = nullptr;
}

KNTree::KNTree(Node* n)
{
	root = n;
}

KNTree::~KNTree()
{
}

bool KNTree::insert(Point pt)
{

	if (root == nullptr)
	{
		root = new Node(pt, Node::Vertical);
		return true;
	}
	return insert(pt, this->root);
}

bool KNTree::insert(Point pt, Node* n)
{
	int c = n->compareTo(pt);
	if (c == -1) 
	{ // The point is below n
		if (n->getRight() == nullptr) n->setRight(pt);
		else return insert(pt, n->getRight());
	}
	else if (c == 1)
	{ // The point is above n
		if (n->getLeft() == nullptr) n->setLeft(pt);
		else return insert(pt, n->getLeft());
	}
	else 
	{ // The point exists in the tree
		return false;
	}

	return true;
}

Node* KNTree::getNode(Point pt)
{
	return this->getNode(pt, root);
}

Node* KNTree::getNode(Point pt, Node* n)
{
	if (n == nullptr) return nullptr; // Base case
	// Compare the point to the current node
	int c = n->compareTo(pt);
	if (c == 0) return n;
	else if (c == -1) return this->getNode(pt, n->getRight());
	else return this->getNode(pt, n->getLeft());
}

Node* KNTree::nearest(Point pt)
{
	if (root == nullptr) return nullptr;
	return nearest(pt, root);
}

Node* KNTree::nearest(Point pt, Node* n)
{
	if (n == nullptr) return nullptr; // Base case

	Node* best; // This will be used to find the closest node
	int c = n->compareTo(pt); // Compare the node to the point to find which subtree to search first

	if (c == 0) return n;
	else best = nearest(pt, c == 1 ? n->getLeft() : n->getRight()); // Recursively search subtree

	best = closerNode(pt, n, best); // Compare the node with the closest in its subtree

	// It is possible for a closer node to be in the other subtree
	if (n->perpendicularDistance(pt) < pt.distTo(best->getPoint())) {
		// Recursively search the other side
		best = closerNode(pt, nearest(pt, c == 1 ? n->getRight() : n->getLeft()), best);
	}

	return best;
}

Node* KNTree::closerNode(Point pt, Node* n1, Node* n2)
{
	if (n1 == nullptr) return n2;
	if (n2 == nullptr) return n1;

	return pt.distTo(n1->getPoint()) < pt.distTo(n2->getPoint()) ? n1 : n2;
}
void KNTree::PrintInOrder()
{
	PrintInOrder(this->root);
}
void KNTree::PrintInOrder(Node* n)
{
	
	if (n->getLeft() != nullptr) PrintInOrder(n->getLeft());	
	std::cout << " id: " << n->getPoint().getId() << " x: " << n->getPoint().getCoord(0) << " y: " << n->getPoint().getCoord(1) << " dist to point(1, 45): " << n->getPoint().distTo(Point(101, 1, 45)) << std::endl;

	if (n->getRight() != nullptr) PrintInOrder(n->getRight());
	//std::cout << "id: " << n->getPoint().getId() << " x: " << n->getPoint().getCoord(0) << " y: " << n->getPoint().getCoord(1) << " dist to point(1, 45): " << n->getPoint().distTo(Point(101, 1, 45)) << std::endl;
}

//std::list<Point> KNTree::inOrder()
//{
//	return inOrder(root);
//}
//
//std::list<Point> KNTree::inOrder(Node* n)
//{
//	std::list<Point> list;
//	if (n->getRight() != nullptr) list.emplace_back(n->getRight());
//	
//	return std::list<Point>();
//}



