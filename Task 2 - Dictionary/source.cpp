/// 2. Write a function called counter(lst) which returns a dict of values->counts
/// >>> counter([1, 2, 3, 5, 1, 2, 2, 4, 5, 1, 5, 2, 2, 3, 1, 2])
/// { 1 : 4, 2 : 6, 3 : 2, 4 : 1, 5 : 3}

#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>
#include <map>

/// <summary>Reads all integers from file</summary>
/// <param name="path">Path to file from which the method reads the values</param>  
/// <returns>Vector containing all integer values from file</returns> 
std::vector<int> ReadFromFile(std::string path)
{
	std::ifstream input(path);
	std::vector<int> nrFromFile;

	// we are going to read from the file until it's end (eof())
	uint16_t aux;
	while (!input.eof())
	{
		input >> aux;
		nrFromFile.push_back(aux);
	}

	input.close();
	return nrFromFile;
}

/// <summary>Creates a map based on a vector</summary>
/// <param name="path">Path to file from which the method reads the values</param>  
/// <returns>Map containing how many times every number appears in the vector</returns> 
std::map<int, int> counter(std::vector<int> vector)
{
	std::map<int, int> dict;
	std::map<int, int>::iterator it;

	for (int index : vector)
	{
		it = dict.find(index);

		if (it == dict.end())
		{
			dict.insert(std::pair<int, int>(index, 1));

			continue;
		}

		it->second += 1;
	}

	return dict;
}

int main()
{
	std::vector<int> numbers = ReadFromFile("input.txt");
	std::map<int, int> dict = counter(numbers);

	std::map<int, int>::iterator it;
	std::cout << " +> dict contains: {" << std::endl;
	for (it = dict.begin(); it != dict.end(); ++it)
	{
		std::cout << "   " << it->first << " : " << it->second << ", " << std::endl;
	}
	std::cout << " }" << std::endl;

	_getch();
	return 0;
}