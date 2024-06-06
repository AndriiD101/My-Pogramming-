import random
import telebot
from telebot import types
import pickle
import datetime as dt
import requests
import json

API_KEY_TELEGRAM = '7291165381:AAGNPCa2jI5V9SimqRYOOe7UKUGElNW78CE'
API_KEY_OPENWEATHER = 'd039ca07f1aa96d0f872e02adc2f6d83'

BASE_URL = "https://api.openweathermap.org/data/2.5/weather?"

bot = telebot.TeleBot(API_KEY_TELEGRAM)

TARGET = "C:/Users/denys/OneDrive/Desktop/Programming/telegram bot/city.txt"
    
@bot.message_handler(commands=['greet'])
def greet(message):
    bot.reply_to(message, "Hey! How's it going?")

@bot.message_handler(func=lambda msg: True)
def give_weather(message):
    city = message.text
    url = BASE_URL + "appid=" + API_KEY_OPENWEATHER + "&q=" + city
    response = requests.get(url).json()
    print(response)

    weather_description = response.get('weather')[0].get('description')
    temperature = response.get('main').get('temp')

    formatted_message = f"Weather in {city}: {weather_description}, Temperature: {round(temperature-273.15)}°C"
    bot.reply_to(message, formatted_message)
    with open(TARGET, 'a') as cityfile:
        cityfile.write(city + '\n')
    bot.reply_to(message, f"City '{city}' saved!")
    with open(TARGET, 'r') as cityfile:
        print(cityfile.read())


if __name__ == '__main__':
    bot.polling()