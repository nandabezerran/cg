faces = [	


]

for i in range(0,len(faces)):
	faces[i] = faces[i] - 1

cont = 0
for i in range(0,len(faces)):
	print(faces[i], end=',')
	cont = cont + 1
	if(cont == 3):
		print('')
		cont = 0