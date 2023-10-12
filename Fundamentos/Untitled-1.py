import re

#1_ra linea
Estados = input()
cantidadEstados = Estados.count(' ')

for i in range(len(Estados)):
    if not Estados[i].isalnum() and Estados[i] != ' ' and Estados[i] != '_':
        break
#2_da linea
AlfabetoCinta = input()

#3_ra linea
AlfabetoPila = input()

#4_ta linea
EstadoInicial = input()

#5_ta linea
EstadosFinales = input()

#6_ta linea
FondoPila = input()

#7_ma linea
Transiciones = input()

#8_va linea
PalabraaReconocer = input()

