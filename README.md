# Skilaverkefni 3
## 1
### a
leggja saman allar tölur í lista
### b
Bubblesort
### c
Mergesort

## 4
### a
```python
def fall(L):
	\# setja upp lista með stak fyrir fyrir hverja tölu undir hæstu tölunni
	hæsta = max(l)
	countL = [0] * (hæsta+1)	
	resultL = [0]*len(L)
	\# telja þær tölur
	for i in L:
		countL[i] += 1
	\# finna hvaða index tölurnar eiga að fara í
	summa = 0
	for i in range(len(countL)):
		summma += countL[i]
		countL[i] = summa
	\# setja allar tölurnar á sinn stað
	for i in range(len(L)):
		resultL[ CountL[L[i]]-1 ] = L[i]
		countL[L[i]] - = 1

	return resultL

```
### b
Þetta er countingsort
### c