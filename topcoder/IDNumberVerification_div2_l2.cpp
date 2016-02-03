#include <iostream>
using namespace std;


class IDNumberVerification
{


public:
	string verify(string id, string[] regionCodes);

};

string IDNumberVerification::verify(string id, string[] regionCodes)
{
		   012345-6789-10111213-  	
	//id = RRRRRR-YYYY M M D D - zzz-x

	int length_of_code = sizeof(regionCodes/regionCodes[0]);
	// 1. Validate region code.
	for(int i=0; i<length_of_code; i++)
	{
		bool region_code_match = false;
		if(0 == id.compare(0,6, regionCodes[i])
		{
			region_code_match = true;
			cout<<"\n Matches with region code= " << regionCodes[i];
			break;
		}
	}
	if(region_code_match == false)
	{
		return "Invalid";
	}

	//2. Validate DOB
	string dob = id.substr(6,8);
	unsigned int num = stoi(dob);
	cout<<"\n DOB= " << dob <<", dob-num= " << num;

	int year = num/10000;
	if(year<1900 || year > 2011)
	{
		cout<<"\n year is invalid";
		return "Invalid";
	}

	for(int i=10; i<14; i++)
	{
		if(id[i] <'0' || id[i] > '9')
		{
			cout<<"\n Month-date is invalid, index[" <<i <<"]= " << id[i];
			return "Invalid";
		}
	}	

	int month =  (num %10000) / 100;
	if(month <1 || month > 12)
	{
		cout<<"\n Month is invalid, val= " << month;
		return "Invalid";
	}

	int day = num%100;
	if(day<1 || day > 31)
	{
		cout<<"\n Day is invalid, val= " << day;
		return "Invalid";
	}

	// Validate for leap year.
	if(month == 2)
	{
		if((year%400 == 0) || (year%4 == 0 && year%100 != 0))
		{
			if(day > 29)
			{
				cout<<"\n day " << day <<"  is not matching for feb leap year " << year;
				return "Invalid";
			}
		} 
		else
		{
            if(day > 28)
            {
                cout<<"\n day " << day <<"  is not matching for feb year " << year;
                return "Invalid";
            }
		}
	}

	// Validate for 30, 31 and 28 days.
	if((day == 31) && !(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
	{	
		cout<<"\n Validated months for 31 days";
		return "Invalid";
	}


	 string code = id.substr(14,3);
	 int code_num = atoi(code.c_str());
	 if(code_num == 0)
	 {
		cout<<"\n code is invalid";
		return "Invalid";
	 }

	int multiplyer = 217;
	unsigned int val=0;
	for(int i=0; i<17; i++)
	{
		val += multiplyer*(id[i] - 48);
		multiplyer--;
	}
	val = val%11;
	int x= 10-val;

}
int main()
{


return 0;
}
