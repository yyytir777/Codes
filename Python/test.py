scores_list = []
sum = 0

for i in range(5):
    score = int(input("?ą? ? ?? Ľ???¤ : "))
    scores_list.append(score)
    sum += score

scoreAvg = sum / len(scores_list)

cnt = 0
for i in range(len(scores_list)):
    if scores_list[i] >= scoreAvg:
        cnt += 1

print("80?  ?´? ?ą? ? ë°ě?? ????? ", cnt, "ëŞě??¤")