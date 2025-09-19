// Executes the Take-Expensive-Delta algorithm

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

retval doTakeExpensiveDelta(){
	chrono::high_resolution_clock::time_point begin, end;
	chrono::nanoseconds elapsed;
	begin = chrono::high_resolution_clock::now();

	retval output;
	shipments.clear();
	sort(edges.begin(), edges.end(), compA);
//	printEdges();
	edgeND temp;
	vector<edgeND> edgeNDs;
	for(vector<edge>::iterator it=edges.begin(); it!=edges.end()-1; ++it){
		temp.edge=it;
		temp.ND=(*(it+1)).cost-(*it).cost;
		edgeNDs.push_back(temp);
	}
	temp.edge=edges.end()-1;
	temp.ND=0;
	edgeNDs.push_back(temp);
	sort(edgeNDs.begin(), edgeNDs.end(), compND_D);
//	cout << "\n";
//	for(vector<edgeND>::iterator it=edgeNDs.begin(); it!=edgeNDs.end(); ++it){
//		print(*((*it).edge));
//		cout << "\n" << flush;
//	}
	int totalCost=0;
	for(vector<edgeND>::iterator it=edgeNDs.begin(); it!=edgeNDs.end(); ++it){
		if(!(*(*(*it).edge).donor).usedUp && !(*(*(*it).edge).bank).usedUp){
			sendAllFood(*(*it).edge);
			totalCost += (*(*it).edge).cost;
		}
	}

	end = chrono::high_resolution_clock::now();
	elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	output.cost = totalCost;
	output.edges = shipments.size();
	output.runtime = elapsed;
	return output;
}
