from cs50 import get_string

def main():
    # Input the phrase
    phrase = get_string("Text: ")
    # Call the CHECK_SENTENCE function
    phrase = check_sentence(phrase)

    # Check the grade
    while True:
        if phrase <= 1:
            print("Before Grade 1")
            break
        elif 1 < phrase <= 16:
            print(f"Grade {phrase}")
            break
        else:
            print("Grade 16+")
            break

def check_sentence(text):
    letter, sentence, word = 0, 0, 1

    # Check every characters in the text
    for i in text:

        # If has space between the words
        if ' ' in i:
            word += 1

        # Check for punctuation
        elif '.' in i or '!' in i or '?' in i:
            sentence += 1

        # Check for letters
        elif i.isalpha() == True:
            letter += 1

    # Coleman Liau formula
    index = 0.0588 * letter / word * 100 - 0.296 * sentence / word * 100 - 15.8

    # Return the round of
    return round(index)
main()
