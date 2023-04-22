#include "utility.hpp"
using namespace std;

void getDirectoryFromFile(string& filePath)
{
	const size_t last_slash_index = filePath.rfind('\\'); // in windows "\\" in linux "/"
	if (string::npos != last_slash_index)
	{
		filePath = filePath.substr(0, last_slash_index);
	}
}

std::string unix_time_to_date(const time_t& unix_time)
{
    struct tm timeinfo;
    char buffer[50];
    gmtime_s(&timeinfo, &unix_time);
    strftime(buffer, 50, "(%H:%M:%S , %d/%m/%Y)", &timeinfo);
    std::string string_time(buffer);
    return string_time; // world time
}
