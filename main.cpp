#include <iostream>
using namespace std;
char* join(char* a, int aLen, char* b, int bLen) 
{
	int aPos = 0;
	int bPos = 0;
	int joinLength = aLen + bLen;
	char* tempArray = new char[aLen + bLen];
	for (int i = 0; i < joinLength; i++)
	{
		if (aPos < aLen && bPos < bLen) {
			if (a[aPos] < b[bPos]) tempArray[i] = a[aPos++];
			else tempArray[i] = b[bPos++];
		}
		else 
		{
			if (aPos < aLen) tempArray[i] = a[aPos++];
		}
	}
	for (int i = 0; i < joinLength; i++)
	{
		a[i] = tempArray[i];
	}
	delete[joinLength] tempArray;
	return a;
}
char* stafrof(char* texti, int lengd) 
{
	if (lengd == 1)
	{
		return texti;
	}
	int split;
	if (lengd % 2 == 1) split = lengd / 2 + 1;
	else split = lengd / 2;
	return join(stafrof(texti, split), split, stafrof(texti+split, lengd - split), lengd - split);
}
int main() 
{
	char word[5] = { 'e','d','c', 'b', 'a' };
	stafrof(word, 5);
	cout << word[0] << word[1] << word[2] << word[3] << endl;
}
