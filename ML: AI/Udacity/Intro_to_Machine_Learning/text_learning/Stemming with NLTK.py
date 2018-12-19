from nltk.stem.snowball import SnowballStemmer

stemmer = SnowballStemmer("english")

stemmer.stem("responsiveness")
stemmer.stem("responsivity")
stemmer.stem("unresponsive")