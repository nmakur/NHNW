// THIS FILE IS FOR ALL FUNCTIONS INVOLVING DATA

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

void getDataFrom(string prefix){
	ifstream fin;
	ofstream fout;
	string line;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Donor_Bank_Distance.txt");
	fin.open("B:/Eclipse Workspace/NHNW/Text Files/Backup Data/"+prefix+"_Donor_Bank_Distance.txt");
	getline(fin, line);
	while(fin){
		fout << line << "\n";
		getline(fin, line);
	}
	fin.close();
	fout.close();

	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Donor_Bank_List.txt");
	fin.open("B:/Eclipse Workspace/NHNW/Text Files/Backup Data/"+prefix+"_Donor_Bank_List.txt");
	getline(fin, line);
	while(fin){
		fout << line << "\n";
		getline(fin, line);
	}
	fin.close();
	fout.close();

	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Supply_Demand_List.txt");
	fin.open("B:/Eclipse Workspace/NHNW/Text Files/Backup Data/"+prefix+"_Supply_Demand_List.txt");
	getline(fin, line);
	while(fin){
		fout << line << "\n";
		getline(fin, line);
	}
	fin.close();
	fout.close();
}

void saveDataTo(string prefix){
	ifstream fin;
	ofstream fout;
	string line;
	fin.open("B:/Eclipse Workspace/NHNW/Text Files/Donor_Bank_Distance.txt");
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Backup Data/"+prefix+"_Donor_Bank_Distance.txt");
	getline(fin, line);
	while(fin){
		fout << line << "\n";
		getline(fin, line);
	}
	fin.close();
	fout.close();

	fin.open("B:/Eclipse Workspace/NHNW/Text Files/Donor_Bank_List.txt");
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Backup Data/"+prefix+"_Donor_Bank_List.txt");
	getline(fin, line);
	while(fin){
		fout << line << "\n";
		getline(fin, line);
	}
	fin.close();
	fout.close();

	fin.open("B:/Eclipse Workspace/NHNW/Text Files/Supply_Demand_List.txt");
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Backup Data/"+prefix+"_Supply_Demand_List.txt");
	getline(fin, line);
	while(fin){
		fout << line << "\n";
		getline(fin, line);
	}
	fin.close();
	fout.close();
}

string prettify(int maxNum, int numNum){
	string max = to_string(maxNum);
	string num = to_string(numNum);
	int padding = max.length()-num.length();
	string output = "";
	for(int i=0; i<padding; i++){
		output += "0";
	}
	output += num;
	return output;
}

void doFixedParamRandomData(int numDonors, int numBanks, int numTypes, int MAX_COST, vector<int> foodQty){
	int numVertices = max(numDonors, numBanks);
	int donorQty[numDonors];
	int bankQty[numBanks];
	ofstream fout;
	// Output the list of donors and banks
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Donor_Bank_List.txt");
	for(int i=0; i<numDonors; i++){
		fout << "0,D" << prettify(numVertices-1, i) << ",\n";
	}
	for(int i=0; i<numBanks-1; i++){
		fout << "1,B" << prettify(numVertices-1, i) << ",\n";
	}
	fout << "1,B" << prettify(numVertices-1, numBanks-1) << ",";
	fout.close();

	// Output the supply/demand
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Supply_Demand_List.txt");
	for(int i=0; i<numTypes; i++){
		for(int i=0; i<numDonors; i++){
			donorQty[i]=0;
		}
		for(int i=0; i<numBanks; i++){
			bankQty[i]=0;
		}
		for(int j=0; j<foodQty.at(i); j++){
			donorQty[rand()%numDonors]++;
			bankQty[rand()%numBanks]++;
		}
		for(int j=0; j<numDonors; j++){
			fout << "0,D" << prettify(numVertices-1, j) << ",T" << prettify(numTypes-1,i) << "," << donorQty[j] << ",\n";
		}
		for(int j=0; j<numBanks; j++){
			fout << "1,B" << prettify(numVertices-1, j) << ",T" << prettify(numTypes-1,i) << "," << bankQty[j] << ",";
			if(j != numBanks-1){
				fout << "\n";
			}
		}
		if(i!=numTypes-1){
			fout << "\n";
		}
	}
	fout.close();

	// Output the costs
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/Donor_Bank_Distance.txt");
	for(int i=0; i<numDonors; i++){
		for(int j=0; j<numBanks; j++){
			fout << "D" << prettify(numVertices-1, i) << ",B" << prettify(numVertices-1,j) << "," << (rand()%MAX_COST+1);
			if(i != numDonors-1 || j!= numBanks-1){
				fout << "\n";
			}
		}
	}
	fout.close();
}

