#include "Point.h"
#include <math.h>
#include <iostream>

Point::Point(int id, double x, double y)
{
	//std::cout << "2d Point is created id: " << id << std::endl;
	this->id = id;
	this->m_coord.push_back(x);
	this->m_coord.push_back(y);
		
}

Point::Point(int id, double x, double y, double z)
{
	std::cout << "3d Point is created" << std::endl;
	this->id = id;
	this->m_coord[0] = x;
	this->m_coord[1] = y;
	this->m_coord[2] = z;

}

Point::Point()
{
}

Point::~Point()
{
	
	//std::cout << "Remove point " <<  id << std::endl;
	m_coord.clear();
}

double Point::getCoord(int i)
{
	if (i >= m_coord.size())
	{
		//std::cout << "Index of vector is out size vector of point" << std::endl;
		return NULL;
	}
	return this->m_coord[i];
}

int Point::getId()
{
	return this->id;
}

int Point::getSize()
{
	return m_coord.size();
}

double Point::distTo(Point pt)
{
	if (pt.getSize() == 2)
		return std::sqrt(std::pow(this->getCoord(0) - pt.getCoord(0), 2)
					   + std::pow(this->getCoord(1) - pt.getCoord(1), 2));
		
return std::sqrt(std::pow(this->getCoord(0) - pt.getCoord(0), 2)
			   + std::pow(this->getCoord(1) - pt.getCoord(1), 2)
			   + std::pow(this->getCoord(2) - pt.getCoord(2), 2));
}

bool Point::equals(Point pt)
{
	if (this->getSize() == 2)
		return (this->getCoord(0) == pt.getCoord(0)) && (this->getCoord(1) == pt.getCoord(1));
	
	return (this->getCoord(0) == pt.getCoord(0)) && (this->getCoord(1) == pt.getCoord(1)) && (this->getCoord(2) == pt.getCoord(2));
}
