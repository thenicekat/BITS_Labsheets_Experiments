

offset = int(input("Enter the number of offset bits: "))
index = int(input("Enter the number of index bits: "))
tag = int(input("Enter the number of tag bits: "))
total = offset + index + tag

while True:
    x = int(input("Enter the number: "))
    
    offset_of_x =h x % (2 ** offset)
    index_of_x = (x >> offset) % (2 ** index)
    tag_of_x = (x >> (offset + index)) % (2 ** tag) 
    
    print(f"offset: {offset_of_x} index: {index_of_x} tag: {tag_of_x}")