import requests

r = requests.get('https://api.onepeloton.com/api/v2/ride/archived?browse_category=cycling&content_format=audio,video&page=0')

print(r.status_code)
print(r.headers['content-type'])
print(r.json())