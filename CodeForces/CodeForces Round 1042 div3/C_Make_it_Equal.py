def solve():
    test_cases = int(input())
    for _ in range(test_cases):
        size, step = map(int, input().split())
        source = list(map(int, input().split()))
        target = list(map(int, input().split()))

        if step == 0:
            if sorted(source) == sorted(target):
                print("YES")
            else:
                print("NO")
            continue

        from collections import defaultdict
        freq_diff = defaultdict(int)

        for value in source:
            remainder = value % step
            mapped = min(remainder, step - remainder)
            freq_diff[mapped] += 1

        for value in target:
            remainder = value % step
            mapped = min(remainder, step - remainder)
            freq_diff[mapped] -= 1

        is_equal = all(count == 0 for count in freq_diff.values())
        print("YES" if is_equal else "NO")


if __name__ == "__main__":
    solve()
