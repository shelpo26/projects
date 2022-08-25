# Function that accepts two arguments

def start():
    print('The sum of 12 and 45 is')
    show_sum(12, 45)

# the show sum function accepts 2 arguments and shows the sum
def show_sum(num1, num2):
    result = num1 + num2
    print(result)

# call main function
start()