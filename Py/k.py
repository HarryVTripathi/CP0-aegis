Sequence : 
_,_,6,_,_,10,_ ⇒ 2,2,3,3,3,3/2,3/2
2,2,2,_,_,10,_ 
2,2,3,3,3,3,_

a= [‘_’, ‘_’, 6]


_,_,6,_,_,10,_

Dist = 1
Ans = []


for x in a:

	if x != “_”:

		if last:
			Last = (last + x)/dist
		Else:
			Last = x / dist

		Ans = Ans + [Last] * dist
		
		Dist = 1

	else:
		Dist += 1