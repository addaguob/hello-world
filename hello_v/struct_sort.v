struct User {
	age int
	name string
}

mut users := [User{26, "Kryzza"}, User{35, "Alex"}, User{89, "Erlina"}]
println(users)
users.sort(a.age < b.age)
println(users)
users.sort(a.name > b.name)
println(users)