// 3. Bonus points, decode this
// QlpoOTFBWSZTWQyQhfwAAAWVgEAEABAz93MwIABUUDTQyMmINU8Q1NGTyniNm7sdsz3jfp9FKs41\nfYwWkEIB9AhHU5MqqlamYbfxdyRThQkAyQhfwA==

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>

std::string ReadStringFromFile(std::string path)
{
	std::ifstream input(path);
	std::string text;

	std::getline(input, text);

	input.close();
	return text;
}

void BruteForceDecoder(std::string encodedText, int spread)
{
	for (int i = 0; i < encodedText.size(); i++)
	{
		encodedText[i] = encodedText[i] - 28;
	}

	std::cout << encodedText << std::endl;
	std::cout << std::endl;

	std::string decodedText;
	for (int index = 0; index < spread; index++)
	{
		decodedText = encodedText;

		for (int i = 0; i < decodedText.size(); i++)
		{
			decodedText[i] = decodedText[i] + index;
		}
		std::cout << " +> Difference: " << index << ", code: " << decodedText << "\n";

		std::string aux;
		for (int index = 0; index < 6; index++)
		{
			aux = decodedText;

			for (int i = 0; i < decodedText.size(); i++)
			{
				aux[i] = aux[i] << index;
			}

			std::cout << " +> Bit-shift: " << index << " positions, code: " << aux << "\n";
		}

		for (int index = 0; index < 6; index++)
		{
			aux = decodedText;

			for (int i = 0; i < decodedText.size(); i++)
			{
				aux[i] = aux[i] >> index;
			}

			std::cout << " +> Bit-shift: " << index << " positions, code: " << aux << "\n";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int index = 0; index < 6; index++)
	{
		decodedText = encodedText;

		for (int i = 0; i < decodedText.size(); i++)
		{
			decodedText[i] = decodedText[i] << index;
		}

		std::cout << " +> Bit-shift: " << index << " positions, code: " << decodedText << "\n";
	}
}

int main()
{
	std::string encodedText = ReadStringFromFile("input.txt");

	BruteForceDecoder(encodedText, 95);

	_getch();
	return 0;
}