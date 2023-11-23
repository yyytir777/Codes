import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import warnings
warnings.filterwarnings('ignore')

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder

data = pd.read_csv('/kaggle/input/mbti-personality-type-twitter-dataset/twitter_MBTI.csv')


# Split the DataFrame into train and test sets
train_data, test_data = train_test_split(data, test_size=0.1, random_state=42)

# Encode the labels using LabelEncoder
le = LabelEncoder()
le.fit(data['label'].unique())
train_data['label'] = le.transform(train_data['label'])
test_data['label'] = le.transform(test_data['label'])

# Initialize TfidfVectorizer
vectorizer = TfidfVectorizer(stop_words='english', max_features=1000)

# Fit and transform the text data
X_train = vectorizer.fit_transform(train_data['text'])
X_test = vectorizer.transform(test_data['text'])

# Get the feature names from the vectorizer
feature_names = vectorizer.get_feature_names_out()

# Create a DataFrame from the feature names and their corresponding TF-IDF scores
tfidf_scores = pd.DataFrame(X_train.toarray(), columns=feature_names)

# Group the data by label and calculate the mean of each feature for each label
mean_tfidf_by_label = tfidf_scores.groupby(train_data['label']).mean()

# Display the top 10 features for each label
for idx, row in mean_tfidf_by_label.iterrows():
    label_idx = int(idx)
    label = le.inverse_transform([label_idx])[0]
    print(f"Top 10 features for label {label}:")
    print(row.nlargest(10))
    print("\n")

#Top 10 features for label enfj:
#https     0.544064
#like      0.088445
#just      0.073376
#im        0.062178
#love      0.054354
#don       0.045868
#good      0.044032
#people    0.038759
#thank     0.037399
#think     0.036237
#Name: 0.0, dtype: float64

#Top 10 features for label enfp:
#https    0.544385
#ike     0.087725
#im       0.075049
#just     0.074734
#love     0.055559
#good     0.045889
#don      0.043349
#thank    0.040182
#lt       0.039768
#know     0.035386
#Name: 1.0, dtype: float64


from sklearn.feature_extraction.text import TfidfVectorizer, ENGLISH_STOP_WORDS
from sklearn.preprocessing import LabelEncoder

# Add common words to the stop_words list
custom_stop_words = ['https', 'like', 'just', 'im', 'love', 'don', 'good', 'thank', 'people', 'know', 'think']

# Combine the default 'english' stop words and the custom stop words
stop_words = list(ENGLISH_STOP_WORDS) + custom_stop_words

# Create the TfidfVectorizer with the updated stop_words list
vectorizer = TfidfVectorizer(stop_words=stop_words)
le = LabelEncoder()

# Fit and transform the data
X_train = vectorizer.fit_transform(train_data['text'])
y_train = le.fit_transform(train_data['label'])

# Transform the test data
X_test = vectorizer.transform(test_data['text'])

# Calculate the mean TF-IDF score for each label
mean_tfidf_by_label = pd.DataFrame(X_train.toarray(), columns=vectorizer.get_feature_names_out()).groupby(y_train).mean()

# Display the top 10 features for each label
for idx, row in mean_tfidf_by_label.iterrows():
    label = le.inverse_transform([idx])[0]
    print(f"Top 10 features for label {label}:")
    print(row.nlargest(10))
    print("\n")

#Top 10 features for label 0:
#ve        0.013251
#really    0.013129
#lt        0.012899
#day       0.012547
#amp       0.012473
#omg       0.012216
#time      0.012174
#today     0.011517
#got       0.010816
#yes       0.010775
#Name: 0, dtype: float64

#Top 10 features for label 1:
#time      0.013075
#lt        0.012994
#omg       0.012984
#ve        0.011553
#oh        0.011525
#really    0.011395
#ur        0.011345
#want      0.011191
#got       0.011111
#day       0.010848
#Name: 1, dtype: float64