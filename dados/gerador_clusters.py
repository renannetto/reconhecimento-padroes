import random
import math

raio = 30
pontos_cluster = 100
distancia_clusters = 50

arquivo_dados = open("2clusters.data", "w")

arquivo_dados.write(str(pontos_cluster*2) + " 2 1\n")

for ponto in range(pontos_cluster):
	raio_ponto = random.randint(0, raio)
	ponto_x =  raio_ponto*math.cos(ponto) - raio - (distancia_clusters/2)
	ponto_y = raio_ponto*math.sin(ponto)
	arquivo_dados.write(str(ponto_x) + " " + str(ponto_y) + " 0\n")

	raio_ponto = random.randint(0, raio)
	ponto_x =  raio_ponto*math.cos(ponto) + raio + (distancia_clusters/2)
	ponto_y = raio_ponto*math.sin(ponto)
	arquivo_dados.write(str(ponto_x) + " " + str(ponto_y) + " 0\n")	
