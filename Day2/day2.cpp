#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int const RED = 12;
int const GREEN = 13;
int const BLUE = 14;

bool isRedValid = false;
bool isGreenValid = false;
bool isBlueValid = false;

int possibleGames = 0;

void findWordP1(string text, string color, int lineNumber)
{
    int finalCount = 0;
    string number;

    for (int x = 8; x < text.length(); x++) {
        if (text.substr(x, color.length()) == color) {
            if (text[x - 3] != ' ') {
                number += text[x - 3];
            }
            number += text[x - 2]; 
            finalCount = stoi(number);

            if (color == "red" && finalCount <= RED) {
                isRedValid = true;
            }
            else if (color == "green" && finalCount <= GREEN) {
                isGreenValid = true;
            }
            else if (color == "blue" && finalCount <= BLUE) {
                isBlueValid = true;
            }
            else {
                isRedValid = false;
                isGreenValid = false;
                isBlueValid = false;
                return;
            }
            number.erase();
        }
    }
}

void PartOne(string text, int lineNumber)
{
    findWordP1(text, "red", lineNumber);
    findWordP1(text, "green", lineNumber);
    findWordP1(text, "blue", lineNumber);

    if (isRedValid && isGreenValid && isBlueValid) {
        possibleGames += lineNumber;
    }
}

int redNum = 0, greenNum = 0, blueNum = 0;
int allThreeNum = 0;

void findWordP2(string text, string color, int lineNumber)
{
    int finalCount = 0;
    vector<int> numberRed;
    vector<int> numberGreen;
    vector<int> numberBlue;
    string number;

    for (int x = 8; x < text.length(); x++) {
        if (text.substr(x, color.length()) == color) {
            if (text[x - 3] != ' ') {
                number += text[x - 3];
            }
            number += text[x - 2];
            finalCount = stoi(number);

            if (color == "red") {
                numberRed.push_back(finalCount);
            }
            else if (color == "green") {
                numberGreen.push_back(finalCount);
            }
            else if (color == "blue") {
                numberBlue.push_back(finalCount);
            }
            number.erase();
        }
    }
    
    if (color == "red") {
        sort(numberRed.begin(), numberRed.end());
        if (numberRed.front() <= RED) {
            redNum = numberRed.back();
        }
        else {
            redNum = numberRed.front();
        }
    }

    if (color == "green") {
        sort(numberGreen.begin(), numberGreen.end());
        if (numberGreen.front() <= GREEN) {
            greenNum = numberGreen.back();
        }
        else {
            greenNum = numberGreen.front();
    }
    }

    if (color == "blue") {
        sort(numberBlue.begin(), numberBlue.end());
        if (numberBlue.front() <= BLUE) {
            blueNum = numberBlue.back();
        }
        else {
            blueNum = numberBlue.front();
        }
    }
}

void PartTwo(string text, int lineNumber)
{
    findWordP2(text, "red", lineNumber);
    findWordP2(text, "green", lineNumber);
    findWordP2(text, "blue", lineNumber);
    allThreeNum += redNum * greenNum * blueNum;
}

int main()
{  
    ifstream input_file;
    int lineNumber = 0;
    string text;
    input_file.open("input.txt");

    while (getline(input_file, text)) {
        lineNumber++;
        
        PartOne(text, lineNumber);
        PartTwo(text, lineNumber);
        
    }
   cout << "Part One: " << possibleGames << endl;
   cout << "Part Two: " << allThreeNum << endl;
}