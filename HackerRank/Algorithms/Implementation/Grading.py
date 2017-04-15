def round_grade(grades):
    res = grades
    if (res >= 38 and res % 5 >= 3):
        res = (res // 5 + 1) * 5
    return res

n = int(input().strip())
round_grades = []
for i in range(n):
    round_grades.append(round_grade(int(input().strip())))
for x in round_grades:
    print(x)
