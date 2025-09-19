// All common functions

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

struct vertex;
struct edge;
struct shipment;

// Global Variables
vector<string> foodTypes;
vector<vertex> vertices[2];
vector<edge> edges;
vector<shipment> shipments;
int ELBOW_CUTOFF;

//Basic Functions
vector<string> split(string inp, char delim){
	vector<string> output;
	string temp="";
	for(int i=0; i<inp.length(); i++){
		if(inp.at(i)==delim){
			output.push_back(temp);
			temp="";
		}else{
			temp+=inp.at(i);
		}
	}
	output.push_back(temp);
	return output;
}

void printLabels(vector<int> inp){
	for(int i=0; i<inp.size(); i++){
		cout << foodTypes.at(i) << ": " << inp.at(i);
		if(i!=inp.size()-1){
			cout << " ";
		}
	}
	cout << flush;
}
void print(vertex inp){
	cout << inp.name << " ";
	cout << "(";
	printLabels(inp.food);
	cout << " |" << inp.usedUp << ")";
	cout << flush;
}
void print(edge inp){
	cout << "(D: " << (*inp.donor).name << ", B: " << (*inp.bank).name << ", " << inp.cost << ")";
	cout << flush;
}
void print(shipment inp){
	cout << (*inp.edge.donor).name << " -- " << (*inp.edge.bank).name << " (";
	printLabels(inp.food);
	cout << ")";
	cout << flush;
}
void printFoodTypes(){
	for(vector<string>::iterator it = foodTypes.begin(); it != foodTypes.end(); ++it){
		cout << *it;
		if(it != foodTypes.end()-1){
			cout << " ";
		}
	}
	cout << endl;
	cout << flush;
}
void printDonors(){
	for(vector<vertex>::iterator it=vertices[0].begin(); it!=vertices[0].end(); ++it){
		print(*it);
		cout << endl;
	}
	cout << flush;
}
void printBanks(){
	for(vector<vertex>::iterator it=vertices[1].begin(); it!=vertices[1].end(); ++it){
		print(*it);
		cout << endl;
	}
	cout << flush;
}
void printEdges(){
	for(vector<edge>::iterator it=edges.begin(); it!=edges.end(); ++it){
		print(*it);
		cout << endl;
	}
	cout << flush;
}
void printShipments(){
	for(vector<shipment>::iterator it=shipments.begin(); it!=shipments.end(); ++it){
		print(*it);
		cout << endl;
	}
	cout << flush;
}

bool isIn(vector<string> inp, string check){
	for(int i=0; i<inp.size(); i++){
		if(inp.at(i) == check){
			return true;
		}
	}
	return false;
}

int getIndex(vector<string> list, string name){
	for(int i=0; i<list.size(); i++){
		if(list.at(i) == name){
			return i;
		}
	}
	return -1;
}
int getIndex(vector<vertex> list, string name){
	for(int i=0; i<list.size(); i++){
		if(list.at(i).name == name){
			return i;
		}
	}
}

bool compA(edge e1, edge e2){
	return e1.cost < e2.cost;
}
bool compD(edge e1, edge e2){
	return e1.cost > e2.cost;
}
bool compND_A(edgeND e1, edgeND e2){
	if(e1.ND == e2.ND){
		return compD(*e1.edge, *e2.edge);
	}
	return e1.ND < e2.ND;
}
bool compND_D(edgeND e1, edgeND e2){
	if(e1.ND == e2.ND){
		return compA(*e1.edge, *e2.edge);
	}
	return e1.ND > e2.ND;
}

//Important Functions

void sendFood(shipment inp){
	(*inp.edge.donor).usedUp=true;
	(*inp.edge.bank).usedUp=true;
	int donorFood, bankFood;
	for(int i=0; i<foodTypes.size(); i++){
		donorFood = (*inp.edge.donor).food.at(i)-(inp.food).at(i);
		bankFood = (*inp.edge.bank).food.at(i)-(inp.food).at(i);
		(*inp.edge.donor).food.erase((*inp.edge.donor).food.begin()+i);
		(*inp.edge.donor).food.insert((*inp.edge.donor).food.begin()+i, donorFood);
		(*inp.edge.bank).food.erase((*inp.edge.bank).food.begin()+i);
		(*inp.edge.bank).food.insert((*inp.edge.bank).food.begin()+i, bankFood);
		if((*inp.edge.donor).food.at(i) != 0){
			(*inp.edge.donor).usedUp = false;
		}
		if((*inp.edge.bank).food.at(i) != 0){
			(*inp.edge.bank).usedUp = false;
		}
	}
	shipments.push_back(inp);
}
void sendAllFood(edge inp){
	shipment temp;
	temp.edge=inp;
	for(int i=0; i<foodTypes.size(); i++){
		temp.food.push_back(min((*temp.edge.donor).food.at(i),(*temp.edge.bank).food.at(i)));
	}
	sendFood(temp);
}

bool isUsedUp(edge e){
	if((*e.donor).usedUp || (*e.bank).usedUp){
		return true;
	}
	vector<int> mins;
	for(int i=0; i<(*e.donor).food.size(); i++){
		mins.push_back(min((*e.donor).food.at(i), (*e.bank).food.at(i)));
	}
	bool output = true;
	for(vector<int>::iterator it=mins.begin(); it!=mins.end(); ++it){
		output = output && (*it==0);
	}
	return output;
}

bool canRemove(vector<edge>::iterator inp){
	for(vector<edge>::iterator it=edges.begin(); it!=edges.end(); ++it){
		if(it != inp){
			sendAllFood(*it);
		}
	}
	bool output = true;
	for(vector<vertex>::iterator it=vertices[0].begin(); it!=vertices[0].end(); ++it){
		output = output && (*it).usedUp;
	}
	resetFood();
	return output;
}

vector<edge> order_recursive(vector<edge> paths, vector<double> weights){
	cout << paths.size() << endl << flush;
	if(paths.size()==1){
		vector<edge> output;
		output.push_back(paths.at(0));
		return output;
	}else{
		std::random_device rd;
		std::mt19937 gen(rd());
		discrete_distribution<> d(weights.begin(), weights.end());
		int i=d(gen);

		edge temp=paths.at(i);
		double fixedWeight = 1-weights.at(i);
		vector<edge> tempPaths;
		vector<double> tempWeights;
		for(int it=0; it<paths.size(); it++){
			if(it!=i){
				tempPaths.push_back(paths.at(it));
				tempWeights.push_back(weights.at(it)/fixedWeight);
			}
		}
		vector<edge> output = order_recursive(tempPaths, tempWeights);
		output.insert(output.begin(),temp);
		return output;
	}
}
vector<edge> order(vector<double> weights){
	int n = weights.size();
	random_device rd;
	mt19937 gen(rd());
	vector<edge> output;

	for (int i=0; i < n; i++) {
		discrete_distribution<> d(weights.begin(), weights.end());
		int choose=d(gen);
		output.push_back(edges.at(choose));
		weights.erase(weights.begin()+choose);
		weights.insert(weights.begin()+choose,0);
	}
	return output;
}
