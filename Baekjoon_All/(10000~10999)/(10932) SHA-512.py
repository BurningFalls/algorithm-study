import hashlib
 
input_data = input()
encoded_data = input_data.encode()
result = hashlib.sha512(encoded_data).hexdigest()
print(result)
