#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <Windows.h>
#include <string>
#include <stdlib.h>
using namespace std;
//Flags to indeicate if the program has ran before 
bool isFirstRun = true;
bool isFirstRunPartTwo = true;
//This class handles all user objects
//Stores their names, height, and weights
class user
{
public:
	string name;
	float height;
	float weightArray[5];

	/*Positions of weight array
	0. Current weight
	1. Historic One
	2. Historic Two
	3. Historic Three
	4. Historic Four*/
};

//This validates a string input
bool stringValidator(string testSubject)
{
	bool isString = false;
	for (size_t i = 0; i < testSubject.length(); i++)
	{
		if (testSubject[i] >= 'a' && testSubject[i] <= 'z' || testSubject[i] >= 'A' && testSubject[i] <= 'Z')
		{
			isString = true;
		}
		else
		{
			return 1;
		}
	}
	if (isString)
	{
		return 0;
	}
}

//This validates a number input 
bool numberValidator(string testSubject)
{
	bool isValid = false;
	for (size_t i = 0; i < testSubject.length(); i++)
	{
		if (testSubject[i] >= '0' && testSubject[i] <= '9' || testSubject[i] == '.')
		{
			isValid = true;
		}
		else
		{
			return 1;
		}
	}
	if (isValid)
	{
		return 0;
	}

}


//This class handles what user item is to be selected for a menu query 
int userSelect(user* userList)
{

	bool validInput = false;
	//loop to ensure no choice larger than users available 
	while (!validInput)
	{
		int choice = 0;
		string strChoice;
		while (numberValidator(strChoice))
		{
			cout << "Please select a user: " << endl;

			//Prints out all names held in user with a corresponding number
			//Number is not indexed
			for (size_t i = 0; i < 5; i++)
			{
				cout << i + 1 << ". " << userList[i].name << endl;
			}
			cin >> strChoice;
		}
		choice = stof(strChoice);

		if (choice <= 5 && choice > 0)
		{
			validInput = true;

			//Indexs number to match the user position in the userList
			choice = choice - 1;
			return choice;
		}
	}
}

//This class handle calculating bmi and mean bmi
float bmiCalc(user* userList, int userIndex, int choice)
{
	//Choice is whats being calculated
	switch (choice)
	{
	case 0:
	{
		//This takes the height and weight for the corresponding user
		//Calculates bmi and then returns that value as a float
		float bmi = userList[userIndex].weightArray[0] / pow(userList[userIndex].height, 2);
		return bmi;
		break;
	}
	case 1:
	{
		//This takes the weight and height from a user, calculates bmi and then adds this value to meanBmi
		float meanBmi = 0;
		int count = 0;
		for (size_t i = 0; i < 5; i++)
		{
			if (userList[userIndex].weightArray[i]!=0)
			{
				meanBmi = meanBmi + (userList[userIndex].weightArray[i] / pow(userList[userIndex].height, 2));
				count += 1;
			}
			
		}

		//Dividing meanBmi by 5 gives the actual mean
		//Then returns this value as a float
		meanBmi = meanBmi / count;
		return meanBmi;
		break;
	}
	default:
		break;
	}

}

//This takes the known bmi as an argument
//Using if statements decides what cat of bmi it falls under
//Then returns as a sting
string bmiClassification(float bmi)
{
	string classification;
	if (bmi <= 18.5)
	{
		classification = "Underweight";
	}
	if (bmi > 18.5 && bmi <= 24.9)

	{
		classification = "Healthy weight";
	}
	if (bmi >= 25 && bmi <= 29.9)
	{
		classification = "Overweight";
	}
	if (bmi >= 30)
	{
		classification = "Obese";
	}
	return classification;
}

