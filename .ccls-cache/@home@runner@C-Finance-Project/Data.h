#ifndef DATA_H
#define DATA_H

#include <map>
#include <vector>
#include <chrono>
#include <utility>
#include <string>


class Data
{
public:
	using Serie = std::vector<float>;

	explicit Data();

private:
	std::map<std::string, Serie> data;

};

#endif