// Executes the Avoid-Cheap-Delta algorithm

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

retval doAvoidCheapDelta(){
	chrono::high_resolution_clock::time_point begin, end;
	chrono::nanoseconds elapsed;
	begin = chrono::high_resolution_clock::now();

	retval output;
	shipments.clear();
	sort(edges.begin(), edges.end(), compA);
	edgeND temp;
	vector<edgeND> edgeNDs;
	for(vector<edge>::iterator it=edges.begin(); it!=edges.end()-1; ++it){
		temp.edge=it;
		temp.ND=(*(it+1)).cost-(*it).cost;
		edgeNDs.push_back(temp);
	}
	temp.edge=edges.end()-1;
	temp.ND=-1;
	edgeNDs.push_back(temp);
	sort(edgeNDs.begin(), edgeNDs.end(), compND_A);
	vector<edge> temp2;
	for(vector<edgeND>::iterator it=edgeNDs.begin(); it!=edgeNDs.end(); ++it){
		temp2.push_back(*(*it).edge);
	}
	edges.clear();
	for(vector<edge>::iterator it=temp2.begin(); it!=temp2.end(); ++it){
		edges.push_back(*it);
	}
	for(vector<edge>::iterator it=edges.begin(); it!=edges.end(); ++it){
		if(canRemove(it)){
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
