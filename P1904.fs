let tiles n =
    Seq.init (int n) id
    |> Seq.fold (fun (n1, n2) items -> ((n1 + n2) % 15746 , n1)) (1, 0)
    |> fst

open System
Console.ReadLine() |> int |> tiles |> printfn "%A"
