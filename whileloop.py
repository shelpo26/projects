count = 0
user_input = input('enter any key')
while user_input != 'q':
    print('count is: ', count)
    count += 1
    user_input = input('keep counting? enter any key to continue or q to quit ').lower
print('\n\nThank you for counting with me')
