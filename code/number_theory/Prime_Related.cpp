/********************************************************************************
File Name	: Prime_Related.cpp
Function	: Provide template codes about Prime Problems.
Author		: EnRonG
Version		: 0.1
Last Change	: 2019-03-12 18:23
=================================================================================
Changes
Time			Type		User		Detail
2019-03-12 18:23	Create		EnRonG		Created Prime_Related.cpp
2019-03-12 18:30	Add		EnRonG		Added Ouler Sleve Method
							Template Code.
********************************************************************************/

/****************************************************
Dependencies:
Algorithm			: Ouler Sleve Method
Time Complexity			: O(N)
Space Complexity		: O(N)
Remarks				: None
Author				: EnRonG
=====================================================
Caution:
Please avoid using this method while the
upper limit is very large.
****************************************************/

#include <stdio.h>
#include <string.h>
#define SIZE 1000010

/********************************
SIZE can be changed when seeing 
specific problem.
********************************/

int	n_IsPrime[SIZE];
int	n_NextPos;
int	n_PrimeCount;
int	n_PrimeList[SIZE];
int	n_UpperLimit;

/********************************
Before using the function, scan
the n_UpperLimit first.

The function will mark all the
prime numbers and count the total
number in the period.

After using the function, for
every int n_A in the period.

if (n_IsPrime[n_A] == 1)
{
	n_A is a prime.
}
********************************/

void v_MakeList()
{
	for (int i = 2; i < n_UpperLimit; i++)
	{
		n_IsPrime[i]	= 1;
	}
	
	for (int i = 2; i < n_UpperLimit; i++)
	{
		if (n_IsPrime[i])
		{
			n_PrimeCount++;
			n_PrimeList[n_PrimeCount]	= i;
		}
		
		for (int j = 1; j <= n_PrimeCount; j++)
		{
			n_NextPos				= i * n_PrimeList[j];
			
			if (n_NextPos > n_UpperLimit)
			{
				break;
			}
			
			n_IsPrime[n_NextPos]	= 0;
			
			if (i % n_PrimeList[j] == 0)
			{
				break;
			}
		}
	}
}
