#ifndef FOODFUNCS_HPP_
#define FOODFUNCS_HPP_
//#define DEBUGMODE

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<chrono>
#include <bits/stdc++.h>
using namespace std;

// Structs
struct vertex{
	string name;
	vector<int> food;
	bool usedUp;
};
struct edge{
	vector<vertex>::iterator donor;
	vector<vertex>::iterator bank;
	int cost;
};
struct shipment{
	edge edge;
	vector<int> food;
};
struct edgeND{
	vector<edge>::iterator edge;
	int ND;
};
struct retval{
	int cost;
	int edges;
	chrono::nanoseconds runtime;
};

// Global Variables
extern vector<string> foodTypes;
extern vector<vertex> vertices[2];
extern vector<edge> edges;
extern vector<shipment> shipments;

// AvoidCheapDelta.cc

retval doAvoidCheapDelta();

// AvoidExpensive.cc

retval doAvoidExpensive();

// BruteForce.cc

retval doBruteForce();

// CommandPrompt.cc

void doCommandPrompt();

// FuncDefs.cc

vector<string> split(string inp, char delim);

void print(vertex inp);
void print(edge inp);
void print(shipment inp);
void printFoodTypes();
void printDonors();
void printBanks();
void printEdges();
void printShipments();
void logEdges();

bool isIn(vector<string> inp, string check);

int getIndex(vector<string> list, string name);
int getIndex(vector<vertex> list, string name);

bool compA(edge e1, edge e2);
bool compD(edge e1, edge e2);
bool compND_A(edgeND e1, edgeND e2);
bool compND_D(edgeND e1, edgeND e2);

void sendFood(shipment inp);
void sendAllFood(edge inp);

bool canRemove(vector<edge>::iterator inp);

// Logs
void clearLog();
void exportLog();
void logNote(string text);
void logBreak();
void logData();
void logShipments();
void logShipments(string titleText);


void doTestData();
void getDataFrom(string prefix);
void saveDataTo(string prefix);
void doFixedParamRandomData(int numDonors, int numBanks, int numTypes, int MAX_COST, vector<int> foodQty);
void doRandomData();

void doInput();
void updateFood(vector<vertex>& list, string vertexName, string foodName, int qty);
void resetFood();

retval doTakeCheap();
retval doTakeExpensiveDelta();

bool isUsedUp(edge e);

void runSimul(int num, bool includes[]);
void runIterativeSimul(int MAX_DONORS, int MAX_BANKS, bool includes[]);

vector<double> softmax(vector<edge> input, double temp);
vector<double> linear(vector<edge> input);
vector<edge> order_recursive(vector<edge> paths, vector<double> weights);
vector<edge> order(vector<double> weights);

retval doLinear();
retval doLinear(int REPEAT_NUM);
retval doSoftmax();
retval doSoftmax(int REPEAT_NUM);
retval doSoftmax(int REPEAT_NUM, double temp);

extern int ELBOW_CUTOFF;

#endif /* FOODFUNCS_HPP_ */
