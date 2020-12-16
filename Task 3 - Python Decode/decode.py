encoded = bytes("QlpoOTFBWSZTWQyQhfwAAAWVgEAEABAz93MwIABUUDTQyMmINU8Q1NGTyniNm7sdsz3jfp9FKs41\\nfYwWkEIB9AhHU5MqqlamYbfxdyRThQkAyQhfwA==", 'utf8')
decoded = bytes.decode(encoded, encoding='utf8')

print(decoded)