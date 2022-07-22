#include "Edge.h"


int Edge::getFrom() const
{
	return from;
}
int Edge::getTo() const
{
	return to;
}

int Edge::getWeight() const
{
	return weight;
}

void Edge::setFrom(int other)
{
	from = other;
}
void Edge::setTo(int other)
{
	to = other;
}
void Edge::setWeight(int other)
{
	weight = other;
}
void Edge::print() const
{
	cout << "(" << from << "," << to << ")" << endl;
}
Edge& Edge::operator =(const Edge& other)
{
	from = other.from;
	to = other.to;
	weight = other.weight;
	return *this;
}

bool Edge::operator ==(const Edge& other)
{
	return(from == other.getFrom() && to == other.getTo(), weight == other.getWeight());
}
