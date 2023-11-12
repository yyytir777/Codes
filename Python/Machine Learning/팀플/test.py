import pickle
import numpy as np

with open("C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\wonjae_input_data.pkl", "rb") as fr:
    input_data = pickle.load(fr)

array = np.array(input_data)
print(np.shape(array))