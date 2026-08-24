#include <iostream>
#include<ctime>
#include <cstdlib>
using namespace std;

enum enQuestionLevel
{
	Easy = 1, Med = 2, Hard = 3, MixLevel = 4
};

enum enOperType
{
	Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5
};

struct stGameResults
{
	short QuestNumber = 0;
	enQuestionLevel QuestionLevel;
	enOperType OperType;
	short NumberRightAnswer = 0;
	short NumberWorngAnswer = 0;
};

int ReadHowManyQuestion()
{
	int NumberQuest = 0;

	do
	{
		cout << "How Many Questions do you want to answer ? ";
		cin >> NumberQuest;

	} while (NumberQuest < 1);

	return NumberQuest;
}

enQuestionLevel ReadQuestionsLevel()
{
	int Level = 0;

	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> Level;
	} while (Level < 1 || Level > 4);

	return (enQuestionLevel)Level;
}

enOperType ReadOperatioType()
{
	int OperType = 0;

	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] MixOp ? ";
		cin >> OperType;
	} while (OperType < 1 || OperType > 5);

	return (enOperType)OperType;

}


int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

int SumNumber(int Num1, int Num2)
{
	return Num1 + Num2;
}

int SubtractNumber(int Num1, int Num2)
{
	return Num1 - Num2;
}

int MultiplNumber(int Num1, int Num2)
{
	return Num1 * Num2;
}

int DividNumber(int Num1, int Num2)
{
	return Num1 / Num2;
}

string SetOperTypeName(enOperType OperType)
{
	string arrOperType[5] = { "+","-","*","/","Mix" };

	return arrOperType[OperType - 1];
}

void PrintCalculation(int Num1, int Num2, string OperType)
{
	cout << endl << Num1 << endl << Num2 << "  " << OperType << "\n";
	cout << "_________________\n";
}

int MixNumber(enOperType OperType,int Num1, int Num2)
{
	string OperType1;

	int Random = RandomNumber(1, 4);

	switch (Random)
	{
	case 1:
		OperType1 = "+";
		PrintCalculation(Num1, Num2, OperType1);
		return SumNumber(Num1, Num2);
		break;
	case 2:
		OperType1 = "-";
		PrintCalculation(Num1, Num2, OperType1);
		return SubtractNumber(Num1, Num2);
		break;
	case 3:
		OperType1 = "*";
		PrintCalculation(Num1, Num2, OperType1);
		return MultiplNumber(Num1, Num2);
		break;
	case 4:
		OperType1 = "/";
		PrintCalculation(Num1, Num2, OperType1);
		return DividNumber(Num1, Num2);
		break;
	}
}

void LevelEasy(int &Num1,int &Num2)
{
	Num1 = RandomNumber(1, 10);
	Num2 = RandomNumber(1, 10);
}

void LevelMed(int& Num1, int& Num2)
{
	Num1 = RandomNumber(10, 50);
	Num2 = RandomNumber(10, 50);
}

void LevelHard(int& Num1, int& Num2)
{
	Num1 = RandomNumber(50, 100);
    Num2 = RandomNumber(50, 100);
}

void LevelMix(int& Num1, int& Num2)
{
	int Random = RandomNumber(1, 3);

	switch (Random)
	{
	case 1:
		LevelEasy(Num1, Num2);
		break;
	case 2:
		LevelMed(Num1, Num2);
		break;
	case 3:
		LevelHard(Num1, Num2);
		break;
	}
}

void ChoiceLevel(enQuestionLevel QuestionLevel, int& Num1, int& Num2)
{
	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		LevelEasy(Num1, Num2);
		break;
	case enQuestionLevel::Med:
		LevelMed(Num1, Num2);
		break;
	case enQuestionLevel::Hard:
		LevelHard(Num1, Num2);
		break;
	case enQuestionLevel::MixLevel:
		LevelMix(Num1, Num2);
		break;
	}
}




