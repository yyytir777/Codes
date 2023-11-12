import pickle

with open("input_data.pkl", "rb") as f:
    loaded_data = pickle.load(f)

print(loaded_data)