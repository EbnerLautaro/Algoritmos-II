"""
type TuplaR = tuple
    paradas         : List of String
    cantidad_paradas : Nat
endtuple



// PRE: (length_list(distancias)+1 == length_list(localidades)

fun paradasCombustible (autonomia: Nat, localidades: List of String, distancias: List of Nat) ret r: TuplaR
    var paradas: List of String
    paradas = empty_list()
        
    var combustible, cantidad_paradas : Nat
    cantidad_paradas := 0
    combustible := 0


    for i:=0 to length_list(distancias) do
        if (combustible >= index_list(distancias, i)) then
            combustible := combustible - index_list(distancias, i)
        else
            combustible := 100 - index_list(distancias, i)
            cantidad_paradas = cantidad_paradas + 1
            addr(paradas, index_list(localidades, i))
        fi
    od
    r.paradas := paradas
    r.cantidad_paradas := cantidad_paradas
endfun
"""

def paradasCombustible(autonomia, localidades, distancias):
    paradas = []
    cantidad_paradas = 0
    combustible = 0
    for i in range (len(distancias)):
        if combustible >= distancias[i]:
            combustible -= distancias[i]
        
        else:
            combustible = 100 - distancias[i]
            cantidad_paradas += 1
            paradas.append(localidades[i])
            
    return (cantidad_paradas, paradas)



if __name__ == "__main__":
   
    localidades = ['loc0', 'loc1', 'loc2', 'loc3']
    distancias = [30, 40, 50]
    autonomia = 100
    cant_paradas, paradas = paradasCombustible(autonomia, localidades, distancias)
    print(cant_paradas)
    print(paradas)
