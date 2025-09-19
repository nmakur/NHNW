// THIS FILE IS FOR ALL FUNCTIONS WRITING TO LOG

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include<ctime>
#include "FoodFuncs.hpp"
using namespace std;

void logNote(string text){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	fout << endl << text << endl;
	fout.close();
}

void clearLog(){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt");
	fout << "";
	fout.close();
}

void exportLog(){
	ifstream fin;
	ofstream fout;
	string line;
	fin.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt");
	fout.open("C:/Users/Admin/Documents/NHNW/LOG.txt", ios::app);
	for(int i=0; i<100; i++){
		fout << "#";
	}
	fout << endl << endl;
	time_t ttime = time(0);
	char* dt = ctime(&ttime);
	line = (string) dt;
	fout << line << endl;
	getline(fin, line);
	while(fin){
		fout << line << "\n";
		getline(fin, line);
	}
	fin.close();
	fout.close();
}

void logBreak(){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	fout << endl;
	for(int i=0; i<100; i++){
		fout << "-";
	}
	fout << endl;
	fout.close();
}

void log(vertex inp){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	fout << inp.name << " ";
	fout << "(";
	for(int i=0; i<inp.food.size(); i++){
		fout << foodTypes.at(i) << ": " << inp.food.at(i);
		if(i!=inp.food.size()-1){
			fout << ", ";
		}
	}
	fout << ")";
	fout.close();
}
void log(edge inp){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	fout << "(D: " << (*inp.donor).name << ", B: " << (*inp.bank).name << ", " << inp.cost << ")";
	fout.close();
}
void logFoodTypes(){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	for(vector<string>::iterator it = foodTypes.begin(); it != foodTypes.end(); ++it){
		fout << *it;
		if(it != foodTypes.end()-1){
			fout << " ";
		}
	}
	fout << endl;
	fout.close();
}
void logDonors(){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	for(vector<vertex>::iterator it=vertices[0].begin(); it!=vertices[0].end(); ++it){
		log(*it);
		fout << endl;
	}
	fout.close();
}
void logBanks(){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	for(vector<vertex>::iterator it=vertices[1].begin(); it!=vertices[1].end(); ++it){
		log(*it);
		fout << endl;
	}
	fout.close();
}
void logEdges(){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	for(vector<edge>::iterator it=edges.begin(); it!=edges.end(); ++it){
		log(*it);
		fout << endl;
	}
	fout.close();
}

void logData(){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	fout << endl << "THE FOOD TYPES ARE:" << endl;
	logFoodTypes();
	fout << endl << "THE DONORS ARE:" << endl;
	logDonors();
	fout << endl << "THE BANKS ARE:" << endl;
	logBanks();
	fout << endl << "THE COSTS ARE:" << endl;
	logEdges();
	fout << endl;
	for(int i=0; i<100; i++){
		fout << "-";
	}
	fout << endl;
	fout.close();
}

void logShipments(){
	int totalCost=0;
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	fout << "\n";
	for(vector<shipment>::iterator it=shipments.begin(); it!=shipments.end(); ++it){
		fout << (*(*it).edge.donor).name << " -- " << (*(*it).edge.bank).name << " (";
		for(int i=0; i<(*it).food.size(); i++){
			fout << foodTypes.at(i) << ": " << (*it).food.at(i);
			if(i!=(*it).food.size()-1){
				fout << ", ";
			}
		}
		fout << ")\n";
		totalCost += (*it).edge.cost;
	}
	fout << "\nTHE TOTAL COST OF THIS SHIPMENT IS: " << totalCost << endl;
	fout << "THIS SHIPMENT USES " << shipments.size() << " EDGES" << endl << endl;
	for(int i=0; i<100; i++){
		fout << "-";
	}
	fout << endl;
	fout.close();
}

void logShipments(string titleText){
	ofstream fout;
	fout.open("B:/Eclipse Workspace/NHNW/Text Files/_LOG.txt", ios::app);
	fout << endl << titleText << endl;
	fout.close();
	logShipments();
}
