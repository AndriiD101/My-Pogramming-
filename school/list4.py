import random

list = ['rock', 'paper', 'scissors']
t = True

while t == True:
    you = int(input("choose \n0)rock \n1)paper \n2)scissors \nenter the number: "))
    quit = input('If you want to quit press enter, if not write no: ')
    hum = list[you]
    AI = list[random.randint(0, 2)]
    if hum == 'rock' and AI == 'scissors':
        print('you won')
    elif hum == 'scissors' and AI == 'rock':
        print('AI won')
    elif hum == 'rock' and AI == 'paper':
        print('AI won')
    elif hum == 'paper' and AI == 'rock':
        print('you won')
    elif hum == 'scissors' and AI == 'paper':
        print('you won')
    elif AI == 'scissors' and hum == 'paper':
        print('AI won')
    elif you =='':
        t = False
    else:
        print("draw")