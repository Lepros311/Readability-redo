#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);

int count_words(string text);

int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
//    printf("%s\n", text);


    int letters = count_letters(text); // count_letters(text); is enough to call the function, but it will return the number of letters and I want to capture that. So, I'm declaring my variable as 'letters' and the value returned by the function will be stored in that variable for later use.

//    printf("%i letters\n", letters); // This has to come after 'letters' is declared/initialized, otherwise it will not know what 'letters' is since the program reads from top to bottom.

    int words = count_words(text);

//    printf("%i words\n", words);

    int sentences = count_sentences(text);

//    printf("%i sentences\n", sentences);


    float L = (float) letters / (float) words * 100;  // For accuracy, we need to cast the integers as floats when dividing. This is mentioned in the second bullet point at 'Putting it All Together > Hints'.

    float S = (float) sentences / (float) words * 100;  // Again, for accuracy, we need to cast the integers as floats when dividing. This is mentioned in the second bullet point at 'Putting it All Together > Hints'.

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = round(index);  // To use the 'round' function, we need to add math.h to the top of our file.

    if (index >= 16) {
        printf("Grade 16+\n");
    } else if (index < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", grade);
    }
}



int count_letters(string text) {
    int letters_counting = 0;
    for (int i = 0; i < strlen(text); i++) {  // This for loop is saying that I want to step through the text the user gives me. I'm using 'i' as my counter. Also note, 'strlen' is a special function that returns the length of a string. However, it requires that we add '#include <string.h> at the top of our code so we can use it.
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {  // I realized when testing the word count that letters was also counting spaces. I forgot to add this if statement to account for that. Now it will only count letters if they are actual letters (not spaces, punctuation, etc.).
        letters_counting++;  // 'count_letters' is going to increase by 1 each time we step through the for loop. We step through the for loop basically as many times as the text string is long. For a 3-letter word, we step through the for loop 3 times and 'count_letters' ends up with a value of 3.
        }
    } return letters_counting;


//    return 27; // I set this to return '27' (could be anything really) just so my printf of 'letters' above is working and all is well with this function so far.
}


// I just copied and pasted the function above because I know I'll be doing something very similar, only for words instead. I'll just start by changing any occurrence of '...letters' to '...words'.
int count_words(string text) {
    int words_counting = 0;
    for (int i = 0; i <= strlen(text); i++) {  // I noticed that my word count was off by 1, so I changed it from '<' to '<='.
        if (text[i] == 32 || text[i] == '\0') {  // 32 is the ASCII value of a space and '\0' is the invisible value denoting the end of a string. If we reach either of these, we count a word.
        words_counting++;
        }
    } return words_counting;

//    } return 18;  // Again, this is just so I can be sure that this function is connected properly with the printf in main. I will worry about the actual words I test this and see 18 output in the console.
}



// Again, I just copied and pasted this function from the one above since we are stepping through the same text in the same way. Only this time I will replace '...words' with '...sentences' and altar my if statement.
int count_sentences(string text) {
    int sentences_counting = 0;
    for (int i = 0; i <= strlen(text); i++) {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63) {  // 46 is the ASCII value of a period, 33 is an exclamation point, and 63 is a question mark. If either of these is encountered as we step through the text, we will count one sentence.
        sentences_counting++;
        }
    } return sentences_counting;
}
