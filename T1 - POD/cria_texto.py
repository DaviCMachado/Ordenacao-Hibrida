import random

x = 10000

# Gera x números inteiros aleatórios entre 0 e 1000
numeros = [random.randint(0, 1000) for _ in range(x)]

parcialmente_ordenados = sorted(numeros[:int(x/2)]) + sorted(numeros[int(x/2):])

repetidos = [random.randint(0, 2) for _ in range(x)]

# Abre um arquivo para escrita
with open('numeros.txt', 'w') as arquivo:
    # Escreve os números no arquivo separados por espaço
    arquivo.write(' '.join(map(str, numeros)))

with open('parcial.txt', 'w') as arquivo:
    arquivo.write(' '.join(map(str, parcialmente_ordenados)))

with open('repete.txt', 'w') as arquivo:
    arquivo.write(' '.join(map(str, repetidos)))
