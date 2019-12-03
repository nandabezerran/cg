import numpy as np
import re
import os

#substituir o nome do objeto antigo pelo atual

obj = open('./objetos/obj/travesseiro4.obj', 'r')
conteudo = obj.readlines()    
arquivo = open('arquivo.txt', 'w')
final = open('./objetos/travesseiro4.h','w') 


#CONSERTANDO FORMATAÇÃO DOS VERTICES E DAS NORMAIS

v = []
vn = []
f = []

for i in range(0,len(conteudo)):
		if conteudo[i][0] == "v" and conteudo[i][1] == " ": 
			v.append(conteudo[i])

		elif conteudo[i][0] == "v" and conteudo[i][1] == "n":
			vn.append(conteudo[i])

		elif conteudo[i][0] == "f" and conteudo[i][1] == " ":
			f.append(conteudo[i])

vertices = []
for i in range(0,len(v)):
	for j in range(2,len(v[i])):
		if v[i][j] == " " or j == len(v[i]) - 1:
			vertices.append(",")
		vertices.append(v[i][j])

normais = []
for i in range(0,len(vn)):
	for j in range(3,len(vn[i])):
		if vn[i][j] == " " or j == len(vn[i]) - 1:
			normais.append(",")
		normais.append(vn[i][j])


#CONSERTANDO FORMATAÇÃO DAS FACES

for i in range(0,len(conteudo)):
 
    if conteudo[i][0] == "f" and conteudo[i][1] == " ":
        conteudo[i] = re.sub('//[0-9]+',"",conteudo[i])
        conteudo[i] = re.sub('f ',"",conteudo[i])
        arquivo.write(conteudo[i])

arquivo.close()
arquivo_read = open('arquivo.txt','r')
matrix = np.loadtxt(arquivo_read, usecols=range(3))
os.remove('arquivo.txt') #apagar arquivo intermediário

for i in range (0,len(matrix)):
    for j in range (0,3):
        matrix[i][j] -= 1 
             
matrix = np.array2string(matrix, separator=', ')
matrix = matrix.replace("[[","")
matrix = matrix.replace(" [","")
matrix = matrix.replace("]","")
matrix = matrix.replace(".","")


#ESCREVENDO NO ARQUIVO

final.write('const int travesseiro4_num_vertices = ' + str(len(v)) + ';\n')
final.write('const int travesseiro4_num_faces = ' + str(len(f)) + ';\n\n')
final.write('float travesseiro4_vertices[] = { \n')
vertices.append("\n")
for i in range(0,len(vertices)):
	final.write(vertices[i])
final.write('};\n\n')


final .write('int travesseiro4_faces[] = { \n')
final.write(matrix) 
final.write('\n\n};\n\n')


final.write('float travesseiro4_normais[] = { \n')
normais.append("\n")
for i in range(0,len(normais)):
	final.write(normais[i])
final.write('};\n\n')


#FECHANDO ARQUIVOS

obj.close()
arquivo.close()
final.close()