//This reads everything from the file and adds everything to an item in userList
void addUserList(user* userList)
{
	ifstream file("bmiuserdata.txt");	//Opens bmiuserfile.txt
	string str = "";
	string name;
	if (file.is_open())	//Checks that the file is open
	{
		while (file >> str)
		{
			for (int i = 0; i < 5; i++)	//Looping 5 times for 5 users
			{
				if (str == "user")	//If the current word being analysed in the file is word this happens
				{
					string name = "";
					file >> str;	//Due to the layout of bmiuserdata such operations are repeated to be on the correct line
					file >> str;
					if (str == "name")	//If the current word being looked at is name
					{

						bool finishedName = false;
						bool firstWord = true;

						//This while loops add a space between the first and last name 
						while (!finishedName)
						{
							file >> str;
							if (!firstWord)
							{
								name += " ";
							}
							firstWord = false;
							if (str.substr(str.length() - 1) == ";")	//Substr looks at the chars in a string, this is looking for the stopping char ; 
							{
								str = str.substr(0, str.length() - 1);	//Removes the stopping char from the string 
								finishedName = true;
							}
							name += str;
							userList[i].name = name;	//Adds the name to the current user
						}
						name = "";
					}
					file >> str;
					if (str == "height")	//Looks to see if the current word is height
					{
						file >> str;
						if (str.substr(str.length() - 1) == ";")
						{
							str = str.substr(0, str.length() - 1);
						}
						string strheight = str;
						float height = stof(strheight);	//Converts the string of height to a float value 
						userList[i].height = height;	//Adds the height to the current user
					}
					file >> str;
					if (str == "weight")
					{
						file >> str;
						if (str.substr(str.length() - 1) == ";")
						{
							str = str.substr(0, str.length() - 1);
						}
						string strweight = str;
						float weight = stof(strweight);	//Converts string weight to a float
						userList[i].weightArray[0] = weight;	//Adds current weight to the first position of weight array
					}
					file >> str;
					if (str == "historicone")
					{
						file >> str;
						if (str.substr(str.length() - 1) == ";")
						{
							str = str.substr(0, str.length() - 1);
						}
						string strhistoricone = str;
						float historicone = stof(strhistoricone);
						userList[i].weightArray[1] = historicone;
					}
					file >> str;
					if (str == "historictwo")
					{
						file >> str;
						if (str.substr(str.length() - 1) == ";")
						{
							str = str.substr(0, str.length() - 1);
						}
						string strhistorictwo = str;
						float historictwo = stof(strhistorictwo);
						userList[i].weightArray[2] = historictwo;
					}
					file >> str;
					if (str == "historicthree")
					{
						file >> str;
						if (str.substr(str.length() - 1) == ";")
						{
							str = str.substr(0, str.length() - 1);
						}
						string strhistoricthree = str;
						float historicthree = stof(strhistoricthree);
						userList[i].weightArray[3] = historicthree;
					}
					file >> str;
					if (str == "historicfour")
					{
						file >> str;
						if (str.substr(str.length() - 1) == ";")
						{
							str = str.substr(0, str.length() - 1);
						}
						string strhistoricfour = str;
						float historicfour = stof(strhistoricfour);
						userList[i].weightArray[4] = historicfour;
					}
					file >> str;
					file >> str;

					if (str == "}") //} is the end of each user
					{
						file >> str; //This is always done to ensure that when the last user has been read there will be null data in str
					}
				}
			}
			if (file.eof())	//Closes the file when there is no more data to be read
			{
				file.close();
			}
		}
	}

	else	//If the bmiuserdata file didn't open correctly this happens
	{
		cout << "Error opening file - addUserList" << endl;
	}

}

//This loops from userList displaying all names with an index
void listUserNames(user* userList)
{
	cout << "User Names:" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		cout << "[" << i + 1 << "] " << userList[i].name << endl;
	}
}

//Displays user details to screen
void showUserDetails(user* userList)
{
	int userIndex;
	userIndex = userSelect(userList);

	cout << "User details: " << endl;
	cout << userList[userIndex].name << endl;	//Pulls name from userList
	cout << "Height: " << userList[userIndex].height << "m" << endl;	//Pulls height from userList
	cout << "Weight: " << userList[userIndex].weightArray[0] << "Kg" << endl;	//Pulls weight from the first position in weightArray
	cout << "BMI: " << bmiCalc(userList, userIndex, 0) << endl;	//Calls bmiCalc then displays bmi
	cout << "BMI Classificaiton: " + bmiClassification(bmiCalc(userList, userIndex, 0)) << endl;	//Calls bmiClassification then displays 

}

//Reads everything stored in userList and then prints it
//All info in userList is copied from bmiuserdata.txt
void readFromFile(user* userList)
{
	int userIndex;
	userIndex = userSelect(userList);
	cout << "Details of user in file: " << endl;
	cout << userList[userIndex].name << endl;
	cout << "Height: " << userList[userIndex].height << "m" << endl;
	cout << "Weight: " << userList[userIndex].weightArray[0] << "Kg" << endl;
	cout << "Historic Weights: " << endl;
	cout << "Historic one: " << userList[userIndex].weightArray[1] << "Kg" << endl;
	cout << "Historic two: " << userList[userIndex].weightArray[2] << "Kg" << endl;
	cout << "Historic three: " << userList[userIndex].weightArray[3] << "Kg" << endl;
	cout << "Historic four: " << userList[userIndex].weightArray[4] << "Kg" << endl;

}

