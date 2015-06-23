/*
 * linecounter.h
 *
 *  Created on: 2015/06/05
 *      Author: derushio
 */

#ifndef LINECOUNTER_H_
#define LINECOUNTER_H_

#include <cstdlib>
#include <iostream>
#include <string>

#define PRESET_INDEX 1
#define STATEMENT_HEAD "wc -l `find . \\("
#define STATEMENT_FOOT " \\) -print`"
#define FINDITEM_HEAD " -name \\"
#define FINDITEM_OR " -or"

using namespace std;

int main(int argc, char* argv[]);
void printHelp();
void androidPreset();
void iosPreset();
void cppPreset();
void execArgv(int argc, char* argv[]);
string makeFindStatement(string item);
void execStatement(string statement);

#endif /* LINECOUNTER_H_ */
