def main():

    #Gets the N for 1st case
    inputN = input()
    inputN = int(inputN)

    #List to store 
    listOfElements = []

    prevTime = 0
    totalMiles = 0

    while(inputN != -1):
        for i in range(inputN):
            strLine = str(input())
            listOfElements = strLine.split()

            milesPerHour = int(listOfElements[0])
            hours = int(listOfElements[1]) - prevTime
            prevTime = int(listOfElements[1])

            totalMiles = (totalMiles) + (milesPerHour * hours)

        print(totalMiles, "miles")
 
        #Reset
        totalMiles = 0
        prevTime = 0
        listOfElements.clear()

        #Get antoher case
        inputN = input()
        inputN = int(inputN)
 
#Program runs here
main()