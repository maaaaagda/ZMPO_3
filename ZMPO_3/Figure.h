#pragma once
#define _USE_MATH_DEFINES
#include "stdafx.h"
#include "iostream"
#include <vector>
#include <string>
#include <math.h>

using namespace std;
class Figure
{
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual string toString() = 0;
};

class Circle: public Figure
{ 
	double _radius;
public:
	Circle(double radius):_radius(radius){}
	string toString() { return "Circle: " + to_string(_radius); }
	double getArea() { return M_PI*_radius*_radius; }
	double getPerimeter() { return 2 * M_PI*_radius; }
};

class Rectangle : public Figure
{
	double _firstSide;
	double _secondSide;

public: 
	Rectangle(double firstSide, double secondSide):_firstSide(firstSide), _secondSide(secondSide){}
	string toString() { return "Rectangle: " + to_string(_firstSide) + " " + to_string(_secondSide); }
	double getArea() { return _firstSide * _secondSide; }
	double getPerimeter() { return 2*(_firstSide +_secondSide); }
};

class Square : public Figure
{
	double _side;
public:
	Square(double side):_side(side){}
	string toString(){ return "Square: " + to_string(_side); }
	double getArea() { return _side*_side; }
	double getPerimeter() { return 4 * _side; }
};

class Trapeze : public Figure
{
	double _firstParallelSide;
	double _secondParallelSide;
	double _firstOtherSide;
	double _secondOtherSide;
	double _height;
public:
	Trapeze(double firstParallelSide, double secondParallelSide, double firstOtherSide, double secondOtherSide, double height) :
		_firstParallelSide(firstParallelSide), _secondParallelSide(secondParallelSide),
		_height(height), _firstOtherSide(firstOtherSide), _secondOtherSide(secondOtherSide) {}
	string toString(){return "Trapeze: " + to_string(_firstParallelSide) + " " + to_string(_secondParallelSide)
		+ " " + to_string(_firstOtherSide) + " " + to_string(_secondOtherSide) + " " 
		+ to_string(_height);}
	double getArea() { return (_firstParallelSide + _secondParallelSide)*_height / 2; }
	double getPerimeter() {
		return _firstParallelSide + _secondParallelSide + _firstOtherSide + _secondOtherSide;}
};

