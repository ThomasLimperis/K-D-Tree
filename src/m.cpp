#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "BSTNode.hpp"
#include "BST.hpp"
#include <vector>
#include <string>

#include "KDT.hpp"


using namespace std;

int main()
{

	BST<int> ra;
	//ra.in
	vector<Point> n;	//(1, 3.2) (3.2, 1) (5.7, 3.2) (1.8, 1.9) (4.4, 2.2)
	//n.push_back("ee","eee");
//	n.push_back({4,0,});
//	n.push_back({2,1});
//	n.push_back({0,0});
//	n.push_back({3,3});
//	n.push_back({6,1});
//	n.push_back({9,4});
//	n.push_back({10,5});




	//(1, 1)(1, 3.2) (3.2, 1) (5.7, 3.2) (1.8, 1.9) (4.4, 2.2)
	KDT h;
	int hight = h.build(n);
	cout << hight;
	h.inorder();
	//auto iter = h.findNearestNeighbor({1,3.2});
	//iter = h.findNearestNeighbor({1.8,1.9});
	//iter = h.findNearestNeighbor({5.7,3.2});
	//cout << *iter;






//h.insert(2);
//auto it = h.find(4);
//cout << *it;









//
	return 0;
}
