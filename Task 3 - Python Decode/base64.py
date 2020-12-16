import base64

b64bytes = bytes("QlpoOTFBWSZTWQyQhfwAAAWVgEAEABAz93MwIABUUDTQyMmINU8Q1NGTyniNm7sdsz3jfp9FKs41\\nfYwWkEIB9AhHU5MqqlamYbfxdyRThQkAyQhfwA==", 'utf8')
encoded = base64.decodebytes(b64bytes).decode('utf8')

print(encoded)