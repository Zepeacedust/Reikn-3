# Skilaverkefni 3
## 1
### a
leggja saman allar t�lur � lista
### b
Bubblesort
### c
Mergesort

## 4
### a
```python
def fall(L):
	\# setja upp lista me� stak fyrir fyrir hverja t�lu undir h�stu t�lunni
	h�sta = max(l)
	countL = [0] * (h�sta+1)	
	resultL = [0]*len(L)
	\# telja ��r t�lur
	for i in L:
		countL[i] += 1
	\# finna hva�a index t�lurnar eiga a� fara �
	summa = 0
	for i in range(len(countL)):
		summma += countL[i]
		countL[i] = summa
	\# setja allar t�lurnar � sinn sta�
	for i in range(len(L)):
		resultL[ CountL[L[i]]-1 ] = L[i]
		countL[L[i]] - = 1

	return resultL

```
### b
�etta er countingsort
### c