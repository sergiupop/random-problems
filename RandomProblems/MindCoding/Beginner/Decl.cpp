/*** https://mindcoding.ro/pb/decl ***/

#include <iostream>
#include <string>

using namespace std;

int getTypeSize(string type) {
    if (type == "char") {
        return 1;
    }
    if (type == "short") {
        return 2;
    }
    if (type == "int") {
        return 4;
    }

    return -1;
}

int getVariableDeclarationSize(string variableDeclaration, int typeSize) {
    int size = 0;
    if (variableDeclaration.find("[") == string::npos && variableDeclaration.find("]") == string::npos) {
        size += typeSize;
    }
    else {
        bool isArrayDeclaration = true;
        int arraySize = 1;
        string currentArrayVariable = variableDeclaration;
        while (isArrayDeclaration) {
            unsigned open = currentArrayVariable.find("[");
            unsigned close = currentArrayVariable.find("]");

            if (open == string::npos && close == string::npos) isArrayDeclaration = false;

            arraySize *= stoi(currentArrayVariable.substr(open + 1, close - open - 1));
            if (close == currentArrayVariable.length() - 1) {
                isArrayDeclaration = false;
            }
            else {
                currentArrayVariable = currentArrayVariable.substr(close + 1, currentArrayVariable.length() - close - 1);
            }
        }
        size += arraySize * typeSize;
    }

    return size;
}

int main()
{
	string line;
	while (getline(cin, line))
	{
        string* declarationParts = new string[3];
        string currentDeclarationPart;
        int wordIndex = 0;

        for (auto c : line) {
            if (c == ' ') {
                declarationParts[wordIndex] = currentDeclarationPart;
                wordIndex++;
                currentDeclarationPart.erase();
            }
            else {
                currentDeclarationPart += c;
            }
        }
        declarationParts[wordIndex] = currentDeclarationPart;

        string type = declarationParts[wordIndex - 1];
        string variables = declarationParts[wordIndex];
        delete[] declarationParts;

        int typeSize = getTypeSize(type);
        int currentDeclarationSize = 0;
        string currentVariableDeclaration;

        for (auto c : variables) {
            if (c == ',') {
                int currentVariableDeclarationSize = getVariableDeclarationSize(currentVariableDeclaration, typeSize);
                currentDeclarationSize += currentVariableDeclarationSize;
                currentVariableDeclaration.erase();
            }
            else {
                currentVariableDeclaration += c;
            }
        }
        currentDeclarationSize += getVariableDeclarationSize(currentVariableDeclaration, typeSize);

        cout << currentDeclarationSize << endl;
	}

	return 0;
}