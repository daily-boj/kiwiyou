open System

let rope_count = int (Console.ReadLine())
let ropes = Seq.init rope_count (fun _ -> Console.ReadLine()) |> Seq.map int |> Seq.toList |> List.sort

let maximum = List.zip ropes [0..rope_count - 1] |> List.fold (fun prev (w, i) -> max prev (w * (rope_count - i)) ) 0

printfn "%A" maximum