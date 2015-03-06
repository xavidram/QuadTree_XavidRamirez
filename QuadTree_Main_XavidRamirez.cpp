/*
Xavid Ramirez
This QuadTree given to us to create in our
Algorithms and Data Structures class.
I would suggest those viewing this QuadTree to use it as an example,
but don't submit it. I put this quadtree up because it was not my final
submission, the submission I turned in was a bit more efficient, well, a lot
more efficient.
*/
#include "quadTree.h"
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	quadTree qt;

	for (int i = 0; i<5000000; i++)
	{
		point p;
		p.x = rand();
		p.y = rand();
		qt.insert(p);
	}

	cout << "nearest search: " << endl;
	point test1;
	test1.x = 50;
	test1.y = 200;

	point test2;
	test2.x = 10000;
	test2.y = 20000;

	point test3;
	test3.x = 15797;
	test3.y = 4578;

	point test4;
	test4.x = 381;
	test4.y = 5815;

	point result;

	clock_t start, end, dif;

	start = clock();
	result = qt.nearestNeighbor(test1);
	end = clock();
	dif = end - start;
	cout << result.x << ", " << result.y << endl;
	cout << "That search took: " << dif << " milliseconds." << endl;
	if (result.x == 47 && result.y == 197)
		cout << "right answer" << endl;
	else
		cout << "WRONG!!!!!!" << endl;
	if (dif < 100)
		cout << "Acceptable Speed!" << endl;
	else
		cout << "Too slow." << endl;

	start = clock();
	result = qt.nearestNeighbor(test2);
	end = clock();
	dif = end - start;
	cout << result.x << ", " << result.y << endl;
	cout << "That search took: " << dif << " milliseconds." << endl;
	if (result.x == 9997 && result.y == 19996)
		cout << "right answer" << endl;
	else
		cout << "WRONG!!!!!!" << endl;
	if (dif < 100)
		cout << "Acceptable Speed!" << endl;
	else
		cout << "Too slow." << endl;

	start = clock();
	result = qt.nearestNeighbor(test3);
	end = clock();
	dif = end - start;
	cout << result.x << ", " << result.y << endl;
	cout << "That search took: " << dif << " milliseconds." << endl;
	if (result.x == 15799 && result.y == 4582)
		cout << "right answer" << endl;
	else
		cout << "WRONG!!!!!!" << endl;
	if (dif < 100)
		cout << "Acceptable Speed!" << endl;
	else
		cout << "Too slow." << endl;

	start = clock();
	result = qt.nearestNeighbor(test4);
	end = clock();
	dif = end - start;
	cout << result.x << ", " << result.y << endl;
	cout << "That search took: " << dif << " milliseconds." << endl;
	if (result.x == 374 && result.y == 5815)
		cout << "right answer" << endl;
	else
		cout << "WRONG!!!!!!" << endl;
	if (dif < 100)
		cout << "Acceptable Speed!" << endl;
	else
		cout << "Too slow." << endl;

	for (int i = 0; i<10; i++)
	{
		point test;
		test.x = rand();
		test.y = rand();

		start = clock();
		result = qt.nearestNeighbor(test);
		end = clock();
		dif = end - start;
		cout << result.x << ", " << result.y << endl;
		cout << "That search took: " << dif << " milliseconds." << endl;
		if (dif < 100)
			cout << "Acceptable Speed!" << endl;
		else
			cout << "Too slow." << endl;
	}

	system("pause");
	return 0;
}