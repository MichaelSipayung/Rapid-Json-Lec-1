// Rapid Json Lec 1.cpp : Defines the entry point for the application.
//

#include "Rapid Json Lec 1.h"


int main()
{	
	// 1. parse json string into dom 
	const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
	rapidjson::Document d;
	d.Parse(json);

	//2.modify it  by dom 
	rapidjson::Value& s = d["stars"];
	rapidjson::Value& str = d["project"];
	str.SetString("rapidjson++");

	//3.stringfy the dom 
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	d.Accept(writer);

	std::cout << "hello rapid json . a ligeweight c++ for json parser" << std::endl;
	std::cout << buffer.GetString()<< std::endl;
	
	std::cout << "Set cmake configuration" << std::endl;
	const char* configuration = "{\"name\": \"x64 - Debug\",\"generator\": \"Ninja\",\"configurationType\": \"Debug\"}";
	rapidjson::Document test;
	test.Parse(configuration);
	rapidjson::StringBuffer buf;
	rapidjson::Writer<rapidjson::StringBuffer> writerTest(buf);
	test.Accept(writerTest);
	std::cout << " test reading cmake configuration.json" << std::endl;
	std::cout << buf.GetString() << std::endl;





	return 0;
}
