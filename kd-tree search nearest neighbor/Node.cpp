#include "Node.h"
#include <iostream>


Node::Node()
{
}

Node::Node(Point pt, Orientation orient)
{
	this->m_point = pt;
	this->orient = orient;
	
}

Node::~Node()
{
	std::cout << "Node is removed" << std::endl;
	
	delete left, right;
}

Point Node::getPoint()
{
	return m_point;
}

Node::Orientation Node::getOrient()
{
	return this->orient;
}

Node::Orientation Node::otherOrint(Orientation o)
{
	if (this->m_point.getSize() == 2)
	{
		if (o == Horisontal) return Vertical;
		return Horisontal;
	}
	else
	{
		std::cout << "3d isn't implemented" << std::endl;
	}

}

int Node::compareTo(Point pt)
{
	if (this->m_point.equals(pt))
			return 0;



	if (m_point.getSize() == 2)
	{
		if (this->orient == Vertical) 
			return pt.getCoord(0) < m_point.getCoord(0) ? -1 : 1;
		else 
			return pt.getCoord(1) < m_point.getCoord(1) ? -1 : 1;

	}
	else
	{
		std::cout << "3d isn't implemented" << std::endl;
	}
	
	return 0;
}
