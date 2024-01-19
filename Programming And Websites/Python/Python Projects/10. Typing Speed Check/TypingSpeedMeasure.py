import time
def calculate_typing_speed(text, time_taken):
    words = text.split()
    word_count = len(words)
    minutes = time_taken / 60
    wpm = word_count / minutes
    return wpm
def calculate_accuracy(original_text, typed_text):
    original_words = original_text.split()
    typed_words = typed_text.split()
    correct_word_count = sum(1 for w1, w2 in zip(original_words, typed_words) if w1 == w2)
    total_word_count = len(original_words)
    accuracy = (correct_word_count / total_word_count) * 100
    return round(accuracy, 2)
def main():
    print("Welcome to the Typing Speed Calculator!")
    input("Press Enter to start the typing test...")
    text_to_type = "The quick brown fox jumps over the lazy dog."
    print(f"Type the following text as fast as you can:\n{text_to_type}")
    start_time = time.time()
    user_input = input("Start typing: ")
    end_time = time.time()
    time_taken = end_time - start_time
    typed_text = user_input.strip()
    accuracy = calculate_accuracy(text_to_type, typed_text)
    wpm = calculate_typing_speed(text_to_type, time_taken)
    print(f"\nYou typed at {wpm:.2f} WPM with {accuracy}% accuracy!")
    print(f"Time taken: {time_taken:.2f} seconds")

if __name__ == "__main__":
    main()
