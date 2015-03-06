/*
Xavid Ramirez
This QuadTree given to us to create in our
Algorithms and Data Structures class.
I would suggest those viewing this QuadTree to use it as an example,
but don't submit it. I put this quadtree up because it was not my final
submission, the submission I turned in was a bit more efficient, well, a lot
more efficient.
*/
#include <iostream>
#include <math.h>
using namespace std;

class point
{
public:
	int x;
	int y;


};

class quadTree
{
private:
	class node {
	public:
		point  data;

		node * ne;
		node * nw;
		node * se;
		node * sw;

		node(point p)
		{
			data = p;
			ne = NULL;
			nw = NULL;
			se = NULL;
			sw = NULL;
		}
	};

	node * root;

public:
	quadTree()
	{
		root = NULL;
	}

	~quadTree()
	{
		DeleteQuad(root);
	}


	//must have expected (assuming random set of previously inserted points) run time: O(log n)

	void insert(node * &ptr, point pos)
	{
		if (ptr == NULL)
			ptr = new node(pos);
		else if (ptr->data.x == pos.x && ptr->data.y == pos.y){}
		else if (pos.x < ptr->data.x)
		{
			if (pos.y < ptr->data.y)
				insert(ptr->sw, pos);
			else
				insert(ptr->nw, pos);
		}
		else 
		{
			if (pos.y < ptr->data.y)
				insert(ptr->se, pos);
			else
				insert(ptr->ne, pos);
		}
	}

	void insert(point p)
	{
		insert(root, p);
	}

	//return the point in the quadtree nearest to p (standard Euclidean distance metric)
	//Must have expected (assuming random set of previously inserted points) run time: O(log n)

	double PointDistance(point a, point b)
	{
		double w, v;
		w = a.x - b.x;
		v = a.y - b.y;
		return sqrt(w*w + v*v);

	}


	void nearestNeighbor(node * root, point p, point *& close) {

		if (root == NULL) {}
		else {

			if (close->x == p.x && close->y == p.y) {}

			else {


				if (PointDistance(p, root->data) < PointDistance(p, *close))
						close = &(root->data);

							if (p.x > root->data.x)
							{

								nearestNeighbor(root->ne, p, close);
								nearestNeighbor(root->se, p, close);
								//this if will do quadrant nw but exclude sw
								if (p.y > root->data.y)
									nearestNeighbor(root->nw, p, close);
								//this if will do quadrant sw but exclude nw
								else 
									nearestNeighbor(root->sw, p, close);

							}
							else
							{

								nearestNeighbor(root->nw, p, close);
								nearestNeighbor(root->sw, p, close);

								//this if will do quadrant ne but exclude se
								if (p.y > root->data.y)
									nearestNeighbor(root->ne, p, close);
								//this if will do quadrant se but exclude ne
								else 
									nearestNeighbor(root->se, p, close);

							}

			}
		}
	}


	point nearestNeighbor(point p)
	{
		point * closer = &(root->data);
		nearestNeighbor(root, p, closer);

		return *closer;

	}


	void DeleteQuad(node * ptr)
	{
		if (ptr == NULL){}
		else
		{
			DeleteQuad(ptr->nw);
			DeleteQuad(ptr->ne);
			DeleteQuad(ptr->sw);
			DeleteQuad(ptr->sw);
			delete ptr;
		}
	}

};