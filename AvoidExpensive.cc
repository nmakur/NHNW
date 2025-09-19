// Executes the Avoid-Expensive algorithm

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

retval doAvoidExpensive(){
	chrono::high_resolution_clock::time_point begin, end;
	chrono::nanoseconds elapsed;
	begin = chrono::high_resolution_clock::now();

	retval output;
	shipments.clear();
	sort(edges.begin(), edges.end(), compD);
	for(vector<edge>::iterator it=edges.begin(); it!=edges.end(); ++it){
		if(canRemove(it)){
//			cout << "CAN REMOVE\n";
			edges.erase(it);
			--it;
		}
	}
	shipments.clear();
	int totalCost=0;
	for(vector<edge>::iterator it=edges.begin(); it!=edges.end(); ++it){
		sendAllFood(*it);
		totalCost += (*it).cost;
	}

	end = chrono::high_resolution_clock::now();
	elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	output.cost = totalCost;
	output.edges = shipments.size();
	output.runtime = elapsed;
	return output;
}
