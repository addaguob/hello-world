mut nums := [1, 2, 3]
println(nums[1])
println(nums)
nums[0] = 4
println(nums[0])
// add a value to existing array
nums << 1
println(nums)
// Try adding a new array to previous one
mut nums_b := [5, 6, 7]
nums << nums_b
println(nums)
// See concatenating using << operator
mut names := ['John']
names << 'Peter'
names << 'Sam'
println(names)

mut nums_c := [1, 2, 3]
println(nums_c.len) // "3"
println(nums_c.cap) // "3" or greater
nums_c = [] // The array is now empty
println(nums_c.len) // "0"

arr := []int{len: 5, init: -1}
// `arr == [-1, -1, -1, -1, -1]`, arr.cap == 5

// Declare an empty array:
println("Declare an empty array:")
users := []int{}
println(arr[0])
println(arr[1])
println(arr[2])
mut numbers := []int{cap: 1000}
println(numbers.len) // 0
// Now appending elements won't reallocate
println("Now appending elements won't reallocate")
for i in 0 .. 1000 {
	numbers << i
}

println("fnums is a fixed size array with 3 elements.")
mut fnums := [3]int{} // fnums is a fixed size array with 3 elements.
fnums[0] = 1
fnums[1] = 10
fnums[2] = 100
println(fnums) // => [1, 10, 100]
println(typeof(fnums).name) // => [3]int

fnums2 := [1, 10, 100]! // short init syntax that does the same (the syntax will probably change)

anums := fnums[..] // same as `anums := fnums[0..fnums.len]`
println(anums) // => [1, 10, 100]
println(typeof(anums).name) // => []int