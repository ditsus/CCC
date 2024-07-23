#include <iostream>
#include <unordered_map>
using namespace std;


unordered_map<string, int> groups;

int main() {
int x, y, g;
int	violationCount = 0;

cin >> x;

string same1[x];
string same2[x];

for (int i = 0; i < x; i++)
{
	string temp1, temp2;
	cin >> temp1 >> temp2;
	same1[i] = temp1;
	same2[i] = temp2;
}

cin >> y;

string diff1[y];
string diff2[y];
	
for (int i = 0; i < y; i++)
{
	string temp1, temp2;
	cin >> temp1 >> temp2;
	diff1[i] = temp1;
	diff2[i] = temp2;
}

cin >> g;
	
for (int i = 0; i < g; i++)
{
	string temp1, temp2, temp3;
	cin >> temp1 >> temp2 >> temp3;
	groups[temp1] = i;
	groups[temp2] = i;
	groups[temp3] = i;
}

for (int i = 0; i < x; i++)
{
	if (groups[same1[i]] != groups[same2[i]])
	{
		violationCount++;
	}
}

for (int i = 0; i < y; i++)
{
	if (groups[diff1[i]] == groups[diff2[i]])
	{
		violationCount++;
	}
}

cout << violationCount;

	
  return 0;
}
