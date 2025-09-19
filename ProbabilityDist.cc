#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
#include "FoodFuncs.hpp"
using namespace std;

vector<double> softmax(vector<edge> input, double temp) {
	int i;
	double sum, constant;

	sum = 0.0;
	for (i = 0; i < input.size(); ++i) {
		sum += exp(-input.at(i).cost/temp);
	}

	vector<double> output;
	constant = log(sum);
	for (i=0; i < input.size(); i++) {
		output.push_back(exp(-input.at(i).cost/temp-constant));
	}
	return output;
}


vector<double> linear(vector<edge> input) {

	int i;
	double m, sum;

	m = -INFINITY;
	for (i = 0; i < input.size(); ++i) {
		if (m < input.at(i).cost) {
			m = input.at(i).cost;
		}
	}
	m++;
	sum = 0.0;
	for (i = 0; i < input.size(); ++i) {
		sum += m-input.at(i).cost;
	}

	vector<double> output;
	for (i=0; i < input.size(); i++) {
		output.push_back((m-input.at(i).cost)/sum);
	}
	return output;
}
