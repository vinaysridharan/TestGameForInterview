#include "stdafx.h"
#include "CheckWriter.h"
using namespace std;

string CheckWriter::convertToWords(int number)
{
	bool skipNext = false;
	string output = "";
	int num = number;
	vector<int> digits;
	while (num){
		digits.push_back(num % 10);
		num /= 10;
	}
	reverse(digits.begin(), digits.end()); //Gets you the digits from left to right

	for (int i = 0; i < digits.size(); i++){
		int indx = digits.size() - i;
		int mod_3 = indx % 3;
		int base_3 = indx / 3;
		if (mod_3 < 2)
		{
			if (skipNext == false){
				switch (digits[i])
				{
				case 1:
					output.append("one ");
					break;
				case 2:
					output.append("two ");
					break;
				case 3:
					output.append("three ");
					break;
				case 4:
					output.append("four ");
					break;
				case 5:
					output.append("five ");
					break;
				case 6:
					output.append("six ");
					break;
				case 7:
					output.append("seven ");
					break;
				case 8:
					output.append("eight ");
					break;
				case 9:
					output.append("nine ");
					break;
				default:
					break;
				}
			}
			else
			{
				skipNext = false;
			}
			if (mod_3 == 0) output.append("hundred ");
			if (mod_3 == 1){
				switch (base_3){
				case 0:
					break;
				case 1:
					output.append("thousand ");
					break;
				case 2:
					output.append("million ");
					break;
				case 3:
					output.append("billion ");
					break;
				case 4:
					output.append("trillion ");
					break;
				case 5:
					output.append("quadrillion ");
					break;
				default:
					output.append("You don't have this kind of money");
					break;
				}
			}

		}
		else if (skipNext == true) skipNext == false;

		if (mod_3 == 2){
			int temp_num = digits[i] * 10 + digits[i + 1];
			if (temp_num >= 10 && temp_num <= 20){
				skipNext = true;

				switch (temp_num)
				{
				case 10:
					output.append("ten ");
					break;
				case 11:
					output.append("eleven ");
					break;

				case 12:
					output.append("twelve ");
					break;
				case 13:
					output.append("thirteen ");
					break;
				case 14:
					output.append("fourteen ");
					break;
				case 15:
					output.append("fifteen ");
					break;
				case 16:
					output.append("sixteen ");
					break;
				case 17:
					output.append("seventeen ");
					break;
				case 18:
					output.append("eighteen ");
					break;
				case 19:
					output.append("nineteen ");
					break;
				}
			}
			else{
				switch (digits[i])
				{
				case 2:
					output.append("twenty ");
					break;
				case 3:
					output.append("thirty ");
					break;
				case 4:
					output.append("fourty ");
					break;
				case 5:
					output.append("fifty ");
					break;
				case 6:
					output.append("sixty ");
					break;
				case 7:
					output.append("seventy ");
					break;
				case 8:
					output.append("eighty ");
					break;
				case 9:
					output.append("ninety ");
					break;
				}

			}
		}

	}
	return output;
}