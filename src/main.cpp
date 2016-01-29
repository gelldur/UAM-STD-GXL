#include <iostream>
#include <pugixml.hpp>
#include <cstring>
#include "Graph.h"

Graph parseGraph(pugi::xml_document& document)
{
	auto graphXml = document.find_node([](pugi::xml_node element)
									   {
										   return strcmp(element.name(), "graph") == 0;
									   });
	Graph graph(graphXml.attribute("id").as_string());
	for (auto node : graphXml.children())
	{
		const std::string& nodeName = node.name();
		if (nodeName == "node")
		{
			graph.addNode(node.attribute("id").as_string("unknown"));
		}
		else if (nodeName == "edge")
		{
			//For Bidirectional graph
			graph.addBidirectionalEdge(node.attribute("from").as_string("unknown"), node.attribute("to")
					.as_string("unknown"));
		}
	}

	return graph;
}

int main(int argc, const char* args[])
{
	if (argc < 2)
	{
		std::cout << "Please pass file path to read" << std::endl;
		return 1;
	}


	std::string fileName = args[1];
	std::cout << "Parsing file: " << fileName << std::endl;

	pugi::xml_document document;
	auto result = document.load_file(fileName.c_str(), pugi::parse_default, pugi::encoding_auto);

	switch (result.status)
	{
		case pugi::xml_parse_status::status_ok:
			std::cout << "status ok" << std::endl;
			break;
		case pugi::xml_parse_status::status_unrecognized_tag:
			std::cout << "status_unrecognized_tag" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_file_not_found:
			std::cout << "status_file_not_found" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_io_error:
			std::cout << "status_io_error" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_out_of_memory:
			std::cout << "status_out_of_memory" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_internal_error:
			std::cout << "status_internal_error" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_bad_pi:
			std::cout << "status_bad_pi" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_bad_comment:
			std::cout << "status_bad_comment" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_bad_cdata:
			std::cout << "status_bad_cdata" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_bad_doctype:
			std::cout << "status_bad_doctype" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_bad_start_element:
			std::cout << "status_bad_start_element" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_bad_attribute:
			std::cout << "status_bad_attribute" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_bad_end_element:
			std::cout << "status_bad_end_element" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_end_element_mismatch:
			std::cout << "status_end_element_mismatch" << std::endl;
			return 2;
		case pugi::xml_parse_status::status_no_document_element:
			std::cout << "status_no_document_element" << std::endl;
			return 2;
	}

	//auto graph = parseGraph(document);
	{
		Graph graph("test1 - (1,6) bridge");
		graph.addBidirectionalEdge("0", "2");
		graph.addBidirectionalEdge("0", "1");
		graph.addBidirectionalEdge("1", "2");
		graph.addBidirectionalEdge("1", "6");
		graph.addBidirectionalEdge("1", "4");
		graph.addBidirectionalEdge("1", "3");
		graph.addBidirectionalEdge("3", "5");
		graph.addBidirectionalEdge("4", "5");
		graph.print();
		std::cout << "Bridges in graph:" << std::endl;
		graph.printBridges();
		std::cout << "##############################" << std::endl;
	}
	{
		Graph graph("test2 - (3,4),(0,3) bridge");
		graph.addBidirectionalEdge("1", "0");
		graph.addBidirectionalEdge("0", "2");
		graph.addBidirectionalEdge("2", "1");
		graph.addBidirectionalEdge("0", "3");
		graph.addBidirectionalEdge("3", "4");
		graph.print();
		std::cout << "Bridges in graph:" << std::endl;
		graph.printBridges();
		std::cout << "##############################" << std::endl;
	}
	{
		Graph graph("test3 - (2,3),(1,2),(0,1) bridge");
		graph.addBidirectionalEdge("0", "1");
		graph.addBidirectionalEdge("1", "2");
		graph.addBidirectionalEdge("2", "3");
		graph.print();
		std::cout << "Bridges in graph:" << std::endl;
		graph.printBridges();
		std::cout << "##############################" << std::endl;
	}
	{
		Graph graph("test4 - NO bridge");
		graph.addBidirectionalEdge("0", "1");
		graph.addBidirectionalEdge("1", "2");
		graph.addBidirectionalEdge("2", "3");
		graph.addBidirectionalEdge("3", "0");
		graph.print();
		std::cout << "Bridges in graph:" << std::endl;
		graph.printBridges();
		std::cout << "##############################" << std::endl;
	}

	return 0;
}