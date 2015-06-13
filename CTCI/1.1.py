# implement an algo to determine if a string has all unique chars. What if can't use additional data structures?

def is_unique_chars(str):
	count = {}
	for char in str:
		if char in count:
			count[char] += 1
		else:
			count[char] = 1
	for key in count:
		if count[key] > 1:
			return False
	return  True

print is_unique_chars('asdfg23985i')
print is_unique_chars('asdfg23985iR')
	
