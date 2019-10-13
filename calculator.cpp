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

void deleteZeros() {
	if (isComma)
	{
		while (current.at(current.length() - 1) == '0' || current.at(current.length() - 1) == '.')
		{
			if (current.length() != 1)
			{
				current.erase(current.length() - 1, 1);
			}
			else
			{
				break;
			}
		}
	}
}

void calculateA() {

	isReset = true;
	isOperandA = true;
	isOperandB = false;
	
	deleteZeros();
	stringstream ss;
	ss << current;
	ss >> valueB;	

	switch (operandA)
	{
			// negative
	case 'n':
		valueB *= -1;
		if (strA.empty())
		{
			strA = "neg(" + current + ")";
			calculations.push_back(strA);
		}
		else
		{
			strA = "neg(" + strA + ")";
			calculations[calculations.size() - 1] = strA;
		}
		break;
			//sqrt
	case 's':
		if (valueB < 0)
		{
			isNaN = true;
			current = "NaN";
			return;
		}
		valueB = sqrt(valueB);
		if (strA.empty())
		{
			strA = "sqrt(" + current + ")";
			calculations.push_back(strA);
		}
		else
		{
			strA = "sqrt(" + strA + ")";
			calculations[calculations.size() - 1] = strA;
		}
		break;
			//recipro
	case '1':
		if (valueB == 0.0)
		{
			isNaN = true;
			current = "NaN";
			return;
		}
		valueB = 1.0 / valueB;
		if (strA.empty())
		{
			strA = "rec(" + current + ")";
			calculations.push_back(strA);
		}
		else
		{
			strA = "rec(" + strA + ")";
			calculations[calculations.size() - 1] = strA;
		}
		break;
			//mod
	case '%':
		valueB = valueA*valueB / 100.0;
		break;
	}
	ss.str("");
	ss.clear();
	ss << valueB;
	current = ss.str();
	if (operandA == '%')
	{
		calculations.push_back(current);
	}
}

void calculateB() {
	isReset = true;
	if (!isOperandB)
	{
		deleteZeros();
		stringstream ss;
		ss << current;
		ss >> valueB;


		if (isOperandA)
		{
			//calculations.push_back(strA);
			strA = "";
			isOperandA = false;
		}
		else
		{
			calculations.push_back(current);
		}

		switch (operandB)
		{
			
		case '+':
			valueA += valueB;
			break;
		case '-':
			valueA -= valueB;
			break;
		case '/':
			if (valueB == 0.0)
			{
				isNaN = true;
				current = "NaN";
				return;
			}
			valueA /= valueB;
			break;
		case '*':
			valueA *= valueB;
			break;
		default:
			valueA = valueB;
			break;
		}

		isOperandB = true;
		ss.str("");
		ss.clear();
		ss << valueA;
		current = ss.str();
	}
	else
	{
		if (calculations.size() != 0)
			calculations.pop_back();
	}

}
