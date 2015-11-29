#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iostream>
#include <strstream>

using namespace std;

template <typename T>
std::string convertToString(const T val) //function to change int to string 
{
	std::string s;
	strstream ss;
	ss << val;
	ss >> s;
	return s;
} //end function

void fillZero(std::string &val)
{
	val = "0" + val; 
}

int main(int argc, char const *argv[])
{
	std::string all_line;
	for (int i = 1; i <= 30; ++i)
	{
		for (int j = 01; j <= 20; ++j)
		{
			for (int k = 001; k <= 300; ++k)
			{
				std::string temp1 = convertToString(i);
				if (i < 10) fillZero(temp1);
				
				std::string temp2 = convertToString(j);
				if(j < 10) fillZero(temp2);	
				
				std::string temp3 = convertToString(k);
				if (k < 100)
				{
					if (k < 10)
					{
						fillZero(temp3);
						fillZero(temp3);
					}
					else
						fillZero(temp3);
				}

				all_line += "http://iplat.ujn.edu.cn/photo/2014/2014" + temp1 + temp2 + temp3 + ".jpg\n";
			}
		} //end for
	}
	
	std::ofstream ofs("dic.txt");
	ofs << all_line;
	return 0;
}