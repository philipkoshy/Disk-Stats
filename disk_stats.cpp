/************************************************************
 * Author: Philip Koshy
 *
 * This program reads disk statistics from /proc/diskstats
 * For more information, see the kernel documentation here:
 * http://www.kernel.org/doc/Documentation/iostats.txt
 *
 ************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <boost/algorithm/string.hpp>

using namespace std;

string findLine(ifstream& fin, const string& targetString)
{
	string line;

	while(!fin.eof())
	{
		getline( fin, line );
		if( line.find( targetString ) != string::npos )
			return line;
	}
}

int main()
{
	using namespace boost;

	ifstream fin("/proc/diskstats");
	string line = findLine( fin, "sda1" );
	
	vector<string> fields;
	split( fields, line, is_any_of("\t ") );


	vector<string>::iterator end = find( fields.begin(), fields.end(), "sda1");
	fields.erase(fields.begin(), ++end);
	
	cout << "[1] Reads Completed: " << fields[0]	<< endl;
	cout << "[2] Merged Reads: " << fields[1] << endl;
	cout << "[3] Sector Read Count: " << fields[2] << endl;
	cout << "[4] Milliseconds Spent Reading: " << fields[3] << endl;
	cout << "[5] Writes Completed: " << fields[4] << endl;
	cout << "[6] EMPTY " << endl;
	cout << "[7] Sector Write Count: " << fields[6] << endl;
	cout << "[8] Milliseconds Spent Writing: " << fields[7] << endl;
	cout << "[9] Current I/O Count: " << fields[8] << endl;
	cout << "[10] Milliseconds Spent Doing I/O: " << fields[9] << endl;
	cout << "[11] Weighted # of I/O Milliseconds: " << fields[10] << endl; 

	fin.close();

	return 0;
}