//Shows all historic data + bmi + bmi classification
void showUserHistoricDetails(user* userList)
{
	float totalWeight = 0;
	float meanWeight = 0;
	float percentageChange = 0;
	int count = 0;

	int userIndex = userSelect(userList);

	//mean of all weights
	for (size_t i = 0; i < 5; i++)
	{
		if (userList[userIndex].weightArray[i] != 0)
		{
			totalWeight = totalWeight + userList[userIndex].weightArray[i];
			count += 1;
		}
		
	}
	meanWeight = totalWeight / count;



	if (userList[userIndex].weightArray[1] != 0)
	{

		//if the persons left weight 
		if (userList[userIndex].weightArray[0] < userList[userIndex].weightArray[1])
		{
			percentageChange = ((userList[userIndex].weightArray[1] - userList[userIndex].weightArray[0]) / userList[userIndex].weightArray[1]) * 100;
		}

		//if the person has got heavier
		if (userList[userIndex].weightArray[0] >= userList[userIndex].weightArray[1])
		{
			percentageChange = ((userList[userIndex].weightArray[0] - userList[userIndex].weightArray[1]) / userList[userIndex].weightArray[1]) * 100;
		}
	}
	else
	{
		percentageChange = 0;
	}


	//Gets all information from userList to print onto screen
	cout << "Historic Information: " << endl;
	cout << userList[userIndex].name << endl;
	cout << "Current weight: " << userList[userIndex].weightArray[0] << "Kg" << endl;
	cout << "% Change: " << percentageChange << "%" << endl;
	cout << "Mean: " << meanWeight << "Kg" << endl;
	cout << "BMI: " << bmiCalc(userList, userIndex, 0) << endl;	//This bmiCalc prints the current bmi
	cout << "Mean BMI: " << bmiCalc(userList, userIndex, 1) << endl;	//This bmiCalc prints the mean bmi
	cout << "BMI classification: " << bmiClassification(bmiCalc(userList, userIndex, 0)) << endl;


}

//Writes everything from file to an item in userList
void saveToFile(int count)
{

	fstream file("bmiuserdata.txt", std::fstream::in | std::fstream::out);	//This opens a file and allows for appending of the file
	for (size_t i = 0; i < 5; i++)
	{
		string firstName;
		string secondName;
		string fullName;
		string height;
		string currentWeight;
		string historicOne;
		string historicTwo;
		string historicThree;
		string historicFour;

		cout << "User: " << i+1 << endl;	//Adds an index

		//All this allow stores details for the user in veriables
		while (stringValidator(firstName))
		{
			cout << "Please enter first name: " << endl;
			cin >> firstName;
		}

		while (stringValidator(secondName))
		{
			cout << "Please enter second name: " << endl;
			cin >> secondName;
		}

		while (numberValidator(height))
		{
			cout << "Please enter height: " << endl;
			cin >> height;
		}

		while (numberValidator(currentWeight))
		{
			cout << "Please enter current weight: " << endl;
			cin >> currentWeight;
		}

		

		fullName = firstName + " " + secondName;

		//Writes all details to the file
		file << "user" << endl;
		file << "{" << endl;
		file << "name " << fullName << ";" << endl;
		file << "height " << height << ";" << endl;
		file << "weight " << currentWeight << ";" << endl;
		file << "historicone " << 0 << ";" << endl;
		file << "historictwo " << 0 << ";" << endl;
		file << "historicthree " << 0 << ";" << endl;
		file << "historicfour " << 0 << ";" << endl;
		file << "}" << endl;
	}
	//Closes file to make changes saved
	file.close();
}

//Used to call classes to display user bmi and then display with classification 
void bmiUserCalc(user* userList)
{
	int userIndex;
	userIndex = userSelect(userList);
	cout << userList[userIndex].name << endl;
	cout << "BMI: " << bmiCalc(userList, userIndex, 0) << endl;
	cout << "BMI Classificaiton: " + bmiClassification(bmiCalc(userList, userIndex, 0)) << endl;
}

