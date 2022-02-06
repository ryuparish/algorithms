import sys

def main(a, myString):
    index = 0
    charCount = []
    for char in myString:
        if char == a:
            charCount.append(index)
        index += 1
    return charCount

print(main('p', "apple"))
