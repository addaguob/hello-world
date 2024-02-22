fn main()
{
	println(add(1,2))
	println(sub(5,2))
	println(mult(2,2))
	println(divd(4,2))

}
/*
This is a great and unique feature. Hoistings in C, C++, Java and Python requires declaration
of functions prior to their execution.
*/
fn add(x int, y int) int 
{
	return x + y
}

fn sub(x int, y int) int 
{
	return x - y
}

fn mult(x int, y int) int 
{
	return x * y
}

fn divd(x int, y int) int 
{
	return x / y
}