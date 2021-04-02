import hashlib
 
input_data = input()
encoded_data = input_data.encode()
result = hashlib.sha1(encoded_data).hexdigest()
print(result)
