// A Simple Merge based O(n) 
// solution to find median of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

/* This function returns 
median of ar1[] and ar2[]. 
Assumptions in this function: 
Both ar1[] and ar2[] 
are sorted arrays 
Both have n elements */
int getMedian(int ar1[], 
			int ar2[], int n) 
{ 
	int i = 0; /* Current index of 
				i/p array ar1[] */
	int j = 0; /* Current index of 
				i/p array ar2[] */
	int count; 
	int m1 = -1, m2 = -1; 

	
	for (count = 0; count <= n; count++) 
	{ 
		/* Below is to handle case where 
		all elements of ar1[] are 
		smaller than smallest(or first) 
		element of ar2[]*/
		if (i == n) 
		{ 
			m1 = m2; 
			m2 = ar2[0]; 
			break; 
		} 

		/*Below is to handle case where 
		all elements of ar2[] are 
		smaller than smallest(or first) 
		element of ar1[]*/
		else if (j == n) 
		{ 
			m1 = m2; 
			m2 = ar1[0]; 
			break; 
		} 

		if (ar1[i] < ar2[j]) 
		{ 
			/* Store the prev median */
			m1 = m2; 
			m2 = ar1[i]; 
			i++; 
		} 
		
