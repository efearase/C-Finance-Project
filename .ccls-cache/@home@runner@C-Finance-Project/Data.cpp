#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <vector>
#include <chrono>
#include <ctime>
#include <cmath>
#include <iterator>
#include <algorithm>
#include <limits>
#include <exception>
#include <stdexcept>

#include "Data.h"

Data::Data() {
	std::string champ;
  data.emplace(champ, Data::Serie{});
	}