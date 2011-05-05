#!/usr/bin/python
#Prime number generator


from math import sqrt
import sys

def primefind(limit):
	plist = [2]
	x = 1
	while len(plist) < limit:
		x += 2
		isPrime = True
		for y in plist:
			if(y > sqrt(x)):
				break
			elif(x % y == 0):
				isPrime = False
				break
		if isPrime:
			plist.append(x)
	return plist

try:
	x = primefind(int(sys.argv[1]))
except:
	x = primefind(1000)

print x
