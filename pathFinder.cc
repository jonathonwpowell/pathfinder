#include <queue>
#include <iostream>
/**
Author: Jonathon Powell
*/
struct node
{
	int xCorr; //x corrdinate of node
	int yCorr; //y corrdinate of node
	int dist;  //distance from source
	int prev;  //prev node in optimal path
};

int main()
{
	
}

int FindPath(const int nStartx, const int nStartY, const int nTargetX,
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

	//create array of nodes, one for each spot on the map
	int arraySize = nMapWidth * nMapHeight;
	struct node nodes[arraySize]

		
		
	std::queue<unsigned char> queue;
}
