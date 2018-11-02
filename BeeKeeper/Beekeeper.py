#Global vowels
doubleVowels = ['aa', 'ee', 'ii', 'oo', 'uu', 'yy']

def main():

    #Gets the N for 1st case
    inputN = input()
    inputN = int(inputN)

    #List to store the words
    listOfWords = []

    mostRepeatVowels = ""

    while(inputN != 0):
        for i in range(inputN):
            newWord = str(input())
            listOfWords.append(newWord)

        biggest = -1
        for word in listOfWords:
            #Gets the sum of how many doubleVowels are in the list
            count = sum([word.count(substr) for substr in doubleVowels])
            if(count > biggest):
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