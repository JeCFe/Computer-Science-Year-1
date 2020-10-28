
//Jessica Clara Fealy


#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
template <class T>
class rotateVector
{
public:
	//Sets the vector
	void setVector()
	{
		T temp;
		int size;
		int i = 0;
		cout << "How many values being entererd? ";
		cin >> size;

		cout << "Fill vector: ";
		while (i++ != size)
		{
			cin >> temp;
			taskTenVector.push_back(temp);
		}
	}

	
	void rotateRight()
	{
		T temp;
		temp = taskTenVector.back();
		taskTenVector.pop_back();
		taskTenVector.insert(taskTenVector.begin(), temp);
	}

	void rotateLeft()
	{
		T temp;
		temp = taskTenVector[0];
		taskTenVector.push_back(temp);
		taskTenVector.erase(taskTenVector.begin());
	}

	void output()
	{
		for (size_t i = 0; i < taskTenVector.size(); i++)
		{
			cout << taskTenVector[i] << " ";
		}
	}
private:
	vector<T> taskTenVector;
};

template<class T>
T biggestValue(T valueA, T valueB)
{
	if (valueA>valueB)
	{
		return valueA;
	}
	else
	{
		return valueB;
	}
}

//Adds all numbers before the input
void taskOne()
{
	//Uses a for loop to go though all number before the input and adds them together
	int input;
	bool boolInput = false;
	int finalNum = 0;
	cout << "Task 1: " << endl;
	do
	{
		cout << "Enter number n: ";
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			boolInput = true;
		}
	} while (!boolInput);
	
	for (size_t i = 0; i <= input; i++)
	{
		finalNum = finalNum + i;
	}
	cout << "Final Number: " << finalNum << endl;
	cout << "--------------" << endl;

}

//Add if number is a multiple of 3 or 5
void taskTwo()
{
	//THis function takes an input
	//Does an or statment on the mod of 3 and 5 to the poisiting of i
	//If i is a mod of 3 and 5 then add that number
	int input;
	bool boolInput = false;
	int finalNum = 0;
	cout << "Task Two: " << endl;
	do
	{
		cout << "Enter number n: ";
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			boolInput = true;
		}
	} while (!boolInput);
	for (size_t i = 0; i < input; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			finalNum = finalNum + i;
		}
	}
	cout << "Final Number: " << finalNum << endl;
	cout << "--------------" << endl;
}

//Latin 
void taskThree()
{
	//This function operates by taking a sentence into a char vector
	//Determing when a new word is reached by looking for spaces, taking the first letter and saving in a temp cahr 
	//When reached end of word push the first letter to the back and then add ay to the end
	//Then add word to a string
	//Repeat until all words have been sorted
	string fullSentence;
	vector<char> fullSentenceArray;
	vector<char> word;
	string modifiedSentence;
	char firstLetter;
	bool newWordFlag = true;
	cout << "Enter sentence: ";
	cin.ignore();
	getline(cin, fullSentence);
	//Saving sentence to char vector
	for (size_t i = 0; i < fullSentence.length(); i++)
	{
		fullSentenceArray.push_back(fullSentence[i]);
	}
	fullSentenceArray.push_back(' ');	//A space is added to the end so the final word can be detected

	for (size_t i = 0; i < fullSentenceArray.size(); i++)
	{

		if (!newWordFlag && fullSentenceArray[i] != ' ')
		{
			word.push_back(fullSentenceArray[i]);
		}
		if (newWordFlag == true)
		{
			firstLetter = fullSentenceArray[i];
			firstLetter = tolower(firstLetter);
			newWordFlag = false;
		}
		if (fullSentenceArray[i] == ' ')
		{
			word.push_back(firstLetter);
			word.push_back('a');
			word.push_back('y');
			for (size_t i = 0; i < word.size(); i++)
			{
				modifiedSentence = modifiedSentence + word[i];
			}
			modifiedSentence = modifiedSentence + " ";
			newWordFlag = true;
			word.clear();
			
		}

	}
	cout << "Modified sentence: " << modifiedSentence << endl;
	cout << "--------------" << endl;
}

