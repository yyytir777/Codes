import pandas as pd
import csv

# with open('C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\twitter_MBTI.csv', newline='') as csvfile:
#     csvreader = csv.DictReader(csvfile)


df = pd.read_csv("C:\\Users\\yyyti\\Documents\\Code\\Python\\Machine Learning\\팀플\\twitter_MBTI.csv", encoding='iso-8859-1')

array = df.to_numpy()

string = array[:1,:]
split_string = [text.split("|||") for text in string]

print(split_string)
