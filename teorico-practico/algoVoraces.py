

 
# /* 
#     Se supone que: 
#     - "Conjunto" es un conjunto de monedas
#     - "monto" es el monto del cual se tiene que dar el cambio
# */
# // fun cambio(monto: Nat, Conjunto :set of Nat) ret S:Nat
# //     var resto, aux: Nat 
# //     Ccopy = copy_set(Conjunto)
# //     S := 0
# //     resto := monto
# //     while (resto > 0) do
# //         aux = max_of_Set(Ccopy)    
# //         remove_of_Set(Ccopy, aux)
# //         S := S + (resto / aux)                    // divicion entera (5/2 = 2, resto=1)
# //         resto := resto % aux
# //     od
# // endfun

    

def cambio (monto, conjunto):
    res = 0
    aux = 0
    ccopy = conjunto
    resto = monto
    while (resto > 0):
        aux = max(ccopy)
        ccopy.remove(aux)
        res += int(resto / aux)
        resto = resto % aux

    return res



# if __name__ == "__main__":

a = int(input())
print(cambio(a, [1, 2, 5, 10, 20]))