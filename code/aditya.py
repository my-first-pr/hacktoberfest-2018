import random
import time

#list of words
words = ("python", "india", "japan", "mother", "computer", "watch", "keyboard", "compass", 
"bottle", "monitor", "switch", "shoes", "chain", "mobile", "coffee", "alfredo", "mouse", 
"stomach", "tablet", "mojito", "halapeneos", "pizza", "nutella", "peanut", "broccoli")
n = 0

#defining class player
class Player:
    def __init__(self, name):
        self.name = name
        self.score = 0

#Function to fetch Jumbled Word!
def getJumbledWord():
    word = random.choice(words)
    origWord = word
    jumbledWord = ''.join(random.sample(word, len(word)))
    return jumbledWord, origWord

#Function to show Result
def showResult(player1, player2):
    if player1.score > player2.score:
        print('Player 1 {} is Winner!'.format(player1.name))
        print('Player 1 Score: ', player1.score)
        print('Player 2 Score: ', player2.score)

    if player1.score < player2.score:
        print('Player 2 {} is Winner!'.format(player2.name))
        print('Player 2 Score: ', player2.score)
        print('Player 1 Score: ', player1.score)
    
    else:
        print('The Game is Drawn!')
        print('Player 1: {}       Player 2: {}'.format(player1.score, player2.score))

#Function for countdown timer (source: https://stackoverflow.com/questions/25189554/countdown-clock-0105)
def countdown(t):
    while t:
        mins, secs = divmod(t, 60)
        timeformat = '{:02d}:{:02d}'.format(mins, secs)
        print(timeformat, end='\r')
        time.sleep(1)
        t -= 1

print('Welcome to JUmBLeD!')
print('Guess the correct anwer to win points!')
print('The one who scores the most out of 10 questions wins!')
print('Note: Player who fails to give answer within 15 secs will loose!\n\n')

print('Player1:')
name1 = input('Enter your Name: ')
player1 = Player(name1)

print('Player2:')
name2 = input('Enter your Name: ')
player2 = Player(name2)

while(n<=5):
    jumbledWord1, origWord1 = getJumbledWord()
    print('Question {}: \n\n'.format(n))
    print('Player 1:') 
    print('Your Jumbled word is: ', jumbledWord1)
    
    w1 = input('Player 1 Answer: ')

    if w1 == origWord1:
        player1.score += 1
        print('correct!')
        print('Score: ', player1.score)
        print('\n')
    else: 
        print("Incorrect!")
        print('Score: ', player1.score)
        print('\n')
    

    jumbledWord2, origWord2 = getJumbledWord()
    print('Player 2:')
    print('Your Jumbled word is: ', jumbledWord2)

    w2 = input('Player 2 Answer: ')

    if w2 == origWord2:
        player2.score += 1
        print('correct!')
        print('Score: ', player2.score)
        print('\n')
    else: 
        print("Incorrect!")
        print('Score: ', player2.score)
        print('\n')
    n += 1

showResult(player1, player2)