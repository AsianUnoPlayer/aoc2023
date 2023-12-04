#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{  
    ifstream input_file;
    int lineNumber = 0, readingLineNum = 0;
    string text;
    input_file.open("input.txt");
    
    //#$%&*+-/=@
    char symbolList[10] = {'#', '$', '%', '&', '*', '+', '-', '/', '=', '@'}; //# = 0, $ = 1, % = 2, & = 3, * = 4, + = 5, - = 6, / = 7, eq = 8, @ = 9
    int currentPosOfSym[10], previousPosOfSym[10];

    while (getline(input_file, text)) {
        lineNumber++; readingLineNum++;

        int symbolPos, periodPos;

        //copying arrays that hopefully works?
        copy(begin(currentPosOfSym), end(currentPosOfSym), begin(previousPosOfSym));
        fill_n(currentPosOfSym, 10, 0); //resets current one

        //find() only for one, so ahhhhhhhhh
        for (int x = 0; x < sizeof(symbolList)/sizeof(symbolList[0]); x++) {
            symbolPos = text.find(symbolList[x]);

            if (symbolPos != -1) {
                currentPosOfSym[x] = symbolPos;
                cout << symbolPos << " ";
            }
        }
        //maybe??
        //thought process. Make a map for every 3 lines. Check then erase.

        //finding all the number groups || maybe save this as a func and do on all 3 lines
        int currentPeriod = 0, nextPeriod, period1, period2;
        while (currentPeriod <= text.length()) {
            periodPos = text.find_first_not_of(".#$%&*+-/=@", currentPeriod);
            currentPeriod = periodPos;

            //cout << currentPeriod << " ";
            period1 = currentPeriod;

            nextPeriod = text.find(".", currentPeriod);
            currentPeriod = nextPeriod;

            //cout << currentPeriod << " ";
            period2 = currentPeriod;
        }

        string line1, line2, line3;
        if (readingLineNum == 1) {
            line1 = text;
        }
        else if (readingLineNum == 2) {
            line2 = text;
        }
        else if (readingLineNum == 3) {
            line3 = text;
            
            //cout << "[" << lineNumber << "]" << endl;
            //cout << "PreviousPos: ";
            for (int x = 0; x < 10; x++) {
                if (previousPosOfSym[x] != 0) {
                    cout << previousPosOfSym[x] << " ";
                }
            }

            //cout << endl << "CurrentPos: ";
            for (int x = 0; x < 10; x++) {
                if (currentPosOfSym[x] != 0) {
                    cout << currentPosOfSym[x] << " ";
                }
            }

            readingLineNum = 0;
            line1.erase(); line2.erase(); line3.erase();
        }
        cout << endl;

        //if line == 3, erase?
    }
    cout << "done" << endl;
}