//concentrates 2 lists
void taskFour()
{
	//This functions operates by moving all of list 1 into combList 
	//Then moving all of list 2 into comb list
	string tempString;
	vector<char> listOne;
	vector<char> listTwo;
	vector<char> combList;

	cout << "Task 4: " << endl;
	cout << "Enter list one: ";
	cin >> tempString;
	
	for (size_t i = 0; i < tempString.length(); i++)
	{
		listOne.push_back(tempString[i]);
	}
	cout << "Enter list two: ";
	cin >> tempString;
	for (size_t i = 0; i < tempString.length(); i++)
	{
		listTwo.push_back(tempString[i]);
	}

	for (size_t i = 0; i < listOne.size(); i++)
	{
		combList.push_back(listOne[i]);
	}
	for (size_t i = 0; i < listTwo.size(); i++)
	{
		combList.push_back(listTwo[i]);
	}
	cout << "Combo List: ";
	for (size_t i = 0; i < combList.size(); i++)
	{
		cout << combList[i] << " ";
	}
	cout << endl;
	cout << "--------------" << endl;

}

//Biggest value using a template
void taskFive()
{
	//This function uses a T template defined at the begining of the program to detemine the largest value
	cout << "Task 5: " << endl;
	cout << "Ints only" << endl;
	int a; //To change the data type the template uses change a and b data type modifer
	int b;
	cout << "Enter value A: ";
	cin >> a;
	cout << "Enter value B: ";
	cin >> b;
	cout << "Biggest: " << biggestValue(a, b) << endl;	//Returns ands displays the biggest
	cout << "--------------" << endl;
}

//Returns a list of digits 
vector<char> taskSix()
{
	//This function by taking an input as a char vector
	//Adding each char to a new string with a comma between
	//Then displaying the string
	int input;
	bool boolInput = false;
	string output;
	vector<char> charInput;
	cout << "Task 6: " << endl;
	do
	{
		cout << "Enter number n: ";
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			boolInput = true;
		}
	} while (!boolInput);
	output = to_string(input);
	for (size_t i = 0; i < output.length(); i++)
	{
		charInput.push_back(output[i]);
	}

	cout << "Inital input: " << input << endl;
	cout << "Char input: ";
	for (size_t i = 0; i < charInput.size(); i++)
	{
		if (i == charInput.size() -1)
		{
			cout << charInput[i];
		}
		else
		{
			cout << charInput[i] << ", ";
		}

	}
	cout << endl;
	cout << "--------------" << endl;
	return charInput;
}

//Framing a sentence
void taskSeven()
{
	//Takes a sentence into a stirng vector
	//Determine the largest word
	//Add * to the beginning and end of the word 
	//Adding spaces to the words which are shorter than the longest word
	//Adding * to the string which is the length of the longest word
	//Adding all components to a string vector
	//Displaying new string vector
	string initalSentence;
	vector<string> sentenceToFrame;
	vector<string>FinishedFrame;
	string tempWord;
	cout << "Task 7:" << endl;
	cout << "Please enter sentence: ";
	cin.ignore();
	getline(cin, initalSentence);
	initalSentence = initalSentence + " ";
	for (size_t i = 0; i < initalSentence.length(); i++)
	{
		if (initalSentence[i] == ' ')
		{
			sentenceToFrame.push_back(tempWord);
			tempWord.clear();
		}
		else
		{
			tempWord = tempWord + initalSentence[i];
		}
	}
	string largest = sentenceToFrame[0];
	for (size_t i = 0; i < sentenceToFrame.size(); i++)
	{
		if (sentenceToFrame[i].length() > largest.length())
		{
			largest = sentenceToFrame[i];
		}
	}
	
	string starBar;
	for (size_t i = 0; i <= largest.length(); i++)
	{
		starBar = starBar + "*";
	}
	starBar = starBar + "*";

	for (size_t i = 0; i < sentenceToFrame.size(); i++)
	{
		string wordToEdit = sentenceToFrame[i];
		string newWord = wordToEdit;

			newWord.insert(newWord.begin(), '*');
			while (newWord.length() <= largest.length())
			{
				newWord = newWord + " ";
			}
			newWord = newWord + "*";
		
		FinishedFrame.push_back(newWord);
	}
	cout << starBar << endl;
	for (size_t i = 0; i < FinishedFrame.size(); i++)
	{
		cout << FinishedFrame[i] << endl;
	}
	cout << starBar << endl;
	cout << "--------------" << endl;

}

