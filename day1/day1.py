f = open("input.txt")
data = f.read()

string_counts = [elf.split() for elf in data.split('\n\n')]
int_counts = [list(map(lambda x: int(x), elf)) for elf in string_counts]
totals = [sum(elf) for elf in int_counts]
sorted_totals = sorted(totals, reverse=True)

print("Elf with most calories has: ", sorted_totals[0])
print("Elf with 2nd most calories has: ", sorted_totals[1])
print("Elf with 3rd most calories has: ", sorted_totals[2])
print("Top three elves combined have: ", sorted_totals[0] + sorted_totals[1] + sorted_totals[2])

f.close()
