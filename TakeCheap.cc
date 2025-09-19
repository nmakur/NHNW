// Executes the Take-Cheap algorithm

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

retval doTakeCheap(){
	// Start the timer for the algorithm
	chrono::high_resolution_clock::time_point begin, end;
	chrono::nanoseconds elapsed;
	begin = chrono::high_resolution_clock::now();

	retval output;
	shipments.clear(); // Clear the vector containing the final plan
	sort(edges.begin(), edges.end(), compA); // Sort the edges from cheapest to most expensive
	int totalCost=0;

	// Send all food along the edges in the sorted order
	for(vector<edge>::iterator it = edges.begin(); it != edges.end(); ++it){
		if(!isUsedUp(*it)){ // Check if it is possible to send food along the edge *it
			sendAllFood(*it); // Sends all possible food along *it, and logs the food sent to shipments
			totalCost += (*it).cost; // Update the total cost
		}
	}

	// End the timer for the algorithm and compute the runtime
	end = chrono::high_resolution_clock::now();
	elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	// Compile the total cost, number of edges used, and runtime into the output
	output.cost = totalCost;
	output.edges = shipments.size();
	output.runtime = elapsed;
	// Return
	return output;
}

