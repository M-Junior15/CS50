s = str(input("Do you agree? "))

if s.lower() in ['y', 'yes']:
    print("Agreed.")
elif s.lower() in ['n', 'no']:
    print("Not agreed.")
else:
    print("How to use: type [y/n] or [yes/no]")
    