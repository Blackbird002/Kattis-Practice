def main():
    jonSayStr = input()
    docWantsStr = input()

    jonSay = len(jonSayStr)
    docWants = len(docWantsStr)

    if(docWants <= jonSay):
        print("go")
    else:
        print("no")

#Runs the program
main()