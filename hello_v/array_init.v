fn main()
{
	arr := []int{len: 5, cap: 3, init: 1}
	println(arr.cap)
	println(arr.len)

	for i in arr {
		print(i.str() + " ")
	}

	println("")
	println("Initialize using array indices:")
	arr_ind := [] int {len: 10, init: index}
	for i in arr_ind {
		println(i)
	}

	//Explore difference between copying and cloning arrays
	mut arr_to_clone := [1, 4, 3]

	// error: use `array2 := array1.clone()` instead of `array2 := array1` (or use `unsafe`)
	// mut arr_assign_only := arr_to_clone 

	mut arr_assign_only := arr_to_clone.clone()

	println(arr_assign_only)
}
// Okay