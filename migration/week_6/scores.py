scores = []

for i in range(3):
    scores.append(int(input("Score: ")))

average = sum(scores) / len(scores)
print(f"Average: {average}")
