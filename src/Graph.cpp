//
// Created by Dawid Drozd aka Gelldur on 28.01.16.
//

#include "Graph.h"
#include <iostream>

Graph::Graph(const std::string& name)
		: _name(name)
{
}

void Graph::addEdge(const std::string& from, const std::string& to)
{
	_vertices[from].insert(to);
}

void Graph::addBidirectionalEdge(const std::string& verticleA, const std::string& verticleB)
{
	addEdge(verticleA, verticleB);
	addEdge(verticleB, verticleA);
}

void Graph::addNode(const std::string& node)
{
	_vertices[node] = {};
}

void Graph::print()
{
	std::cout << "Graph: " << _name << std::endl;
	std::cout << "Check graph connectivity: " << (isConnected() ? "true" : "false") << std::endl;
	for (const auto& vertice : _vertices)
	{
		std::cout << "--- node: " << vertice.first << "\n";
		for (const auto& edge : vertice.second)
		{
			std::cout << vertice.first << " -> " << edge << "\n";
		}
		std::cout << "-------------\n" << std::endl;
	}
}

void Graph::dfsLookForBridge(const std::string& verticle, std::map<std::string, Verticle>& verticles)
{
	static int order = 0;
	verticles[verticle].isVisited = true;

	verticles[verticle].disc = verticles[verticle].low = ++order;

	for (const auto& verticleTo : _vertices[verticle])
	{
		if (verticles[verticleTo].isVisited == false)
		{
			verticles[verticleTo].parent = verticle;
			dfsLookForBridge(verticleTo, verticles);

			verticles[verticle].low = std::min(verticles[verticle].low, verticles[verticleTo].low);

			if (verticles[verticleTo].low > verticles[verticle].disc)
			{
				std::cout << verticle << " - " << verticleTo << std::endl;
			}
		}
		else if (verticleTo != verticles[verticle].parent)
		{
			verticles[verticle].low = std::min(verticles[verticle].low, verticles[verticleTo].disc);
		}
	}
}

bool Graph::printBridges()
{
	if (_vertices.size() < 1)
	{
		return false;
	}

	std::map<std::string, Verticle> verticles;
	for (const auto& vertice : _vertices)
	{
		verticles[vertice.first] = {false, 0, 0, ""};
	}

	for (const auto& element : verticles)
	{
		if (element.second.isVisited == false)
		{
			dfsLookForBridge(element.first, verticles);
		}
	}

	return false;
}

bool Graph::isConnected()
{
	for (const auto& node : _vertices)
	{
		if (node.second.size() < 1)
		{
			return false;
		}
	}
	return true;
}
