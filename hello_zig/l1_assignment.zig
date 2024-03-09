const std = @import("std");

pub fn main() void {
    const constant: i32 = 5;
    const variable: u32 = 5000;
    std.debug.print("constant: {d}!\n", .{constant});
    std.debug.print("variable: {d}!\n", .{variable});
}
// TODO: How to print variables