//
// Created by Dawid Drozd aka Gelldur on 28.01.16.
//

#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

class Graph
{
public:
	Graph(const std::string& name);

	void addEdge(const std::string& from, const std::string& to);
	void addBidirectionalEdge(const std::string& verticleA, const std::string& verticleB);
	void addNode(const std::string& node);

	bool printBridges();

	bool isConnected();

	void print();
private:
	struct Verticle
	{
		bool isVisited;
		int disc;
		int low;
		std::string parent;
	};

	void dfsLookForBridge(const std::string& verticle, std::map<std::string, Verticle>& verticles);

	std::string _name;
	std::map<std::string, std::set<std::string>> _vertices;
};


