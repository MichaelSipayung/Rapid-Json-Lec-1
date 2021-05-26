// Rapid Json Lec 1.cpp : Defines the entry point for the application.
//

#include "Rapid Json Lec 1.h"


int main()
{
	/*
	std::cout << "Hello CMake." << std::endl;
	//parse a json into dom 
	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	rapidjson::Document d;
	d.Parse(json);

	//modify it  by dom 
	rapidjson::Value& s = d["stars"];
	s.SetInt(s.GetInt() + 1);

	//stringfy the dom 
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	d.Accept(buffer);

	//set output 
	std::cout << buffer.GetString() << std::endl;
		*/		
	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	rapidjson::Document d;
	d.Parse(json);

	rapidjson::Value& s = d["stars"];
	rapidjson::Value& str = d["project"];

	str.SetString("rapidjson++");

	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	d.Accept(writer);

	std::cout << "hello rapid json . a ligeweight c++ for json parser" << std::endl;
	std::cout << buffer.GetString()<< std::endl;

	return 0;
}
