#ifndef POSITION_H
#define POSITION_H

class Position{
public:
	Position();
	Position(float x, float y);
	~Position();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	Position operator+(Position &other);
	Position operator-(Position &other);
	Position operator+=(Position &other);
	Position operator-=(Position &other);
	bool operator==(Position &other);
	Position operator/(Position &other);
	Position operator*(Position &other);
	Position operator*=(Position &other);
	Position operator/=(Position &other);
	Position &operator--();
	Position &operator++();
	Position operator--(int z);
	Position operator++(int z);
private:
	float m_x;
	float m_y;
};
#endif