import random
import math

numero_pontos = 500

raio = 30

arquivo_dados = open("2d.data", "w")

arquivo_dados.write(str(numero_pontos) + " 2 2\n")

for ponto in range(numero_pontos/2):
	raio_ponto = random.randint(0, raio)
	ponto_x = raio_ponto*math.cos(ponto)
	ponto_y = raio_ponto*math.sin(ponto)
	arquivo_dados.write(str(ponto_x) + " " + str(ponto_y) + " 0\n")
	
	raio_ponto = random.randint(raio*1.1, 3*raio)	
	ponto_x = raio_ponto*math.cos(ponto)
	ponto_y = raio_ponto*math.sin(ponto)
	arquivo_dados.write(str(ponto_x) + " " + str(ponto_y) + " 1\n")

