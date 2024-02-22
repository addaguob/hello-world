fn main()
{
	name := "Alexander Daguob"
	nickname := name[0..4]
	println("Hello, ${name}. Can I call you ${nickname} for short?")
	initials := name[0].ascii_str() + name[10].ascii_str()
	println("Your initials are ${initials}.")
	println(name.len)	
	star_str := '\u2605'
	println(star_str)

	// Raw string - try \n \r
	mut raw_s := "\n\r"
	println(raw_s)
	raw_s = r"\n\r"
	println(raw_s)

	// String to int conversion
	s := '42'
	n := s.int() // 42
	
	// all int literals are supported
	n195 := '0xc3'.int()
	n8 := '0o10'.int()
	n3850 := '0b1111_0000_1010'.int()
	neg3850 := '-0b1111_0000_1010'.int()
	println(n195)
	println(n8)
	println(n3850)
	println(neg3850)

	x := 123.4567
	println('[${x:.2}]') // round to two decimal places => [123.46]
	println('[${x:10}]') // right-align with spaces on the left => [   123.457]
	println('[${int(x):-10}]') // left-align with spaces on the right => [123       ]
	println('[${int(x):010}]') // pad with zeros on the left => [0000000123]
	println('[${int(x):b}]') // output as binary => [1111011]
	println('[${int(x):o}]') // output as octal => [173]
	println('[${int(x):X}]') // output as uppercase hex => [7B]

	println('[${10.0000:.2}]') // remove insignificant 0s at the end => [10]
	println('[${10.14300:.2}]') // remove insignificant 0s at the end => [10]
	println('[${10.0000:.2f}]') // do show the 0s at the end, even though they do not change the number => [10.00]

	name2 := 'Bob'
	bobby := name2 + 'by' // + is used to concatenate strings
	println(bobby) // "Bobby"
	mut greeting := 'hello '
	greeting += 'world' // `+=` is used to append to a string
	println(greeting) // "hello world"
	age := 11
	println('age = ' + age.str())
}