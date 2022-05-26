



cant_ballenas........... 5

tiempo_supervivencia.... [179, 120, 155, 75, 130]
tiempo.................. 45
orden................... [3,  1,  4,  2]
orden................... [75,  120,  130,  155]


type Respuesta = tuple
    cant_rescates: Nat
    orden_rescate: list of Nat
endtuple

fun rescatarBallenas(cant_ballenas: Nat, tiempo_supervivencia: list of Nat, tiempo: Nat) ret orden: List of Nat

    var cant_rescates: Nat
    var orden_rescate: list of Nat

    cant_rescates := 0
    orden_rescate := empty_list()



endfun