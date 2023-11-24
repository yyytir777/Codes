import tensorflow as tf
import pickle
import numpy as np
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences

with open("Python\\Machine Learning\\group_project\\input\\input_data.pkl", "rb") as fr:
    input_data = pickle.load(fr)

with open("Python\\Machine Learning\\group_project\\input\\target_class.pkl", "rb") as fr:
    target_class_data = pickle.load(fr)

texts = [str(item) for item in input_data]

# Tokenize and pad sequences
tokenizer = Tokenizer()
tokenizer.fit_on_texts(texts)
sequences = tokenizer.texts_to_sequences(texts)
padded_sequences = pad_sequences(sequences)

# Convert target data to binary format
binary_mapping = {'i': 0, 'e': 1, 'n': 0, 's': 1, 'f': 0, 't': 1, 'p': 0, 'j': 1}
target_class_data_mapped = [[binary_mapping[j] for j in mbti] for mbti in target_class_data]

# Split data into train and test
x_train = padded_sequences[::5]  # Using every 5th element for test
y_train = np.array(target_class_data_mapped[::5], dtype=np.float32)
x_test = padded_sequences[1::5]  # Using every element except for the 5th for train
y_test = np.array(target_class_data_mapped[1::5], dtype=np.float32)

# RNN model definition
model = tf.keras.Sequential([
    tf.keras.layers.Embedding(input_dim=len(tokenizer.word_index) + 1, output_dim=4, input_length=padded_sequences.shape[1]),
    tf.keras.layers.SimpleRNN(units=4),
    tf.keras.layers.Dense(units=4, activation='softmax')
])

# Model compilation
model.compile(optimizer='adam', loss='binary_crossentropy', metrics=['accuracy'])

# Model training
model.fit(x_train, y_train, epochs=10, batch_size=100)

# Model evaluation
results = model.predict(x_test)
print(results)
print("Test Loss:", results[0])
print("Test Accuracy:", results[1])
