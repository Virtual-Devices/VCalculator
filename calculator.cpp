#include "calculator.h"
#include <cmath>

calculator::calculator(double scale, int x, int y)
{
	showed = false;
	this->scale = scale;
	height = (int)(scale*baseWidth);
	width = (int)(scale*baseWidth);
	this->x = x;
	this->y = y;

	keys[0][0] = "0";
	keys[0][1] = "0";
	keys[0][2] = ",";
	keys[0][3] = "+";
	keys[0][4] = "=";

	keys[1][0] = "1";
	keys[1][1] = "2";
	keys[1][2] = "3";
	keys[1][3] = "-";
	keys[1][4] = "=";

	keys[2][0] = "4";
	keys[2][1] = "5";
	keys[2][2] = "6";
	keys[2][3] = "*";
	keys[2][4] = "1/x";

	keys[3][0] = "7";
	keys[3][1] = "8";
	keys[3][2] = "9";
	keys[3][3] = "/";
	keys[3][4] = "%";

	keys[4][0] = "<-";
	keys[4][1] = "CE";
	keys[4][2] = "C";
	keys[4][3] = "neg";
	keys[4][4] = "sqrt";
}


calculator::~calculator()
{
}

bool isComma = false;
bool isReset = false;
bool isOperandA = false;
char operandA = '0';
bool isOperandB = false;
char operandB = '0';
bool isNaN = false;

vector<string> calculations;
string current = "0";
string strA = "";
double valueA = 0;
double valueB = 0;
int beforeX = -1;
int beforeY = -1;


