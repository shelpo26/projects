# Function that accepts two arguments

def main():
    num1 = int(input('enter 1st number: '))
    num2 = int(input('enter 2nd number: '))
    print('the result is', show_sum(num1, num2))

# the show sum function accepts 2 arguments and shows the sum
def show_sum(num1, num2):
    result = num1 + num2
    return result

# call main function
main()