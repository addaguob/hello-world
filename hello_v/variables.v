fn main()
{
	name := "Alexander"
	age := 35
	dream_money := i64(999999999)
	print("Hi my name is ")
	print(name)
	print(" and I'm ")
	print(age)
	print(" years old. I wish I have ")
	print(dream_money)
	println("PHP and smile.")

	// Try one line
	println("Hello, I'm ${name}, ${age} years of age and I want PHP${dream_money}!")

	// Let's try swapping two integers
	mut n1 := 1
	mut n2 := 2
	println("n1 = ${n1}, n2 = ${n2}")
	n1, n2 = n2, n1
	println("n1 = ${n1}, n2 = ${n2}")
	// This is nice like in Python's one-line swapping.

	u := u16(12)
	println(u)
	v := 13 + u    // v is of type `u16` - no promotion
	println(v)
	x := f32(45.6)
	println(x)
	y := x + 3.14  // y is of type `f32` - no promotion
	println(y)
	a := 75        // a is of type `int` - default for int literal
	println(a)
	b := 14.7      // b is of type `f64` - default for float literal
	println(b)
	c := u + a     // c is of type `int` - automatic promotion of `u`'s value
	println(c)
	d := b + x     // d is of type `f64` - automatic promotion of `x`'s value
	println(d)
}