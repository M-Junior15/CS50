import csv

with open("phonebook.csv", 'a') as file:

    name = str(input("Name: "))
    number = str(input("Number: "))
    
    writer = csv.writer(file)
    
    writer.writerow([name, number])
