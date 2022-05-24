# Ejemplo:
# localidades = [localidad1, localidad2, localidad3]
# distancias  = [12, 32]
# esto significa que la ruta empieza en la localidad1 y la localidad2 esta a 12 km de la localidad1, se sigue que 
# la distancia entre localidades[n] y localidades[n+1] es distancias[n] 

# copy_list        copia la lista
# index_list       devuelve el elemento en una posicion dad
# length_list      devuelve el largo de una lista
# append_list      agrega el elemento a la lista

# type Respuesta = tuple
#     cant_paradas : Nat
#     paradas      : List of String
# endtuple

fun paradasCombustible (autonomia: Nat, localidades: List of String, distancias List of Nat) ret r: Respuesta
    var lista_paradas: List of String
    var cant_paradas, combustible: Nat
    
    combustible := 0
    for i:=0 to length_list(localidades) do                   # recorro todas las localidades
        if (combustible < index_list(distancias, i+1)) then     # no llego a la proxima localidad?
            cant_paradas := cant_paradas + 1                    # sumo 1 a la cantidad de paradas
            append_list(lista_paradas, localidades[i])          # agrego la localidad a la lista de paradas
            combustible := autonomia                           # lleno el tanque
        else 
            combustible := combustible - index_list(distancias, i)
        fi
    od
    r.cant_paradas = cant_paradas
    r.paradas = paradas
endfun



def paradasCombustible (autonomia, localidades, distancias):
    lista_paradas = []
    cant_paradas = 0
    combustible = 0
    for i in range(len(distancias)):
        if (combustible < distancias[i]):
            cant_paradas += 1
            lista_paradas.append(localidades[i])
            combustible = autonomia
            combustible -= distancias[i]
            print("cargaste combustible en {}".format(localidades[i]))
        else:
            combustible -= distancias[i]
        
    return (lista_paradas, cant_paradas)


dis =[10, 10, 10, 100]
autonomia =100
a,b = paradasCombustible(autonomia, ["loc0", "loc1", "loc2", "loc3", "loc4"], dis)
print("paraste en: {}".format(a))
print("paraste {} veces".format(b))
print("tendrias que haber parado {} veces".format(1+(sum(dis)//autonomia)))

