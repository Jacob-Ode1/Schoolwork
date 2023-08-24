let rec enum (lst:'a list)=
    let rec all (pre:'a list)(post:'a list):'a list list=
        match post with
        |[]->pre::[]
        |x::xs-> (all pre xs)@(all (x::pre) xs)
    in
     match lst with
    |[]->[[]]
    |_-> all [] lst