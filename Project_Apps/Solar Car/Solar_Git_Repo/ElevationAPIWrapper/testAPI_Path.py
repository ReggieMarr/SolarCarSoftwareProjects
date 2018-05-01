import urllib.request
import json

api_key = 'AIzaSyDNZlYoKzNgHVubWwuhGwzPcwDHmaEtNUQ'

endpoint = 'https://maps.googleapis.com/maps/api/elevation/json?'

#latA = input('Start Lattitude:').replace(' ','+')
#longA = input('Start Longitude:').replace(' ','+')
latA = '43.25941'
longA = '-79.907749'
#latB = input('End Lattitude:').replace(' ','+')
#longB = input('End Longitude:').replace(' ','+')
latB = '43.2584836'
longB = '-79.908994'

#path = latA+','+longA+'|'+latB+','+longB+'|'+latA+','+longA
path = '1,1|2,2|3,3'
samples = '3'
elevation_req = 'path={}&samples={}&key={}'.format(path, samples, api_key)
request = endpoint + elevation_req
response = urllib.request.urlopen(request).read()

print(response)

#elevation = json.loads(response)
#print(elevation)
