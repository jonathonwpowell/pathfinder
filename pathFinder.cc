#include <queue>
#include <iostream>
#include <limits.h>
/**
Author: Jonathon Powell
*/
struct node
{
	int xCorr; 		//x corrdinate of node
	int yCorr; 		//y corrdinate of node
	int dist;  		//distance from source
	int prev;  		//prev node in optimal path
	int isPassable; //1 if passable, 0 if not
};

int main()
{
	unsigned char pMap[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
	int pOutBuffer[12];
	int dist = FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);
	std::cout << "return(should be 3): " + dist;

	unsigned char pMap[] = {0, 0, 1, 0, 1, 1, 1, 0, 1};
	int pOutBuffer[7];
	dist = FindPath(2, 0, 0, 2, pMap, 3, 3, pOutBuffer, 7);
	std::cout << "return(should be -1): " + dist;
}

int FindPath(const int nStartX, const int nStartY, const int nTargetX,
	const int nTargetY, const unsigned char* pMap,
	const int nMapWidth, const int nMapHeight, int* pOutBuffer,
	const int nOutBufferSize)
{
	//make sure assumtions are true
	if (nMapHeight < 1 || nMapWidth < 1 || nStartX < 0 || nStartX >= nMapWidth
		|| nStartY < 0 || nStartY >= nMapHeight || nOutBufferSize < 0)
	{
		std::cout << "Assumtions not true";
		exit(-1);
	}

	//check if the destination is the start
	if(nStartX == nTargetX && nStartY == nTargetY)
		return 0;

	//create array of nodes, one for each spot on the map
	int arraySize = nMapWidth * nMapHeight;
	struct node nodes[arraySize]

	//initialize each node
	for(int i = 0; i < arraySize; i++){
		nodes[i].xCorr = i % nMapWidth;
		nodes[i].yCorr = i / nMapWidth;
		nodes[i].dist = INT_MAX; 
		nodes[i].prev = -1;
	}
	
	//create a priority queue for storing nodes to process
	std::priority_queue<int> queue;

	//push the start location onto the queue
	//only pushes the location in the map array
	queue.push(nStartY * nMapWidth + nStartX);
	
	//set the distance for the start node to 0
	nodes[nStartY * nMapWidth + nStartX].dist = 0;

	while(!queue.empty()){
		//get the next node in the queue
		int curr = queue.pop(); 

		//if the current node is the target, break while loop
		if (curr == nTargetY * nMapWidth + nTargetX)
			break;

		//check if there is a node to the left
		if (curr >= 0 && nodes[curr].yCorr == nodes[curr-1].yCorr)
		{
			//if it is possibly part of a shorter path and passable
			if (nodes[curr-1].dist > nodes[curr].dist + 1
					&& pMap[curr-1] == 1)
			{
				//update the distance from source to the new value
				nodes[curr-1].dist = nodes[curr].dist + 1;
				//update the previous node to curr
				nodes[curr-1].prev = curr;
				//puh onto the queue
				queue.push(curr-1);
			}
		}
		//check if there is a node to the right
		if (curr + 1 <  arraySize  && nodes[curr].yCorr == nodes[curr+1].yCorr)
		{
			//if it is possibly part of a shorter path and passable
			if (nodes[curr+1].dist > nodes[curr].dist + 1
					&& pMap[curr+1] == 1)
			{
				//update the distance from source to the new value
				nodes[curr+1].dist = nodes[curr].dist + 1;
				//update the previous node to curr
				nodes[curr+1].prev = curr;
				//puh onto the queue
				queue.push(curr+1);
			}
		}
		//check if there is a node above
		if (curr - nMapWidth >= 0)
		{
			//if it is possibly part of a shorter path and passable
			if (nodes[curr-nMapWidth].dist > nodes[curr].dist + 1 
					&& pMap[curr-mMapWidth] == 1)
			{
				//update the distance from source to the new value
				nodes[curr-nMapWidth].dist = nodes[curr].dist + 1;
				//update the previous node to curr
				nodes[curr-nMapWidth].prev = curr;
				//puh onto the queue
				queue.push(curr-nMapWidth);
			}
		}
		//check if there is a node to the below
		if (curr + nMapWidth + 1 < arraySize)
		{
			//if it is possibly part of a shorter path and passable
			if (nodes[curr+nMapWidth].dist > nodes[curr].dist + 1
				   	&& pMap[curr+nMapWidth] == 1)
			{
				//update the distance from source to the new value
				nodes[curr+nMapWidth].dist = nodes[curr].dist + 1;
				//update the previous node to curr
				nodes[curr+nMapWidth].prev = curr;
				//puh onto the queue
				queue.push(curr+nMapWidth);
			}
		}
		
		
		//return -1 if no path
		if (nodes[nTargetY * nMapWidth + nTargetX].prev == -1)
			return -1;

		//stack for finding the path between the source and dest
		std::stack<int> pathStack;


		//return the distance if there is a path
		return nodes[nTargetY * nMapWidth + nTargetX].dist;
	}


}
