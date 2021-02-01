#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <algorithm>
class Field
{
public:

	Field();
	~Field();

	void FieldGeneration();
	void IntFieldOutput();
	void ConvertationToChar();
	void FieldForPlayerGeneration();
	void CharFieldOutput();
	void ImportTaskToFile();
	void LoadDoneTask(const std::string Filename);
	bool Check();
	std::string Result();
	bool CheckAlgorithm();


private:
	int matrix_size;
	int** Int_Field;
	char** Char_Field;
	int** Done_Field;
};

