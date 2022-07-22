#pragma once
#include <iostream>
using std::ostream;


class Pair
{
private:
	int vertex;
	int weight;
public:
	Pair() { vertex = 0; weight = -1; };
	Pair(int _key, int _data): vertex(_key), weight(_data){}
	int getVertex() const;
	int getWeight() const;
	void setVertex(int other);
	void setWeight(int other);
	void print() const;
	Pair& operator =(const Pair& other);
	friend ostream& operator<<(ostream& out, const Pair& pair);
};
