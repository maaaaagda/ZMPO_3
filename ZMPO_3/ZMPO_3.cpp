// ZMPO_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Figure.cpp"

int main()
{
	int figuresTabSize = 0;
	vector <int> taken;
	Figure **figuresTab = NULL;
/*	figuresTab = new Figure *[figuresTabSize];
	figuresTab[3] = new Square(8);
	figuresTab[4] = new Square(6);
	taken.push_back(3);
	taken.push_back(4);
	show(taken, figuresTab);
	cout<<sumArea(taken, figuresTab)<<endl;
	cout << sumPerimeter(taken, figuresTab) << endl;
	*/
	bool exit = false;

	vector<string> words;
	string text;

	do
	{
		words.clear();
		getline(cin, text);
		string::size_type beg = 0, end;
		do {
			end = text.find(' ', beg);
			if (end == string::npos) {
				end = text.size();
			}
			words.emplace_back(text.substr(beg, end - beg));
			beg = end + 1;
		} while (beg < text.size());



		if (words[0] == "!go")
		{
			try
			{
				figuresTabSize = stoi(words[1]);
				figuresTab = new Figure*[figuresTabSize];
				cout << "DONE" << endl;

			}

			catch (invalid_argument e)
			{
				cout << "ERROR" << endl;
			}

		}
		else if (words[0] == "!createCircle") //position radius
		{
			try
			{
				int position = stoi(words[1]);
				double radius = stod(words[2]);
				if (position >= 0 && position < figuresTabSize)
				{
					taken.push_back(position);
					cout << createCircle(figuresTab, position, radius) << endl;
				}
				else cout << "ERROR" << endl;
			}
			catch (invalid_argument e)
			{
				cout << "ERROR" << endl;
			}
		}
		else if (words[0] == "!createRectangle") //position firstSide secondSide
		{
			try
			{
				int position = stoi(words[1]);
				double firstSide = stod(words[2]);
				double secondSide = stod(words[3]);
				if (position >= 0 && position < figuresTabSize)
				{
					taken.push_back(position);
					cout << createRectangle(figuresTab, position, firstSide, secondSide) << endl;
				}
				else cout << "ERROR" << endl;
			}
			catch (invalid_argument e)
			{
				cout << "ERROR" << endl;
			}
		}
		else if (words[0] == "!createSquare") //position side
		{
			try
			{
				int position = stoi(words[1]);
				double side = stod(words[2]);
				if (position >= 0 && position < figuresTabSize)
				{
					taken.push_back(position);
					cout << createSquare(figuresTab, position, side) << endl;
				}
				else cout << "ERROR" << endl;
			}
			catch (invalid_argument e)
			{
				cout << "ERROR" << endl;
			}
		}
		else if (words[0] == "!createTrapeze") //position parallelSide1 parallelSide2 otherSide1 otherSide2 height
		{
			try
			{
				int position = stoi(words[1]);
				double firstParallelSide = stod(words[2]);
				double secondParallelSide = stod(words[3]);
				double firstOtherSide = stod(words[4]);
				double secondOtherSide = stod(words[5]);
				double height = stod(words[6]);
				if (position >= 0 && position < figuresTabSize)
				{
					taken.push_back(position);
					cout << createTrapeze(figuresTab, position, firstParallelSide, secondParallelSide, firstOtherSide, secondOtherSide, height) << endl;
				}
				else cout << "ERROR" << endl;
			}
			catch (invalid_argument e)
			{
				cout << "ERROR" << endl;
			}
		}
		else if (words[0] == "!show")
		{
			show(taken, figuresTab);
		}
		else if (words[0] == "!sumArea")
		{
			cout<<sumArea(taken, figuresTab)<<endl;
		}
		else if (words[0] == "!sumPerimeter")
		{
			cout << sumPerimeter(taken, figuresTab) << endl;
		}
		else if (words[0] == "!exit")
		{
			exit = true;
		}

	} while (!exit);
	 return 0;
}

