''' 
Script description: Get all data about solar systeam '''

import os
import requests


os.system('clear') #limpiar pantalla

def get_data():
    print("::SOLAR SYTEM INFORMATION:::")
 
try:
    url = "https://api.le-systeme-solaire.net/rest/bodies/?filter%5B%5D=isComet"
    #Request to AOI
    res= requests.get(url)
    res.raise_for_status()

    #Convert answer to JSON (JS Object Notation)
    data = res.json()

    print(data)

except requests.exceptions.RequestException as e:
    print(f"API error:{e}")
get_data()
    
