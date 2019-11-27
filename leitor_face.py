import numpy as np
import re
import os

obj = open('obj.txt', 'r')
conteudo = obj.readlines()
    
arquivo = open('arquivo.txt', 'w')
final = open('arquivo_final.txt','w') #txt final



for i in range(0,len(conteudo)):
 
    if conteudo[i][0] == "f" and conteudo[i][1] == " ":
        conteudo[i] = re.sub('//[0-9]+',"",conteudo[i])
        conteudo[i] = re.sub('f ',"",conteudo[i])
        arquivo.write(conteudo[i])


arquivo.close()


arquivo_read = open('arquivo.txt','r')
matrix = np.loadtxt(arquivo_read, usecols=range(3))

os.remove('arquivo.txt') #apagar arquivo intermediário

final.write('const int objeto_num_faces = ' + str(len(matrix)) + '\n')

for i in range (0,len(matrix)):
    for j in range (0,3):
        matrix[i][j] -= 1 
             
matrix = np.array2string(matrix, separator=', ')

final .write('float objeto_faces[] = { \n')

matrix = matrix.replace("[[","")
matrix = matrix.replace("[","")
matrix = matrix.replace("]","")
matrix = matrix.replace(".","")

final.write(matrix) 

final.write('};\n\n')

obj.close()
arquivo.close()
final.close()
