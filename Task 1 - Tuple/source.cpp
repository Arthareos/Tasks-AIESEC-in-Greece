/// 1. Write a function called stats(lst) to return a (min, max, average) tuple of a list without using
/// the builtin max, min or sum functions.
/// stats([47, 45, 8, 31, 78, 96, 11, 53, 32, 9, 38, 97, 93, 72, 7, 8, 23, 47, 66, 46])
///	(7, 97, 45.35)

#include <iostream>
#include <conio.h>
#include <fstream>
#include <tuple>
#include <vector>

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

/// <returns>Tuple of &lt;min, max, average&gt; form</returns> 
std::tuple<int, int, float> stats(std::vector<int> vector)
{
	std::tuple<int, int, float> tuple;
	std::get<0>(tuple) = INT_MAX;
	std::get<1>(tuple) = INT_MIN;
	std::get<2>(tuple) = 0;

	for (int index : vector)
	{
		std::get<2>(tuple) += index;

		if (index < std::get<0>(tuple))
		{
			std::get<0>(tuple) = index;
		}

		if (index > std::get<1>(tuple))
		{
			std::get<1>(tuple) = index;
		}
	}

	std::get<2>(tuple) /= vector.size();

	return tuple;
}

int main()
{
	std::vector<int> numbers = ReadFromFile("input.txt");
	std::tuple<int, int, float> tuple = stats(numbers);

	std::cout << " +> The tuple is <" << std::get<0>(tuple) << ", " << std::get<1>(tuple) << ", " << std::get<2>(tuple) << ">;" << std::endl;

	_getch();
	return 0;
}