''' Hacktoberfest 2018 code sample '''

class HelloHacktoberfest2018:

    def __init__(self, message):
        self.message = message

    def show_message(self):
        print(self.message)

def main():
    hacktober_machine = HelloHacktoberfest2018("Hello Hacktoberfest 2018! This is Gabe from Guam")
    hacktober_machine.show_message
    

if __name__ == "__main__":
    main()
