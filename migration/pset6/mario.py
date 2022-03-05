def main():
    # Input the height
    height = input("Height: ")
    
    # Call the function CHECK
    height = check_num(height)

    # Print the pyramid
    for i in range(height):
        # Print the left side of the pyramid
        print(" " * (height - i - 1), end="")
        print("#" * (i + 1), end="")

        # Print the right side of the pyramid
        print("  ", end="")
        print("#" * (i + 1))

# Function to verify if it's numeric and it's between 0 and 9
def check_num(n):
    # Infinity loop
    while True:
        # Check if is empty
        if n == "":
            print("Invalid input")
            n = input("Height: ")          

        # Check if it's alpha
        elif n.isalpha() == True:
            print("Height must be numeric")
            n = input("Height: ")
        
        # Check if it's not alpha and is greater tha 8 and less than 1
        elif n.isalpha() == False and int(n) < 1 or int(n) > 8:
            print("Height must be between 0 and 9")
            n = input("Height: ")
        
        # Check if it's numeric and it's between 0 and 9
        elif n.isalpha() == False and 0 < int(n) < 9:
            break
        
    # Return integer N
    return int(n)

main()
