import requests
import re

def get_country_for_city(city):
    response = requests.get(f"https://www.geonames.org/search.html?q={city}&country=")
    country = re.findall("/countries.*\\.html", response.text)[0].strip(".html").split("/")[-1]
    return country

city_name = "pidoras"
country_name = get_country_for_city(city_name)
print(f"{city_name} belongs to {country_name}")