void doRandomData(){
	srand(time(NULL));
	int MAX_VERTICES = 14;
	int MAX_NUM_TYPES = 10;
	int MAX_FOOD_QTY = 1000; // Must be at least MAX_VERTICES*20
	int MAX_COST = 100;
	int numDonors = rand()%(MAX_VERTICES)+1;
	int numBanks = rand()%(MAX_VERTICES)+1;
	int numVertices = max(numDonors, numBanks);
	int numTypes = rand()%(MAX_NUM_TYPES)+1;
	vector<int> foodQty;
	for(int i=0; i<numTypes; i++){
		foodQty.push_back(rand()%(MAX_FOOD_QTY-20*numVertices+1)+20*numVertices);
	}
	doFixedParamRandomData(numDonors, numBanks, numTypes, MAX_COST, foodQty);
}


void updateFood(vector<vertex>& list, string vertexName, string foodName, int qty){
	vector<vertex>::iterator vertexIndex=list.begin() + getIndex(list, vertexName);
	vertex temp = *vertexIndex;
	vector<int>::iterator foodIndex = temp.food.begin() + getIndex(foodTypes, foodName);
	temp.food.erase(foodIndex);
	temp.food.insert(foodIndex, qty);
	if(qty!=0){
		temp.usedUp=false;
	}
	list.erase(vertexIndex);
	list.insert(vertexIndex, temp);
}

void doInput(){
	foodTypes.clear();
	vertices[0].clear();
	vertices[1].clear();
	edges.clear();
	shipments.clear();
	//Input the types of food
	ifstream inp;
	inp.open("B:/Eclipse Workspace/NHNW/Text Files/Supply_Demand_List.txt");
	string line;
	vector<string> splitLine;
	getline(inp, line);
	while(inp){
		splitLine = split(line, ',');
		if(!isIn(foodTypes, splitLine.at(2))){
			foodTypes.push_back(splitLine.at(2));
		}
		getline(inp, line);
	}
	inp.close();
//	cout << "foodTypes is:\n"; printFoodTypes();

	//Input the donors/banks
	inp.open("B:/Eclipse Workspace/NHNW/Text Files/Donor_Bank_List.txt");
	vertex temp;
	for(int i=0; i<foodTypes.size(); i++){
		temp.food.push_back(0);
	}
	temp.usedUp=true;
	getline(inp, line);
	while(inp){
		splitLine = split(line, ',');
		temp.name = splitLine.at(1);
		vertices[stoi(splitLine.at(0))].push_back(temp);
		getline(inp, line);
	}
	inp.close();

	//Input the supply/demand
	inp.open("B:/Eclipse Workspace/NHNW/Text Files/Supply_Demand_List.txt");
	getline(inp, line);
	while(inp){
		splitLine = split(line, ',');
		updateFood(vertices[stoi(splitLine.at(0))], splitLine.at(1), splitLine.at(2), stoi(splitLine.at(3)));
		getline(inp, line);
	}
	inp.close();
//	cout << "donorList is:\n"; printDonors();
//	cout << "bankList is:\n"; printBanks;

	//Input edges
	inp.open("B:/Eclipse Workspace/NHNW/Text Files/Donor_Bank_Distance.txt");
	edge tempEdge;
	vector<vertex>::iterator it;
	getline(inp, line);
	while(inp){
		splitLine = split(line, ',');
//		cout << splitLine.at(1) << "x" << flush;
		it=vertices[0].begin();
		while((*it).name != splitLine.at(0)){
			++it;
		}
		tempEdge.donor=it;
		it=vertices[1].begin();
		while((*it).name != splitLine.at(1)){
			++it;
		}
		tempEdge.bank=it;
		tempEdge.cost=stoi(splitLine.at(2));
		edges.push_back(tempEdge);
		getline(inp, line);
	}
//	cout << "edges is:\n"; printEdges();
}

void resetFood(){
	ifstream inp;
	string line;
	vector<string> splitLine;
	inp.open("B:/Eclipse Workspace/NHNW/Text Files/Supply_Demand_List.txt");
	getline(inp, line);
	while(inp){
		splitLine = split(line, ',');
		updateFood(vertices[stoi(splitLine.at(0))], splitLine.at(1), splitLine.at(2), stoi(splitLine.at(3)));
		getline(inp, line);
	}
	inp.close();
}
