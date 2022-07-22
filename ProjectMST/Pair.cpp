#include "Pair.h"


int Pair::getVertex() const
{
	return vertex;
}

int Pair::getWeight() const
{
	return weight;
}

void Pair::setVertex(int _key)
{
	vertex = _key;
}

void Pair::setWeight(int other)
{
	weight = other;
}

void Pair::print() const
{
	std::cout << vertex << " " << weight << std::endl;
}

Pair& Pair::operator =(const Pair& other)
{
	vertex = other.vertex;
	weight = other.weight;
	return *this;
}

ostream& operator<<(ostream& out, const Pair& pair)
{
	out << pair.weight;
	return out;
}