//Highest common factor
int taskEight(int numA, int numB)
{
	
	if (numB == 0)
	{
		//numA is the HCF
		return numA;
	}
	else
	{
		//Keep finding the mod until there is no remainder
		//This means the value being passed to numA is the HCF
		return taskEight(numB, (numA % numB)); 
	}
}

//odd even prime perfect square
void taskNine()
{
	cout << "Task 9: " << endl;
	vector<vector<int>> TwoDVector;
	vector<int> even;
	vector<int> odd;
	vector<int> prime;
	vector<int> square;
	int lowerBound;
	int upperBound;
	cout << "Lower Bound: ";
	cin >> lowerBound;
	cout << "Upper Bound: ";
	cin >> upperBound;
	for (size_t i = lowerBound; i < upperBound; i++)
	{
		if (i % 2 != 0 ) //odd number
		{
			even.push_back(i);
		}
		if (i % 2 == 0) //Even numbers
		{
			odd.push_back(i);
		}

		float sqr = sqrt(i);
		//If sqr round down is still the same number then this must be a whole number
		if (floor(sqr) == sqr)
		{
			//i is a perf square
			square.push_back(i);
		}
	}
	for (size_t i = lowerBound; i < upperBound; i++) //Prime number
	{
		//1 can not be a prime number
		if (i != 1)
		{
			bool Prime = true;
			for (size_t j = 2; j <= i; ++j)
			{
				//A prime is divisable by itself
				if (i != j)
				{

					//If theres no remainder this number cant be prime
					if (i % j == 0)
					{
						Prime = false;
					}
				}
			}
			if (Prime)
			{
				prime.push_back(i);
			}
		}
	} 

	TwoDVector.push_back(even);
	TwoDVector.push_back(odd);
	TwoDVector.push_back(prime);
	TwoDVector.push_back(square);

	for (size_t i = 0; i < TwoDVector.size(); i++)
	{
		for (size_t j = 0; j < TwoDVector[i].size(); j++)
		{
			cout << TwoDVector[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;

}

//rotate vecotor
void taskTen()
{
	//Uses a T templated to initalise, rotate and display vector
	cout << "Task Ten: " << endl;
	rotateVector<char> rotatevector;
	rotatevector.setVector();
	rotatevector.rotateRight();
	cout << "Vector rotated right: ";
	rotatevector.output();
	cout << endl;
	rotatevector.rotateLeft();
	cout << "Vector rotated left: ";
	rotatevector.output();
	cout << endl;
	cout << "--------------" << endl;
}

int main()
{
	vector<char> taskSixAnswer;

	taskOne();
	taskTwo();
	taskThree();
	taskFour();
	taskFive();
	taskSixAnswer = taskSix();
	taskSeven();
	int numA;
	int numB;
	int HCF;
	cout << "Task 8: " << endl;
	cout << "Enter Num A: ";
	cin >> numA;
	cout << "Enter Num B: ";
	cin >> numB;
	HCF = taskEight(numA, numB);
	cout << "Highest Common Facotor: " << HCF << endl;
	cout << "--------------" << endl;

	taskNine();
	taskTen();

}