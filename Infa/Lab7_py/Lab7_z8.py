
result = input("Введите результат матча (Пример: Название 1-Название 2 A:B): ")

team1_e = result.index('-')
team2_s = team1_e + 1
team2_e = result.index(' ')

team1 = result[:team1_e]
team2 = result[team2_s:team2_e]
score_part = result[team2_e+1:]

s1, s2 = map(int, score_part.split(':'))
if s1 > s2:
    winner = team1
elif s2 > s1:
    winner = team2
else:
    winner = "Ничья"
print("Победитель:", winner)
