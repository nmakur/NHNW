#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

int main(){
#ifndef DEBUGMODE
	doCommandPrompt();
#else
//	clearLog();
//	retval outs;
//	string temp, base;
//	int totalCost;
//	for(int d=1; d<=33; d++){
//		for(int b=1; b<=12; b++){
//			srand(time(NULL));
//			int MAX_FOOD_QTY = 1000;
//			int numVertices = 35;
//			vector<int> foodQty;
//			for(int i=0; i<4; i++){
//				foodQty.push_back(rand()%(MAX_FOOD_QTY-20*numVertices+1)+20*numVertices);
//			}
//			doFixedParamRandomData(d, b, 4, 100, foodQty);
//			doInput();
//			base = to_string(d) + "," + to_string(b) + ",";
//			for(int i=0; i<edges.size(); i++){
//				totalCost+=edges.at(i).cost;
//			}
//			base += to_string(totalCost) + ",";
//			outs = doTakeCheap();
//			temp = base + to_string(outs.cost) + "," + to_string(outs.edges);
//			logNote(temp);
//		}
//	}

	clearLog();
	retval outs;
	string temp, base;
	int totalCost;
	vector<int> foodQty;
	for(int d=1; d<=33; d++){
		for(int b=1; b<=12; b++){
			srand(time(NULL));
			int MAX_FOOD_QTY = 1000;
			int numVertices = 35;
			foodQty.clear();
			for(int i=0; i<4; i++){
				foodQty.push_back(rand()%(MAX_FOOD_QTY-20*numVertices+1)+20*numVertices);
			}
			totalCost=0;
			doFixedParamRandomData(d, b, 4, 100, foodQty);
			doInput();
			base = to_string(d) + "," + to_string(b) + ",";
			for(int i=0; i<edges.size(); i++){
				totalCost+=edges.at(i).cost;
			}
			base += to_string(totalCost) + ",";
			outs = doTakeCheap();
			temp = base + to_string(outs.cost) + "," + to_string(outs.edges);
			logNote(temp);
		}
	}

//	retval outs;
//	string temp, base;
//	int totalCost;
//	bool includes[] = {false, false, false, false, false, true};
//	clearLog();
//	for(int i=0; i<1; i++){
//		srand(time(NULL));
//		int MAX_FOOD_QTY = 20000; // Must be at least MAX_VERTICES*20
//		int numVertices = 500;
//		vector<int> foodQty;
//		for(int i=0; i<10; i++){
//			foodQty.push_back(rand()%(MAX_FOOD_QTY-20*numVertices+1)+20*numVertices);
//		}
//		doFixedParamRandomData(350, 100, 10, 100, foodQty);
//		doInput();
//		base = ",";
////		for(int j=0; j<edges.size(); j++){
////			totalCost += edges.at(j).cost;
////		}
////		base += to_string(totalCost) + ",";
//		if(includes[0]){
//			outs = doTakeCheap();
//			temp = "0" + base + to_string(outs.runtime.count()) + ",";
//			logNote(temp);
//			doInput();
//		}if(includes[1]){
//			outs = doTakeExpensiveDelta();
//			temp = "1" + base + to_string(outs.runtime.count()) + ",";
//			logNote(temp);
//			doInput();
//		}if(includes[2]){
//			outs = doAvoidExpensive();
//			temp = "2" + base + to_string(outs.runtime.count()) + ",";
//			logNote(temp);
//			doInput();
//		}if(includes[3]){
//			outs = doAvoidCheapDelta();
//			temp = "3" + base + to_string(outs.runtime.count()) + ",";
//			logNote(temp);
//			doInput();
//		}if(includes[4]){
//			outs = doLinear();
//			temp = "4" + base + to_string(outs.runtime.count()) + ",";
//			logNote(temp);
//			doInput();
//		}if(includes[5]){
//			outs = doSoftmax();
//			temp = "5" + base + to_string(outs.runtime.count()) + ",";
//			logNote(temp);
//			doInput();
//		}
//		logNote("");
//	}
#endif
}
