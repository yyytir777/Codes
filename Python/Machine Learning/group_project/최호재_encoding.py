import re
import string
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem import WordNetLemmatizer
import nltk

nltk.download('punkt')
nltk.download('stopwords')
nltk.download('wordnet')

def preprocess_tweet(tweet):
    # Convert to lower case
    tweet = tweet.lower()
    # Remove URLs
    tweet = re.sub(r"http\S+|www\S+|https\S+", '', tweet, flags=re.MULTILINE)
    # Remove user @ references and '#' from tweet
    tweet = re.sub(r'\@\w+|\#','', tweet)
    # Remove punctuations
    tweet = tweet.translate(str.maketrans('', '', string.punctuation))
    # Remove numbers
    tweet = re.sub(r'\d+', '', tweet)
    # Remove excess whitespace
    tweet = tweet.strip()
    # Tokenize the tweet
    tweet_tokens = word_tokenize(tweet)
    # Remove stopwords
    stopwords_english = set(stopwords.words('english'))
    tweet_clean = [word for word in tweet_tokens if word not in stopwords_english]
    # Instantiate lemmatizer
    lemmatizer = WordNetLemmatizer()
    # Lemmatize the words in the tweet
    tweet_lemmatized = [lemmatizer.lemmatize(word) for word in tweet_clean]
    return ' '.join(tweet_lemmatized)

# Example dataset as one long string, where each entry is separated by '|||'
dataset = "I'm like entp but idiotic|||Hey boy, do you want to watch twitch with me?|||I kin Simon from Alvin And The Chipmunks|||I need more sleep|||Why do they call me a menace?|||I am like infp but better|||Thinking about being unproductive|||Is it genius?|||I feel empty|||I'm going to make clever decisions|||Hey girl, do you want to watch twitch with me?|||I'm like istp but smart|||How do I deal with emotional people?|||It is 3 am and I'm daydreaming about procrastinating|||Am I chaotic or just an intp?|||How do I deal with entps?|||Why smoke, when you can spend many hours on social media?|||I think I will pretend to be sane for fun.|||Hey girl, do you want to watch twitch with me?|||My Ti makes me empty"

# Split the dataset into individual text entries
texts = dataset.split('|||')

# Preprocess the texts
preprocessed_texts = [preprocess_tweet(text) for text in texts]
print(preprocessed_texts)
# The preprocessed_texts will contain the output of the cleaned and preprocessed text entries.