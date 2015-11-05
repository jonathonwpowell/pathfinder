README:

Author: Jonathon Powell

A simple pathfinder algorithm for a 2-d array of passable/impassible locations
as well as tests for it.  It is an implementation of Dijkstra's algorithm,
details of which can be found at https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

Compiled with g++ on Ubuntu 14.04LTS

Files:
tester.cc
pathfinder.cc
pathfinder.h
Makefile
Pathfinder Test Plan.docx
README.md
test_results.txt

File Descriptions:

tester.cc
	This file is used to test the pathfinder function.  It calls the
	function many times and prints the return and the pOutBuffer.  It
	does not currently support an automatic way to see if the tests
	pass or not, as the scope of the project is fairly small so it seemed
	overkill.

Pathfinder Test Plan.docx
	This is a word file that has the name, conditions, and expected
	results of all the tests in tester.  While the returns are printed
	in running the tester, the pOutBuffer values need to be checked against
	this document

pathfinder.h
	Contains the function definition for the FindPath Function

pathfinder.cc
	Implements a pathfinding algorithm that takes in all th information
	in the function definition, and returns the length of the shortest path
	if it is possible, -1 if it is not possible, and -2 if the input has an
	error.  It will also fill pOutBuffer with the shortest path values

Makefile
	Compiles the pathfinder function with the tester into path_finder_test.
	The FindPath function cannot be called by itself from the command line,
	but can be imported into other code.

README
	Please see README for details about README

test_results.txt
	Output of path_finder_test into a text document
	May or may not be up to date