//This update the corresponding user weight
void updateUserWeight(user* userList)
{
	int userIndex = userSelect(userList);
	string strNewWeight;
	float newWeight;
	float tempWeightArray[5];

	while (numberValidator(strNewWeight))
	{
		cout << "Please enter new weight: " << endl;
		cin >> strNewWeight;
	}

	newWeight = stof(strNewWeight);


	//Writes the new weight into the first position of the temp array
	tempWeightArray[0] = newWeight;

	//Save all but last entry of weightArray into a temp array
	for (size_t i = 0; i < 4; i++)
	{
		tempWeightArray[i + 1] = userList[userIndex].weightArray[i];
	}

	//Now that the temp array has the complete new weight list
	//The entire temp array is written into the weightArray
	for (size_t i = 0; i < 5; i++)
	{
		userList[userIndex].weightArray[i] = tempWeightArray[i];
	}

	//To ensure all information in file is accurate 
	//The file is overwritten
	//All Users in userList is writtien to the file.
	fstream file("bmiuserdata.txt");
	for (size_t i = 0; i < 5; i++)
	{
		file << "user" << endl;
		file << "{" << endl;
		file << "name " << userList[i].name << ";" << endl;
		file << "height " << userList[i].height << ";" << endl;
		file << "weight " << userList[i].weightArray[0] << ";" << endl;
		file << "historicone " << userList[i].weightArray[1] << ";" << endl;
		file << "historictwo " << userList[i].weightArray[2] << ";" << endl;
		file << "historicthree " << userList[i].weightArray[3] << ";" << endl;
		file << "historicfour " << userList[i].weightArray[4] << ";" << endl;
		file << "}" << endl;
	}
	//File is closed to ensure the changes are saved
	file.close();
}

int main()
{
	int userCount;
	userCount = 4;
	//Used to determine if this is the first run though
	//If so then add 5 users to the bmi file
	if (isFirstRun)
	{
		isFirstRun = false;

		saveToFile(userCount);

		cout << "Please press enter to continue." << endl;
		if (GetKeyState(VK_RETURN))
		{
			main();
		}//continue on this
	}
	int count = 0;
	user userList[5];	//Creates new user array
	addUserList(userList);
	if (isFirstRunPartTwo)
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 1; j <= 4; j++)
			{
				userList[i].weightArray[j] = 0;
			}
		}
		isFirstRunPartTwo = false;
	}
	int choice;

	cout << endl << endl << endl;
	cout << "######  #     # ###     #####                                                                " << endl;
	cout << "#     # ##   ##  #     #     #   ##   #       ####  #    # #        ##   #####  ####  #####  " << endl;
	cout << "#     # # # # #  #     #        #  #  #      #    # #    # #       #  #    #   #    # #    # " << endl;
	cout << "#     # # # # #  #     #        #  #  #      #    # #    # #       #  #    #   #    # #    # " << endl;
	cout << "######  #  #  #  #     #       #    # #      #      #    # #      #    #   #   #    # #    # " << endl;
	cout << "#     # #     #  #     #       ###### #      #      #    # #      ######   #   #    # #####  " << endl;
	cout << "#     # #     #  #     #     # #    # #      #    # #    # #      #    #   #   #    # #   #  " << endl;
	cout << "######  #     # ###     #####  #    # ######  ####   ####  ###### #    #   #    ####  #    # " << endl;

	//Displays intro questions
	cout << endl << endl;;
	cout << "Please select one of the following menu options.\nYou do this by typing the corresponding number and pressing enter.\n" << endl;
	cout << "1. List users names"
		"\n2. Update weight for a user"
		"\n3. Calculate BMI for a user"
		"\n4. Show user details"
		"\n5. Show user historical data"
		"\n6. Save user details to file"
		"\n7. Read user details from file"
		"\n8. Exit program" << endl << endl;

	//Decides what to do with the choice
	cin >> choice;
	switch (choice)
	{

	case 1:
	{
		listUserNames(userList);
		break;
	}
	case 2:
	{
		updateUserWeight(userList);
		break;
	}
	case 3:
	{
		bmiUserCalc(userList);
		break;
	}
	case 4:
	{

		showUserDetails(userList);
		break;

	}
	case 5:
	{
		showUserHistoricDetails(userList);
		break;
	}
	case 6:
	{
		//To ensure no more than 5 entries 
		if (userCount < 4)
		{
			count++;
			saveToFile(count);
		}
		else
		{
			cout << "No more enteries can be handled" << endl;
		}

		break;
	}
	case 7:
	{
		readFromFile(userList);
		break;
	}
	case 8:
	{
		//Finishes program
		cout << "Goodbye.";
		exit(0);
		break;
	}
	default:
	{
		break;
	}
	}
	bool pressedEnter = false;
	cout << "Please press enter to continue." << endl;

	//This checks if the user wants to continue 
	while (!pressedEnter)
	{
		if (GetKeyState(VK_RETURN) == 1)	//Gets the current kayboard state
		{
			pressedEnter = true;
			main();
		}
	}
}

