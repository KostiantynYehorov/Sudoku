#include "Field.h"

Field::Field()
{
	this->matrix_size = 9;
	this->Int_Field = new int* [matrix_size];
	this->Char_Field = new char* [matrix_size];
	this->Done_Field = new int* [matrix_size];

	for (int i = 0; i < matrix_size; i++)
	{
		this->Int_Field[i] = new int[matrix_size];
		this->Char_Field[i] = new char[matrix_size];
		this->Done_Field[i] = new int[matrix_size];
	}
}

Field::~Field()
{
	for (int i = 0; i < matrix_size; i++)
	{
		delete[] Int_Field[i], Char_Field[i], Done_Field[i];
	}

	delete[] Int_Field;
	delete[] Char_Field;
	delete[] Done_Field;
}

void Field::FieldGeneration()
{
	int key = 6;
	std::vector<int> vc;

	for (int i = 1; i < matrix_size + 1; i++) { vc.push_back(i); }
	random_shuffle(vc.begin(), vc.end());

	for (int i = 0; i < matrix_size; i++) { Int_Field[0][i] = vc.at(i); }

	for (int i = 1; i < matrix_size; i++)
	{
		if (i == 1) { key = 6; }
		else if (i == 2) { key = 3; }
		else if (i == 3) { key = 1; }
		else if (i == 4) { key = 7; }
		else if (i == 5) { key = 4; }
		else if (i == 6) { key = 2; }
		else if (i == 7) { key = 8; }
		else if (i == 8) { key = 5; }

		for (int j = 0; j < matrix_size; j++)
		{
			if (j + key > 8) {
				Int_Field[i][j + key - 9] = vc.at(j);
			}

			else {
				Int_Field[i][j + key] = vc.at(j);
			}
		}
	}
}

void Field::IntFieldOutput()
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			std::cout << Int_Field[i][j] << "\t";
		}

		std::cout << std::endl << std::endl;
	}
}

void Field::ConvertationToChar()
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			Char_Field[i][j] = Int_Field[i][j] + '0';
		}
	}
}

void Field::FieldForPlayerGeneration()
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Char_Field[i][(rand() % 11) - 1] = '*';
		}
	}
}

void Field::CharFieldOutput()
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			std::cout << Char_Field[i][j] << "\t";
		}

		std::cout << std::endl << std::endl;
	}
}

void Field::ImportTaskToFile()
{
	std::ofstream file("Task.txt");

	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			file << Char_Field[i][j] << "\t";
		}

		file << std::endl << std::endl;
	}

	file.close();
}

void Field::LoadDoneTask(const std::string Filename)
{
	std::ifstream file(Filename);

	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			file >> Done_Field[i][j];
		}
	}

	file.close();
}

bool Field::Check()
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			if (Done_Field[i][j] != Int_Field[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

std::string Field::Result()
{
	if (Check())
	{
		return "You're right! Congratulations)\n";
	}

	return "You're wrong! Good Bye(\n";
}

bool Field::CheckAlgorithm()
{
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			if (Done_Field[i][j] == 0) { continue; }

			else { if (Done_Field[i][j] != Int_Field[i][j]) { return true; } }
		}
	}

	return false;
}