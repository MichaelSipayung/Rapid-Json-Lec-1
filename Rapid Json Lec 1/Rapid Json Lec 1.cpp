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
	std::cout << " test reading cmake configuration.json , test" << std::endl;
	std::cout << buf.GetString() << std::endl;

	std::cout << "Lecture 1" << std::endl;
	const char* jsonVar= "{\"hello\": \"world\",\"t\" : true ,\"f\" : false,\"n\" : null,\"i\" : 123,\"pi\" : 3.1416,\"a\" : [1, 2, 3, 4]}";

	//parse it into document
	rapidjson::Document  doc;
	doc.Parse(jsonVar);
	assert(doc.HasMember("hello")); //test if it's has a  member hello
	assert(doc["t"].IsBool());//assertion success
	std::cout << "Show string \t: [" << doc["hello"].GetString() << "]" << std::endl;
	std::cout << "Show pi value \t: [" << doc["pi"].GetDouble() << "]" << std::endl;
	std::cout << "Show boolean value \t: [" << doc["t"].GetBool() << "]" << std::endl;
	if (doc["t"].GetBool())
	{
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}

	std::cout << "Test if it's null" << std::endl;
	if (doc["n"].IsNull())
	{
		std::cout << "it contain  null value" << std::endl;
	}
	else {
		std::cout << "not null, other type" << std::endl;
	}

	//test assertion for type int 

	assert(doc["i"].IsNumber()); //raise an exception if not
	assert(doc["i"].IsInt());
	std::cout << "test suceess" << std::endl;

	std::cout << "Json array" << std::endl;
	const rapidjson::Value& val = doc["a"];
	//testing assertion 
	std::cout << "show array\t: [";
	for (auto i = 0; i != val.Size(); ++i) {
		std::cout << i << " -> " << val[i].GetInt() << "|";
	}
	std::cout << "]" << std::endl;
	
	std::cout << "query array " << std::endl;
	std::cout << "Traverse element using iterator \t\t: [";
	for (rapidjson::Value::ConstValueIterator itr = val.Begin(); itr != val.End(); ++itr) {
		std::cout << itr->GetInt() << "|";
	}
	std::cout << "]" << std::endl;

	std::cout << "Using modern c++ to traverse the element\t:[";
	for (auto& i : val.GetArray()) {
		std::cout << i.GetInt() << "|";
	}
	std::cout << "]" << std::endl;
	std::cout << "Traverse all array json range based for \t:[ ";
	for (auto& i : doc["a"].GetArray()) {
		std::cout << i.GetInt() << "|";
	}
	std::cout << "]" << std::endl;

	std::cout << "Query Object" << std::endl;
	static const char* kTypeNames[]={ "Null", "False", "True", "Object", "Array", "String", "Number" };
	for (rapidjson::Value::ConstMemberIterator i = doc.MemberBegin(); i != doc.MemberEnd(); ++i) {
		std::cout << i->name.GetString()<<" | "<< kTypeNames[i->value.GetType()] << std::endl;
	}
	std::cout << "Ensure whether a member exist\t:[";
	rapidjson::Value::MemberIterator itr1 = doc.FindMember("notExist");
	if (itr1!=doc.MemberEnd()) //traverse the element
	{
		std::cout << "exist \t: [ " << itr1->value.GetString() << "]" << std::endl;
	}
	else {
		std::cout << "member  not exist" << std::endl;
	}

	std::cout << "Range based for loop to traverse all object" << std::endl;
	for (auto& i : doc.GetObject()) {
		std::cout << "Object \t:[ " << i.name.GetString() << "|" << kTypeNames[i.value.GetType()] <<std::endl;
	}


	return 0;
}
