#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include<chrono>
#include "FoodFuncs.hpp"
using namespace std;

void runSimul(int num, bool includes[]){
	retval outs;
	string temp, base;
	for(int i=0; i<num; i++){
		doRandomData();
		doInput();
		base = "," + to_string(vertices[0].size()) + "," + to_string(vertices[1].size()) + "," + to_string(foodTypes.size()) + ",";
		int totalCost=0;
		for(int i=0; i<edges.size(); i++){
			totalCost += edges.at(i).cost;
		}
		base += to_string(totalCost) + ",";
		if(includes[0]){
			outs = doTakeCheap();
			temp = "0" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
			logNote(temp);
			doInput();
		}if(includes[1]){
			outs = doTakeExpensiveDelta();
			temp = "1" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
			logNote(temp);
			doInput();
		}if(includes[2]){
			outs = doAvoidExpensive();
			temp = "2" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
			logNote(temp);
			doInput();
		}if(includes[3]){
			outs = doAvoidCheapDelta();
			temp = "3" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
			logNote(temp);
			doInput();
		}if(includes[4]){
			outs = doLinear();
			temp = "4" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
			logNote(temp);
			doInput();
		}if(includes[5]){
			outs = doSoftmax();
			temp = "5" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
			logNote(temp);
			doInput();
		}
		logNote("");
	}
	logBreak();
}

void runIterativeSimul(int MAX_DONORS, int MAX_BANKS, bool includes[]){
	int MAX_COST=100;
	int MAX_NUM_TYPES=10;
	int MAX_FOOD_QTY=1000;
	int numTypes = rand()%(MAX_NUM_TYPES)+1;
	int numVertices=max(MAX_DONORS, MAX_BANKS);
	retval outs;
	string temp, base;
	vector<int> foodQty;
	for(int k=0; k<numTypes; k++){
		foodQty.push_back(rand()%(MAX_FOOD_QTY-20*numVertices+1)+20*numVertices);
	}
	for(int i=1; i<MAX_DONORS+1; i++){
		for(int j=1; j<MAX_BANKS+1; j++){
			for(int k=0; k<5; k++){
			doFixedParamRandomData(i, j, numTypes, MAX_COST, foodQty);
			doInput();
			base = "," + to_string(vertices[0].size()) + "," + to_string(vertices[1].size()) + "," + to_string(foodTypes.size()) + ",";
			int totalCost=0;
			for(int i=0; i<edges.size(); i++){
				totalCost += edges.at(i).cost;
			}
			base += to_string(totalCost) + ",";
			if(includes[0]){
				outs = doTakeCheap();
				temp = "0" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
				logNote(temp);
				doInput();
			}if(includes[1]){
				outs = doTakeExpensiveDelta();
				temp = "1" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
				logNote(temp);
				doInput();
			}if(includes[2]){
				outs = doAvoidExpensive();
				temp = "2" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
				logNote(temp);
				doInput();
			}if(includes[3]){
				outs = doAvoidCheapDelta();
				temp = "3" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
				logNote(temp);
				doInput();
			}if(includes[4]){
				outs = doLinear();
				temp = "4" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
				logNote(temp);
				doInput();
			}if(includes[5]){
				outs = doSoftmax();
				temp = "5" + base + to_string(outs.cost) + "," + to_string(outs.edges) + "," + to_string(outs.runtime.count()) + ",";
				logNote(temp);
				doInput();
			}
			logNote("");
			}
		}
	}
	logBreak();
}
