# Rock, paper, scissors game

# Import random function
import random
import color



def main():
    again = input('Do you want to play 'Rock-Paper-Scissors':, enter n to quit').lower()
    while again != 'n':
        computer_randomized_choice()
        user_choice()
        again = input('Do you want to play 'Rock-Paper-Scissors':, y/n ')
        print('good bye')
        quit()


def computer_randomized_choice():
    'get computer choice game_choice = ['rock', 'paper', 'scissors']'
    global computer_choice
    rpslist = ['rock', 'paper', 'scissors']
    computer_choice = random.choice(rpslist)
    # print ('computer_choice: ', computer_choice)
    return computer_choice

# get user choice
def user_choice():
    user_input = input('Enter your choice: Rock, Paper, or Scissors: ').lower()
    print('user_input:', user_input)
    if user_input== 'rock':
        user_choice_rock()
    elif user_input== 'paper':
        user_choice_paper()
    elif user_input == 'scissors':
            user_choice_scissors()
    else:
        print('please enter the correct stuff')
        user_choice()
    print('////////////////////////////////////////////////')
    main()

# compare user choice and computer choice
def user_choice_rock():
    if computer_choice == 'rock':
        print(color.yellow("YOU TIE: you entered 'Rock and computer selected 'Rock'"))
    elif computer_choice == 'paper':
        print(color.red("YOU LOSE: you entered 'Rock' and Computer selected 'paper'"))
    elif computer_choice == 'scissors':
        print(color.green("YOU WIN: you entered 'Rock' and computer selected 'scissors'"))
    else:
        print('try again')
        user_choice()




