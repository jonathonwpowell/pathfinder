#include <iostream>
#include "pathfinder.h"
int main()
{
	unsigned char pMap[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
	int pOutBuffer[12];
	int dist = FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);
	std::cout << "return (should be 3): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer[i] << " ";	
	std::cout << "\n";

	unsigned char pMap2[] = {0, 0, 1, 0, 1, 1, 1, 0, 1};
	int pOutBuffer2[7];
	dist = FindPath(2, 0, 0, 2, pMap2, 3, 3, pOutBuffer2, 7);
	std::cout << "return (should be -1): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer2[i] << " ";	
	std::cout << "\n";

	unsigned char pMap3[] = {1, 0, 0, 1, 0, 0, 1, 1, 1};
	int pOutBuffer3[7];
	dist = FindPath(0, 0, 2, 2, pMap3, 3, 3, pOutBuffer3, 7);
	std::cout << "return (should be 4): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer3[i] << " ";	
	std::cout << "\n";
	
	unsigned char pMap4[] = {1, 0, 1, 1, 0, 1, 1, 0, 1};
	int pOutBuffer4[7];
	dist = FindPath(0, 0, 2, 2, pMap4, 3, 3, pOutBuffer4, 7);
	std::cout << "return (should be -1): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer4[i] << " ";	
	std::cout << "\n";

	unsigned char pMap5[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer5[8];
	dist = FindPath(0, 0, 7, 0, pMap5, 8, 1, pOutBuffer5, 8);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer5[i] << " ";	
	std::cout << "\n";

	unsigned char pMap6[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer6[8];
	dist = FindPath(7, 0, 0, 0, pMap6, 8, 1, pOutBuffer6, 8);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer6[i] << " ";	
	std::cout << "\n";

	unsigned char pMap7[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer7[8];
	dist = FindPath(0, 0, 0, 7, pMap7, 1, 8, pOutBuffer7, 8);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer7[i] << " ";	
	std::cout << "\n";

	unsigned char pMap8[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer8[8];
	dist = FindPath(0, 7, 0, 0, pMap8, 1, 8, pOutBuffer8, 8);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer8[i] << " ";	
	std::cout << "\n";


}
