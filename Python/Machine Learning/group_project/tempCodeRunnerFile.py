상블 진행
# model_list = [knn, rnn, xg, rf]
# ensemble_predict_list = list()
# for i in range(len(knn)):
#     first_feature = majority_vote(list([knn[i][0], rnn[i][0], xg[i][0], rf[i][0]]))
#     second_feature = majority_vote(list([knn[i][1], rnn[i][1], xg[i][1], rf[i][1]]))
#     third_feature = majority_vote(list([knn[i][2], rnn[i][2], xg[i][2], rf[i][2]]))
#     forth_feature = majority_vote(list([knn[i][3], rnn[i][3], xg[i][3], rf[i][3]]))

#     ensemble_predict_list.append([first_feature, second_feature, third_feature, forth_feature])


# with open("y_test.pkl", "rb") as fr:
#     y_test = pickle.load(fr)

# ensemble_predict_list = np.array(ensemble_predict_list)
# y_test = np.array(y_test)

# cnt = 0
# temp_sum = 0
# dimension_cnt = [0, 0, 0, 0]
# test_data_size = 1563
# for i in range(test_data_size):
#     print(ensemble_predict_list[i], y_test[i])
#     temp = 0
#     for j in range(4):
#         if ensemble_predict_list[i][j] == y_test[i][j]:
#             dimension_cnt[j] += 1
#             temp += 1
    
#     temp_sum += temp
#     if temp == 4:
#         cnt += 1

# print("cnt : %d" %cnt)
# print("size : %d" %test_data_size)
# print("accuracy : %0.3f" %(cnt / test_data_size))
# print()
# print("temp : %d" %temp_sum)
# print("size : %d" %(test_data_size * 4))
# print("accuracy : %0.3f" %(temp_sum / (test_data_size * 4)))
# print()
# for i in range(4):
#     print("%d 차원 정확도 : %0.3f" %(i, (dimension_cnt[i] / test_data_size)))

