#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream inputFile("loc1.cpp");
    if (!inputFile)
    {
        cout << "Failed to open the input file." << endl;
        return 1;
    }
    string line;
    int codeLines = 0;
    bool inMultiLineComment = false;
    while (getline(inputFile, line))
    {
        string trimmedLine;
        for (char c : line)
        {
            if (!isspace(c))
            {
                trimmedLine += c;
            }
        }
        if (inMultiLineComment)
        {
            int commentEnd = trimmedLine.find("*/");
            if (commentEnd == -1)
            {
                continue;
            }
            else
            {
                inMultiLineComment = false;
                trimmedLine = trimmedLine.substr(commentEnd + 2);
            }
        }
        if (trimmedLine.empty() || (trimmedLine.find("//") == 0))
        {
            continue;
        }
        int commentStart = trimmedLine.find("/*");
        if (commentStart != -1)
        {
            inMultiLineComment = true;
            trimmedLine = trimmedLine.substr(0, commentStart);
        }
        if (!trimmedLine.empty())
        {
            codeLines++;
        }
    }
    cout << "Number of lines of code: " << codeLines << endl;
    inputFile.close();
    return 0;
}
