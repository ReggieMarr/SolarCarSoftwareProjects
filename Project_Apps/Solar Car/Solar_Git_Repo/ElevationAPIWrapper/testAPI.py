import urllib.request
import json

api_key = 'AIzaSyDNZlYoKzNgHVubWwuhGwzPcwDHmaEtNUQ'
endpoint = 'https://maps.googleapis.com/maps/api/elevation/json?'
lat = input('Lattitude:')
long = input('Longitude:')
location = lat + ',' + long
elevation_req = 'locations={}&key={}'.format(location, api_key)
request = endpoint + elevation_req
#request = 'https://maps.googleapis.com/maps/api/elevation/json?locations=39.7391536,-104.9847034&key=AIzaSyDNZlYoKzNgHVubWwuhGwzPcwDHmaEtNUQ'
#request = 'https://maps.googleapis.com/maps/api/elevation/json?locations=-104.9847034,39.7391536&key=AIzaSyDNZlYoKzNgHVubWwuhGwzPcwDHmaEtNUQ'

response = urllib.request.urlopen(request).read()
#elevation = json.loads(response)
#print(elevation)
