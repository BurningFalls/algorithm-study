import hashlib
 
input_data = input()
encoded_data = input_data.encode()
result = hashlib.sha384(encoded_data).hexdigest()
print(result)
