// const std = @import("std");

// pub fn main() void {
//     std.debug.print("Hello, world!\n", .{});
// }


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