//============================================================================
// Name        : linecounter.cpp
// Author      : Derushio
// Version     :
// Copyright   : Itnav
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "linecounter.h"

int main(int argc, char* argv[]) {
	if (string(argv[1]).compare("--help") == 0) {
		printHelp();
		return EXIT_SUCCESS;
	}

	int preset;
	try {
		preset = stoi(string(argv[PRESET_INDEX]));
	} catch (...) {
		preset = -1;
	}

	switch (preset) {
	case -1:
		execArgv(argc, argv);
		break;
	case 0:
		androidPreset();
		break;
	case 1:
		iosPreset();
		break;
	case 2:
		cppPreset();
		break;
	}

	return EXIT_SUCCESS;
}

void printHelp() {
	string message("preset\n0:android\n1:ios\n2:cpp\nother:\"*.extension\"...");
	cout << message.c_str() << endl;
}

void androidPreset() {
	string statement(STATEMENT_HEAD);
	statement += makeFindStatement("*.java");
	statement += FINDITEM_OR;

	statement += makeFindStatement("*.xml");
	statement += STATEMENT_FOOT;

	execStatement(statement);
}

void iosPreset() {
	string statement(STATEMENT_HEAD);
	statement += makeFindStatement("*.swift");
	statement += FINDITEM_OR;

	statement += makeFindStatement("*.h");
	statement += FINDITEM_OR;

	statement += makeFindStatement("*.m");
	statement += STATEMENT_FOOT;

	execStatement(statement);
}

void cppPreset() {
	string statement(STATEMENT_HEAD);
	statement += makeFindStatement("*.h");
	statement += FINDITEM_OR;

	statement += makeFindStatement("*.c");
	statement += FINDITEM_OR;

	statement += makeFindStatement("*.m");
	statement += FINDITEM_OR;

	statement += makeFindStatement("*.cpp");
	statement += FINDITEM_OR;

	statement += makeFindStatement("*.c++");
	statement += STATEMENT_FOOT;

	execStatement(statement);
}

void execArgv(int argc, char* argv[]) {
	string statement(STATEMENT_HEAD);
	for (int i = 1; i < argc; i++) {
		statement += makeFindStatement(argv[i]);

		if (i != argc - 1) {
			statement += FINDITEM_OR;
		}
	}
	statement += STATEMENT_FOOT;
	execStatement(statement);
}

string makeFindStatement(string item) {
	string statement(FINDITEM_HEAD);
	statement += item;
	return statement;
}

void execStatement(string statement) {
	cout << statement.c_str() << endl;
	system(statement.c_str());
}
