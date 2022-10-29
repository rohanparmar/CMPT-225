import math

def toBinary(a):
  l,m=[],[]
  for i in a:
    l.append(ord(i))
  for i in l:
    m.append(int(bin(i)[2:]))
  return m

# read the file line by line and convert it into well formatted data
# each line is made of two words separated by a space
# store the well formatted data in the file "myDataFile.txt"
# With the following format:
# word1:word2
with open("myDataFile.txt", "r") as oldFile:
    with open("myDataFile1.txt", "w") as newFile:
        for line in oldFile:
            # split the line into two words
            words = line.split(":")
            word1 = words[0]
            translation = str(toBinary(word1))
            # write the two words in the new file
            newFile.write(word1 + ":" + translation + "\n")

