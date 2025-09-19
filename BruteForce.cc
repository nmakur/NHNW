// Executes the Brute-Force algorithm

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

retval doBruteForce(){
	chrono::high_resolution_clock::time_point begin, end;
	chrono::nanoseconds elapsed;
	begin = chrono::high_resolution_clock::now();

	retval output;
	shipments.clear();
	int totalCost;
	vector<shipment> minShipments;
	int minCost=INT_MAX;
	int nums[edges.size()];
	for(int i=0; i<edges.size(); i++){
		nums[i]=i;
	}
	while(next_permutation(nums, nums+edges.size())){
		totalCost=0;
		shipments.clear();
		resetFood();
		for(int i=0; i<edges.size(); i++){
			if(!isUsedUp(edges.at(nums[i]))){
				sendAllFood(edges.at(nums[i]));
				totalCost += (edges.at(nums[i])).cost;
			}
		}
		if(totalCost<minCost){
			minCost=totalCost;
			minShipments.clear();
			for(vector<shipment>::iterator it=shipments.begin(); it!=shipments.end(); ++it){
				minShipments.push_back(*it);
			}
			logShipments("NEW MINIMUM:");
		}
	}
	totalCost=minCost;
	shipments.clear();
	for(vector<shipment>::iterator it=minShipments.begin(); it!=minShipments.end(); ++it){
		shipments.push_back(*it);
	}
	end = chrono::high_resolution_clock::now();
	elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	output.cost = totalCost;
	output.edges = shipments.size();
	output.runtime = elapsed;
	return output;
}
