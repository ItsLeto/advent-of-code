const std = @import("std");

pub fn part1() !i32 {
    std.debug.print("====== Day 1 ======\n", .{});
    const file = try std.fs.cwd().openFile("inputs/day01/input_test.txt", .{});
    defer file.close();

    var buf: [1024]u8 = undefined;
    var reader = file.reader();

    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    defer {
        _ = gpa.deinit();
    }

    var left = std.ArrayList(i32).init(allocator);
    defer left.deinit();
    var right = std.ArrayList(i32).init(allocator);
    defer right.deinit();

    while (try reader.readUntilDelimiterOrEof(&buf, '\n')) |line| {
        var tokenizer = std.mem.tokenize(u8, line, " ");

        const first_str = tokenizer.next() orelse return error.InvalidInput;
        const first_int = try std.fmt.parseInt(i32, first_str, 10);
        try left.append(first_int);

        const second_str = tokenizer.next() orelse return error.InvalidInput;
        const second_int = try std.fmt.parseInt(i32, second_str, 10);
        try right.append(second_int);
    }

    std.mem.sort(i32, left.items, {}, std.sort.asc(i32));
    std.mem.sort(i32, right.items, {}, std.sort.asc(i32));

    var sum: i32 = 0;
    for (left.items, right.items) |l, r| {
        std.debug.print("{d} {d} | {d}\n", .{ l, r, r - l });
        sum += r - l;
    }

    std.debug.print("=========\nSum: {d}\n", .{sum});
    return sum;
}
