import pyttsx3

engine = pyttsx3.init()

name  = int(input("Whar's your name? "))
engine.say(name)
engine.runAndWait()
