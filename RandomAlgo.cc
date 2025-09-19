#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"

//#define ELBOW_CALC

using namespace std;

retval doLinear(int REPEAT_NUM){
	chrono::high_resolution_clock::time_point begin, end;
	chrono::nanoseconds elapsed;
	begin = chrono::high_resolution_clock::now();

	retval output;
	int minCost = INFINITY;
	vector<shipment> minShipments;
	int count=-1;
	bool toggle = true;
	for(int i=0; i<REPEAT_NUM; i++){
		resetFood();
		shipments.clear();
		vector<double> temp = linear(edges);
		edges = order(temp);
		int totalCost=0;
		for(vector<edge>::iterator it = edges.begin(); it != edges.end(); ++it){
			if(!isUsedUp(*it)){
				sendAllFood(*it);
				totalCost += (*it).cost;
			}
		}
		if(totalCost<minCost){
			minCost=totalCost;
			minShipments.clear();
			for(vector<shipment>::iterator it=shipments.begin(); it!=shipments.end(); ++it){
				minShipments.push_back(*it);
			}
			count=-1;
		}
		count++;
#ifdef ELBOW_CALC
		if(toggle && count >= ELBOW_CUTOFF){
			cout << i << endl;
			toggle = false;
		}
		#endif
	}
	shipments.clear();
	for(vector<shipment>::iterator it=minShipments.begin(); it!=minShipments.end(); ++it){
		shipments.push_back(*it);
	}
#ifdef ELBOW_CALC
	if(toggle){
		cout << ">" << REPEAT_NUM << endl;
	}
	#endif

	end = chrono::high_resolution_clock::now();
	elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	output.cost = minCost;
	output.edges = minShipments.size();
	output.runtime = elapsed;
	return output;
}

retval doLinear(){
	return doLinear(50);
}

retval doSoftmax(int REPEAT_NUM, double temp){
	chrono::high_resolution_clock::time_point begin, end;
	chrono::nanoseconds elapsed;
	begin = chrono::high_resolution_clock::now();

	retval output;
	int minCost = INFINITY;
	vector<shipment> minShipments;
//	int count=-1;
//	bool toggle = true;
	for(int i=0; i<REPEAT_NUM; i++){
		resetFood();
		shipments.clear();
		vector<double> prob = softmax(edges, temp);
		edges = order(prob);
		int totalCost=0;
		for(vector<edge>::iterator it = edges.begin(); it != edges.end(); ++it){
			if(!isUsedUp(*it)){
				sendAllFood(*it);
				totalCost += (*it).cost;
			}
		}
		if(totalCost<minCost){
			minCost=totalCost;
			minShipments.clear();
			for(vector<shipment>::iterator it=shipments.begin(); it!=shipments.end(); ++it){
				minShipments.push_back(*it);
			}
//			count=-1;
		}
//		count++;
#ifdef ELBOW_CALC
		if(toggle && count >= ELBOW_CUTOFF){
			cout << i << endl;
			toggle = false;
		}
		#endif
	}
	shipments.clear();
	for(vector<shipment>::iterator it=minShipments.begin(); it!=minShipments.end(); ++it){
		shipments.push_back(*it);
	}
#ifdef ELBOW_CALC
	if(toggle){
		cout << ">" << REPEAT_NUM << endl;
	}
	#endif

	end = chrono::high_resolution_clock::now();
	elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	output.cost = minCost;
	output.edges = minShipments.size();
	output.runtime = elapsed;
	return output;
}

retval doSoftmax(int REPEAT_NUM){
	return doSoftmax(REPEAT_NUM,1);
}

retval doSoftmax(){
	return doSoftmax(50);
}
