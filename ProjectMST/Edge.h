#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Edge
{
	int from;
	int to;
	int weight;

public:
	Edge() = default;
	Edge(int _from, int _to, int _weight) :from(_from), to(_to), weight(_weight) {};
	~Edge()=default;
	int getFrom() const;
	int getTo() const;
	int getWeight() const;
	void setFrom(int other);
	void setTo(int other);
	void setWeight(int other);
	void print() const;
	Edge& operator =(const Edge& other);
	bool operator ==(const Edge& other);
};

