#pragma once
#include <vector>


class Point
{
public:
	Point();
	Point(int id, double x, double y);
	Point(int id, double x, double y, double z);
	~Point();
	double getCoord(int i);
	int getSize();
	//double distTo(Point* pt);
	bool equals(Point pt);


private:
	int id;
	std::vector<double> m_coord;
};


