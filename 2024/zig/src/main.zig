const std = @import("std");
const day01 = @import("./day01.zig");

pub fn main() !void {
    std.debug.print("Advent of Code 2024\n", .{});

    const day01_part1 = day01.part1();
    std.debug.print("day01_part1: {any}\n", .{day01_part1});
}
