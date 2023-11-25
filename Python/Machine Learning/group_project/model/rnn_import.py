import pickle

with open("rnn_predict_data.pkl", "rb") as fr:
    predictions = pickle.load(fr)

print(predictions)