string SetQuestionLevelName(enQuestionLevel QuestionLevel)
{
	string arrQuestionLevelName[4] = { "Easy","Med","Hard","Mix" };
	return arrQuestionLevelName[QuestionLevel - 1];
}

int ChoiceCalculation(enOperType OperType, int Num1, int Num2)
{
	string OperType1 = SetOperTypeName(OperType);

	switch (OperType)
	{
	case enOperType::Add:
		
		PrintCalculation(Num1, Num2, OperType1);
		return SumNumber(Num1, Num2);
	case enOperType::Sub:
		PrintCalculation(Num1, Num2, OperType1);
		return SubtractNumber(Num1, Num2);
	case enOperType::Mul:
		PrintCalculation(Num1, Num2, OperType1);
		return MultiplNumber(Num1, Num2);
	case enOperType::Div:
		PrintCalculation(Num1, Num2, OperType1);
		return DividNumber(Num1, Num2);
	case enOperType::MixOp:
		OperType = (enOperType)RandomNumber(1, 4);
		return ChoiceCalculation(OperType, Num1, Num2);
		//return MixNumber(OperType,Num1, Num2);
	}
}

int ReadUserAnswer()
{
	int UserAnswer;
	cin >> UserAnswer;
	return UserAnswer;
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void SetScreenColor(bool IsRigth)
{
	if (IsRigth)
	{
		system("color 2F");
	}
	else
	{
		system("color 4F");
		cout << "\a";
	}
}

bool CheckUserAnswer(int Result, int UserAnswer)
{
	if (Result == UserAnswer)
	{
		
		return true;
	}
	else
	{
		
		return false;
	}
}

void Counter(int Result, int UserAnswer, stGameResults& GameResults)
{
	bool IsRight = CheckUserAnswer(Result, UserAnswer);
	if (IsRight)
	{
		cout << "\nRight Answer  :-)\n";
		GameResults.NumberRightAnswer++;
	}
	else
	{
		cout << "\nWorng Answer  :-(\n";
		cout << "The right answer is : " << Result << endl;
		GameResults.NumberWorngAnswer++;
	}

	SetScreenColor(IsRight);
}

stGameResults PlayGame(short HowManyQuestions)
{
	stGameResults GameResults;
	int Num1 = 0, Num2 = 0;
	int Result = 0;
	int UserAnswer;

	GameResults.QuestionLevel = ReadQuestionsLevel();
	GameResults.OperType = ReadOperatioType();

	for (short Question = 1; Question <= HowManyQuestions; Question++)
	{
		cout << "\nQuestion  [" << Question << "/" << HowManyQuestions << "]\n\n";
		GameResults.QuestNumber = Question;
		ChoiceLevel(GameResults.QuestionLevel, Num1, Num2);
		
		Result = ChoiceCalculation(GameResults.OperType, Num1, Num2);
		UserAnswer = ReadUserAnswer();
		Counter(Result, UserAnswer, GameResults);

	}

	return GameResults;
}

string PassFail(stGameResults GameResults)
{
	if (GameResults.NumberRightAnswer >= GameResults.NumberWorngAnswer)
	{
		return "Pass";
	}
	else
	{
		return "Fail";
	}
}

void ShowFinalGameResults(stGameResults GameResults)
{
	cout << "\n\n------------------------------------------------\n\n";
	cout << "             Final Results is " << PassFail(GameResults) << endl;
	cout << "\n------------------------------------------------\n\n";
	cout << "Number of Questions : " << GameResults.QuestNumber << endl;
	cout << "Questions Level     : " << SetQuestionLevelName(GameResults.QuestionLevel) << endl;
	cout << "OpType              :" << SetOperTypeName(GameResults.OperType) << endl;
	cout << "Number of Right Answers: " << GameResults.NumberRightAnswer << endl;
	cout << "Number of worng Answers: " << GameResults.NumberWorngAnswer << endl;
	cout << "\n------------------------------------------------\n\n";


}


void StartGame()
{
    char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyQuestion());
		ShowFinalGameResults(GameResults);

		cout << endl << "Do you want to play again? Y/N ? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();
    return 0;
}
