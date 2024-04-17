import serial
from pydub import AudioSegment
from pydub.playback import play
import time
import speech_recognition as sr
def record():
    rec = sr.Recognizer()
    with sr.Microphone() as source:
        print('Говорите...')
        rec.adjust_for_ambient_noise(source, duration=0.5)
        audio = rec.listen(source)
    text = rec.recognize_google(audio, language="ru-RU")
    print(text) ####
    return text




letter_dick = {
            'а' : [1,0],
            'б' : [3,0],
            'в' : [2,7],
            'г' : [3,3],
            'д' : [1,3],
            'е' : [1,2],
            'ё' : [1,4],
            'ж' : [2,3],
            'з' : [5,6],
            'и' : [2,1],
            'к' : [5,0],
            'л' : [7,0],
            'м' : [5,1],
            'н' : [5,3],
            'о' : [5,2],
            'п' : [7,1],
            'р' : [7,2],
            'с' : [6,1],
            'т' : [6,3],
            'у' : [5,4],
            'ф' : [3,1],
            'х' : [3,2],
            'ц' : [1,1],
            'ч' : [7,3],
            'ш' : [1,6],
            'щ' : [5,5],
            'ъ' : [7,6],
            'ы' : [6,5],
            'ь' : [6,7],
            'э' : [2,5],
            'ю' : [3,6],
            'я' : [3,5],
            ' ' : [0,0],
        }





port = "/dev/ttyUSB0"
baudrate = 9600

#try:
ser = serial.Serial(port, baudrate=baudrate)
print("Serial connection established.")

play(AudioSegment.from_wav('start_s.wav'))
speech = record()
for i in speech:
    command = str(letter_dick[i][0])
    ser.write(command.encode())
    print(command)
    time.sleep(10)
    command = "8"
    ser.write(command.encode())
    time.sleep(5)

    command = str(letter_dick[i][1])
    ser.write(command.encode())
    time.sleep(10)
    command = "8"
    ser.write(command.encode())
    time.sleep(5)
    command = "9"
    ser.write(command.encode())
    time.sleep(5)

print("Печать окончена.")
baudrate = 9600

#try:
ser = serial.Serial(port, baudrate=baudrate)
print("Serial connection established.")

def printing(sp):
    for i in sp:
        command = str(letter_dick[i][0])
        ser.write(command.encode())
        print(command)
        time.sleep(10)
        command = "8"
        ser.write(command.encode())
        time.sleep(5)

        command = str(letter_dick[i][1])
        ser.write(command.encode())
        time.sleep(10)
        command = "8"
        ser.write(command.encode())
        time.sleep(5)
        command = "9"
        ser.write(command.encode())
        time.sleep(5)

        command = "11"
        ser.write(command.encode())

count_for_p = -1
fin_c = len(speech)
while fin_c>0:
    for i in speech:
        count_for_p += 1
        if i == " ":
            probel = count_for_p

        if count_for_p == 25:
            printing(speech[:probel])
            sp = speech[probel + 1:]
            count_for_p = -1
            fin_c-= probel
            break


print("Печать окончена.")