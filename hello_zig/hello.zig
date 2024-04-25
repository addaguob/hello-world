// Create a file called main.zig, with the following contents:

// const std = @import("std");

// pub fn main() void {
//     std.debug.print("Hello, {s}!\n", .{"World"});
// }

// Use zig run main.zig to build and run it. In this example, Hello, World! will be written to stderr, and is assumed to never fail.

// FOUND 'INVALID BYTES'
// Make sure your main.zig file is UTF-8 encoded as the Zig compiler does not currently support other encodings. To re-encode your file as UTF-8, run zig fmt main.zig and reopen the file in your editor.


// Success
// Save the following text as test_pass.zig, and run zig test test_pass.zig; you should read All 1 tests passed. in your terminal.

const std = @import("std");
const expect = std.testing.expect;

test "always succeeds" {
    try expect(true);
}


// Failure
// Now, save the following text as test_fail.zig and observe it fail.

// const std = @import("std");
// const expect = std.testing.expect;

// test "always fails" {
//     try expect(false);
// }

// Which should output something like:

// Test [1/1] test.always fails... FAIL (TestUnexpectedResult)
// /usr/lib/zig/std/testing.zig:515:14: 0x2241ef in expect (test)
//     if (!ok) return error.TestUnexpectedResult;
//              ^
// [...]/test_fail:5:5: 0x224305 in test.always fails (test)
//     try expect(false);
//     ^
// 0 passed; 0 skipped; 1 failed.


// Assignment
// Value assignment has the following syntax: (const|var) identifier[: type] = value.

// const indicates that identifier is a constant that stores an immutable value.
// var indicates that identifier is a variable that stores a mutable value.
// : type is a type annotation for identifier, and may be omitted if the data type of value can be inferred.
// const constant: i32 = 5; // signed 32-bit constant
// var variable: u32 = 5000; // unsigned 32-bit variable

// // @as performs an explicit type coercion
// const inferred_constant = @as(i32, 5);
// var inferred_variable = @as(u32, 5000);

// Constants and variables must have a value. If no known value can be given, the undefined value, which coerces to any type, may be used as long as a type annotation is provided.

// const a: i32 = undefined;
// var b: u32 = undefined;

// Where possible, const values are preferred over var values.