rocket := `🚀`
println(rocket)
// println(rocket[0]) Index not supported

hello := 'Hello World 👋'
println(hello)
hello_runes := hello.runes() // [`H`, `e`, `l`, `l`, `o`, ` `, `W`, `o`, `r`, `l`, `d`, ` `, `👋`]
println(hello_runes.string() == hello)

mut a := i64(0x7B)
println(a)
mut b := 0b01111011
println(b)
mut c := 0o173
println(c)

num := 1_000_000 // same as 1000000
println(num)
three := 0b0_11 // same as 0b11
println(three)
float_num := 3_122.55 // same as 3122.55
println(float_num)
hexa := 0xF_F // same as 255
println(hexa)
oct := 0o17_3 // same as 0o173
println(oct)

a = i64(123)
println(a)
b = u8(42)
println(b)
c = i16(12345)
println(c)