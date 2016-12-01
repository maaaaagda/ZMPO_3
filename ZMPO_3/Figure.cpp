#include "stdafx.h"
#include "Figure.h"

namespace {
	void show(vector <int> taken, Figure **FigureTab)
	{
		for (size_t i = 0; i < taken.size(); i++)
		{
			cout << FigureTab[taken[i]]->toString() << endl;
		}
	}
	double sumArea(vector <int> taken, Figure **FigureTab)
	{
		double sum = 0;
		for (size_t i = 0; i < taken.size(); i++)
		{
			sum += FigureTab[taken[i]]->getArea();
		}
		return sum;
	}
	double sumPerimeter(vector <int> taken, Figure **FigureTab)
	{
		double sum = 0;
		for (size_t i = 0; i < taken.size(); i++)
		{
			sum += FigureTab[taken[i]]->getPerimeter();
		}
		return sum;
	}
	string createCircle(Figure **figuresTab, int position, double radius)
	{
		figuresTab[position] = new Circle(radius);
		return "DONE";
	}
	string createRectangle(Figure **figuresTab, int position, double firstSide, double secondSide)
	{
		figuresTab[position] = new Rectangle(firstSide, secondSide);
		return "DONE";
	}
	string createSquare(Figure **figuresTab, int position, double side)
	{
		figuresTab[position] = new Square(side);
		return "DONE";
	}
	string createTrapeze(Figure **figuresTab, int position, double firstParallelSide, double secondParallelSide,
		double firstOtherSide, double secondOtherSide, double height)
	{
		figuresTab[position] = new Trapeze(firstParallelSide, secondParallelSide, firstOtherSide, secondOtherSide, height);
		return "DONE";
	}
	string getArea(Figure **figuresTab, int position)
	{
		return to_string(figuresTab[position]->getArea());

	}
	string getPerimeter(Figure **figuresTab, int position)
	{
		return to_string(figuresTab[position]->getPerimeter());

	}
	string createFigureCopy(Figure **figuresTab, int positionFrom, int positionTo)
	{
		return "";
	}

}