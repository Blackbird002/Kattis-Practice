#Global vowels
vs = ['aa', 'ee', 'ii', 'oo', 'uu', 'yy']

def main():

    #Gets the N for 1st case
    inputN = input()
    inputN = int(inputN)

    #List to store the words
    listOfWords = []

    mostRepeatVowels = "None"

    while(inputN != 0):
        for i in range(inputN):
            word = input()
            listOfWords.append(word)

        biggest = 0
        for word in listOfWords:
            count = sum([word.count(substr) for substr in vs])
            if(count >= biggest):
               biggest = count
               mostRepeatVowels = word

        print(mostRepeatVowels)

        #Reset for the next test case
        mostRepeatVowels = ""
        listOfWords.clear()

        #Get antoher case
        inputN = input()
        inputN = int(inputN)


 
#Program runs here
main()