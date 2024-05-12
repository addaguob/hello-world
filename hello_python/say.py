import cowsay
import pyttsx3

engine = pyttsx3.init()
this = input("What's this? ")

cowsay.cow(this)
engine.say(this)
engine.runAndWait()


num = 1


def get_var_name(variable):
    var_name = [name for name, value in locals().items()
                if value is variable][0]
    return var_name


print(get_var_name(num))
