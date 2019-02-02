#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
#include <vector>
#include <time.h> 
#include <string>
#include <queue>
#include <deque>
using namespace std;

const int side_length = 20; //Size of field
const int destination_loc = side_length*side_length - 1; //Location of destination

//We use this to establish the shortest distance through the map
struct Node{
	int distance = -1;
	vector<int> adj; //For adjacent nodes

};

class MazeGame{
private:
	int dim_len = side_length;
	int size = dim_len * dim_len;
	void getMapValue(int val);
	vector<Node> node_list; //Used for determing solution feasibility
	deque<int> visit_queue;
	void checkFeasibility(); //Prevents being locked out by obstacles

public:
	vector<int> layout = vector<int>(size, 0);
	int hero_pos = 0;
	MazeGame();
	void printMap();
	void move(char key);
	void playGame();
};