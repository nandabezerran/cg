obj = open('objetos/obj.txt', 'r')
conteudo = obj.readlines()

#SEPARANDO ARQUIVO EM VETORES

v = []
vn = []
f = []

for i in range(0,len(conteudo)):
		if conteudo[i][0] == "v" and conteudo[i][1] == " ": 
			v.append(conteudo[i])

		elif conteudo[i][0] == "v" and conteudo[i][1] == "n":
			vn.append(conteudo[i])

		if conteudo[i][0] == "f" and conteudo[i][1] == " ":
			f.append(conteudo[i])

#CONSERTANDO FORMATAÇÃO DOS VETORES

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

faces = []
for i in range(0,len(f)):
	for j in range(2,len(f[i])):
		if f[i][j] == " " or j == len(f[i]) - 1:
			faces.append(",")
		if f[i][j] != '/' and f[i][j-1] != '/':
			faces.append(f[i][j])

# subtraindo das faces

for i in range(0,len(faces),3):
	faces[i] = str(int(faces[i]) - 1)

#ESCREVENDO NO ARQUIVO

arquivo = open('arquivo.txt', 'w')


arquivo.write('const int objeto_num_vertices = ' + str(len(v)) + '\n')
arquivo.write('const int objeto_num_faces = ' + str(len(f)) + '\n')
arquivo.write('float objeto_vertices[] = { \n')

vertices.append("\n")
for i in range(1,len(vertices)):
	arquivo.write(vertices[i])

arquivo.write('};\n\n')
arquivo.write('float objeto_faces[] = { \n')


faces.append("\n")
for i in range(0,len(faces)):
	arquivo.write(faces[i])

arquivo.write('};\n\n')
arquivo.write('float objeto_normais[] = { \n')

normais.append("\n")
for i in range(1,len(normais)):
	arquivo.write(normais[i])

arquivo.write('};\n\n')

obj.close()
arquivo.close()
