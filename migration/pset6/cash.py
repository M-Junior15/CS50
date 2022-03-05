from cs50 import get_float

while True:
    number = get_float("Change owed: ")
    if number > 0:
        break
    
cont = 0
number = int(number * 100)
while True:
    if number == 0:
        break
    
    elif number >= 25:
        number -= 25
        cont += 1
        
    elif number >= 10:
        number -= 10
        cont += 1
        
    elif number >= 5:
        number -= 5
        cont += 1
    
    elif number >= 1:
        number -= 1
        cont += 1

    
print(cont)
