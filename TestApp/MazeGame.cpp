// This simple game requires you to use the w-a-s-d keys to navigate K-Man to the destination letter E in a set number of moves.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
#include <vector>
#include <time.h> 
#include <string>
#include <queue>
#include <deque>
#include "MazeGame.h"

using namespace std;
int n_moves = 50; //Number of moves to get character to destination
bool game_win = false;
MazeGame::MazeGame(){
	cout << "Get K-man through the maze in 50 moves or less" << endl;
	layout[hero_pos] = -1; //Places K-man
	layout[destination_loc] = 2; // Places end
	srand(time(NULL));
	for (int i = 0; i < size; i++){
		if (i != hero_pos && i != destination_loc) {
			int rand_n = rand() % 100;
			if (rand_n < 90) layout[i] = 0;
			else layout[i] = 1;
		}
	}
	//Now initialize adjacencies
	for (int x = 0; x < size; x++){
		Node x_point;
		if (x % dim_len > 0 && layout[x - 1] != 1) x_point.adj.push_back(x - 1);   //Can go left
		if (x < (dim_len - 1)*dim_len && layout[x + dim_len] != 1) x_point.adj.push_back(x + dim_len); //Can go down
		if (x % dim_len < dim_len - 1 && layout[x + 1] != 1) x_point.adj.push_back(x + 1); //Can go right
		if (x >= dim_len && layout[x - dim_len] != 1) x_point.adj.push_back(x - dim_len); //Can go up
		node_list.push_back(x_point);
	}
	//Now test whether a solution is possible
	checkFeasibility(); //Checks feasibility using a BFS algorithim

}
void MazeGame::checkFeasibility(){
	visit_queue.push_back(0);
	node_list[0].distance = 0;
	while (!visit_queue.empty()){
		int s = visit_queue.front();
		visit_queue.pop_front();
		for (int i = 0; i < node_list[s].adj.size(); i++){
			int adj_node_pos = node_list[s].adj[i];
			if (node_list[adj_node_pos].distance == -1) {
				visit_queue.push_back(adj_node_pos);
				node_list[adj_node_pos].distance = node_list[s].distance + 1;
			}
		}
	}
	if (node_list[destination_loc].distance <= n_moves && node_list[destination_loc].distance > 0) {
		cout << "Solution possible in ";
		cout << node_list[destination_loc].distance << " moves";
	}
	else { cout << "NO SOLUTION POSSIBLE, RESETTING"; MazeGame(); }
}

void MazeGame::getMapValue(int val){
	switch (val)
	{
	case 1:
		cout << 'o';
		break;
	case 2:
		cout << 'E';
		break;
	case -1:
		cout << 'K';
		break;
	default:
		cout << ' ';
		break;
	};
}
void MazeGame::printMap(){
	layout[hero_pos] = -1; //Places K-man
	for (int pos = 0; pos < layout.size(); pos++){
		int floor_switch = pos % dim_len;
		if (floor_switch == 0) cout << endl;
		getMapValue(layout[pos]);
	}
	cout << endl;

}
void MazeGame::move(char key){
	switch (key)
	{
	case 'w':
		if (hero_pos >= dim_len && layout[hero_pos - dim_len] != 1) {
			layout[hero_pos] = 0;
			hero_pos -= dim_len;
		}
		break;
	case 'd':
		if (hero_pos % dim_len < dim_len - 1 && layout[hero_pos + 1] != 1) {
			layout[hero_pos] = 0;
			hero_pos += 1;
		}
		break;
	case 's':
		if (hero_pos < (dim_len - 1)*dim_len && layout[hero_pos + dim_len] != 1) {
			layout[hero_pos] = 0;
			hero_pos += dim_len;
		}
		break;
	case 'a':
		if (hero_pos % dim_len > 0 && layout[hero_pos - 1] != 1)
		{
			layout[hero_pos] = 0;
			hero_pos -= 1;
		}
		break;
	default: cout << "Wrong, use w-a-s-d";
		break;
	}
	cout << string(1000, '\n');
	if (hero_pos == destination_loc)
	{
		cout << endl << "YOU WIN!" << endl;
		game_win = true;
	}
	else printMap();
	cout << "Number of moves remaining: " << n_moves;

}
void MazeGame::playGame()
{
	printMap();
	while (n_moves > 0 && game_win == false)
	{
		char move_key;
		cin >> move_key;
		n_moves--;
		move(move_key);
	}
	if (game_win == false) cout << endl << "OUT OF MOVES!" << endl;
}

