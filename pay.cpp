#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include "person.cpp"

using namespace std;


void readData(vector<Person> &employees)
{

  Person employee;
  string fName, lName, coName;
  float rate, hours;
  int id;
	string line;
  ifstream inFile;

  inFile.open("input.txt");

  if(inFile.is_open())
    {
      inFile >> fName;
      while(!inFile.eof())
      {
        inFile >> lName;
        inFile >> id;
        inFile >> coName;
        inFile >> hours;
        inFile >> rate;
        getline(inFile, line);
        employee.setFirstName(fName);
        employee.setLastName(lName);
        employee.setEmployeeId(id);
        employee.setCompanyName(coName);
        employee.setHoursWorked(hours);
        employee.setPayRate(rate);
        inFile >> fName;
      }
    }
      inFile.close();

}

void getCompanies(vector<Person> &employees, vector<string> &companyNames)
{

  string cursor;
  int n = employees.size();
  for (int i = 0; i < n; i++)
  {
    cout << employees.at(i).getCompanyName() << endl;
    cursor = employees.at(i).getCompanyName();
  }

}

void printHighestPaid(vector<Person> &employees)
{

  int cursor1 = 0;
  int m = employees.size();
  for (int j = 0; j < m; j++)
  {
      if (employees.at(cursor1).totalPay() < employees.at(j).totalPay())
      {
          cursor1 = j;
      }

   }
   cout <<  endl;
   cout << "Highest Paid:: " << employees.at(cursor1).fullName() << endl;
   cout << "Employee ID:: " << employees.at(cursor1).getEmployeeId() << endl;
   cout << "Employer:: " << employees.at(cursor1).getCompanyName() << endl;
   cout << "Total Pay:: $" << employees.at(cursor1).totalPay() << endl;

 }

void seperateAndSave(vector<Person> &employees, vector<string> &companyNames)
{

  string line;
  string Name;
  string coName;
  int id;
  float totalPay;
  string cursor2;
  int o = companyNames.size();
  for (int j = 0; j < o; j++)
  {
    cursor2 = companyNames.at(j);
    string line = employees.at(j).getCompanyName();
    ofstream inFile;
    inFile.open(cursor2 + ".txt");
    if(line == cursor2)
  	{
      int p = employees.size();
  		for(int k = 0; k < p; k++)
  		{
  			Name = employees.at(k).fullName();
  			totalPay = employees.at(k).totalPay();
  			inFile << Name << " " << id << " $" << totalPay << endl;
  			cout << Name << " " << id << " $" << totalPay << endl;
  		}
      inFile.close();
  }
inFile.close();


  }

}

int main()
{

  vector<Person> employees;
  vector<string> companyNames;
  readData(employees);
  getCompanies(employees, companyNames);
  printHighestPaid(employees);
  seperateAndSave(employees, companyNames);
  return 0;


}
