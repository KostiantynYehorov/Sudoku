#include "Player.h"
#include "Field.h"

void Player::StartMenu()
{
	std::cout << "Downloading the game, please wait!\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "\nInstruction:\nYou have only one live.\nYou must run the program and download your task. After that, you must upload your answer.\n'Done.txt' - File for check results\n'Task.txt' - File with task\nGood Luck!\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "\nMenu:\n1)Generate your task\n2)Answer for your own Sudoku field\n3)Exit\nYour choice:\t";
	std::cin >> this->choise;

	switch (choise)
	{
	case 1:
		FieldGeneration();
		std::cout << "\n\nYour Task:\n";
		ConvertationToChar();
		FieldForPlayerGeneration();
		CharFieldOutput();
		ImportTaskToFile();
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		std::cout << "\n\nTask is already in your file!\n";

		TaskIsStarted();
		break;
	case 2:
		LoadDoneTask("Your.txt");
		std::cout << "\n\nLooking for you answer!\n";
		
		do
		{
			FieldGeneration();

		} while (CheckAlgorithm());
		
		std::cout << "\n\nYour Answer:\n";
		IntFieldOutput();
		break;
	case 3:
		std::cout << "\n\nBye!\n";
		exit(1);
	default:
		break;
	}

}

void Player::TaskIsStarted()
{
	clock.StartClock();

	while (true)
	{
		std::cout << "\n\nMenu:\n1)Upload from file\n2)See Answer\n3)Exit\nYour choice:\t";
		std::cin >> this->choise;

		switch (choise)
		{
		case 1:
			clock.EndClock();
			LoadDoneTask("Done.txt");
			std::cout << "\n\nLoading from file!\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			Check();
			std::cout << Result() << std::endl;
			clock.SeeTime();
			exit(1);
		case 2:
			std::cout << "\n\nYour Answer:\n";
			IntFieldOutput();
			break;
		case 3:
			std::cout << "\n\nBye!\n";
			exit(1);
			break;
		default:
			break;
		}
	}
}

void Player::Clock::StartClock()
{
	start = std::chrono::high_resolution_clock::now();
}

void Player::Clock::EndClock()
{
	end = std::chrono::high_resolution_clock::now();
	time = end - start;
}

void Player::Clock::SeeTime()
{
	std::cout << "Your time:\t" << time.count() << " seconds\n";
}
