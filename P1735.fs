let rec gcd x y =
    match y with
    | 0 -> x
    | 1 -> 1
    | _ -> gcd y (x % y)

open System
let a = Console.ReadLine().Split [|' '|] |> Array.map int
let b = Console.ReadLine().Split [|' '|] |> Array.map int
let rn, rd = a.[0] * b.[1] + b.[0] * a.[1], a.[1] * b.[1]
let g = gcd rn rd
let n, d = rn / g, rd / g

Console.WriteLine(n.ToString() + " " + d.ToString())