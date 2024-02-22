mut arr2 := [][]int{len: 3, init: []int{len:3, init: 1}}
println(arr2)
arr2[0][1] = 5
println(arr2)

mut arr3 := [][][]int{
	len: 3,
	init: [][]int{
		len: 3,
		init: []int{
			len: 3,
			init: 1
		}
	}
}
println(arr3)
arr3[2][2][2] = 111
println(arr3)