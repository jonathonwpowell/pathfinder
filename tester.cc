#include <iostream>
#include "pathfinder.h"
/**
 * Author: Jonathon Powell
 * This file is designed to help test the FindPath function
 * Each test prints out the expected return value of
 * FindPath for the given input, the actual return value of the
 * given input, and the values in pOutBuffer.  For expected values
 * in the pOutBuffer and more information, please see the test plan doc
 */


int main()
{
	//Base Test
	unsigned char pMap[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
	int pOutBuffer[12];
	int dist = FindPath(0, 0, 1, 2, pMap, 4, 3, pOutBuffer, 12);
	std::cout << "return (should be 3): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer[i] << " ";	
	std::cout << "\n";

	//Base Fail Test
	unsigned char pMap2[] = {0, 0, 1, 0, 1, 1, 1, 0, 1};
	int pOutBuffer2[7];
	dist = FindPath(2, 0, 0, 2, pMap2, 3, 3, pOutBuffer2, 7);
	std::cout << "return (should be -1): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer2[i] << " ";	
	std::cout << "\n";

	//Follow Edge Test
	unsigned char pMap3[] = {1, 0, 0, 1, 0, 0, 1, 1, 1};
	int pOutBuffer3[7];
	dist = FindPath(0, 0, 2, 2, pMap3, 3, 3, pOutBuffer3, 7);
	std::cout << "return (should be 4): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer3[i] << " ";	
	std::cout << "\n";
	
	//No Wrap Around Test
	unsigned char pMap4[] = {1, 0, 1, 1, 0, 1, 1, 0, 1};
	int pOutBuffer4[7];
	dist = FindPath(0, 0, 2, 2, pMap4, 3, 3, pOutBuffer4, 7);
	std::cout << "return (should be -1): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer4[i] << " ";	
	std::cout << "\n";

	//Line L to R Test
	unsigned char pMap5[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer5[8];
	dist = FindPath(0, 0, 7, 0, pMap5, 8, 1, pOutBuffer5, 8);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer5[i] << " ";	
	std::cout << "\n";

	//Line R to L Test
	unsigned char pMap6[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer6[8];
	dist = FindPath(7, 0, 0, 0, pMap6, 8, 1, pOutBuffer6, 8);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer6[i] << " ";	
	std::cout << "\n";

	//Line top to bottom Test
	unsigned char pMap7[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer7[8];
	dist = FindPath(0, 0, 0, 7, pMap7, 1, 8, pOutBuffer7, 8);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer7[i] << " ";	
	std::cout << "\n";

	//Line bottom to top Test
	unsigned char pMap8[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer8[8];
	dist = FindPath(0, 7, 0, 0, pMap8, 1, 8, pOutBuffer8, 8);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist; i++)
		std::cout << pOutBuffer8[i] << " ";	
	std::cout << "\n";

	//Short Buffer Test
	unsigned char pMap9[] = {1, 1, 1, 1, 1, 1, 1, 1};
	int pOutBuffer9[4];
	dist = FindPath(0, 7, 0, 0, pMap9, 1, 8, pOutBuffer9, 4);
	std::cout << "return (should be 7): " << dist;
	std::cout << "\n" << "pOutBuffer: ";
	for (int i = 0; i < dist && i < 4; i++)
		std::cout << pOutBuffer9[i] << " ";	
	std::cout << "\n";
	
	//Invalid Input Test
	dist = FindPath(0, 7, 0, 0, pMap9, 1, 0, pOutBuffer9, 4);
	std::cout << "return (should be -2): " << dist << "\n";
}
