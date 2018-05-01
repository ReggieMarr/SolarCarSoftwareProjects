import urllib.request
import json

api_key = 'AIzaSyDNZlYoKzNgHVubWwuhGwzPcwDHmaEtNUQ'

ELEVATION_BASE_URL = 'https://maps.googleapis.com/maps/api/elevation/json?'
CHART_BASE_URL = 'https://chart.apis.google.com/chart?'

elevationArray = []

def getElevation(lattitudeA = '43.25941',longitudeA = '-79.907749',lattitudeB = '43.2584836',longitudeB='-79.908994',samples ='4'):
    latA = lattitudeA
    longA = longitudeA

    latB = lattitudeB
    longB = longitudeB

    path = latA+','+longA+'|'+latB+','+longB
    samples = samples
    
    reqElevation = 'path={}&samples={}&key={}'.format(path, samples, api_key)

    return reqElevation

elevation_req = getElevation(lattitudeA = '43.25941',longitudeA = '-79.907749',lattitudeB = '43.2584836',longitudeB='-79.908994',samples ='4')

request = ELEVATION_BASE_URL + elevation_req
response = urllib.request.urlopen(request).read()

for resultset in response['results']:
    elevationArray.append(resultset['elevation'])
