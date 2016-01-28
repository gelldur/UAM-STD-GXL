#include <iostream>
#include <pugixml.hpp>


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
	return 0;
}