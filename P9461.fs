let padovan n =
    Seq.init (n) id
    |> Seq.fold (fun (a, b, c) items -> (b + c, a, b)) (1L, 1L, 0L)

open System
let cases = int (Console.ReadLine())
for _ in 1..cases do
    let n = int (Console.ReadLine())
    let (_, _, result) = (padovan n)
    printfn "%d" result
