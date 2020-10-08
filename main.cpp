#include <iostream>
#include <math.h>
using namespace std;

///Þetta reiknirit til að setja tölu inn í lista klárast í o(n) þar sem það þarf alltaf að skrifa upp annað array, það tekur samt o(log2(n)) tíma til að finna töluna
bool insert(int newNum, int** arr, int* length) 
{
	int location = 0;
	for (size_t i = pow(ceil(log2(*length)),2) / 2; i > 0; i>>=1)
	{
		if (location < *length && (*arr)[location + i] <= newNum) location += i;
	}
	int* tempArray = new int[*length + 1];
	for (size_t i = 0; i < location; i++)
	{
		tempArray[i] = (*arr)[i];
	}
	for (size_t i = location; i < *length + 1; i++)
	{
		tempArray[i] = (*arr)[i-1];
	}
	tempArray[location] = newNum;
	///ég veit ekki alveg hvort þetta sé besta leiðin til að gera þetta en þetta virkar og (ætti að) hreynsa upp eftir sig á heapinum. 
	*length += 1;
	int* arrHolder = *arr;
	*arr = tempArray;
	delete[] arrHolder;

	return true;
}

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
			if (bPos < bLen) tempArray[i] = b[bPos++];
		}
	}
	for (int i = 0; i < joinLength; i++)
	{
		a[i] = tempArray[i];
	}
	delete[] tempArray;
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
	char word[5] = {'b', 'a', 'n', 'a', 'b'};
	cout << word[0] << word[1] << word[2] << word[3] << word[4] << endl;
	stafrof(word, 5);
	cout << word[0] << word[1] << word[2] << word[3] << word[4] << endl;
	int* numeros = new int[8]{ 1,2,3,4,5,6,7 };
	int numerosLen = 8;
	insert(8, &numeros, &numerosLen);
	cout << &numeros << endl;

	cout << numeros[0] << numeros[1] << numeros[2] << numeros[3] << numeros[4] << numeros[5] << numeros[6] << numeros[7] << endl;
}
